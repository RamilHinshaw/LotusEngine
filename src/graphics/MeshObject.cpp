#include "MeshObject.hpp"

MeshObject::MeshObject()
{

}

MeshObject::~MeshObject()
{

}

void MeshObject::draw(glm::mat4 view, glm::mat4 projection)   //Pass projection & camera
{
    //Shader
    m_shader->bind();
    m_shader->setMat4("u_transform", m_transform->getModel());
    m_shader->setMat4("u_view", view);
    m_shader->setMat4("u_projection", projection);    

    // Texture
    // std::cout << m_texture << std::endl;

    if (m_texture != nullptr)
        m_texture->bind(0);
    
    //Mesh
    m_mesh->draw();  
}

void MeshObject::dispose()
    {
    if (m_texture != nullptr)
    {
        m_texture->dispose();
        delete m_texture;
        m_texture = nullptr;
    }

    if (m_mesh != nullptr)
    {
        m_mesh->dispose();
        delete m_mesh;
        m_mesh = nullptr;
    }

    if (m_shader != nullptr)
    {
        m_shader->dispose();
        delete m_shader;
        m_shader = nullptr;
    }

    delete m_transform;
    m_transform = nullptr;
    }

Shader& MeshObject::getShader()
{
    return *m_shader;
}

Texture& MeshObject::getTexture()
{
    return *m_texture;
}

Mesh& MeshObject::getMesh()
{
    return *m_mesh;
}

Transform& MeshObject::getTransform()
{
    return *m_transform;
}
