#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTextCoord;
layout(location = 3) in mat4 instance;

out vec3 normal;
out vec3 fragPos;
out vec2 textCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	textCoord = inTextCoord;

	mat4 world = model * instance;

	normal = normalize(mat3(world)  * inNormal);
	gl_Position = projection * view * world * vec4(vertex_position, 1.0);
	fragPos = vec3(world * vec4(vertex_position, 1.0));
}
