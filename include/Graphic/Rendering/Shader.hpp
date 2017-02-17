#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

namespace ece
{
	class Shader
	{
	public:
		using ShaderID = int;

		enum ShaderType : int
		{
			COMPUTE_SHADER = 0,
			FRAGMENT_SHADER = 1,
			GEOMETRY_SHADER = 2,
			VERTEX_SHADER = 3,
			TESS_EVALUATION_SHADER = 4,
			TESS_CONTROL_SHADER = 5
		};

		Shader() = delete;
		Shader(const ShaderType & type); // TODO: shader type should be provided at same time that the source code.
		Shader(const Shader & copy) = delete;
		Shader(Shader && move) = default;

		virtual ~Shader() = 0;

		Shader & operator=(const Shader & copy) = delete;
		Shader & operator=(Shader && move) = default;

		virtual void loadFromFile(const std::string & filename) = 0;
		virtual void loadFromString(const std::string & sourceCode) = 0;

		virtual void compile() = 0;

		const ShaderID & getId() const;
		const ShaderType & getType() const;
		const std::string & getFilename() const;

		virtual void reset() = 0;

	protected:
		ShaderID id;
		ShaderType type;
		std::string filename;
	};

	inline Shader::Shader(const ShaderType & type) : id(-1), type(type), filename("") {}

	inline Shader::~Shader() {}

	inline const Shader::ShaderID & Shader::getId() const { return this->id; }
	inline const Shader::ShaderType & Shader::getType() const { return this->type; }
	inline const std::string & Shader::getFilename() const { return this->filename; }
}

#endif // SHADER_HPP