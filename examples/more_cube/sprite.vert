#version 450

layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	texCoord = aTexCoord;
	gl_Position = projection * view * model * vec4(vertex_position, 0.0f, 1.0f);
}
