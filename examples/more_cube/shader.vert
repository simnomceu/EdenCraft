#version 460
		
layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec3 vertex_colour;
layout(location = 2) in vec2 aTexCoord;

out vec3 colour;
out vec2 texCoord;

void main() {
	colour = vertex_colour;
	texCoord = aTexCoord;
	gl_Position = vec4(vertex_position, 0.0, 1.0);
}