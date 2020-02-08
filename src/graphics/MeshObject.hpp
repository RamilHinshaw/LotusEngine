#include "opengl/Mesh.hpp"
#include "opengl/Shader.hpp"
#include "opengl/Texture.hpp"
#include "../common/Transform.hpp"
#include <glm/glm.hpp>

class MeshObject  //ToDo: Should be abstract
{
    public:    
        
        MeshObject();   
        ~MeshObject();

        virtual void draw(glm::mat4 view, glm::mat4 proj);  //Both View And Projection Matrix should be combined!
        virtual void dispose();

        //ToDo: Use State Managers for this in the future to help improve performance
        Shader& getShader();
        Texture& getTexture();        
        Mesh& getMesh();
        

    protected:
        Mesh *m_mesh;
        Shader *m_shader;
        Texture *m_texture;
        Transform *m_transform;


};


