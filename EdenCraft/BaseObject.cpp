#include "BaseObject.hpp"

BaseObject::BaseObject() : vaoId{0}, vboIds{ 0, 0 }, shaderScript{}
{
	glGenVertexArrays(1, &this->vaoId);
}


BaseObject::~BaseObject()
{
}

void BaseObject::applyShaders(std::string vsScript, std::string fsScript)
{
	this->shaderScript.loadVertexShader(vsScript);
	this->shaderScript.loadFragmentShader(fsScript);
	this->shaderScript.generate();
}

void BaseObject::applyShadersFromFiles(std::string vsFile, std::string fsFile)
{
	this->shaderScript.loadVertexShaderFromFile(vsFile);
	this->shaderScript.loadFragmentShaderFromFile(fsFile);
	this->shaderScript.generate();
}

GLuint BaseObject::getVAO()
{
	return this->vaoId;
}

void BaseObject::prepareShaders()
{
	this->shaderScript.activate();
}
