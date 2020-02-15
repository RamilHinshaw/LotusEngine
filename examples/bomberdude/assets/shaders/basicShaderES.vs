#version 300 es
precision mediump float;

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;

out vec4 outColor;
out vec2 outTexCoord;

void main()
{
    gl_Position = vec4(position, 1.0);
    outColor = color;
    outTexCoord = texCoord;
}