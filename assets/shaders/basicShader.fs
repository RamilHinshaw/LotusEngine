#version 330 core

out vec4 FragColor;

in vec4 outColor;
in vec2 outTexCoord;

uniform sampler2D ourTexture;

void main()
{
    //FragColor = outColor;
    FragColor = outColor * texture(ourTexture, outTexCoord);
}