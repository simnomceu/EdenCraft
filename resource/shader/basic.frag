#version 450

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

    bool diffuseMapEnabled;
    bool specularMapEnabled;

    sampler2D diffuseMap;
    sampler2D specularMap;
};

struct Light
{
    int type;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    /* Basic Light */
    vec3 position;
    /* Directional Light */
    vec3 direction;
};

in vec3 color;
in vec3 normal;
in vec3 fragPos;
in vec2 textCoord;

out vec4 frag_colour;

uniform Material material;
uniform Light light;

const int BASIC_LIGHT = 0;
const int DIRECTIONAL_LIGHT = 1;

void main() {
	vec3 lightDir;
    if (light.type == BASIC_LIGHT) {
        lightDir = normalize(light.position - fragPos);
    } else if (light.type == DIRECTIONAL_LIGHT) {
        lightDir == normalize(-light.direction);
    }

	float diff = max(dot(normalize(normal), lightDir), 0.0);

	vec3 viewPos = vec3(0.0, 0.0, 10.0);
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normalize(normal));
	float spec = pow(max(dot(reflectDir, viewDir), 0.0), material.shininess);

    vec3 ambient, diffuse, specular;
    if (material.diffuseMapEnabled) {
        ambient = light.ambient * vec3(texture(material.diffuseMap, textCoord));
        diffuse = light.diffuse * (diff * vec3(texture(material.diffuseMap, textCoord)));
    }
    else {
       ambient = light.ambient * material.ambient;
       diffuse = light.diffuse * (diff * material.diffuse);
    }

    if (material.specularMapEnabled) {
        specular = light.specular * (spec * vec3(texture(material.specularMap, textCoord)));
    }
    else {
        specular = light.specular * (spec * material.specular);
    }

	vec3 result = (ambient + diffuse + specular) * color;
	frag_colour = vec4(result, 1.0);

    frag_colour = clamp(frag_colour, 0.0, 1.0);
}
