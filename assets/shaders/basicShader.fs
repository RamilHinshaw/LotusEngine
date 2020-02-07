//Fragment Shader

#version 330 core

out vec4 FragColor;

in vec4 outColor;
in vec2 outTexCoord;

uniform sampler2D ourTexture;
uniform bool showTexture;

void main()
{   
    // if (outColor == 0)
    // {
    //     outColor = vec4(1.0,1.0,1.0,1.0);
    // }

    if (showTexture)
    {
        FragColor = outColor;
    }

    else
    {
        vec4 texColor = outColor * texture(ourTexture, outTexCoord);

        //Tranparency
        if (texColor.a < 0.1)
            discard;

        FragColor = texColor;
    }

}