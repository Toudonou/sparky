//
// Created by Toudonou on 7/2/2024.
//

#include "Simple2DRender2D.h"

sparky::Simple2DRender2D::Simple2DRender2D() = default;

sparky::Simple2DRender2D::~Simple2DRender2D() = default;

void sparky::Simple2DRender2D::Draw() const {
    for (const auto renderable: m_RenderQueue) {
        renderable->getVertexArray()->bind();
        renderable->getIndexBuffer()->bind();
        renderable->getPositionBuffer()->bind();
        renderable->getColorBuffer()->bind();

        glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

        renderable->getVertexArray()->unbind();
        renderable->getIndexBuffer()->unbind();
        renderable->getPositionBuffer()->unbind();
        renderable->getColorBuffer()->unbind();
    }
}

void sparky::Simple2DRender2D::AddRenderable2D(Renderable2D *renderable2D) {
    m_RenderQueue.push_back(renderable2D);
}
