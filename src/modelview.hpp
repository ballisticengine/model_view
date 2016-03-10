#ifndef MODELVIEW_HPP
#define	MODELVIEW_HPP

#include <iostream>
#include <SDL2/SDL.h>

#include "libload/LibLoad.hpp"
#include "ModelViewRenderingManager.hpp"
#include "renderer/RendererInterface.hpp"


using namespace std;

class ModelView {
     SDL_Surface *screen;
     SDL_Renderer* displayRenderer;
     SDL_Window *window;
    ModelViewRenderingManager *rendering;
    bool exit;
public:
    void initWindow();
    void eventLoop();
    ModelView();
    ~ModelView();

};

#endif	

