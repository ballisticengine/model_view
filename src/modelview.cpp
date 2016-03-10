#include "modelview.hpp"
#include "config/EngineState.hpp"
#include "libload/LibLoad.hpp"
#include "types/shape.hpp"


//Renderer *ModelView::r = 0;

void ModelView::initWindow() {
    LibLoad::getInstance()->setWD("../ballistic_engine/bin");
    LibLoad::getInstance()->discoverLoaders();
    LibLoad::getInstance()->registerModule("renderer2", "RendererOpenGL", "returnRenderer");
    RendererInterface *ri = (RendererInterface *) LibLoad::getInstance()->getModuleClass("renderer2");

    rendering = ModelViewRenderingManager::getInstance();
    rendering->setRenderer(ri);
    
    ri->init(800, 600, 0);
    
    string file_name =  EngineState::getInstance()->getString("model");
    Loader *loader = (Loader *)LibLoad::getInstance()->getLoaderByExtension(Utils::getExt(file_name));
    void *s = loader->load(file_name);
    EngineState::getInstance()->setPtr("loaded_model", s);
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    SDL_CreateWindowAndRenderer(800, 600,
            SDL_WINDOW_OPENGL, &window, &displayRenderer);
    screen = SDL_GetWindowSurface(window);
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);
    //    ModelView::r=new Renderer();
    //    r->basicinit();
}

void ModelView::eventLoop() {
    SDL_Event event;
    while (!exit) {
        while (SDL_PollEvent(& event)) {
            if (event.type == SDL_QUIT) {
                exit = true;
            }
            rendering->render();
            SDL_GL_SwapWindow(window);
        }
    }
}

ModelView::ModelView() {

}

ModelView::~ModelView() {
    //     delete r;
    SDL_Quit();
}

int main(int argc, char **argv) {
    cout << "Ballistic model viewer "  << "\n";
    
    if(argc < 2) {
        cout << "No params\n";
        return 1;
    }
    EngineState::getInstance()->setString("model", argv[1]);
    ModelView app;
    app.initWindow();
    app.eventLoop();
    return 0;
}
