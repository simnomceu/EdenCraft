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

		virtual void detachShader(const Shader::ShaderID & shader);

		virtual void link();
		virtual void use();

		void bindInfo(const glm::mat4 & info, const std::string & name);
		void bindInfo(const glm::vec3 & info, const std::string & name);

	private:
		std::vector<Shader*> shaders;
	};
}

#endif // PROGRAMGL_HPP