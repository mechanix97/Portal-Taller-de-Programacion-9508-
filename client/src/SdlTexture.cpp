#include <SDL2/SDL_image.h>
#include <string>

#include "../include/SdlTexture.h"
#include "../include/SdlWindow.h"
#include "../include/SdlException.h"

SdlTexture::SdlTexture(){}

SdlTexture::SdlTexture(const SdlWindow& window)   
    : renderer(window.getRenderer()){}

SdlTexture::SdlTexture(const std::string &filename, const SdlWindow& window)
    : renderer(window.getRenderer()) {
    this->texture = loadTexture(filename);
}

SdlTexture::~SdlTexture() {
    SDL_DestroyTexture(this->texture);
}

void SdlTexture::setAlpha( uint8_t alpha )  const{ //Modulate texture alpha 
    SDL_SetTextureBlendMode( this->texture, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( this->texture, alpha ); 
}

SDL_Texture* SdlTexture::loadTexture(const std::string &filename) {
    SDL_Texture* texture = IMG_LoadTexture(this->renderer,
                                           filename.c_str());
    if (!texture) {
        throw SdlException("Error al cargar la textura", SDL_GetError());
    }
    return texture;
}

int SdlTexture::render(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    return SDL_RenderCopy(this->renderer, this->texture, &sdlSrc, &sdlDest);
}

void SdlTexture::setColorMod(uint32_t red,uint32_t green,uint32_t blue){
    SDL_SetTextureColorMod( this->texture, red, green, blue );
}

int SdlTexture::renderFlipedVertical(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, SDL_FLIP_VERTICAL);
}

int SdlTexture::renderFlipedHorizontal(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, SDL_FLIP_HORIZONTAL);
}

int SdlTexture::renderFlipedDiagonal(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    SDL_RendererFlip flip =(SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);

    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, flip);
}


int SdlTexture::renderInAngle(const Area& src, const Area& dest,double angle) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {dest.getWidth()/2, dest.getHeight()/2};

    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        angle,&center, SDL_FLIP_NONE);
}

void SdlTexture::getSize(int* w,int* h){
    SDL_QueryTexture(this->texture,NULL,NULL, w, h);
}
