#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 textCoord;

out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	color = inColor;
	gl_Position = projection * view * model * vec4(vertex_position, 1.0);
}
