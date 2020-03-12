#ifndef __SDL_WINDOW_H__
#define __SDL_WINDOW_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL_mixer.h>
#include <vector>

#include "../include/SdlException.h"
#include "Area.h"


class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class SdlWindow {
public:
    SdlWindow(int width, int height);
    ~SdlWindow();
    void fill();
    void fill(int r, int g, int b, int alpha);
    void render();
    void fullscreen();
    void windowed();
    int getResX() const;
    int getResY() const;
    SDL_Renderer* getRenderer() const;
    void changeRes(int w, int h);
    std::vector<std::pair<int,int>> getResolutions() const;
private:
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
