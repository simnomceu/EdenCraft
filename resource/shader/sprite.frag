#version 450

in vec2 texturePos;

out vec4 fragColor;

uniform sampler2D theTexture;

void main() {
	fragColor = texture(theTexture, texturePos);
}
