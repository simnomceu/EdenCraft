#ifndef OPENGL_EXTENSION_HPP
#define OPENGL_EXTENSION_HPP

#include <string>

namespace ece
{
	using OptionOpenGL = unsigned int;

	const OptionOpenGL NO_OPENGL_OPTIONS			= 0 << 0;
	const OptionOpenGL COMMAND_EXECUTION			= 1 << 0;
	const OptionOpenGL TIMER_QUERIES				= 1 << 1;
	const OptionOpenGL SYNCHRONIZATION				= 1 << 2;
	const OptionOpenGL ASYNCHRONOUS_QUERIES			= 1 << 3;
	const OptionOpenGL BUFFER_OBJECTS				= 1 << 4;
	const OptionOpenGL SHADERS_AND_PROGRAMS			= 1 << 5;
	const OptionOpenGL TEXTURES_AND_SAMPLERS		= 1 << 6;
	const OptionOpenGL FRAMEBUFFER_OBJECTS			= 1 << 7;
	const OptionOpenGL VERTICES						= 1 << 8;
	const OptionOpenGL VERTEX_ARRAYS				= 1 << 9;
	const OptionOpenGL VERTEX_ATTRIBUTES			= 1 << 10;
	const OptionOpenGL VERTEX_POST_PROCESSING		= 1 << 11;
	const OptionOpenGL RASTERIZATION				= 1 << 12;
	const OptionOpenGL FRAGMENT_SHADERS				= 1 << 13;
	const OptionOpenGL COMPUTE_SHADERS				= 1 << 14;
	const OptionOpenGL PER_FRAGMENT_OPERATIONS		= 1 << 15;
	const OptionOpenGL HINTS						= 1 << 16;
	const OptionOpenGL WHOLE_FRAMEBUFFER			= 1 << 17;
	const OptionOpenGL READING_AND_COPYING_PIXELS	= 1 << 18;
	const OptionOpenGL DEBUG_OUTPUT					= 1 << 19;
	const OptionOpenGL STATE_AND_STATE_REQUESTS		= 1 << 20;
	const OptionOpenGL PLATFORM						= 1 << 21;

	class OpenGLExtension
	{
	public:
		inline OpenGLExtension();
		OpenGLExtension(const OpenGLExtension & copy) = default;
		OpenGLExtension(OpenGLExtension && move) = default;

		inline virtual ~OpenGLExtension() = 0;

		OpenGLExtension & operator=(const OpenGLExtension & copy) = default;
		OpenGLExtension & operator=(OpenGLExtension && move) = default;

		virtual std::array<int, 2> init(const OptionOpenGL options) = 0;
		inline bool isLoaded(const OptionOpenGL option) const;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) = 0;

		bool loadExtensions(const OptionOpenGL options);

		inline virtual void loadPlatformExtensions();

		void loadCommandExecutionExtensions();
		void loadTimerQueriesExtensions();
		void loadSynchronizationExtensions();
		void loadAsynchronousQueries();
		void loadBufferObjectsExtensions();
		void loadShadersAndProgramsExtensions();
		void loadTexturesAndSamplersExtensions();
		void loadFramebufferObjectsExtensions();
		void loadVerticesExtensions();
		void loadVertexArraysExtensions();
		void loadVertexAttributesExtensions();
		void loadVertexPostProcessingExtensions();
		void loadRasterizationExtensions();
		void loadFragmentShadersExtensions();
		void loadComputeShadersExtensions();
		void loadPerFragmentOperationsExtensions();
		void loadHintsExtensions();
		void loadWholeFramebufferExtensions();
		void loadReadingAndCopyingPixelsExtensions();
		void loadDebugOutputExtensions();
		void loadStateAndStateRequestsExtensions();

		OptionOpenGL _loaded;
	};
}

#include "renderer/opengl/opengl_extension.inl"

#endif // OPENGL_EXTENSION_HPP
