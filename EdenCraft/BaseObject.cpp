#include "BaseObject.hpp"

BaseObject::BaseObject() : vaoId{0}, vboIds{ 0, 0 }, shaderScript{0}
{
	glGenVertexArrays(1, &this->vaoId);
}


BaseObject::~BaseObject()
{
}

void BaseObject::applyShaders(const char* vsScript, const char * fsScript)
{
	int params = -1;

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsScript, nullptr);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: GL vertex shader index " << vs << " did not compile\n" << std::endl;
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsScript, nullptr);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: GL fragment shader index " << fs << " did not compile\n" << std::endl;
	}

	this->shaderScript = glCreateProgram();
	glAttachShader(this->shaderScript, vs);
	glAttachShader(this->shaderScript, fs);

	glLinkProgram(this->shaderScript);
	/* check for shader linking errors - very important! */
	glGetProgramiv(this->shaderScript, GL_LINK_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: could not link shader programme GL index" << this->shaderScript << std::endl;
	}

	//glBindAttribLocation(this->shaderScript, VERTICE, "in_vertices");
	//glBindAttribLocation(this->shaderScript, COLOR, "in_colors");
}

GLuint BaseObject::getVAO()
{
	return this->vaoId;
}

void BaseObject::prepareShaders()
{
	glUseProgram(this->shaderScript);
}
