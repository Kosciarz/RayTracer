#include "raylib.h"

#include <fstream>
#include <iostream>

int main()
{
    constexpr int window_width = 256;
    constexpr int window_height = 256;

    InitWindow(window_width, window_height, "image");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        for (auto i = 0; i < window_height; ++i)
        {
            for (auto j = 0; j < window_width; j++)
            {
                unsigned char red = static_cast<unsigned char>(255.0 * j / (window_width - 1));
                unsigned char green = static_cast<unsigned char>(255.0 * i / (window_height - 1));
                unsigned char blue = 100;

                Color pixel = {red, green, blue, 255};

                DrawPixel(j, i, pixel);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}