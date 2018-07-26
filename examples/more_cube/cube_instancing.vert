#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 inNormal;
layout(location = 3) in vec2 inTextCoord;
layout(location = 4) in vec3 offset;

out vec3 color;
out vec3 normal;
out vec3 fragPos;
out vec2 textCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	color = inColor;
	textCoord = inTextCoord;
	normal = mat3(transpose(inverse(model))) * inNormal;
	gl_Position = projection * view * model * vec4(vertex_position + offset, 1.0);
	fragPos = vec3(model * vec4(vertex_position + offset, 1.0));
}
