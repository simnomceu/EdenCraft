#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexture;
layout(location = 3) in mat4 instance;

out vec3 normal;
out vec3 fragPos;
out vec2 texturePos;
out vec3 viewPos;
out vec3 viewDir;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    mat4 world = model * instance;
    vec4 worldPos = world * vec4(inPosition, 1.0);

    gl_Position = projection * view * worldPos;

    normal = normalize(transpose(inverse(mat3(world))) * inNormal);
    fragPos = vec3(worldPos);
    viewPos = vec3(view[3]);
    viewDir = normalize(viewPos - fragPos);
    texturePos = inTexture;
}
