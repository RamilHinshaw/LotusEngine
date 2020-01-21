#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"
#include "../common/Transform.hpp"
#include <glm/glm.hpp>

class MeshObject2D  //ToDo: Should be abstract
{
    public:    
        
        MeshObject2D();   
        ~MeshObject2D();

        virtual void draw(glm::mat4 view, glm::mat4 projection);

        virtual void dispose();

        Shader& getShader();

        Texture& getTexture();
        
        Mesh& getMesh();
        

    protected:
        Mesh *m_mesh;
        Shader *m_shader;
        Texture *m_texture;
        Transform *m_transform;


};


