#ifndef SHADER_SOURCE_HPP
#define SHADER_SOURCE_HPP

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

	class ShaderSource
	{
	public:
		ShaderSource() = default;
		ShaderSource(const ShaderSource & copy) = default;
		ShaderSource(ShaderSource && move) = default;

		~ShaderSource() = default;

		ShaderSource & operator=(const ShaderSource & copy) = default;
		ShaderSource & operator=(ShaderSource && move) = default;

		virtual const ShaderType & getType() const = 0;
		virtual const std::string & getSource() const = 0;
	};
}

#endif // SHADER_SOURCE_HPP