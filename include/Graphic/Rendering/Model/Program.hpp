#ifndef PROGRAM_H
#define PROGRAM_H

#include "Util\OpenGL\OpenGL.hpp"

#include <string>

namespace ece
{
    class Program
    {
    public:
        Program();
        Program(const Program & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
        Program(Program && move) = default;
        ~Program();

        Program & operator=(const Program & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
        Program & operator=(Program && move) = default;

        void init();//

        void loadShaderFromFile(const ShaderType type, const std::string & filename);//
        void loadShaderFromString(const ShaderType type, const std::string & content);//

        void link();//
        void use();

		void bindInfo(const Matrix4x4 & info, const std::string & name);
		void bindInfo(const Vertex3D & info, const std::string & name);

        //void displayActiveUniforms();
        //void displayActiveAttribs();

    private:
        ProgramID handle;
        ShaderID vertex;//
        ShaderID fragment;//
    };
}

#endif // PROGRAM_H
