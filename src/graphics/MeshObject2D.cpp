#include "MeshObject2D.hpp"

MeshObject2D();   
~MeshObject2D();

void MeshObject2D::draw(glm::mat4 view, glm::mat4 projection)   //Pass projection & camera
{
    //Shader
    m_shader->bind();
    m_shader->setMat4("model", m_transform->getModel());
    m_shader->setMat4("view", view);
    m_shader->setMat4("projection", projection);
    

    //Texture
    if (m_texture != nullptr)
        m_texture->bind(0);
    
    //Mesh
    m_mesh->draw();  
}

void MeshObject2D::dispose()
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

Shader& MeshObject2D::getShader()
{
    return *m_shader;
}

Texture& MeshObject2D::getTexture()
{
    return *m_texture;
}

Mesh& MeshObject2D::getMesh()
{
    return *m_mesh;
}
