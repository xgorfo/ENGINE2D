#include "Application.hpp"
#include <stdexcept>

int main() {
    try {
        Game::Application app;
        app.run();
    } catch (...) {
        return -1;
    }
    return 0;
}