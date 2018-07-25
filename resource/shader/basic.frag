#version 450

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 position;
};

in vec3 color;
in vec3 normal;
in vec3 fragPos;

out vec4 frag_colour;

uniform Material material;
uniform Light light;

void main() {
	vec3 lightDir = normalize(light.position - fragPos);

	float diff = max(dot(normalize(normal), lightDir), 0.0);

	vec3 viewPos = vec3(0.0, 0.0, 10.0);
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normalize(normal));
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	vec3 ambient = light.ambient * material.ambient;
	vec3 diffuse = light.diffuse * (diff * material.diffuse);
	vec3 specular = light.specular * (spec * material.specular);

	vec3 result = (ambient + diffuse + specular) * color;
	frag_colour = vec4(result, 1.0);

    frag_colour = clamp(frag_colour, 0.0, 1.0);
}
