#ifndef OLDGLSLPROGRAM_H
#define OLDGLSLPROGRAM_H

#include "GL\glew.h"
#include "glm\glm.hpp"
#include <string>

namespace ece
{
    class OldGLSLProgram
    {
    public:
        enum GLSLShaderType {
            VERTEX,
            FRAGMENT
        };

        OldGLSLProgram();
        OldGLSLProgram(const OldGLSLProgram & copy) = default;
        OldGLSLProgram(OldGLSLProgram && move) = default;
        ~OldGLSLProgram();

        OldGLSLProgram & operator=(const OldGLSLProgram & copy) = default;
        OldGLSLProgram & operator=(OldGLSLProgram && move) = default;

        void init();

        void loadShaderFromFile(const GLSLShaderType type, const std::string & filename);
        void loadShaderFromString(const GLSLShaderType type, const std::string & content);

        void link();
        void use();

        void setUniform(const std::string & name, const glm::mat4 & value);

        void displayActiveUniforms();
        void displayActiveAttribs();

    private:
        GLuint handle;
        GLuint vertex;
        GLuint fragment;
    };
}

#endif // OLDGLSLPROGRAM_H
