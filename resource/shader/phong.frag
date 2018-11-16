#version 450

#define MAX_NUMBER_OF_LIGHTS 8

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
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    vec3 position;
    vec3 direction;

    float constant;
    float linear;
    float quadratic;

    float innerCutOff;
    float outerCutOff;

    bool usePosition;
    bool useDirection;
    bool useAttenuation;
    bool useCutOff;
    bool useBlinn;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texturePos;

out vec4 fragColor;

uniform Material material;
uniform Light lights[MAX_NUMBER_OF_LIGHTS];
uniform int numberOfLights;
uniform mat4 view;

vec3 getLightDir(int i);
float computeIntensity(vec3 lightDir, int i);
float computeAttenuation(int i);
float computeSpecularFactor(int i, vec3 viewDir, vec3 lightDir);
float computeDiffuseFactor(int i, vec3 lightDir);

void main()
{
    vec3 viewPos = vec3(view[3]);
    vec3 viewDir = normalize(viewPos - fragPos);

    vec3 ambient = vec3(0.0, 0.0, 0.0);
    vec3 diffuse = vec3(0.0, 0.0, 0.0);
    vec3 specular = vec3(0.0, 0.0, 0.0);
    for (int i = 0; i < numberOfLights; ++i) {
        vec3 lightDir = getLightDir(i);

        float diff = computeDiffuseFactor(i, lightDir);
        float spec = computeSpecularFactor(i, viewDir, lightDir);

        float attenuation = computeAttenuation(i);

        float intensity = computeIntensity(lightDir, i);

        ambient += lights[i].ambient * attenuation;
        diffuse += lights[i].diffuse * diff * attenuation * intensity;
        specular += lights[i].specular * spec * attenuation * intensity;
    }

    if (material.diffuseMapEnabled) {
        ambient *= texture(material.diffuseMap, texturePos).rgb;
        diffuse *= texture(material.diffuseMap, texturePos).rgb;
    }
    else {
       ambient *= material.ambient;
       diffuse *= material.diffuse;
    }

    if (material.specularMapEnabled) {
        specular *= texture(material.specularMap, texturePos).rgb;
    }
    else {
        specular *= material.specular;
    }

    fragColor = clamp(vec4(ambient + diffuse + specular, 1.0), 0.0, 1.0);
}

vec3 getLightDir(int i)
{
    if (lights[i].usePosition) {
        return normalize(lights[i].position - fragPos);
    } else if (lights[i].useDirection) {
        return normalize(-lights[i].direction);
    }
}

float computeIntensity(vec3 lightDir, int i)
{
    if (lights[i].useCutOff) {
        float angle = dot(lightDir, normalize(-lights[i].direction));
        float cutOffRange = lights[i].innerCutOff - lights[i].outerCutOff;
        return clamp((angle - lights[i].outerCutOff) / cutOffRange, 0.0, 1.0);
    }
    else {
        return 1.0;
    }
}

float computeAttenuation(int i)
{
    if (lights[i].useAttenuation) {
        float distance = length(lights[i].position - fragPos);
        return 1.0 / (lights[i].constant + lights[i].linear * distance + lights[i].quadratic * (distance * distance));
    }
    else {
        return 1.0;
    }
}

float computeSpecularFactor(int i, vec3 viewDir, vec3 lightDir)
{
    if (lights[i].useBlinn) {
        vec3 halfwayDir = normalize(lightDir + viewDir);
        return pow(max(dot(normal, halfwayDir), 0.0), material.shininess * 2.0);
    }
    else {
        vec3 reflectDir = reflect(-lightDir, normal);
        return pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    }
}

float computeDiffuseFactor(int i, vec3 lightDir)
{
    return max(dot(normal, lightDir), 0.0);
}
