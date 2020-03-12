#include "../include/gameView.h"

GameView::GameView(uint32_t x, uint32_t y, SoundManager& sm,
	const std::string backgroundFile) :
 	finished(false),
resx(x),resy(y),window(x,y), textureManager(window), soundManager(sm),myChell(nullptr),
myChellId(0), scale(1), paused(false), background(window,backgroundFile),
pauseView(this->textureManager,window,*this,this->soundManager),
recordingDot(this->window,"o",0.98,0.02,10,1){
	this->cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
	SDL_SetCursor(this->cursor);
	this->resolutions = this->window.getResolutions();
	this->getResolutionsIndex();
	this->recordingDot.changeColor(255,0,0);
	this->recordingDot.setOutline(5);
}

GameView::~GameView(){
	if(this->myChell != nullptr){
		delete this->myChell;
	}
	for( auto it : this->entities){
		if(it.second != nullptr){
			delete it.second;
		}
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			delete it.second;
		}
	}
	SDL_FreeCursor(this->cursor);
	if(this->endMesage != nullptr){
		delete this->endMesage;
	}
}

void GameView::step(){
	for( auto it : this->entities){
		if(it.second != nullptr){
			it.second->step();
		}
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			it.second->step();
		}
	}
	if(this->myChell != nullptr){
		this->danceMode = this->myChell->isDancing();
		this->myChell->step();
	}	
}

void GameView::render(bool recording){
	this->updateResolution();
	this->window.fill(); // Repinto el fondo gris
	if(this->myChell != nullptr){
		this->posx = this->myChell->getPosX();
		this->posy = this->myChell->getPosY();
	}
	if(this->danceMode){
		this->background.setColorMod(rand()%255,rand()%255,rand()%255);	
	}else{
		this->background.resetColorMod();	
	}
	this->background.render(this->posx,this->posy,this->resx,this->resy,this->scale);

	for( auto it : this->entities){
		if(it.second != nullptr){			
			if(this->danceMode){
				it.second->setColorMod(rand()%255,rand()%255,rand()%255);
			}else{
				it.second->resetColorMod();
			}
			it.second->render(this->posx,this->posy,this->resx,this->resy,this->scale);	
		}		
	}
	for( auto it : this->chells){
		if(it.second != nullptr){
			it.second->render(this->posx,this->posy,this->resx,this->resy,this->scale);	
		}		
	}
	if(this->myChell != nullptr){
		this->myChell->renderCentered(this->resx,this->resy,this->scale);	
	}
	if(recording){
		this->recordingDot.render(this->resx,this->resy);
	}
	if(this->endMesage != nullptr){
		this->endMesage->render(this->resx,this->resy);
	} else if(this->paused){
		this->pauseView.render(this->resx,this->resy);	
	}
    this->window.render();
}

void GameView::updateHandler(Update update){
	if(this->finished){
		return;
	}
	EntityFactory ef;
	uint32_t id;
	switch(update.getCommand()){
	case COMMAND::CREATE_COMMAND:			
		id = update.getIdObject();
		if(id == this->myChellId){ 
			this->myChell = (Chell *)ef.create(update,this->textureManager,this->soundManager);
		} else if(update.getIdClass() == ENTITY::CHELL){
			this->chells[id] = (Chell *) ef.create(update,this->textureManager,this->soundManager);
			this->chells[id]->setColorMod(this->getRand(),this->getRand(),this->getRand());
		} else {
			this->entities[id] = ef.create(update,this->textureManager,this->soundManager);
		}
		break;
	case COMMAND::UPDATE_COMMAND:
		id = update.getIdObject();
		if(id == this->myChellId && this->myChell != nullptr){
			this->myChell->update(update);			
		} else if (this->chells.find(id) != this->chells.end()){
			this->chells[id]->update(update);
		} else if( this->entities.find(id) != this->entities.end()){
			this->entities[id]->update(update);
		}
		break;
	case COMMAND::DESTROY_COMMAND:
		id = update.getIdObject();
		if(id == this->myChellId){			
			delete this->myChell;
			this->myChell = nullptr;				
		} else if (this->chells.find(id) != this->chells.end()){
			this->chells.erase(id);
		} else if( this->entities.find(id) != this->entities.end()){
			this->entities.erase(id);
		}
		break;
	case COMMAND::WIN_COMMAND:		
		if(this->myChell != nullptr){
			this->myChell->jig();
		}		
		this->finished = true;
		this->showWinMesage();
		break;
	case COMMAND::LOSE_COMMAND:
		this->finished = true;
		this->showLoseMesage();
		break;
	default:
		break;
	}
}

bool GameView::isFinished() const{
	return this->finished;
}

void GameView::zoomIn(){
	if(this->scale < 1){
		this->scale+=0.05;
	}
}

void GameView::zoomOut(){
	if(this->scale > 0.05){
		this->scale-=0.05;
	}
}

uint32_t GameView::getChellId() const{
	return this->myChellId;
}

void GameView::setChellId(uint32_t id){
	this->myChellId = id;
}

void GameView::updateResolution(){
	this->resx=this->window.getResX();
	this->resy=this->window.getResY();
}

void GameView::fullscreen(){
	this->window.fullscreen();
	this->fullscreenBool = true;
}

void GameView::windowed(){
	this->window.windowed();
	this->fullscreenBool = false;
}

bool GameView::isFullscreen(){
	return this->fullscreenBool;
}

void GameView::prevRes(){
	if(this->resolutionsIndex == 0){
		this->resolutionsIndex = this->resolutions.size() - 1;
	} else {
		--this->resolutionsIndex;
	}
	this->window.changeRes(this->resolutions[this->resolutionsIndex].first,
		this->resolutions[this->resolutionsIndex].second);
}

void GameView::nextRes(){
	++this->resolutionsIndex;
	if(this->resolutionsIndex == this->resolutions.size()){
		this->resolutionsIndex = 0;
	}
	this->window.changeRes(this->resolutions[this->resolutionsIndex].first,
		this->resolutions[this->resolutionsIndex].second);
}

bool GameView::isPaused() const{
	return this->paused;
}

void GameView::pause(){
	this->paused = !this->paused;
	if(this->paused){
		this->soundManager.pauseMusic();
	} else {
		this->soundManager.resumeMusic();
	}

}

int32_t GameView::pixelToCoordX(int32_t x) const{
	if(this->myChell == nullptr){
		return 0;
	}
	int32_t cordx = this->myChell->getPosX();
	int32_t a=x-(this->resx/2);
    a = a/this->scale + cordx;
    return a;
}

int32_t GameView::pixelToCoordY(int32_t y) const{
	if(this->myChell == nullptr){
		return 0;
	}
	int32_t cordy = this->myChell->getPosY();
    int32_t b=y-(2*this->resy/3);
    b = -b/this->scale + cordy;
    return b;
}

SDL_Renderer* GameView::getRenderer() const{
	return this->window.getRenderer();
}

uint32_t GameView::getResX() const{
	return this->resx;
}

uint32_t GameView::getResY() const{
	return this->resy;
}

uint8_t GameView::getRand() const{
	double n = ((double)rand()/RAND_MAX);
	if(n < 0.333){
		return 180;
	}else if(n < 0.666){
		return 220;
	}else{
		return 255;
	}
}

PauseView* GameView::getPausePtr(){
	return &this->pauseView;
}

void GameView::showLoseMesage(){
	this->endMesage = new TextWidget(this->window,"(DERROTA!)",0.5,0.5,70,2);
	this->endMesage->changeColor(255,200,0);
}

void GameView::showWinMesage(){
	this->endMesage = new TextWidget(this->window,"(VICTORIA!)",0.5,0.5,70,2);
	this->endMesage->changeColor(255,200,0);
}

void GameView::getResolutionsIndex(){
	for(uint32_t i = 0; i < this->resolutions.size(); ++i){
		if(this->resolutions[i].first == 800
			&& this->resolutions[i].second == 600){
			this->resolutionsIndex = i;
			return;
		}
	}
	this->resolutionsIndex = 0;
}
