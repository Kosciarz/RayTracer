// #include "raylib.h"

#include <iostream>
#include <fstream>


int main()
{
    
    constexpr int image_width = 256;
    constexpr int image_height = 256;

    std::ofstream file("../image.ppm");
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << '\n';
        return -1;
    }

   file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = 0; i < image_height; ++i)
    {
        for (int j = 0; j < image_width; j++)
        {
            auto red = static_cast<double>(i) / (image_width - 1);
            auto green = static_cast<double>(j) / (image_height - 1);
            auto blue = 0.0;

            int ir = int(255.999 * red);
            int ig = int(255.999 * green);
            int ib = int(255.999 * blue);

            file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    file.close();
}