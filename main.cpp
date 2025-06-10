#include "Game.h"
#include "raylib.h"

int main() {
    InitWindow(800, 600, "Space Invaders NBU");
    SetTargetFPS(60);
    Game game;
    game.run();
    CloseWindow();
    return 0;
}
