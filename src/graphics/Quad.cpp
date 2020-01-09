#include "Quad.hpp"

#include <iostream>

Quad::Quad()
{

}

Quad::Quad(const Rect rect) : rect(rect)
{

    shader = Shader("./assets/shaders/basicShader"); 


    Vertex vertices[] = {

					//Positions								//Colors						//Texture Coordinates
					Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f)),
					Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f)),


					//Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
					//Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f))

				};

	//Turn into class container (indice holding 3 ints)
	unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2		//second triangle
	};


	mesh = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));


    // mesh = generatePrimative();
    // shader = generateShader(); 
    // std::cout << "Quad Generated!" << std::endl;
}


Quad::Quad(const Rect rect, const Shader &shader) : rect(rect), shader(shader)
{
    mesh = generatePrimative();
}

Quad::~Quad()
{
    std::cout << "AM I BEING DELETED!?" << std::endl;
}

void Quad::dispose()
{
    mesh.dispose();
    shader.dispose();    
    std::cout << "Quad DISPOSED!" << std::endl;
}

Mesh Quad::generatePrimative()
{

	Vertex vertices[] = {

					//Positions								//Colors						//Texture Coordinates
					Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f)),
					Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 0.0f)),
					Vertex(glm::vec3(-0.5,	0.5,	0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(0.0f, 1.0f)),


					//Vertex(glm::vec3(0.5,	-0.5,	0),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 0.0f)),
					//Vertex(glm::vec3(0.5,	0.5,	0),	glm::vec4(1.0f,	1.0f, 1.0f, 1.0f), 	glm::vec2(1.0f, 1.0f))

				};

	//Turn into class container (indice holding 3 ints)
	unsigned int indices[] = {
		0, 2, 3,	//first triangle
		0, 1, 2		//second triangle
	};


	return Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));

    //return Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), 0,0); //Unoptimized!    
    //return Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), GL_Triangle_Strip); //Optimized
}

void Quad::draw()
{
    shader.bind();
    mesh.draw();
    // std::cout << "Quad DRAWING!" << std::endl;
}

Shader Quad::generateShader()
{
    //ToDo: PUT THIS IN SHADER STATEMANAGER SO WE DON'T BIND IDENTICAL SHADERS!
    return Shader("./assets/shaders/basicShader"); 
}