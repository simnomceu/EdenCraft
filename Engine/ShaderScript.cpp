#include "ShaderScript.hpp"

#include <iostream>
#include <fstream>

ShaderScript::ShaderScript()
{
	// TODO : check initialization of all what is required (GLEW, context, etc ...)
	this->program = glCreateProgram();
}


ShaderScript::~ShaderScript()
{
}

void ShaderScript::loadVertexShader(std::string vsScript)
{
	const char* vsScriptPtr = vsScript.c_str();
	int params = -1;

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsScriptPtr, nullptr);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: GL vertex shader index " << vs << " did not compile\n" << std::endl;
	}

	glAttachShader(this->program, vs);
}

void ShaderScript::loadFragmentShader(std::string fsScript)
{
	const char* fsScriptPtr = fsScript.c_str();
	int params = -1;

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsScriptPtr, nullptr);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: GL fragment shader index " << fs << " did not compile\n" << std::endl;
	}

	glAttachShader(this->program, fs);
}

void ShaderScript::loadVertexShaderFromFile(std::string vsFile)
{
	std::ifstream infile(vsFile);
	if (infile.is_open()) {
		std::string vsScript;
		vsScript.assign(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
		this->loadVertexShader(vsScript);
	}
	else {
		std::cerr << "Failed to load vertex shader from file " << vsFile << std::endl;
	}
}

void ShaderScript::loadFragmentShaderFromFile(std::string fsFile)
{
	std::ifstream infile(fsFile);
	if (infile.is_open()) {
		std::string fsScript;
		fsScript.assign(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
		this->loadFragmentShader(fsScript);
	}
	else {
		std::cerr << "Failed to load fragment shader from file " << fsFile << std::endl;
	}
}

void ShaderScript::generate()
{
	int params = -1;

	glLinkProgram(this->program);
	glGetProgramiv(this->program, GL_LINK_STATUS, &params);
	if (GL_TRUE != params) {
		std::cerr << "ERROR: could not link shader programme GL index" << this->program << std::endl;
	}
}

void ShaderScript::activate()
{
	glUseProgram(this->program);
}
