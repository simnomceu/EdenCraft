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

#include "opengl.hpp"
namespace ece
{
	template<class T> 
	void OpenGL::uniform(const UniformHandle uniform, const T value)
	{
		throw std::runtime_error("A uniform cannot be set with this type.");
	}

	template<class T>
	void OpenGL::bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage)
	{
		if (!glBufferData) {
			throw OpenGLExtensionException("glBufferData", BUFFER_OBJECTS);
		}

		const GLvoid * dataPtr = data.data();
		glBufferData(type, data.size() * sizeof(T), dataPtr, usage);
		OpenGL::checkErrors();
	}

	template<class T>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	void OpenGL::vertexAttribPointer<short>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, SHORT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<unsigned short>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_SHORT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<int>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, INT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<unsigned int>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_INT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<float>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, FLOAT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<double>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, DOUBLE, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<class T>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<T> & data)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<short> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, SHORT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned short> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_SHORT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<int> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, INT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned int> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_INT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<float> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, FLOAT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<double> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, DOUBLE, normalized, offset, data.data());
		OpenGL::checkErrors();
	}
}