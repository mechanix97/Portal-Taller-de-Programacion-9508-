#include "../include/videoRecorder.h"
#include <iostream>
VideoRecorder::VideoRecorder():
recording(false),running(true),stoping(false),bufferWidth(0), 
bufferHeight(0), frameCount(0){
	av_register_all();
	av_log_set_level(AV_LOG_QUIET);
}

VideoRecorder::~VideoRecorder(){}

void VideoRecorder::run(){
	std::vector<char>* aFrame;
	while(this->running){
		aFrame = this->frames.wait_and_pop();
		if(this->running){
			this->videoOutput->writeFrame(aFrame->data(), this->ctx);	
			delete aFrame;
			--this->frameCount;
			if(this->recording == false && this->frameCount == 0){
				this->videoOutput->close();
		    	sws_freeContext(this->ctx);	
		       	delete this->videoOutput; 	
		       	this->bufferWidth = 0;
				this->bufferHeight = 0;
				this->stoping = false;
			}
		}
	}
}

void VideoRecorder::stop(){
	if(this->recording){
		this->stopRecording();
	}
	this->running = false;
	this->frames.push(nullptr);
}

void VideoRecorder::startRecording(uint32_t width, uint32_t height){
	//si no se cerro la filmacion anterior no inicia una nueva
	if(!this->recording && !this->stoping){
		this->bufferWidth = width;
		this->bufferHeight = height;
		this->frameCount = 0;
		this->ctx = sws_getContext(this->bufferWidth, this->bufferHeight,
	        AV_PIX_FMT_RGB24, this->bufferWidth, this->bufferHeight,
	        AV_PIX_FMT_YUV420P, 0, 0, 0, 0);
		this->videoOutput = new OutputFormat(this->context, this->generateName(),
			width, height);
		this->recording = true;
	}
}

void VideoRecorder::stopRecording(){
	if(this->recording){
		this->recording = false;
		this->stoping = true;		
	}
}

void VideoRecorder::recordFrame(SDL_Renderer* renderer){
    std::vector<char>* v = new std::vector<char>(this->bufferWidth*this->bufferHeight*3);
    if(this->recording){  		  	
    	int res = SDL_RenderReadPixels(renderer, NULL, 
    	SDL_PIXELFORMAT_RGB24, v->data(), this->bufferWidth*3);
    	if (res) {
	        throw std::runtime_error("No se pudo guardar frame\n"+
	        	std::string(SDL_GetError()));
    	}
    	this->frames.push(v);
    	++this->frameCount;
    }
}

void VideoRecorder::checkResolution(uint32_t width, uint32_t height){
	if(this->recording){
		if(this->bufferWidth != width || this->bufferHeight != height){
			this->stopRecording();
			this->startRecording(width,height);
		}
	}
}

std::string VideoRecorder::generateName(){
	auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::stringstream ss;
    ss <<  std::put_time(&tm, "../movies/%d-%m-%Y-%H-%M-%S.mpeg");
    return ss.str();
}

bool VideoRecorder::isRecording() const{
	return this->recording;
}
