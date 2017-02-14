#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Core\Graphic\Rendering\Shader.hpp"
#include "Core\Util\LogService.hpp"

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
		template<class T> void bindInfo(const T & info, const std::string & name);

		virtual void detachShader(const Shader::ShaderID & shader) = 0;

		virtual void link() = 0;
		virtual void use() = 0;

	protected:
		ProgramID id;
	};

	inline Program::Program(): id(-1) {}

	inline Program::~Program() {}

	template<class T>
	inline void Program::bindInfo(const T & info, const std::string & name)
	{
		LogServiceLocator::getService().logWarning("Binding this kind of informations has not already been implemented, it won't do anything.");
	}
}

#endif