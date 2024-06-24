#include "core/graphics/window.h"

int main() {
    auto window = sparky::Window();

    window.Init(800, 600, "Sparky");
    window.Update();
    window.Quit();

    return 0;
}
