//
// Created by Toudonou on 7/2/2024.
//

#ifndef SIMPLE2DRENDER2D_H
#define SIMPLE2DRENDER2D_H
#include <vector>

#include "Renderable2D.h"


namespace sparky {
    class Simple2DRender2D {
    public:
        Simple2DRender2D();
        ~Simple2DRender2D();
        void Draw() const;

        void AddRenderable2D(Renderable2D *renderable2D);

    private:
        std::vector<Renderable2D *> m_RenderQueue;
    };
}


#endif //SIMPLE2DRENDER2D_H
