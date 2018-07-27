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

	mat4 offsetMat = mat4(vec4(1.0, 0.0, 0.0, 0.0), vec4(0.0, 1.0, 0.0, 0.0), vec4(0.0, 0.0, 1.0, 0.0), vec4(offset, 1.0));

	normal = normalize(vec3(offsetMat * vec4(inNormal, 1.0)));
	gl_Position = projection * view * model * offsetMat * vec4(vertex_position, 1.0);
	fragPos = vec3(offsetMat * vec4(vertex_position, 1.0));
}
