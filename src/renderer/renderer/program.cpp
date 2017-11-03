#include "renderer/renderer/program.hpp"

#include "utility/file/file.hpp"
#include "utility/debug/exception.hpp"

#include <iostream>
#include <iomanip>

namespace ece
{
	Program::~Program()
    {
        /*if (this->handle != GL::NULL_ID) {
            glDeleteProgram(this->handle);
        }*/
    }

    void Program::init()
    {
		/*this->handle = GL::createProgram();

        glBindAttribLocation(this->handle, 0, "VertexPosition");
        glBindAttribLocation(this->handle, 1, "VertexColor");*/
    }

	/*void Program::apply(const std::shared_ptr<Shader> & shader)
	{
		// TODO : only adding shader to a list (= FIFO queue ?)
		// Then: attaching it during link, then removing shader from list, detaching it en deleting eventually

		this->shaders.push(shader);
	}*/

	void Program::link()
    {
		/*if (this->handle != GL::NULL_ID) {
			while (!this->shaders.empty()) {
				// TODO: poping shader THEN applying it
			}

			glLinkProgram(this->handle);

			GLint result = GL_FALSE;
			int infoLogLength = 0;
			glGetProgramiv(this->handle, GL_LINK_STATUS, &result);
			glGetProgramiv(this->handle, GL_INFO_LOG_LENGTH, &infoLogLength);
			if (infoLogLength > 0) {
				char* error = new char[infoLogLength + 1];
				glGetProgramInfoLog(this->handle, infoLogLength, NULL, error);
				std::cerr << std::string(error) << std::endl;
				delete[] error;
			}

			// TODO: removing all shaders after link
		}
		else {
			throw ResourceException("Program", this->handle);
		}*/
    }

    void Program::use()
    {
        /*if (this->handle != GL::NULL_ID) {
            glUseProgram(this->handle);
		}
		else {
			throw ResourceException("Program", this->handle);
		}*/
    }

	void Program::bindLocation(const int index, const std::string & name)
	{
		/*if (this->handle != GL::NULL_ID) {
			glBindAttribLocation(this->handle, index, name.data());
		}
		else {
			throw ResourceException("Program", this->handle);
		}*/
	}

	void Program::bindInfo(const FloatMatrix4u & info, const std::string & name)
	{
		/*if (this->handle > GL::NULL_ID) {
			GLuint handle = glGetUniformLocation(this->handle, name.data());
			glUniformMatrix4fv(handle, 1, GL_FALSE, &info[0][0]);
		}
		else {
			throw ResourceException("Program", this->handle);
		}*/
	}

	void Program::bindInfo(const FloatVertex3u & info, const std::string & name)
	{
		/*if (this->handle > GL::NULL_ID) {
			GLuint handle = glGetUniformLocation(this->handle, name.data());
			glUniform3fv(handle, 3, &info[0]);
		}
		else {
			throw ResourceException("Program", this->handle);
		}*/
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
