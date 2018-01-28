#ifndef SHADER_STAGE_HPP
#define SHADER_STAGE_HPP

#include <string>

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	class ShaderStage
	{
	public:
		inline ShaderStage();
		inline ShaderStage(const ShaderStage & copy);
		inline ShaderStage(ShaderStage && move);

		inline ~ShaderStage();

		ShaderStage & operator=(const ShaderStage & copy);
		ShaderStage & operator=(ShaderStage && move);
		
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

#include "renderer/common/shader_stage.inl"

#endif // SHADER_STAGE_HPP