#pragma once

#include <vector>

class Renderer
{
    public:
        void Render(); //Render All Verticies to buffer
        void Sort(); //Sort State Changes
        void Flush(); //Clean Buffer

    private:
        // List of Meshes
        // List of Shaders
        // List of Textures
}