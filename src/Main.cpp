#include "raylib.h"

#include <iostream>

int main()
{
    constexpr int width = 800;
    constexpr int height = 450;

    InitWindow(800, 450, "raylib windows");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}