#version 450
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inShift;
layout(location = 2) in vec4 inColor;

out vec4 particleColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vec4 worldPos = /*model * */vec4(inPosition + inShift, 1.0);

    gl_Position = projection * view * worldPos;

    particleColor = inColor;
}
