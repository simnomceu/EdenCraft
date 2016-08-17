#version 450

layout(location = 0) in vec3 in_vertices;
layout(location = 1) in vec3 in_colors;

out vec3 pass_color;

void main(void)
{
	gl_Position = vec4(in_vertices, 1.0);
	pass_color = in_colors;
}