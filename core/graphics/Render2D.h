//
// Created by Toudonou on 7/2/2024.
//

#ifndef RENDER2D_H
#define RENDER2D_H
#include <vector>

#include "Renderable2D.h"


namespace sparky {
    class Render2D {
    public:
        Render2D();
        ~Render2D();
        void Draw() const;

        void AddRenderable2D(Renderable2D *renderable2D);

    private:
        std::vector<Renderable2D *> m_RenderQueue;
    };
}


#endif //RENDER2D_H
