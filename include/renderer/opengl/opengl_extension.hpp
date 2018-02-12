/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooo.                               .o8                                        
															`888   `Y88.                            "888                                        
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b 
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P 
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888     
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888     
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b   
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

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

		virtual void init(const OptionOpenGL options) = 0;
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
