#ifndef PROGRAMGL_HPP
#define PROGRAMGL_HPP

#include "Core\Graphic\Rendering\Program.hpp"

#include <vector>

namespace ece
{
	class ProgramGL: public Program
	{
	public:
		ProgramGL();
		ProgramGL(const ProgramGL & copy) = delete;
		ProgramGL(ProgramGL && move) = default;

		~ProgramGL();

		ProgramGL & operator=(const ProgramGL & copy) = delete;
		ProgramGL & operator=(ProgramGL && move) = default;

		virtual void attachShader(Shader & shader);
		template<class T> void bindInfo(const T & info, const std::string & name);

		virtual void detachShader(const Shader::ShaderID & shader);

		virtual void link();
		virtual void use();

	private:
		std::vector<Shader*> shaders;
	};


	template<class T>
	inline void ProgramGL::bindInfo(const T & info, const std::string & name)
	{
		LogServiceLocator::getService().logWarning("Binding this kind of informations has not already been implemented, it won't do anything.");
	}
}

#endif // PROGRAMGL_HPP