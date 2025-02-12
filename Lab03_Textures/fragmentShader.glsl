#version 330 core

in vec2 UV;

out vec3 colour;

uniform sampler2D texture1;;
uniform sampler2D texture2;

void main()
{
    colour = vec3(mix(texture(texture1,UV), texture(texture2,UV),0.7));
}
