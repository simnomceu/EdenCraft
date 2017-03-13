#include "Rendering\Model\Program.hpp"

#include "Util\File\File.hpp"
#include "Util\Debug\ResourceException.hpp"
#include "Util\Debug\InitializationException.hpp"

#include <iostream>
#include <iomanip>

namespace ece
{
	Program::Program(): handle(NULL_ID), vertex(NULL_ID), fragment(NULL_ID)
    {
    }

	Program::~Program()
    {
        if (this->handle != NULL_ID) {
			//
            if (this->vertex != 0) {
                glDetachShader(this->handle, this->vertex);
                glDeleteShader(this->vertex);
            }
            if (this->fragment != 0) {
                glDetachShader(this->handle, this->fragment);
                glDeleteShader(this->fragment);
            }
			//
            glDeleteProgram(this->handle);
        }
    }

    void Program::init()
    {
		this->handle = glCreateProgram();
		if (this->handle == NULL_ID) {
			throw InitializationException("Program");
		}
        glBindAttribLocation(this->handle, 0, "VertexPosition");
        glBindAttribLocation(this->handle, 1, "VertexColor");
    }

    void Program::loadShaderFromFile(const ShaderType type, const std::string & filename)
    {
		File shaderFile(filename, std::ios_base::in);
        std::string content = shaderFile.parseToString();
        this->loadShaderFromString(type, content);
    }

    void Program::loadShaderFromString(const ShaderType type, const std::string & content)
    {
        GLuint shaderID = 0;
        switch (type) {
        case VERTEX_SHADER:
            if(this->vertex != 0) {
                glDetachShader(this->handle, this->vertex);
                glDeleteShader(this->vertex);
            }
            this->vertex = glCreateShader(GL_VERTEX_SHADER);
            shaderID = this->vertex;
            break;
        case FRAGMENT_SHADER:
            if(this->fragment != 0) {
                glDetachShader(this->handle, this->fragment);
                glDeleteShader(this->fragment);
            }
            this->fragment = glCreateShader(GL_FRAGMENT_SHADER);
            shaderID = this->fragment;
            break;
        default:
            break;
        }

        const char * sourceShader = content.c_str();
        glShaderSource(shaderID, 1, &sourceShader, NULL);
        glCompileShader(shaderID);

        GLint result = GL_FALSE;
        int infoLogLength = 0;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength > 0) {
            char* error = new char[infoLogLength+1];
            glGetShaderInfoLog(shaderID, infoLogLength, NULL, error);
            std::cerr << std::string(error) << std::endl;
            delete[] error;
        }
        glAttachShader(this->handle, shaderID);
    }

    void Program::link()
    {
        glLinkProgram(this->handle);

        GLint result = GL_FALSE;
        int infoLogLength = 0;
        glGetProgramiv(this->handle, GL_LINK_STATUS, &result);
        glGetProgramiv(this->handle, GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength > 0) {
            char* error = new char[infoLogLength+1];
            glGetProgramInfoLog(this->handle, infoLogLength, NULL, error);
            std::cerr << std::string(error) << std::endl;
            delete[] error;
        }
    }

    void Program::use()
    {
        if (this->handle != 0) {
            glUseProgram(this->handle);
		}
		else {
			throw ResourceException("Program", this->handle);
		}
    }

	void Program::bindInfo(const Matrix4x4 & info, const std::string & name)
	{
		if (this->handle > NULL_ID) {
			GLuint handle = glGetUniformLocation(this->handle, name.data());
			glUniformMatrix4fv(handle, 1, GL_FALSE, &info[0][0]);
		}
		else {
			throw ResourceException("Program", this->handle);
		}
	}

	void Program::bindInfo(const Vertex3D & info, const std::string & name)
	{
		if (this->handle > NULL_ID) {
			GLuint handle = glGetUniformLocation(this->handle, name.data());
			glUniform3fv(handle, 3, &info[0]);
		}
		else {
			throw ResourceException("Program", this->handle);
		}
	}

    /*void Program::displayActiveUniforms() {

        GLint nbUniforms, size, location, maxLength;
        GLsizei written;
        GLenum type;

        glGetProgramiv(handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLength);
        glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &nbUniforms);

        std::vector<GLchar> name(maxLength);

        std::cout << " Location | Name" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        for (int i = 0; i < nbUniforms; ++i) {
            glGetActiveUniform(handle, i, maxLength, &written, &size, &type, &name[0]);
            location = glGetUniformLocation(handle, &name[0]);
            std::cout << location << std::setw(11) << " | " << &name[0] << std::endl;
        }
    }

    void Program::displayActiveAttribs() {

        GLint written, size, location, maxLength, nbAttribs;
        GLenum type;

        glGetProgramiv(handle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
        glGetProgramiv(handle, GL_ACTIVE_ATTRIBUTES, &nbAttribs);

        std::vector<GLchar> name(maxLength);

        std::cout << " Index | Name" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        for (int i = 0; i < nbAttribs; ++i) {
            glGetActiveAttrib(handle, i, maxLength, &written, &size, &type, &name[0]);
            location = glGetAttribLocation(handle, &name[0]);
            std::cout << location << std::setw(8) << " | " << &name[0] << std::endl;
        }
    }*/
}
