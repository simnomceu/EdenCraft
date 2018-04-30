#version 460

layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform vec2 targetSize;

void main() {
	texCoord = aTexCoord;
	gl_Position = vec4(vertex_position, 0.0, 1.0);
    if (targetSize.x != 0) {
        gl_Position.x /= targetSize.x;
        gl_Position.x -= 0.5f;
    }
    if (targetSize.y != 0) {
        gl_Position.y /= targetSize.y;
        gl_Position.y -= 0.5f;
    }
}
