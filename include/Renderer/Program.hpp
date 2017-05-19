#ifndef PROGRAM_H
#define PROGRAM_H

#include "Mathematics\Matrix4u.hpp"
#include "OpenGL\OpenGL.hpp"
#include "ShaderGL.hpp"

#include <string>
#include <memory>
#include <queue>

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

		//void apply(const std::shared_ptr<Shader> & shader);

        void link();//
        void use();

		void bindLocation(const int index, const std::string & name);

		void bindInfo(const FloatMatrix4u & info, const std::string & name);
		void bindInfo(const FloatVertex3u & info, const std::string & name);

		inline const GL::ProgramID & getHandle() const;

        //void displayActiveUniforms();
        //void displayActiveAttribs();

    private:
		GL::ProgramID handle;
    };
}

#include "Program.inl"

#endif // PROGRAM_H
