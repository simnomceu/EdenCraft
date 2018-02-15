#version 460

in vec3 colour;
in vec2 texCoord;

out vec4 frag_colour;

uniform sampler2D theTexture;

void main() {
	frag_colour = texture(theTexture, texCoord);
}