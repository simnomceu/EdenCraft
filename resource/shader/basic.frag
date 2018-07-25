#version 450 core

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

in vec3 color;
in vec3 normal;
in vec3 fragPos;

out vec4 frag_colour;

uniform Material material;

void main() {
	vec3 lightColor = vec3(1.0, 1.0, 1.0);
	vec3 lightPos = vec3(10.0, 10.0, -10.0);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(normalize(normal), lightDir), 0.0);

	vec3 viewPos = vec3(0.0, 0.0, 10.0);
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normalize(normal));
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	vec3 ambient = material.ambient * lightColor;
	vec3 diffuse = lightColor * (diff * material.diffuse);
	vec3 specular = material.specular * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * color;
	frag_colour = vec4(result, 1.0);
}
