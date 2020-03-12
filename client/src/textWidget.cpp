#include "../include/textWidget.h"


TextWidget::TextWidget(const SdlWindow& window,const std::string str,float x,float y,
	uint32_t size,uint32_t font):
window(window),str(str),x(x),y(y),selected(false){
	if( TTF_Init() == -1 ) { 		
		throw std::runtime_error("SDL_ttf could not initialize! SDL_ttf Error: "+
			std::string(TTF_GetError())+"\n");
	}
	switch(font){
		case 1:
			this->font = TTF_OpenFont(FONT_DIR1, size);	
			break;
		case 2:
			this->font = TTF_OpenFont(FONT_DIR2, size);	
			break;
		default:
			this->font = TTF_OpenFont(FONT_DIR1, size);	
			break;
	}
	
	if(this->font == NULL){
		throw std::runtime_error("SDL_ttf could not open font\n");
	}
	this->textColor = { 255, 255, 255 };
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

TextWidget::~TextWidget(){
	TTF_CloseFont(this->font );
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
}

void TextWidget::render(uint32_t resx,uint32_t resy){
	Area src(0,0,this->textSurface->w,this->textSurface->h);
	Area dest((resx-this->textSurface->w)*this->x,
		(resy-this->textSurface->h)*this->y,
		this->textSurface->w,
		this->textSurface->h);
	SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_RenderCopy(this->window.getRenderer(), this->texturePtr, &sdlSrc, &sdlDest);    
}

void TextWidget::changeColor(uint8_t r,uint8_t g,uint8_t b){
	this->textColor = {r,g,b};
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

void TextWidget::setOutline(uint32_t pixels){
	TTF_SetFontOutline(this->font, pixels);
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

bool TextWidget::cursorOn(uint32_t px,uint32_t py,uint32_t resx,uint32_t resy){
	if(px < (resx-this->textSurface->w)*this->x){
		return false;
	} else if (px > (resx-this->textSurface->w)*this->x+this->textSurface->w){
		return false;
	} else if (py < (resy-this->textSurface->h)*this->y){
		return false;
	}  else if (py > (resy-this->textSurface->h)*this->y+this->textSurface->h){
		return false;
	} else{
		return true;
	}
} 

void TextWidget::select(){
	this->changeColor(255,200,0);
}

void TextWidget::deselect(){
	this->changeColor(255,255,255);
}

void TextWidget::lock(){
	this->changeColor(128,128,128);
}

void TextWidget::unlock(){
	this->changeColor(255,255,255);
}

void TextWidget::changeString(const std::string& s){
	this->str = s;
	if(this->textSurface != nullptr){
		SDL_FreeSurface(this->textSurface);
		this->textSurface = nullptr;
	}
	if(this->texturePtr != nullptr){
		SDL_DestroyTexture(this->texturePtr);
		this->texturePtr = nullptr;
	}
	this->textSurface = TTF_RenderText_Solid( this->font, str.c_str(), this->textColor );
	this->texturePtr = SDL_CreateTextureFromSurface( this->window.getRenderer(), 
		this->textSurface );
}

bool TextWidget::firstCursorOn(uint32_t px,uint32_t py,uint32_t resx,uint32_t resy){
	if(px < (resx-this->textSurface->w)*this->x){
		return false;
	} else if (px > (resx-((this->textSurface->w)))*this->x
		+ this->textSurface->w/this->str.size()){
		return false;
	} else if (py < (resy-this->textSurface->h)*this->y){
		return false;
	}  else if (py > (resy-this->textSurface->h)*this->y+this->textSurface->h){
		return false;
	} else{
		return true;
	}
}

bool TextWidget::lastCursorOn(uint32_t px,uint32_t py,uint32_t resx,uint32_t resy){
	if(px < (resx-this->textSurface->w)*this->x 
		+ this->textSurface->w/this->str.size()*(this->str.size()-1))
	{
		return false;
	} else if (px > (resx-this->textSurface->w)*this->x+this->textSurface->w){
		return false;
	} else if (py < (resy-this->textSurface->h)*this->y){
		return false;
	}  else if (py > (resy-this->textSurface->h)*this->y+this->textSurface->h){
		return false;
	} else{
		return true;
	}
}
