#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Core\Graphic\Rendering\Shader.hpp"
#include "Core\Util\LogService.hpp"

#include "GL\glew.h"
#include "glm\glm.hpp"
// TODO : remove this include from here (redefine basic mat and vec classes)

namespace ece
{
	class Program
	{
	public:
		using ProgramID = int;

		Program();
		Program(const Program & copy) = delete;
		Program(Program && move) = default;

		virtual ~Program() = 0;

		Program & operator=(const Program & copy) = delete;
		Program & operator=(Program && move) = default;

		virtual void attachShader(Shader & shader) = 0;
		virtual void bindInfo(const glm::mat4 & info, const std::string & name) = 0;
		virtual void bindInfo(const glm::vec3 & info, const std::string & name) = 0;

		virtual void detachShader(const Shader::ShaderID & shader) = 0;

		virtual void link() = 0;
		virtual void use() = 0;

	protected:
		ProgramID id;
	};

	inline Program::Program(): id(-1) {}

	inline Program::~Program() {}
}

#endif