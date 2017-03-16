#ifndef PROGRAM_H
#define PROGRAM_H

#include "Util\OpenGL\OpenGL.hpp"
#include "Renderer\Shader.hpp"

#include <string>
#include <memory>

namespace ece
{
	// TODO: how to create the Program
	// glCreateShader -> glShaderSource -> glCompileShader -> glCreateProgram -> glAttachShader 
	// -> glLinkProgram -> glDetachShader -> glDeleteShader -> draw using this shader program 
	// -> and when I don't need this shader anymore glDeleteProgram
	// From: http://gamedev.stackexchange.com/questions/47910/after-a-succesful-gllinkprogram-should-i-delete-detach-my-shaders

    class Program
    {
    public:
        inline Program();
		Program(const Program & copy) = default;
        Program(Program && move) = default;
        ~Program();

        Program & operator=(const Program & copy) = default;
        Program & operator=(Program && move) = default;

        void init();//

        /*void loadShaderFromFile(const ShaderType type, const std::string & filename);
        void loadShaderFromString(const ShaderType type, const std::string & content);*/
		void apply(Shader & shader);

        void link();//
        void use();

		void bindLocation(const int index, const std::string & name);

		void bindInfo(const Matrix4x4 & info, const std::string & name);
		void bindInfo(const Vertex3D & info, const std::string & name);


        //void displayActiveUniforms();
        //void displayActiveAttribs();

    private:
        ProgramID handle;
        //ShaderID vertex;
        //ShaderID fragment;
    };
}

#include "Renderer\Program.inl"

#endif // PROGRAM_H
