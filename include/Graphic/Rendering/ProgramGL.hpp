#ifndef PROGRAMGL_HPP
#define PROGRAMGL_HPP

#include "Rendering\Program.hpp"

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

		virtual void attachShader(Shader & shader) override;

		virtual void detachShader(const Shader::ShaderID & shader) override;

		virtual void link() override;
		virtual void use() override;

		virtual void bindInfo(const glm::mat4 & info, const std::string & name) override;
		virtual void bindInfo(const glm::vec3 & info, const std::string & name) override;

	private:
		std::vector<Shader*> shaders;
	};
}

#endif // PROGRAMGL_HPP