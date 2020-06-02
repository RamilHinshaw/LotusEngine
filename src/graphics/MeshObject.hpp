// #include "opengl/Mesh.hpp"
// #include "opengl/Shader.hpp"
// #include "opengl/Texture.hpp"
// #include "../common/Transform.hpp"
// #include <glm/glm.hpp>

// class MeshObject  //ToDo: Should be abstract
// {
//     public:    
        
//         MeshObject();   
//         ~MeshObject();

//         void draw(glm::mat4 view, glm::mat4 proj);  //Both View And Projection Matrix should be combined!
//         void dispose();

//         //ToDo: Use State Managers for this in the future to help improve performance
//         Shader& getShader();
//         Texture& getTexture();        
//         Mesh& getMesh();
//         Transform& getTransform();      

//     protected:
//         Mesh *m_mesh;
//         Shader *m_shader;
//         Texture *m_texture = nullptr;   //ToDo: Find alternative, this is probably causing initial memory leak (or pointing to some garbage data by default)
//         Transform *m_transform = new Transform();


// };


