#version 460

layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform ivec2 targetSize;

void main() {
	texCoord = aTexCoord;
	gl_Position = vec4((vertex_position.x - targetSize.x) / targetSize.x, (vertex_position.y - targetSize.y) / targetSize.y, 0.0f, 1.0f);
}
