#include "Quad.hpp"

#include <iostream>

Quad::Quad()
{
	std::cout << "Quad Constructor Called" << std::endl;
	m_shader = generateShader(); 
    m_mesh = generatePrimative();
}

Quad::Quad(const Rect rect) : rect(rect)
{

    m_shader = new Shader("./assets/shaders/basicShader"); 


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


	m_mesh = new Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));


    // mesh = generatePrimative();
    // shader = generateShader(); 
    // std::cout << "Quad Generated!" << std::endl;
}


// Quad::Quad(const Rect rect, const Shader &shader) : rect(rect)//, shader(shader)
// {
// 	m_shader = &shader;
//     m_mesh = generatePrimative();
// }

// Shader& Quad::getShader()
// {
// 	return *m_shader;
// }

Quad::~Quad()
{
    std::cout << "Quad out of scope!" << std::endl;
}

// void Quad::dispose()
// {
// 	std::cout << "Disposed Quad!" << std::endl;
//     m_mesh->dispose();
//     m_shader->dispose();  

// 	delete m_mesh;
// 	m_mesh = nullptr;

// 	delete m_shader;  
// 	m_shader = nullptr;
//     // std::cout << "Quad DISPOSED!" << std::endl;
// }

Mesh* Quad::generatePrimative()
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


	return new Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));

    //return Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), 0,0); //Unoptimized!    
    //return Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), GL_Triangle_Strip); //Optimized
}

// void Quad::draw()
// {
//     m_shader->bind();
//     m_mesh->draw();
//     // std::cout << "Quad DRAWING!" << std::endl;
// }

Shader* Quad::generateShader()
{
    //ToDo: PUT THIS IN SHADER STATEMANAGER SO WE DON'T BIND IDENTICAL SHADERS!
    return new Shader("./assets/shaders/basicShader"); 
}