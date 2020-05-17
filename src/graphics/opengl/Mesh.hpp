//USED FOR JUST VERTICES

#pragma once

#include "Vertex.hpp"
#include <vector>
#include <string>


class Mesh
{    
    public:
        Mesh();
        Mesh(std::string path); //For Custom Meshes

        //Mesh(Vertex* vertices, unsigned int numVertices);
        virtual ~Mesh();

        std::vector<Vertex>& data() { return verticies;};


    private:
        std::vector<Vertex> verticies;
        //Vertex * verticies;
        //int size;
};

