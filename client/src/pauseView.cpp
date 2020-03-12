#include "../include/pauseView.h"
#include "../include/gameView.h"

PauseView::PauseView(const TextureManager& tm,const SdlWindow& window,GameView& gv,
	SoundManager& sm):
textureManager(tm),gameView(gv),soundManager(sm),blackArea(0,0,600,600),
twPause(window,"(Pausa)",0.05,0.05,48,2),
twResume(window,"Resumir",0.5,0.4,48,1),
twOptions(window,"Opciones",0.5,0.5,48,1),
twExit(window,"Salir",0.5,0.6,48,1),
twScreenOpt(window,"Video",0.5,0.4,48,1),
twControlOpt(window,"Controles",0.5,0.6,48,1), //wip
twSoundOpt(window,"Sonido",0.5,0.5,48,1),
twBack1(window,"Volver",0.5,0.7,48,1),
twMusicVolume1(window,"Volumen de musica",0.3,0.3,48,1),
twMusicVolume2(window,"<100>",0.72,0.4,48,1),
twFxVolume1(window,"Volumen de Efectos",0.3,0.6,48,1),
twFxVolume2(window,"<100>",0.72,0.7,48,1),
twBack2(window,"Volver",0.5,0.9,48,1),
twFull1(window,"Pantalla completa",0.3,0.3,48,1),
twFull2(window,"no",0.6,0.4,48,1),
twRes1(window,"Resolucion",0.3,0.6,48,1),
twRes2(window,"800x600",0.62,0.7,48,1),
twBack3(window,"Volver",0.5,0.9,48,1)
{
	this->twPause.changeColor(255,0,0);
	this->blackTexture = this->textureManager.getBlackTexturePointer();
	this->blackTexture->setAlpha(160);	
}

PauseView::~PauseView(){
	atexit(TTF_Quit);
}
     		

void PauseView::render(uint32_t resx,uint32_t resy){
	int music,fx;
	this->resx = resx;
	this->resy = resy;
	this->blackTexture->render(this->blackArea,Area(0,0,resx,resy));	
	twPause.render(resx,resy);
	switch(this->status){
		case INIT:
			twResume.render(this->resx,this->resy);
			twOptions.render(this->resx,this->resy);
			twExit.render(this->resx,this->resy);
			break;	
		case OPTIONS:
			twScreenOpt.render(this->resx,this->resy);
			twSoundOpt.render(this->resx,this->resy);
			//twControlOpt.render(this->resx,this->resy);
			twBack1.render(this->resx,this->resy);
			break;
		case SCREENOPT:
			if(this->gameView.isFullscreen()){
				twFull2.changeString("<si>");
				twRes2.lock();
			}else{
				twFull2.changeString("<no>");
				twRes2.unlock();				
			}
			twRes2.changeString("<"+std::to_string(resx)
				+"x"+std::to_string(resy)+">");
			twFull1.render(this->resx,this->resy);
			twFull2.render(this->resx,this->resy);
			twRes1.render(this->resx,this->resy);
			twRes2.render(this->resx,this->resy);
			twBack3.render(this->resx,this->resy);
			break;
		case SOUNDOPT:
			music = this->soundManager.getMusicVolume();
			twMusicVolume2.changeString("<"+std::to_string(music)+">");

			fx = this->soundManager.getFxVolume();			
			twFxVolume2.changeString("<"+std::to_string(fx)+">");

			twMusicVolume1.render(this->resx,this->resy);
			twMusicVolume2.render(this->resx,this->resy);
			twFxVolume1.render(this->resx,this->resy);
			twFxVolume2.render(this->resx,this->resy);
			twBack2.render(this->resx,this->resy);
			break;
		case CONTROLOPT:
		
			break;
	}
	
}

void PauseView::mouseButtonDown(uint32_t x,uint32_t y){
	switch(this->status){
		case INIT:
			if(this->twResume.cursorOn(x,y,this->resx,this->resy)){
				this->gameView.pause();
			}else if(this->twOptions.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			}else if( this->twExit.cursorOn(x,y,this->resx,this->resy)){
				this->stop = true;
			}
			break;	
		case OPTIONS:
			if(this->twSoundOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SOUNDOPT;
			}else if(this->twScreenOpt.cursorOn(x,y,this->resx,this->resy)){
				this->status = SCREENOPT;
			}else if( this->twControlOpt.cursorOn(x,y,this->resx,this->resy)){
				//this->status = CONTROLOPT;
			}else if( this->twBack1.cursorOn(x,y,this->resx,this->resy)){
				this->status = INIT;
			}
			break;
		case SCREENOPT:
			if( this->twBack3.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if( this->twFull2.firstCursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->twFull2.lastCursorOn(x,y,this->resx,this->resy)){
				if(this->gameView.isFullscreen()){
					this->gameView.windowed();
				} else {
					this->gameView.fullscreen();
				}
			} else if( this->twRes2.firstCursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.prevRes();
				} 
			} else if( this->twRes2.lastCursorOn(x,y,this->resx,this->resy)){
				if(!this->gameView.isFullscreen()){
					this->gameView.nextRes();
				} 
			}
			break;
		case SOUNDOPT:
			if( this->twBack2.cursorOn(x,y,this->resx,this->resy)){
				this->status = OPTIONS;
			} else if (this->twMusicVolume2.firstCursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicDown();
			} else if (this->twMusicVolume2.lastCursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnMusicUp();
			} else if (this->twFxVolume2.firstCursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnFxDown();
			} else if (this->twFxVolume2.lastCursorOn(x,y,this->resx,this->resy)){
				this->soundManager.turnFxUp();
			}
			break;
		case CONTROLOPT:

			break;	
	}
}

void PauseView::back(){
	switch(this->status){
		case INIT:
			this->gameView.pause();				
			break;	
		case OPTIONS:
			this->status = INIT;
			break;
		case SCREENOPT:
			this->status = OPTIONS;
			break;
		case SOUNDOPT:
			this->status = OPTIONS;
			break;
		case CONTROLOPT:
			this->status = OPTIONS;
			break;
	}
}

bool PauseView::stoped(){
	return this->stop;
}