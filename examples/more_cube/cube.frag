#version 450

in vec3 color;
in vec3 normal;
in vec3 fragPos;

out vec4 frag_colour;

void main() {
	vec3 ambientFactor = vec3(0.24725, 0.1995, 0.0745);
	vec3 diffuseFactor = vec3(0.75164, 0.60648, 0.22648);
	vec3 specularFactor = vec3(0.628281, 0.555802, 0.366065);
	float shininess = 0.4;

	vec3 lightColor = vec3(1.0, 1.0, 1.0);
	vec3 lightPos = vec3(10.0, 10.0, -10.0);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(normalize(normal), lightDir), 0.0);
	
	vec3 viewPos = vec3(0.0, 0.0, 10.0);
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normalize(normal));
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess * 128);

	vec3 ambient = ambientFactor * lightColor;
	vec3 diffuse = lightColor * (diff * diffuseFactor);
	vec3 specular = specularFactor * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * color;
	frag_colour = vec4(result, 1.0);
}
