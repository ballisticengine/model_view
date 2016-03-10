#include "RenderModel.hpp"
#include "config/EngineState.hpp"
#include "types/shape.hpp"

void RenderModel::render() {
    this->renderer->clear(ColorRGBA(0.5, 0.5, 0.5, 1));
    this->renderer->resetMatrix();
    this->renderer->setDrawColor(ColorRGBA(1,0,0,1));
    //this->renderer->translate(Vector3d(0,0, -50));
    Shape *s = (Shape *) EngineState::getInstance()->getPtr("loaded_model");

    this->renderer->renderShape(s);
}