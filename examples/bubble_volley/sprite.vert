#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inTexture;

out vec2 texturePos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    texturePos = inTexture;
//	gl_Position = projection * view * model * vec4(inPosition, 0.0f, 1.0f);
	gl_Position = model * vec4(inPosition, 0.0f, 1.0f);
}
