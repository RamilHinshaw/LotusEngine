//Vertex Shader

#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;

//Camera Relative
uniform mat4 u_transform;
uniform mat4 u_view;
uniform mat4 u_projection;
//uniform mat4 u_projViewTrans;

out vec4 o_color;
out vec2 o_texCoord;

void main()
{
    gl_Position = u_projection * u_view * u_transform * vec4(position, 1.0);

    //gl_Position = u_projViewTrans * vec4(position, 1.0);

    o_color = color;
    o_texCoord = texCoord;
}