#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

namespace ece
{
	enum ShaderType: unsigned short int {
		ECE_NULL_SHADER = 0,
		ECE_COMPUTE_SHADER = 1,
		ECE_FRAGMENT_SHADER = 2,
		ECE_GEOMETRY_SHADER = 3,
		ECE_VERTEX_SHADER = 4,
		ECE_TESS_EVALUATION_SHADER = 5,
		ECE_TESS_CONTROL_SHADER = 6
	};

	using ShaderHandle = unsigned short int;

	class Shader
	{
	public:
		inline Shader();
		Shader(const Shader & copy);
		Shader(Shader && move);

		inline ~Shader();

		Shader & operator=(const Shader & copy);
		Shader & operator=(Shader && move);
		
		void loadFromFile(const ShaderType type, const std::string & filename);
		void loadFromString(const ShaderType type, const std::string & sourceCode);

		inline const std::string & getFilename() const;
		inline const std::string & getSource() const;
		inline ShaderType getType() const;
		inline ShaderHandle getHandle() const;
		
		void compile();
		void terminate();

	private:
		std::string filename;
		std::string source;
		ShaderType type;
		ShaderHandle handle;
	};
}

#include "renderer/common/shader.inl"

#endif // SHADER_GL_HPP