#version 330 core

out vec4 FragColor;

in vec4 outColor;
in vec2 outTexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = outColor;
    // vec4 texColor = outColor * texture(ourTexture, outTexCoord);

    // //Tranparency
    // if (texColor.a < 0.1)
    //     discard;

    // FragColor = texColor;
}