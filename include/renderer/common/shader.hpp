#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	class Shader
	{
	public:
		inline Shader();
		inline Shader(const Shader & copy);
		inline Shader(Shader && move);

		inline ~Shader();

		Shader & operator=(const Shader & copy);
		Shader & operator=(Shader && move);
		
		void loadFromFile(const ShaderType type, const std::string & filename);
		void loadFromString(const ShaderType type, const std::string & sourceCode);

		inline const std::string & getFilename() const;
		inline const std::string & getSource() const;
		inline ShaderType getType() const;
		inline ShaderHandle getHandle() const;
		inline bool isCompilationRequired() const;
		
		void compile();
		void terminate();

	private:
		std::string _filename;
		std::string _source;
		ShaderType _type;
		ShaderHandle _handle;
		bool _compilationRequired;
	};
}

#include "renderer/common/shader.inl"

#endif // SHADER_GL_HPP