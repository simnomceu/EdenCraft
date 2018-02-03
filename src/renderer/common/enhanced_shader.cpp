#include "renderer/common/enhanced_shader.hpp"

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	void EnhancedShader::setStage(ShaderStage & shader)
	{
		// TODO: it should be the version of the current context an not the latest version available.
		std::string versionTag = std::to_string(OpenGL::getLatestMajorVersion()) + std::to_string(OpenGL::getLatestMinorVersion()) + "0";

		std::string tag("#version ");
		auto source = shader.getSource();
		auto pos = source.find(tag);
		if (pos != std::string::npos) {
			source.replace(pos + tag.size(), 3, versionTag.data());
		}
		else {
			source = tag + versionTag + "\n" + source;
		}
		shader.loadFromString(shader.getType(), source);

		Shader::setStage(shader);
	}
}