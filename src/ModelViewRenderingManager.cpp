#include "ModelViewRenderingManager.hpp"
#include "RenderModel.hpp"

ModelViewRenderingManager::ModelViewRenderingManager() {
    addAction(new RenderModel());
}

void ModelViewRenderingManager::render() {
    this->renderer->beforeFrame();
    this->renderer->resetMatrix();
    
    for (auto a : actions) {
        a->render();
    }
    
    this->renderer->afterFrame();

}
