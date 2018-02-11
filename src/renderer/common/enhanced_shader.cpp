#include "renderer/common/enhanced_shader.hpp"

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	void EnhancedShader::setStage(ShaderStage & shader)
	{
		// TODO: it should be the version of the current context an not the latest version available.
		auto latestVersion = OpenGL::getLatestVersion();
		std::string versionTag = std::to_string(latestVersion[0]) + std::to_string(latestVersion[1]) + "0";

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