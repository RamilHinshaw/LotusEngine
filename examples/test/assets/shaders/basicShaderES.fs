#version 300 es
precision mediump float;

out vec4 FragColor;

in vec4 o_color;
in vec2 o_texCoord;
in float o_texID;

uniform sampler2D u_texture;
uniform bool u_showTexture;
uniform vec2 u_texRect;

void main()
{   
    // if (outColor == 0)
    // {
    //     outColor = vec4(1.0,1.0,1.0,1.0);
    // }

    if (u_showTexture)
    {
        FragColor = o_color;
    }

    else
    {
        vec4 texColor = o_color * texture(u_texture, o_texCoord + u_texRect.xy);

        //Tranparency
        if (texColor.a < 0.1)
            discard;

        FragColor = texColor;
    }

}