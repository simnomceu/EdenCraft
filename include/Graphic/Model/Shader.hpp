#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

namespace ece
{
	enum ShaderType : unsigned short int
	{
		COMPUTE_SHADER = 0,
		FRAGMENT_SHADER = 1,
		GEOMETRY_SHADER = 2,
		VERTEX_SHADER = 3,
		TESS_EVALUATION_SHADER = 4,
		TESS_CONTROL_SHADER = 5,
		NULL_TYPE_SHADER
	};

	class Shader
	{
	public:
		inline Shader();
		Shader(const Shader & copy) = default;
		Shader(Shader && move) = default;

		~Shader() = default;

		Shader & operator=(const Shader & copy) = default;
		Shader & operator=(Shader && move) = default;

		void loadFromFile(const ShaderType & type, const std::string & filename);
		void loadFromString(const ShaderType & type, const std::string & sourceCode);

		inline const std::string & getFilename() const;
		inline const std::string & getSource() const;
		inline const ShaderType & getType() const;

	private:
		std::string filename;
		std::string source;

		ShaderType type;
	};
}

#include "Model\Shader.inl"

#endif // SHADER_HPP