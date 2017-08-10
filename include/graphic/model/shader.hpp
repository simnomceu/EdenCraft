#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "renderable/shader_source.hpp"

namespace ece
{
	class Shader: public ShaderSource
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
		inline virtual const std::string & getSource() const override;
		inline virtual const ShaderType & getType() const override;

	private:
		std::string filename;
		std::string source;

		ShaderType type;
	};
}

#include "model/shader.inl"

#endif // SHADER_HPP