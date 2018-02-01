#ifndef SHADER_HPP
#define SHADER_HPP

#include "renderer/opengl/opengl.hpp"
#include "renderer/common/shader_stage.hpp"

namespace ece
{
	class Shader
	{
	public:
		Shader();
		inline Shader(const Handle handle);
		Shader(const Shader & copy) = default;
		Shader(Shader && move) = default;

		~Shader() = default;

		Shader & operator=(const Shader & copy) = default;
		Shader & operator=(Shader && move) = default;

		inline const std::string & getFilename() const;
		inline const std::string & getSource() const;
		inline ShaderType getType() const;
		inline Handle getHandle() const;
		inline bool isCompilationRequired() const;
		
		void compile();
		void terminate();

		void setStage(ShaderStage & shader);
		void link();
		void use() const;

		template<class T> void uniform(const std::string & uniform, const T & value);

	private:
		std::string _filename;
		std::string _source;
		ShaderType _type;
		Handle _handle;
		bool _compilationRequired;
	};
}

#include "renderer/common/shader.inl"

#endif // SHADER_HPP
