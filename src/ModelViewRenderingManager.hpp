#ifndef MODELVIEWRENDERINGMANAGER_HPP
#define	MODELVIEWRENDERINGMANAGER_HPP


#include "misc/singleton.hpp"
#include "renderer/RendererInterface.hpp"
#include "renderer/RenderingManager.hpp"

class ModelViewRenderingManager : public RenderingManagerInterface, public Singleton<ModelViewRenderingManager> {
    public:
            ModelViewRenderingManager();
            void render();
};
#endif	

