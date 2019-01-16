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

#include "renderer/opengl/extension.hpp"
#include "renderer/debug.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			// New version

			inline auto OpenGL::getError() -> ErrorGL { return ErrorGL(glGetError()); }

			template <class T>
			inline void OpenGL::vertexAttrib(Handle index, T v)
			{
				throw std::runtime_error("OpenGL::vertexAttrib method is not defined for this type");
			}

			template <class T>
			inline void vertexAttrib(Handle index, Vector2u<T> v)
			{
				throw std::runtime_error("OpenGL::vertexAttrib method is not defined for this type");
			}

			template <class T>
			inline void vertexAttrib(Handle index, Vector3u<T> v)
			{
				throw std::runtime_error("OpenGL::vertexAttrib method is not defined for this type");
			}

			template <class T>
			inline void vertexAttrib(Handle index, Vector4u<T> v)
			{
				throw std::runtime_error("OpenGL::vertexAttrib method is not defined for this type");
			}

			template <std::size_t Size, typename enabled>
			inline void OpenGL::vertexAttribP(Handle index, PackedVertexAttribType type, bool normalized, unsigned int value)
			{
				if constexpr (Size == 1) {
					checkErrors(glVertexAttribP1ui(index, static_cast<GLenum>(type), normalized, value));
				}
				else if (Size == 2) {
					checkErrors(glVertexAttribP2ui(index, static_cast<GLenum>(type), normalized, value));
				}
				else if (Size == 3) {
					checkErrors(glVertexAttribP3ui(index, static_cast<GLenum>(type), normalized, value));
				}
				else if (Size == 4) {
					checkErrors(glVertexAttribP4ui(index, static_cast<GLenum>(type), normalized, value));
				}
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, float v)
			{
				checkErrors(glVertexAttrib1f(index, v));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, short v)
			{
				checkErrors(glVertexAttrib1s(index, v));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, double v)
			{
				checkErrors(glVertexAttrib1d(index, v));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, int v)
			{
				checkErrors(glVertexAttribI1i(index, v));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, unsigned int v)
			{
				checkErrors(glVertexAttribI1ui(index, v));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector2u<float> v)
			{
				checkErrors(glVertexAttrib2f(index, v[0], v[1]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector2u<short> v)
			{
				checkErrors(glVertexAttrib2s(index, v[0], v[1]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector2u<double> v)
			{
				checkErrors(glVertexAttrib2d(index, v[0], v[1]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector2u<int> v)
			{
				checkErrors(glVertexAttribI2i(index, v[0], v[1]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector2u<unsigned int> v)
			{
				checkErrors(glVertexAttribI2ui(index, v[0], v[1]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector3u<float> v)
			{
				checkErrors(glVertexAttrib3f(index, v[0], v[1], v[2]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector3u<short> v)
			{
				checkErrors(glVertexAttrib3s(index, v[0], v[1], v[2]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector3u<double> v)
			{
				checkErrors(glVertexAttrib3d(index, v[0], v[1], v[2]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector3u<int> v)
			{
				checkErrors(glVertexAttribI3i(index, v[0], v[1], v[2]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector3u<unsigned int> v)
			{
				checkErrors(glVertexAttribI3ui(index, v[0], v[1], v[2]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector4u<float> v)
			{
				checkErrors(glVertexAttrib4f(index, v[0], v[1], v[2], v[3]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector4u<short> v)
			{
				checkErrors(glVertexAttrib4s(index, v[0], v[1], v[2], v[3]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector4u<double> v)
			{
				checkErrors(glVertexAttrib4d(index, v[0], v[1], v[2], v[3]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector4u<int> v)
			{
				checkErrors(glVertexAttribI4i(index, v[0], v[1], v[2], v[3]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, Vector4u<unsigned int> v)
			{
				checkErrors(glVertexAttribI4ui(index, v[0], v[1], v[2], v[3]));
			}

			template<>
			inline void OpenGL::vertexAttrib(Handle index, std::array<std::byte, 4> v)
			{
				checkErrors(glVertexAttrib4Nub(index, static_cast<GLubyte>(v[0]), static_cast<GLubyte>(v[1]), static_cast<GLubyte>(std::move(v[2])), static_cast<GLubyte>(std::move(v[3]))));
			}

			inline void OpenGL::vertexAttribPointer(const int location, const std::size_t size, const DataType type, const bool normalized, const std::size_t stride, const std::size_t offset)
			{
				checkErrors(glVertexAttribPointer(location, static_cast<GLint>(size), static_cast<GLenum>(type), normalized, static_cast<GLsizei>(stride), reinterpret_cast<GLvoid *>(offset)));
			}

			inline void OpenGL::enableVertexAttribArray(const int location)
			{
				checkErrors(glEnableVertexAttribArray(location));
			}

			inline void OpenGL::disableVertexAttribArray(const int location)
			{
				checkErrors(glDisableVertexAttribArray(location));
			}

			inline void OpenGL::enable(const Capability cap)
			{
				checkErrors(glEnable(static_cast<GLenum>(cap)));
			}

			inline void OpenGL::disable(const Capability cap)
			{
				checkErrors(glDisable(static_cast<GLenum>(cap)));
			}

			inline void OpenGL::enableIndexed(const Capability cap, const unsigned short int index)
			{
				checkErrors(glEnablei(static_cast<GLenum>(cap), index));
			}

			inline void OpenGL::disableIndexed(const Capability cap, const unsigned short int index)
			{
				checkErrors(glDisablei(static_cast<GLenum>(cap), index));
			}

			inline void OpenGL::primitiveRestartIndex(std::size_t index)
			{
				checkErrors(glPrimitiveRestartIndex(static_cast<GLuint>(index)));
			}

			inline void OpenGL::drawArrays(const PrimitiveMode mode, const int first, const std::size_t count)
			{
				checkErrors(glDrawArrays(static_cast<GLenum>(mode), first, static_cast<GLsizei>(count)));
			}

			inline void OpenGL::multiDrawArrays(PrimitiveMode mode, const std::vector<int> & first, const std::vector<std::size_t> & count, std::size_t drawcount)
			{
				checkErrors(glMultiDrawArrays(static_cast<GLenum>(mode), first.data(), reinterpret_cast<const GLsizei *>(count.data()), static_cast<GLsizei>(drawcount)));
			}

			inline void OpenGL::drawElements(const PrimitiveMode mode, const std::size_t count, const int offset)
			{
				const auto type = GL_UNSIGNED_INT;
				auto byteOffset = offset * sizeof(unsigned int);
				checkErrors(glDrawElements(static_cast<GLenum>(mode), static_cast<GLsizei>(count), type, reinterpret_cast<GLvoid *>(byteOffset)));
			}

			inline void OpenGL::multiDrawElements(PrimitiveMode mode, const std::vector<std::size_t> & count, const std::vector<std::size_t *> & indices, std::size_t drawcount)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glMultiDrawElements(static_cast<GLenum>(mode), reinterpret_cast<const GLsizei *>(count.data()), type, reinterpret_cast<const GLvoid * const *>(indices.data()), static_cast<GLsizei>(drawcount)));
			}

			inline void OpenGL::drawRangeElements(PrimitiveMode mode, std::size_t start, std::size_t end, std::size_t count, const std::size_t * indices)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawRangeElements(static_cast<GLenum>(mode), start, end, count, type, static_cast<const GLvoid *>(indices)));
			}

			inline void OpenGL::drawArraysInstanced(const PrimitiveMode mode, const int first, const std::size_t count, const std::size_t primcount)
            {
                checkErrors(glDrawArraysInstanced(static_cast<GLenum>(mode), first, count, static_cast<GLsizei>(primcount)));
            }

            inline void OpenGL::drawElementsInstanced(const PrimitiveMode mode, const std::size_t count, const int offset, const std::size_t primcount)
            {
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawElementsInstanced(static_cast<GLenum>(mode), count, type, reinterpret_cast<GLvoid *>(offset), static_cast<GLsizei>(primcount)));
            }

            inline void OpenGL::drawElementsBaseVertex(PrimitiveMode mode, std::size_t count, std::vector<std::size_t> & indices, int basevertex)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawElementsBaseVertex(static_cast<GLenum>(mode), count, type, reinterpret_cast<GLvoid *>(indices.data()), basevertex));
			}

			inline void OpenGL::drawRangeElementsBaseVertex(PrimitiveMode mode, std::size_t start, std::size_t end, std::size_t count, std::vector<std::size_t> & indices, int basevertex)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawRangeElementsBaseVertex(static_cast<GLenum>(mode), start, end, count, type, reinterpret_cast<GLvoid *>(indices.data()), basevertex));
			}

			inline void OpenGL::drawElementsInstancedBaseVertex(PrimitiveMode mode, std::size_t count, std::vector<std::size_t> & indices, std::size_t primcount, int basevertex)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawElementsInstancedBaseVertex(static_cast<GLenum>(mode), count, type, reinterpret_cast<GLvoid *>(indices.data()), static_cast<GLsizei>(primcount), basevertex));
			}

			inline void OpenGL::multiDrawElementsBaseVertex(PrimitiveMode mode, const std::vector<std::size_t> & count, const std::vector<std::size_t *> & indices, std::size_t drawcount, const std::vector<int> & basevertex)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glMultiDrawElementsBaseVertex(static_cast<GLenum>(mode), reinterpret_cast<const GLsizei *>(count.data()), type, reinterpret_cast<const GLvoid * const *>(indices.data()), drawcount, basevertex.data()));
			}

			inline auto OpenGL::genBuffers() -> Handle
			{
				auto handle = NULL_HANDLE;
				checkErrors(glGenBuffers(1, &handle));
				return std::move(handle);
			}

			inline auto OpenGL::genBuffers(const int count) -> std::vector<Handle>
			{
				auto handles = std::vector<Handle>(count, NULL_HANDLE);
				checkErrors(glGenBuffers(count, &handles.front()));

				return std::move(handles);
			}

			inline void OpenGL::deleteBuffer(const Handle buffer)
			{
				checkErrors(glDeleteBuffers(1, &buffer));
			}

			inline void OpenGL::deleteBuffers(const std::vector<Handle> & buffers)
			{
				checkErrors(glDeleteBuffers(static_cast<GLsizei>(buffers.size()), buffers.data()));
			}

			inline void OpenGL::bindBuffer(const BufferType type, const Handle handle)
			{
				checkErrors(glBindBuffer(static_cast<GLenum>(type), handle));
			}

			inline void OpenGL::bindBufferRange(IndexedBufferTarget target, Handle index, Handle buffer, int offset, std::size_t size)
			{
				checkErrors(glBindBufferRange(static_cast<GLenum>(target), index, buffer, offset, size));
			}

			inline void OpenGL::bindBufferBase(IndexedBufferTarget target, Handle index, Handle buffer)
			{
				checkErrors(glBindBufferBase(static_cast<GLenum>(target), index, buffer));
			}

			template <class C, typename enabled>
			inline void OpenGL::bufferData(const BufferType type, const C & data, const BufferUsage usage, const int offset)
			{
				checkErrors(glBufferData(static_cast<GLenum>(type), std::size(data) * sizeof(typename C::value_type), std::data(data) + offset, static_cast<GLenum>(usage)));
			}

			template <class E>
			inline void OpenGL::bufferData(const BufferType type, const std::size_t size, const BufferUsage usage, const int /*offset*/)
			{
				checkErrors(glBufferData(static_cast<GLenum>(type), size * sizeof(E), nullptr, static_cast<GLenum>(usage)));
			}

			template <class C, typename enabled>
			inline void OpenGL::bufferSubData(BufferType target, int offset, std::size_t size, const C & data)
			{
				checkErrors(glBufferSubData(static_cast<GLenum>(target), offset, size, reinterpret_cast<GLvoid *>(data.data())));
			}

			inline auto OpenGL::mapBufferRange(BufferType target, int offset, std::size_t length, MapBufferRangeAccessFlag access) -> void *
			{
				return checkErrors(glMapBufferRange(static_cast<GLenum>(target), offset, length, static_cast<GLbitfield>(access)));
			}

			inline auto OpenGL::mapBuffer(BufferType target, MapBufferAccessFlag access) -> void *
			{
				return checkErrors(glMapBuffer(static_cast<GLenum>(target), static_cast<GLbitfield>(access)));
			}

			inline void OpenGL::flushMappedBufferRange(BufferType target, int offset, std::size_t length)
			{
				return checkErrors(glFlushMappedBufferRange(static_cast<GLenum>(target), offset, length));
			}

			inline auto OpenGL::unmapBuffer(BufferType target) -> bool
			{
				return checkErrors(glUnmapBuffer(static_cast<GLenum>(target)));
			}

			inline void OpenGL::copyBufferSubData(BufferType readTarget, BufferType writeTarget, int readOffset, int writeOffset, std::size_t size)
			{
				checkErrors(glCopyBufferSubData(static_cast<GLenum>(readTarget), static_cast<GLenum>(writeTarget), readOffset, writeOffset, size));
			}

			inline auto OpenGL::genVertexArrays() -> Handle
			{
				auto handle = NULL_HANDLE;
				checkErrors(glGenVertexArrays(1, &handle));
				return std::move(handle);
			}

			inline auto OpenGL::genVertexArrays(const int count) -> std::vector<Handle>
			{
				auto handles = std::vector<Handle>(count, NULL_HANDLE);
				checkErrors(glGenVertexArrays(count, &handles.front()));

				return std::move(handles);
			}

			inline void OpenGL::deleteVertexArrays(std::size_t n, const std::vector<Handle> & arrays)
			{
				checkErrors(glDeleteVertexArrays(n, arrays.data()));
			}

			inline void OpenGL::bindVertexArray(const Handle handle)
			{
				checkErrors(glBindVertexArray(handle));
			}

			inline auto OpenGL::isBuffer(Handle buffer) -> bool
			{
				return checkErrors(glIsBuffer(buffer));
			}

			inline auto OpenGL::getBufferParameteriv(BufferType target, BufferParameter value) -> int
			{
				auto data = 0;
				checkErrors(glGetBufferParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(value), &data));
				return std::move(data);
			}

			inline auto OpenGL::getBufferParameteri64v(BufferType target, BufferParameter value) -> int64_t
			{
				auto data = int64_t{ 0 };
				checkErrors(glGetBufferParameteri64v(static_cast<GLenum>(target), static_cast<GLenum>(value), &data));
				return std::move(data);
			}

			template <class T>
			inline auto OpenGL::getBufferSubData(BufferType target, int offset, std::size_t size) -> std::vector<T>
			{
				auto data = std::vector<T>{};
				checkErrors(glGetBufferSubData(static_cast<GLenum>(target), offset, size, reinterpret_cast<GLvoid *>(data.data())));
				return std::move(data);
			}

			template <class T>
			inline auto OpenGL::getBufferPointer(BufferType target) -> T *
			{
				const auto pname = GL_BUFFER_MAP_POINTER;
				T * params = nullptr;
				checkErrors(glGetBufferPointerv(static_cast<GLenum>(target), pname, reinterpret_cast<GLvoid**>(&params)));
				return std::move(params);
			}

			inline auto OpenGL::isVertexArray(Handle array) -> bool
			{
				return checkErrors(glIsVertexArray(array));
			}

			inline void OpenGL::depthRange(double nearVal, double farVal)
			{
				checkErrors(glDepthRange(nearVal, farVal));
			}

			inline void OpenGL::viewport(const int x, const int y, const unsigned int width, const unsigned int height)
			{
				checkErrors(glViewport(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}

			inline void OpenGL::clampColor(bool clamp)
			{
				checkErrors(glClampColor(GL_CLAMP_READ_COLOR, static_cast<GLenum>(clamp)));
			}

			inline void OpenGL::provokingVertex(ProvokeMode provokeMode)
			{
				checkErrors(glProvokingVertex(static_cast<GLenum>(provokeMode)));
			}

			inline void OpenGL::beginConditionalRender(Handle id, ConditionalRenderQueryMode mode)
			{
				checkErrors(glBeginConditionalRender(id, static_cast<GLenum>(mode)));
			}

			inline void OpenGL::endConditionalRender()
			{
				checkErrors(glEndConditionalRender());
			}

			inline void OpenGL::beginTransformFeedback(PrimitiveMode primitiveMode)
			{
				checkErrors(glBeginTransformFeedback(static_cast<GLenum>(primitiveMode)));
			}

			inline void OpenGL::endTransformFeedback()
			{
				checkErrors(glEndTransformFeedback());
			}

			inline void OpenGL::beginQuery(QueryObjectType target, Handle id)
			{
				checkErrors(glBeginQuery(static_cast<GLenum>(target), id))
			}

			inline void OpenGL::endQuery(QueryObjectType target)
			{
				checkErrors(glEndQuery(static_cast<GLenum>(target)));
			}

			inline auto OpenGL::genQueries(std::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>{};
				checkErrors(glGenQueries(n, reinterpret_cast<GLuint *>(ids.data())));
				return ids;
			}

			inline void OpenGL::deleteQueries(const std::vector<Handle> & ids)
			{
				checkErrors(glDeleteQueries(ids.size(), ids.data()));
			}

			inline auto OpenGL::isQuery(Handle id) -> bool
			{
				return checkErrors(glIsQuery(id));
			}

			inline auto OpenGL::getQuery(QueryObjectType target, QueryObjectTypeParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetQueryiv(static_cast<GLenum>(target), static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <typename T>
			inline auto OpenGL::getQueryObject([[maybe_unused]] Handle id, [[maybe_unused]] QueryObjectTypeName pname) -> T
			{
				throw std::runtime_error("OpenGL::getQueryObject method is not defined for this type");
			}

			template <>
			inline auto OpenGL::getQueryObject(Handle id, QueryObjectTypeName pname) -> int
			{
				auto params = 0;
				checkErrors(glGetQueryObjectiv(id, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getQueryObject(Handle id, QueryObjectTypeName pname) -> unsigned int
			{
				auto params = 0u;
				checkErrors(glGetQueryObjectuiv(id, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getQueryObject(Handle id, QueryObjectTypeName pname) -> int64_t
			{
				auto params = int64_t{ 0 };
				checkErrors(glGetQueryObjecti64v(id, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getQueryObject(Handle id, QueryObjectTypeName pname) -> uint64_t
			{
				auto params = uint64_t{ 0 };
				checkErrors(glGetQueryObjectui64v(id, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::createShader(const ShaderType type) -> Handle
			{
				auto shaderHandle = checkErrors(glCreateShader(static_cast<GLenum>(type)));
				return shaderHandle;
			}

			inline void OpenGL::shaderSource(const Handle handle, const std::string & source)
			{
				auto sourcePtr = source.data();
				checkErrors(glShaderSource(handle, 1, &sourcePtr, nullptr)); // TODO: add the length of the source
			}

			inline void OpenGL::shaderSource(const Handle handle, const std::vector<std::string>& source)
			{
				auto sourcesPtr = std::vector<const char*>{};
				for (const auto & string : source) {
					sourcesPtr.push_back(string.data());
				}
				checkErrors(glShaderSource(handle, 1, sourcesPtr.data(), nullptr)); // TODO: add the lengths of the sources
			}

			inline void OpenGL::compileShader(const Handle handle)
			{
				checkErrors(glCompileShader(handle));
			}

			inline void OpenGL::deleteShader(const Handle handle)
			{
				checkErrors(glDeleteShader(handle));
			}

			inline auto OpenGL::createProgram() -> Handle
			{
				auto programHandle = checkErrors(glCreateProgram());
				return programHandle;
			}

			inline void OpenGL::attachShader(const Handle program, const Handle shader)
			{
				checkErrors(glAttachShader(program, shader));
			}

			inline void OpenGL::detachShader(const Handle program, const Handle shader)
			{
				checkErrors(glDetachShader(program, shader));
			}

			inline void OpenGL::linkProgram(const Handle handle)
			{
				checkErrors(glLinkProgram(handle));
			}

			inline void OpenGL::useProgram(const Handle handle)
			{
				checkErrors(glUseProgram(handle));
			}

			inline void OpenGL::deleteProgram(Handle program)
			{
				checkErrors(glDeleteProgram(program));
			}

			inline auto OpenGL::getActiveAttrib(Handle program, unsigned int index) -> ProgramAttribute
			{
				const auto bufSize = std::size_t{ 4096 };

				auto length = std::size_t{ 0 };
				auto result = ProgramAttribute{};
				result.name.resize(bufSize);

				checkErrors(glGetActiveAttrib(program, index, bufSize, reinterpret_cast<GLsizei*>(&length), reinterpret_cast<GLint*>(&result.size), reinterpret_cast<GLenum*>(&result.type), result.name.data()));
				result.name = result.name.substr(0, length);

				return std::move(result);
			}

			inline auto OpenGL::getAttribLocation(Handle program, const std::string & name) -> int
			{
				return checkErrors(glGetAttribLocation(program, name.data()));
			}

			inline void OpenGL::bindAttribLocation(Handle program, unsigned int index, const std::string & name)
			{
				checkErrors(glBindAttribLocation(program, index, name.data()));
			}

			inline auto OpenGL::getUniformLocation(const Handle handle, const std::string & uniform) -> Handle
			{
				auto location = checkErrors(glGetUniformLocation(handle, uniform.data()));
                if (location < 0) {
                    throw std::runtime_error("No " + uniform + " uniform in the current shader program.");
                }
				return location;
			}

			inline auto OpenGL::getUniformBlockIndex(Handle program, const std::string & uniformBlockName) -> unsigned int
			{
				return checkErrors(glGetUniformBlockIndex(program, uniformBlockName.data()));
			}

			inline auto OpenGL::getActiveUniformBlockName(Handle program, unsigned int uniformBlockIndex) -> std::string
			{
				const auto bufSize = std::size_t{ 4096 };

				auto length = std::size_t{ 0 };
				auto name = std::string(bufSize, '\0');
				checkErrors(glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, reinterpret_cast<GLsizei *>(&length), name.data()));
				name = name.substr(0, length);

				return std::move(name);
			}

			inline auto OpenGL::getActiveUniformBlock(Handle program, unsigned int uniformBlockIndex, UniformBlockParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetActiveUniformBlockiv(program, uniformBlockIndex, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getUniformIndices(Handle program, std::size_t uniformCount) -> UniformBlock
			{
				auto result = UniformBlock();
				result.names.resize(uniformCount);
				result.indices.resize(uniformCount);
				checkErrors(glGetUniformIndices(program, uniformCount, reinterpret_cast<const GLchar **>(result.names.data()), reinterpret_cast<GLuint *>(result.indices.data())));
				return std::move(result);
			}

			inline auto OpenGL::getActiveUniformName(Handle program, unsigned int uniformIndex) -> std::string
			{
				const auto bufSize = std::size_t{ 4096 };

				auto length = std::size_t{ 0 };
				auto name = std::string(bufSize, '\0');
				checkErrors(glGetActiveUniformName(program, uniformIndex, bufSize, reinterpret_cast<GLsizei *>(&length), name.data()));
				name = name.substr(0, length);

				return std::move(name);
			}

			inline auto OpenGL::getActiveUniform(const Handle program, const Handle index) -> UniformInfo
			{
				auto length = 0;
				auto size = 0;
				auto type = GLenum{};
				auto name = std::string(1024, '\0');
				checkErrors(glGetActiveUniform(program, index, 1024, &length, &size, &type, name.data()));
				return { name.substr(0, length), static_cast<UniformDataType>(type), static_cast<std::size_t>(size) };
			}

			inline auto OpenGL::getActiveUniforms(Handle program, const std::vector<unsigned int> & uniformIndices, UniformDataType pname) -> std::vector<int>
			{
				auto params = std::vector<int>(uniformIndices.size(), 0);
				checkErrors(glGetActiveUniformsiv(program, uniformIndices.size(), uniformIndices.data(), static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <class T, unsigned int S>
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] const std::array<T, S> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template<>
			inline void OpenGL::uniform<bool, 1>(const int location, const std::array<bool, 1> & v)
			{
				checkErrors(glUniform1i(location, static_cast<int>(v[0])));
			}

			template <>
			inline void OpenGL::uniform<float, 1>(const int location, const std::array<float, 1> & v)
			{
				checkErrors(glUniform1f(location, v[0]));
			}

			template <>
			inline void OpenGL::uniform<float, 2>(const int location, const std::array<float, 2> & v)
			{
				checkErrors(glUniform2f(location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::uniform<float, 3>(const int location, const std::array<float, 3> & v)
			{
				checkErrors(glUniform3f(location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::uniform<float, 4>(const int location, const std::array<float, 4> & v)
			{
				checkErrors(glUniform4f(location, v[0], v[1], v[2], v[3]));
			}

			template <>
			inline void OpenGL::uniform<int, 1>(const int location, const std::array<int, 1> & v)
			{
				checkErrors(glUniform1i(location, v[0]));
			}

			template <>
			inline void OpenGL::uniform<int, 2>(const int location, const std::array<int, 2> & v)
			{
				checkErrors(glUniform2i(location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::uniform<int, 3>(const int location, const std::array<int, 3> & v)
			{
				checkErrors(glUniform3i(location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::uniform<int, 4>(const int location, const std::array<int, 4> & v)
			{
				checkErrors(glUniform4i(location, v[0], v[1], v[2], v[3]));
			}

			template <>
			inline void OpenGL::uniform<unsigned int, 1>(const int location, const std::array<unsigned int, 1> & v)
			{
				checkErrors(glUniform1ui(location, v[0]));
			}

			template <>
			inline void OpenGL::uniform<unsigned int, 2>(const int location, const std::array<unsigned int, 2> & v)
			{
				checkErrors(glUniform2ui(location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::uniform<unsigned int, 3>(const int location, const std::array<unsigned int, 3> & v)
			{
				checkErrors(glUniform3ui(location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::uniform<unsigned int, 4>(const int location, const std::array<unsigned int, 4> & v)
			{
				checkErrors(glUniform4ui(location, v[0], v[1], v[2], v[3]));
			}

			template <class T, unsigned int S>
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const std::array<T, S> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template<>
			inline void OpenGL::uniform<float, 1>(int location, std::size_t count, const std::array<float, 1> & value)
			{
				checkErrors(glUniform1fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 2>(int location, std::size_t count, const std::array<float, 2> & value)
			{
				checkErrors(glUniform2fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 3>(int location, std::size_t count, const std::array<float, 3> & value)
			{
				checkErrors(glUniform3fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 4>(int location, std::size_t count, const std::array<float, 4> & value)
			{
				checkErrors(glUniform4fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 1>(int location, std::size_t count, const std::array<int, 1> & value)
			{
				checkErrors(glUniform1iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 2>(int location, std::size_t count, const std::array<int, 2> & value)
			{
				checkErrors(glUniform2iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 3>(int location, std::size_t count, const std::array<int, 3> & value)
			{
				checkErrors(glUniform3iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 4>(int location, std::size_t count, const std::array<int, 4> & value)
			{
				checkErrors(glUniform4iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 1>(int location, std::size_t count, const std::array<unsigned int, 1> & value)
			{
				checkErrors(glUniform1uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 2>(int location, std::size_t count, const std::array<unsigned int, 2> & value)
			{
				checkErrors(glUniform2uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 3>(int location, std::size_t count, const std::array<unsigned int, 3> & value)
			{
				checkErrors(glUniform3uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 4>(int location, std::size_t count, const std::array<unsigned int, 4> & value)
			{
				checkErrors(glUniform4uiv(location, count, value.data()));
			}

			template <class T, unsigned int M, unsigned int N>
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 2, 2> & v)
			{
				checkErrors(glUniformMatrix2fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 3, 3> & v)
			{
				checkErrors(glUniformMatrix3fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 4, 4> & v)
			{
				checkErrors(glUniformMatrix4fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 2, 3> & v)
			{
				checkErrors(glUniformMatrix2x3fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 3, 2> & v)
			{
				checkErrors(glUniformMatrix3x2fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 2, 4> & v)
			{
				checkErrors(glUniformMatrix2x4fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 4, 2> & v)
			{
				checkErrors(glUniformMatrix4x2fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 3, 4> & v)
			{
				checkErrors(glUniformMatrix3x4fv(location, 1, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<float, 4, 3> & v)
			{
				checkErrors(glUniformMatrix4x3fv(location, 1, transpose, v.data()));
			}

			template <class T, unsigned int M, unsigned int N>
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 2> & v)
			{
				checkErrors(glUniformMatrix2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 3> & v)
			{
				checkErrors(glUniformMatrix3fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 4> & v)
			{
				checkErrors(glUniformMatrix4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 3> & v)
			{
				checkErrors(glUniformMatrix2x3fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 2> & v)
			{
				checkErrors(glUniformMatrix3x2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 4> & v)
			{
				checkErrors(glUniformMatrix2x4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 2> & v)
			{
				checkErrors(glUniformMatrix4x2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 4> & v)
			{
				checkErrors(glUniformMatrix3x4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 3> & v)
			{
				checkErrors(glUniformMatrix4x3fv(location, count, transpose, v.data()));
			}

			inline void OpenGL::uniformBlockBinding(Handle program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding)
			{
				checkErrors(glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding));
			}

			inline void OpenGL::transformFeedbackVaryings(Handle program, std::size_t count, const std::vector<std::string> & varyings, VaryingBufferMode bufferMode)
			{
				auto ptr = varyings[0].data();
				checkErrors(glTransformFeedbackVaryings(program, count, reinterpret_cast<const GLchar **>(&ptr), static_cast<GLenum>(bufferMode)));
			}

			inline auto OpenGL::getTransformFeedbackVarying(Handle program, unsigned int index) -> VaryingInfo
			{
				const auto bufSize = std::size_t{ 4096 };

				auto length = std::size_t{ 0 };
				auto result = VaryingInfo{};
				result.name.resize(bufSize);
				checkErrors(glGetTransformFeedbackVarying(program, index, bufSize, reinterpret_cast<GLsizei *>(&length), reinterpret_cast<GLsizei *>(&result.size), &result.type, result.name.data()));
				result.name = result.name.substr(0, length);

				return std::move(result);
			}

			inline void OpenGL::validateProgram(Handle program)
			{
				checkErrors(glValidateProgram(program));
			}

			inline auto OpenGL::getProgram(const Handle program, const ProgramParameter pname) -> std::vector<int>
			{
				auto result = std::vector<int>{};
				if (pname == ProgramParameter::COMPUTE_WORK_GROUP_SIZE) {
					result.resize(3);
					checkErrors(glGetProgramiv(static_cast<GLuint>(program), static_cast<GLenum>(pname), result.data()));
				}
				else {
					auto dummy = 0;
					checkErrors(glGetProgramiv(static_cast<GLuint>(program), static_cast<GLenum>(pname), &dummy));
					result.push_back(std::move(dummy));
				}
				return std::move(result);
			}

			inline void OpenGL::bindFragDataLocation(Handle program, unsigned int colorNumber, const std::string & name)
			{
				checkErrors(glBindFragDataLocation(program, colorNumber, name.data()));
			}

			inline auto OpenGL::getFragDataLocation(Handle program, const std::string & name) -> int
			{
				return checkErrors(glGetFragDataLocation(program, name.data()));
			}

			inline auto OpenGL::isShader(Handle shader) -> bool
			{
				return checkErrors(glIsShader(shader));
			}

			inline auto OpenGL::getShader(const Handle shader, const ShaderParameter pname) -> int
            {
				auto result = 0;
				checkErrors(glGetShaderiv(static_cast<GLuint>(shader), static_cast<GLenum>(pname), &result));
				return std::move(result);
            }

			inline auto OpenGL::getAttachedShaders(const Handle program) -> std::vector<Handle>
			{
				auto result = std::vector<Handle>{};
				auto size = 0;

				auto shaders = std::array<GLuint, 6>{};
				checkErrors(glGetAttachedShaders(static_cast<GLuint>(program), 6, &size, shaders.data()));
				for (auto i = 0; i < size; ++i) {
					result.push_back(std::move(static_cast<Handle>(shaders[i])));
				}

				return std::move(result);
			}

			inline auto OpenGL::getShaderInfoLog(const Handle shader) -> std::string
            {
                GLsizei size;
                char infoLog[512];
                checkErrors(glGetShaderInfoLog(static_cast<GLuint>(shader), 512, &size, static_cast<GLchar *>(infoLog)));
                return std::string(infoLog);
            }

            inline auto OpenGL::getShaderSource(Handle shader) -> std::string
			{
				const auto bufSize = std::size_t{ 16384 };

				auto length = std::size_t{ 0 };
				auto source = std::string(bufSize, '\0');
				checkErrors(glGetShaderSource(shader, bufSize, reinterpret_cast<GLsizei *>(&length), source.data()));
				source = source.substr(0, length);
				return std::move(source);
			}

			template <class T>
			inline auto OpenGL::getVertexAttrib([[maybe_unused]] Handle index, [[maybe_unused]] VertexAttribParameter pname) -> T
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template<>
			inline auto OpenGL::getVertexAttrib<double>(Handle index, VertexAttribParameter pname) -> double
			{
				auto params = 0.0;
				checkErrors(glGetVertexAttribdv(index, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template<>
			inline auto OpenGL::getVertexAttrib<float>(Handle index, VertexAttribParameter pname) -> float
			{
				auto params = 0.0f;
				checkErrors(glGetVertexAttribfv(index, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template<>
			inline auto OpenGL::getVertexAttrib<int>(Handle index, VertexAttribParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetVertexAttribiv(index, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			template<>
			inline auto OpenGL::getVertexAttrib<unsigned int>(Handle index, VertexAttribParameter pname) -> unsigned int
			{
				auto params = 0u;
				checkErrors(glGetVertexAttribIuiv(index, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getVertexAttribPointer(Handle index) -> void *
			{
				const auto pname = GL_VERTEX_ATTRIB_ARRAY_POINTER;

				void * pointer = nullptr;
				checkErrors(glGetVertexAttribPointerv(index, pname, &pointer));

				return std::move(pointer);
			}

			template <typename T>
			inline auto OpenGL::getUniform([[maybe_unused]] Handle program, [[maybe_unused]] int location) -> T
			{
				static_assert("No existing specialization for OpenGL::getUniform.");
			}

			template <>
			inline auto OpenGL::getUniform(Handle program, int location) -> float
			{
				auto params = 0.0f;
				checkErrors(glGetUniformfv(program, location, reinterpret_cast<GLfloat *>(&params)));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getUniform(Handle program, int location) -> int
			{
				auto params = 0;
				checkErrors(glGetUniformiv(program, location, reinterpret_cast<GLint *>(&params)));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getUniform(Handle program, int location) -> unsigned int
			{
				auto params = 0u;
				checkErrors(glGetUniformuiv(program, location, reinterpret_cast<GLuint *>(&params)));
				return std::move(params);
			}

			inline auto OpenGL::isProgram(Handle program) -> bool
			{
				return checkErrors(glIsProgram(program));
			}

            inline auto OpenGL::getProgramInfoLog(const Handle program) -> std::string
            {
                auto size = 0;
                auto infoLog = std::string(512, '\r');
                checkErrors(glGetProgramInfoLog(static_cast<GLuint>(program), 512, &size, infoLog.data()));
                return infoLog.substr(0, static_cast<std::size_t>(size));
            }

			inline auto OpenGL::getMultisample(Handle index) -> FloatVector2u
			{
				const auto pname = GL_SAMPLE_POSITION;

				auto val = FloatVector2u{};
				checkErrors(glGetMultisamplefv(pname, index, reinterpret_cast<GLfloat *>(val.data().data())));
				return std::move(val);
			}

			inline void OpenGL::pointSize(const float size) { checkErrors(glPointSize(size)) }

			inline void OpenGL::pointParameter(PointParameter pname, float param)
			{
				checkErrors(glPointParameterf(static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::pointParameter(PointParameter pname, int param)
			{
				checkErrors(glPointParameteri(static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::pointParameter(PointParameter pname, float & params)
			{
				checkErrors(glPointParameterfv(static_cast<GLenum>(pname), reinterpret_cast<const GLfloat *>(&params)));
			}

			inline void OpenGL::pointParameter(PointParameter pname, int & params)
			{
				checkErrors(glPointParameteriv(static_cast<GLenum>(pname), reinterpret_cast<const GLint *>(&params)));
			}

			inline void OpenGL::lineWidth(const float width) { checkErrors(glLineWidth(width)); }

			inline void OpenGL::frontFace(const FrontFaceMode mode)
			{
				checkErrors(glFrontFace(static_cast<GLenum>(mode)));
			}

			inline void OpenGL::cullFace(const CullFaceMode mode)
			{
				checkErrors(glCullFace(static_cast<GLenum>(mode)));
			}

			inline void OpenGL::polygonMode(const PolygonMode mode)
			{
				checkErrors(glPolygonMode(GL_FRONT_AND_BACK, static_cast<GLenum>(mode)));
			}

			inline void OpenGL::polygonOffset(float factor, float units)
			{
				checkErrors(glPolygonOffset(factor, units));
			}

			inline void OpenGL::pixelStore(PixelParameter pname, float param)
			{
				checkErrors(glPixelStoref(static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::pixelStore(PixelParameter pname, int param)
			{
				checkErrors(glPixelStorei(static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::activeTexture(const unsigned int texture)
			{
				if (static_cast<int>(texture) >= OpenGL::getInteger(Parameter::MAX_COMBINED_TEXTURE_IMAGE_UNITS)[0]) {
					throw std::runtime_error("This texture unit is not available ont this platform.");
				}
				checkErrors(glActiveTexture(static_cast<GLenum>(TextureUnit::TEXTURE0) + texture));
			}

			inline void OpenGL::texImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, PixelFormat format, PixelDataType type, const void * data)
			{
				checkErrors(glTexImage3D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLsizei>(depth), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::texImage2D(const TextureTypeTarget target, const unsigned int level, const PixelInternalFormat internalFormat, const std::size_t width, const std::size_t height, const PixelFormat format, const PixelDataType type, const void * data)
			{
				auto levelSec = (target == TextureTypeTarget::TEXTURE_RECTANGLE || target == TextureTypeTarget::PROXY_TEXTURE_RECTANGLE) ? 0 : level;
				checkErrors(glTexImage2D(static_cast<GLenum>(target), levelSec, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), static_cast<GLsizei>(height), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::texImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, std::size_t width, PixelFormat format, PixelDataType type, const void * data)
			{
				checkErrors(glTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::copyTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, int x, int y, std::size_t width, std::size_t height)
			{
				checkErrors(glCopyTexImage2D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), x, y, width, height, 0));
			}

			inline void OpenGL::copyTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, int x, int y, std::size_t width)
			{
				checkErrors(glCopyTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), x, y, width, 0));
			}

			inline void OpenGL::texSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, std::size_t  width, std::size_t  height, std::size_t depth, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLsizei>(depth), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::texSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, std::size_t width, std::size_t height, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::texSubImage1D(TargetTexture1D target, int level, int xoffset, std::size_t width, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage1D(static_cast<GLenum>(target), level, xoffset, static_cast<GLsizei>(width), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::copyTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, std::size_t width, std::size_t height)
			{
				checkErrors(glCopyTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, x, y, width, height));
			}

			inline void OpenGL::copyTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, int x, int y, std::size_t width, std::size_t height)
			{
				checkErrors(glCopyTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, x, y, width, height));
			}

			inline void OpenGL::copyTexSubImage1D(TargetTexture1D target, int level, int xoffset, int x, int y, std::size_t width)
			{
				checkErrors(glCopyTexSubImage1D(static_cast<GLenum>(target), level, xoffset, x, y, width));
			}

			inline void OpenGL::compressedTexImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage3D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, height, depth, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage2D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, height, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, std::size_t width, std::size_t height, std::size_t depth, PixelFormat format, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, std::size_t width, std::size_t height, PixelFormat format, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage1D(TargetTexture1D target, int level, int xoffset, std::size_t width, PixelFormat format, std::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage1D(static_cast<GLenum>(target), level, xoffset, width, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::texImage3DMultisample(TargetTextureMultisample target, std::size_t samples, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, bool fixedSamplelLocations)
			{
				checkErrors(glTexImage3DMultisample(static_cast<GLenum>(target), samples, static_cast<unsigned int>(internalFormat), width, height, depth, fixedSamplelLocations));
			}

			inline void OpenGL::texImage2DMultisample(TargetTextureMultisample target, std::size_t samples, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, bool fixedSamplelLocations)
			{
				checkErrors(glTexImage2DMultisample(static_cast<GLenum>(target), samples, static_cast<unsigned int>(internalFormat), width, height, fixedSamplelLocations));
			}

			inline void OpenGL::texBuffer(PixelInternalFormat internalFormat, Handle buffer)
			{
				const auto target = GL_TEXTURE_BUFFER;

				checkErrors(glTexBuffer(target, static_cast<unsigned int>(internalFormat), buffer));
			}

			template <class T> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const T param)
			{
				static_assert("No existing specialization for OpenGL::texParameter");
			}

			template <> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const float param)
			{
				checkErrors(glTexParameterf(static_cast<GLenum>(target), static_cast<GLenum>(pname), param));
			}

			template <> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const int param)
			{
				checkErrors(glTexParameteri(static_cast<GLenum>(target), static_cast<GLenum>(pname), param));
			}

			template <class T> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<T> & param)
			{
				static_assert("No existing specialization for OpenGL::texParameter");
			}

			template <>
			inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<float> & param)
			{
				checkErrors(glTexParameterfv(static_cast<GLenum>(target), static_cast<GLenum>(pname), param.data()));
			}

			template <>
			inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<int> & param)
			{
				checkErrors(glTexParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), param.data()));
			}

			template <>
			inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<unsigned int> & param)
			{
				checkErrors(glTexParameterIuiv(static_cast<GLenum>(target), static_cast<GLenum>(pname), param.data()));
			}

			inline void OpenGL::generateMipmap(const MipmapTarget target)
			{
				checkErrors(glGenerateMipmap(static_cast<GLenum>(target)));
			}

			inline void OpenGL::bindTexture(const TextureTarget target, const Handle texture)
			{
				checkErrors(glBindTexture(static_cast<GLenum>(target), texture));
			}

			inline void OpenGL::deleteTextures(const std::vector<Handle> & textures)
			{
				checkErrors(glDeleteTextures(textures.size(), textures.data()));
			}

			inline auto OpenGL::genTexture() -> Handle
			{
				auto handle = NULL_HANDLE;
				checkErrors(glGenTextures(1, &handle));
				return std::move(handle);
			}

			inline auto OpenGL::genTextures(const unsigned int n) -> std::vector<Handle>
			{
				auto handles = std::vector<Handle>(n, NULL_HANDLE);
				checkErrors(glGenTextures(n, &handles.back() - n + 1));

				return std::move(handles);
			}

			template <class T>
			inline auto OpenGL::getTexParameter(TextureTarget target, TextureParameter pname) -> std::vector<T>
			{
				throw std::runtime_error("OpenGL::getTexParameter method is not defined for this type");
			}

			template <>
			inline auto OpenGL::getTexParameter<float>(TextureTarget target, TextureParameter pname) -> std::vector<float>
			{
				auto params = std::vector<float>{};
				checkErrors(glGetTexParameterfv(static_cast<GLenum>(target), static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTexParameter<int>(TextureTarget target, TextureParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetTexParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTexParameter<unsigned int>(TextureTarget target, TextureParameter pname) -> std::vector<unsigned int>
			{
				auto params = std::vector<unsigned int>{};
				checkErrors(glGetTexParameterIuiv(static_cast<GLenum>(target), static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <class T>
			inline auto OpenGL::getTexLevelParameter(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<T>
			{
				throw std::runtime_error("OpenGL::getTexLevelParameter method is not defined for this type");
			}

			template <> 
			inline auto OpenGL::getTexLevelParameter<float>(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<float>
			{
				auto params = std::vector<float>{};
				checkErrors(glGetTexLevelParameterfv(static_cast<GLenum>(target), level, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTexLevelParameter<int>(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetTexLevelParameteriv(static_cast<GLenum>(target), level, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			inline auto OpenGL::getTexImage(TextureTarget target, int level, PixelFormat format, DataType type) -> void *
			{
				auto pixels = static_cast<void *>(nullptr); // TODO: should be not working.
				checkErrors(glGetTexImage(static_cast<GLenum>(target), level, static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
				return std::move(pixels);
			}

			inline auto OpenGL::getCompressedTexImage(TextureTarget target, int level) -> void *
			{
				auto pixels = static_cast<void *>(nullptr); // TODO: should be not working.
				checkErrors(glGetCompressedTexImage(static_cast<GLenum>(target), level, pixels));
				return std::move(pixels);
			}
			
			inline auto OpenGL::isTexture(Handle texture) -> bool
			{
				return checkErrors(glIsTexture(texture));
			}

			inline void OpenGL::hint(Hint target, HintMode mode)
			{
				checkErrors(glHint(static_cast<GLenum>(target), static_cast<GLenum>(mode)));
			}

			inline auto OpenGL::readPixels(int x, int y, std::size_t width, std::size_t height, PixelFormat format, DataType type) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<float>(width * height).data()); // TODO: should be not working.
				checkErrors(glReadPixels(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
				return std::move(pixels);
			}
			
			inline void OpenGL::readBuffer(ColorBuffer mode)
			{
				checkErrors(glReadBuffer(static_cast<GLenum>(mode)));
			}
			
			inline void OpenGL::blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, Bitfield mask, ImageFilter filter)
			{
				checkErrors(glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, static_cast<GLbitfield>(mask), static_cast<GLenum>(filter)));
			}

			inline void OpenGL::scissor(const int x, const int y, const unsigned int width, const unsigned int height)
			{
				checkErrors(glScissor(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}

			inline void OpenGL::sampleCoverage(float value, bool invert)
			{
				checkErrors(glSampleCoverage(value, invert));
			}

			inline void OpenGL::sampleMask(unsigned int maskNumber, std::bitset<32> mask)
			{
				checkErrors(glSampleMaski(maskNumber, static_cast<GLbitfield>(mask.to_ulong())));
			}

			inline void OpenGL::stencilFunc(DepthFunctionCondition func, int ref, unsigned int mask)
			{
				checkErrors(glStencilFunc(static_cast<GLenum>(func), ref, mask));
			}

			inline void OpenGL::stencilFuncSeparate(CullFaceMode face, DepthFunctionCondition func, int ref, unsigned int mask)
			{
				checkErrors(glStencilFuncSeparate(static_cast<GLenum>(face), static_cast<GLenum>(func), ref, mask));
			}

			inline void OpenGL::stencilOp(TestCondition sfail, TestCondition dpfail, TestCondition dppass)
			{
				checkErrors(glStencilOp(static_cast<GLenum>(sfail), static_cast<GLenum>(dpfail), static_cast<GLenum>(dppass)));
			}

			inline void OpenGL::stencilOpSeparate(CullFaceMode face, TestCondition sfail, TestCondition dpfail, TestCondition dppass)
			{
				checkErrors(glStencilOpSeparate(static_cast<GLenum>(face), static_cast<GLenum>(sfail), static_cast<GLenum>(dpfail), static_cast<GLenum>(dppass)));
			}

			inline void OpenGL::depthFunc(const DepthFunctionCondition condition)
			{
				checkErrors(glDepthFunc(static_cast<GLenum>(condition)));
			}

			inline void OpenGL::blendEquation(BlendEquationMode mode)
			{
				checkErrors(glBlendEquation(static_cast<GLenum>(mode)));
			}

			inline void OpenGL::blendEquationSeparate(BlendEquationMode modeRGB, BlendEquationMode modeAlpha)
			{
				checkErrors(glBlendEquationSeparate(static_cast<GLenum>(modeRGB), static_cast<GLenum>(modeAlpha)));
			}

			inline void OpenGL::blendFuncSeparate(BlendingFactor srcRGB, BlendingFactor dstRGB, BlendingFactor srcAlpha, BlendingFactor dstAlpha)
			{
				checkErrors(glBlendFuncSeparate(static_cast<GLenum>(srcRGB), static_cast<GLenum>(dstRGB), static_cast<GLenum>(srcAlpha), static_cast<GLenum>(dstAlpha)));
			}

			inline void OpenGL::blendFunc(const BlendingFactor sfactor, const BlendingFactor dfactor)
			{
				checkErrors(glBlendFunc(static_cast<GLenum>(sfactor), static_cast<GLenum>(dfactor)));
			}

			inline void OpenGL::blendColor(float red, float green, float blue, float alpha)
			{
				checkErrors(glBlendColor(red, green, blue, alpha));
			}
			
			inline void OpenGL::logicOp(LogicalOperation opcode)
			{
				checkErrors(glLogicOp(static_cast<GLenum>(opcode)));
			}

			inline void OpenGL::drawBuffer(ColorBuffer buf)
			{
				checkErrors(glDrawBuffer(static_cast<GLenum>(buf)));
			}

			inline void OpenGL::drawBuffers(const std::vector<ColorBuffer> & bufs)
			{
				checkErrors(glDrawBuffers(bufs.size(), reinterpret_cast<const GLenum *>(bufs.data())));
			}

			inline void OpenGL::colorMask(bool red, bool green, bool blue, bool alpha)
			{
				checkErrors(glColorMask(red, green, blue, alpha));
			}

			inline void OpenGL::colorMask(unsigned int buf, bool red, bool green, bool blue, bool alpha)
			{
				checkErrors(glColorMaski(buf, red, green, blue, alpha));
			}

			inline void OpenGL::depthMask(bool flag)
			{
				checkErrors(glDepthMask(flag));
			}

			inline void OpenGL::stencilMask(unsigned int mask)
			{
				checkErrors(glStencilMask(mask));
			}

			inline void OpenGL::stencilMaskSeparate(CullFaceMode face, unsigned int mask)
			{
				checkErrors(glStencilMaskSeparate(static_cast<GLenum>(face), mask));
			}

			inline void OpenGL::clear(const Bitfield mask)
			{
				checkErrors(glClear(GLbitfield(mask)));
			}

			inline void OpenGL::clearColor(const float r, const float g, const float b, const float a)
			{
				checkErrors(glClearColor(r, g, b, a));
			}

			inline void OpenGL::clearDepth(double depth)
			{
				checkErrors(glClearDepth(depth));
			}

			inline void OpenGL::clearStencil(int s)
			{
				checkErrors(glClearStencil(s));
			}

			static inline void OpenGL::clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<int> & value)
			{
				checkErrors(glClearBufferiv(static_cast<GLenum>(buffer), drawbuffer, value.data()));
			}

			static inline void OpenGL::clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<unsigned int> & value)
			{
				checkErrors(glClearBufferuiv(static_cast<GLenum>(buffer), drawbuffer, value.data()));
			}

			static inline void OpenGL::clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<float> & value)
			{
				checkErrors(glClearBufferfv(static_cast<GLenum>(buffer), drawbuffer, value.data()));
			}

			static inline void OpenGL::clearBuffer(GLenum buffer, int drawbuffer, float depth, int stencil)
			{
				checkErrors(glClearBufferfi(static_cast<GLenum>(buffer), drawbuffer, depth, stencil));
			}

			inline void OpenGL::bindFramebuffer(FramebufferTarget target, Handle framebuffer)
			{
				checkErrors(glBindFramebuffer(static_cast<GLenum>(target), framebuffer));
			}

			inline void OpenGL::deleteFramebuffers(std::vector<Handle> & framebuffers)
			{
				checkErrors(glDeleteFramebuffers(static_cast<GLsizei>(framebuffers.size()), reinterpret_cast<GLuint *>(framebuffers.data())));
			}
			
			inline auto OpenGL::genFramebuffers(std::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glGenFramebuffers(n, reinterpret_cast<GLuint *>(ids.data())));
				return std::move(ids);
			}

			inline void OpenGL::bindRenderbuffer(Handle renderbuffer)
			{
				const auto target = GL_RENDERBUFFER;
				checkErrors(glBindRenderbuffer(target, renderbuffer));
			}

			inline void OpenGL::deleteRenderbuffers(std::vector<Handle> & renderbuffers)
			{
				checkErrors(glDeleteRenderbuffers(static_cast<GLsizei>(renderbuffers.size()), reinterpret_cast<GLuint *>(renderbuffers.data())));
			}

			inline auto OpenGL::genRenderbuffers(std::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glGenRenderbuffers(n, reinterpret_cast<GLuint *>(ids.data())));
				return std::move(ids);
			}

			inline void OpenGL::renderbufferStorageMultisample(std::size_t samples, PixelFormat internalformat, std::size_t width, std::size_t height)
			{
				const auto target = GL_RENDERBUFFER;
				checkErrors(glRenderbufferStorageMultisample(target, static_cast<GLsizei>(samples), static_cast<GLenum>(internalformat), static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}
			
			inline void OpenGL::renderbufferStorage(PixelFormat internalformat, std::size_t width, std::size_t height)
			{
				const auto target = GL_RENDERBUFFER;
				checkErrors(glRenderbufferStorage(target, static_cast<GLenum>(internalformat), static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}

			inline void OpenGL::framebufferRenderbuffer(FramebufferTarget target, FramebufferAttachment attachment, unsigned int renderbuffer)
			{
				const auto renderbuffertarget = GL_RENDERBUFFER;
				checkErrors(glFramebufferRenderbuffer(static_cast<GLenum>(target), static_cast<GLenum>(attachment), renderbuffertarget, renderbuffer));
			}

			inline void OpenGL::framebufferTexture(FramebufferTarget target, FramebufferAttachment attachment, Handle texture, int level)
			{
				checkErrors(glFramebufferTexture(static_cast<GLenum>(target), static_cast<GLenum>(attachment), texture, level));
			}

			inline void OpenGL::framebufferTexture1D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level)
			{
				checkErrors(glFramebufferTexture1D(static_cast<GLenum>(target), static_cast<GLenum>(attachment), static_cast<GLenum>(textarget), texture, level));
			}

			inline void OpenGL::framebufferTexture2D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level)
			{
				checkErrors(glFramebufferTexture2D(static_cast<GLenum>(target), static_cast<GLenum>(attachment), static_cast<GLenum>(textarget), texture, level));
			}
			
			inline void OpenGL::framebufferTexture3D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level, int layer)
			{
				checkErrors(glFramebufferTexture3D(static_cast<GLenum>(target), static_cast<GLenum>(attachment), static_cast<GLenum>(textarget), texture, level, layer));
			}
			
			inline void OpenGL::framebufferTextureLayer(FramebufferTarget target, FramebufferAttachment attachment, Handle texture, int level, int layer)
			{
				checkErrors(glFramebufferTextureLayer(static_cast<GLenum>(target), static_cast<GLenum>(attachment), texture, level, layer));
			}
			
			inline auto OpenGL::checkFramebufferStatus(FramebufferTarget target) -> FramebufferStatus
			{
				auto result = checkErrors(glCheckFramebufferStatus(static_cast<GLenum>(target)));
				return std::move(static_cast<FramebufferStatus>(result));
			}

			inline auto OpenGL::isFramebuffer(Handle framebuffer) -> bool
			{
				return checkErrors(glIsFramebuffer(framebuffer));
			}

			inline auto OpenGL::getFramebufferAttachmentParameter(FramebufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetFramebufferAttachmentParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(attachment), static_cast<GLenum>(pname), &params));
				return std::move(params);
			}
			
			inline auto OpenGL::isRenderbuffer(Handle renderbuffer) -> bool
			{
				return checkErrors(isRenderbuffer(renderbuffer));
			}

			inline auto OpenGL::getRenderbufferParameter(RenderbufferParameter pname) -> int
			{
				const auto target = GL_RENDERBUFFER;
				auto params = 0;
				checkErrors(glGetRenderbufferParameteriv(target, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline void OpenGL::flush()
			{
				checkErrors(glFlush());
			}

			inline void OpenGL::finish()
			{
				checkErrors(glFinish());
			}

			inline auto OpenGL::fenceSync() -> Sync
			{
				const auto condition = GL_SYNC_GPU_COMMANDS_COMPLETE;
				const auto flags = 0;
				return checkErrors(glFenceSync(condition, flags));
			}

			inline void OpenGL::deleteSync(Sync sync)
			{
				checkErrors(glDeleteSync(sync));
			}

			inline auto OpenGL::clientWaitSync(Sync sync, const std::bitset<8> & flags, std::uint64_t timeout) -> SyncStatus
			{
				auto result = checkErrors(glClientWaitSync(sync, flags.to_ulong(), timeout));
				return std::move(static_cast<SyncStatus>(result));
			}

			inline void OpenGL::waitSync(Sync sync, const std::bitset<8> & flags)
			{
				const auto timeout = GL_TIMEOUT_IGNORED;
				checkErrors(glWaitSync(sync, flags.to_ulong(), timeout));
			}

			inline auto OpenGL::getSync(Sync sync, SyncParameter pname) -> int
			{
				const auto bufSize = GLsizei{ 1 };
				auto length = GLsizei{};
				auto values = 0;
				checkErrors(glGetSynciv(sync, static_cast<GLenum>(pname), bufSize, &length, &values));
				return std::move(values);
			}
			
			inline auto OpenGL::isSync(Sync sync) -> bool
			{
				return checkErrors(glIsSync(sync));
			}

			static inline auto OpenGL::getBoolean(Parameter pname) -> std::vector<bool>
			{
				const auto maxSize = std::size_t{ 16 };
				auto data = std::vector<unsigned char>(maxSize);
				checkErrors(glGetBooleanv(static_cast<GLenum>(pname), reinterpret_cast<GLboolean *>(data.data())));
				return std::vector<bool>(data.begin(), data.end());
			}

			static inline auto OpenGL::getDouble(Parameter pname) -> std::vector<double>
			{
				const auto maxSize = std::size_t{ 16 };
				auto data = std::vector<double>(maxSize);
				checkErrors(glGetDoublev(static_cast<GLenum>(pname), reinterpret_cast<GLdouble *>(data.data())));
				return std::move(data);
			}

			static inline auto OpenGL::getFloat(Parameter pname) -> std::vector<float>
			{
				const auto maxSize = std::size_t{ 16 };
				auto data = std::vector<float>(maxSize);
				checkErrors(glGetFloatv(static_cast<GLenum>(pname), reinterpret_cast<GLfloat *>(data.data())));
				return std::move(data);
			}

			inline auto OpenGL::getInteger(Parameter pname) -> std::vector<int>
			{
				const auto maxSize = std::size_t{ 16 };
				auto data = std::vector<int>(maxSize);
				checkErrors(glGetIntegerv(static_cast<GLenum>(pname), data.data()));
				return std::move(data);
			}

			inline auto OpenGL::getInteger64(Parameter pname) -> std::vector<std::int64_t>
			{
				const auto maxSize = std::size_t{ 16 };
				auto data = std::vector<std::int64_t>(maxSize);
				checkErrors(glGetInteger64v(static_cast<GLenum>(pname), data.data()));
				return std::move(data);
			}

			inline auto OpenGL::getBoolean(Parameter target, unsigned int index) -> bool
			{
				auto data = false;
				checkErrors(glGetBooleani_v(static_cast<GLenum>(target), index, reinterpret_cast<GLboolean *>(&data)));
				return std::move(data);
			}

			inline auto OpenGL::getInteger(Parameter target, unsigned int index) -> int
			{
				auto data = 0;
				checkErrors(glGetIntegeri_v(static_cast<GLenum>(target), index, &data));
				return std::move(data);
			}

			inline auto OpenGL::getInteger64(Parameter target, unsigned int index) -> std::int64_t
			{
				auto data = std::int64_t{ 0 };
				checkErrors(glGetInteger64i_v(static_cast<GLenum>(target), index, &data));
				return std::move(data);
			}

			inline auto OpenGL::isEnabled(Capability cap) -> bool
			{
				return checkErrors(glIsEnabled(static_cast<GLenum>(cap)));
			}

			inline auto OpenGL::isEnabled(Capability cap, unsigned int index) -> bool
			{
				return checkErrors(glIsEnabledi(static_cast<GLenum>(cap), index));
			}

			inline auto OpenGL::getString(InfoGL parameter) -> std::string
			{
				const auto tmp = checkErrors(glGetString(static_cast<GLenum>(parameter)));
				return std::string(reinterpret_cast<const char *>(tmp));
			}

			inline auto OpenGL::getString(InfoGL name, unsigned int index) -> std::string
			{
				const auto tmp = checkErrors(glGetStringi(static_cast<GLenum>(name), index));
				return std::string(reinterpret_cast<const char *>(tmp));
			}

			inline void OpenGL::queryCounter(Handle id)
			{
				const auto target = GL_TIMESTAMP;
				checkErrors(glQueryCounter(id, target));
			}

			inline auto OpenGL::genSamplers(std::size_t n) -> std::vector<Handle>
			{
				auto samplers = std::vector<Handle>{};
				checkErrors(glGenSamplers(static_cast<GLsizei>(n), samplers.data()));
				return std::move(samplers);
			}

			inline void OpenGL::bindSampler(Handle unit, Handle sampler)
			{
				checkErrors(glBindSampler(unit, sampler));
			}

			inline void OpenGL::samplerParameter(Handle sampler, SamplerParameter pname, float param)
			{
				checkErrors(glSamplerParameterf(sampler, static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::samplerParameter(Handle sampler, SamplerParameter pname, int param)
			{
				checkErrors(glSamplerParameteri(sampler, static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<float> & params)
			{
				checkErrors(glSamplerParameterfv(sampler, static_cast<GLenum>(pname), params.data()));
			}

			inline void OpenGL::samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<int> & params)
			{
				checkErrors(glSamplerParameteriv(sampler, static_cast<GLenum>(pname), params.data()));
			}

			inline void OpenGL::samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<unsigned int> & params)
			{
				checkErrors(glSamplerParameterIuiv(sampler, static_cast<GLenum>(pname), params.data()));
			}

			inline void OpenGL::deleteSamplers(const std::vector<Handle> & samplers)
			{
				checkErrors(glDeleteSamplers(samplers.size(), samplers.data()));
			}
			
			inline auto OpenGL::isSampler(Handle id) -> bool
			{
				return checkErrors(glIsSampler(id));
			}

			template <class T>
			inline auto OpenGL::getSamplerParameter(Handle sampler, SamplerParameter pname) -> std::vector<T>
			{
				throw std::runtime_error("OpenGL::getSamplerParameter method is not defined for this type");
			}

			template <> inline auto OpenGL::getSamplerParameter<float>(Handle sampler, SamplerParameter pname) -> std::vector<float>
			{
				const auto maxSize = std::size_t{ 16 };
				auto params = std::vector<float>(maxSize);
				checkErrors(glGetSamplerParameterfv(sampler, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <> inline auto OpenGL::getSamplerParameter<int>(Handle sampler, SamplerParameter pname) -> std::vector<int>
			{
				const auto maxSize = std::size_t{ 16 };
				auto params = std::vector<int>(maxSize);
				checkErrors(glGetSamplerParameteriv(sampler, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <> inline auto OpenGL::getSamplerParameter<unsigned int>(Handle sampler, SamplerParameter pname) -> std::vector<unsigned int>
			{
				const auto maxSize = std::size_t{ 16 };
				auto params = std::vector<unsigned int>(maxSize);
				checkErrors(glGetSamplerParameterIuiv(sampler, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}
			
			inline void OpenGL::bindFragDataLocationIndexed(Handle program, Handle colorNumber, Handle index, const std::string & name)
			{
				checkErrors(glBindFragDataLocationIndexed(program, colorNumber, index, name.data()))
			}
			
			inline auto OpenGL::getFragDataIndex(Handle program, const std::string & name) -> int
			{
				return checkErrors(glGetFragDataIndex(program, name.data()));
			}

			inline void OpenGL::vertexAttribDivisor(const int index, const std::size_t divisor)
			{
				checkErrors(glVertexAttribDivisor(static_cast<GLuint>(index), static_cast<GLuint>(divisor)));
			}

			template <>
			inline auto OpenGL::getUniform(Handle program, int location) -> double
			{
				auto params = 0.0;
				checkErrors(glGetUniformdv(program, location, reinterpret_cast<GLdouble *>(&params)));
				return std::move(params);
			}

			inline void OpenGL::blendEquation(Handle buf, BlendEquationMode mode)
			{
				checkErrors(glBlendEquationi(buf, static_cast<GLenum>(mode)));
			}
			
			inline void OpenGL::blendEquationSeparate(Handle buf, BlendEquationMode modeRGB, BlendEquationMode modeAlpha)
			{
				checkErrors(glBlendEquationSeparatei(buf, static_cast<GLenum>(modeRGB), static_cast<GLenum>(modeAlpha)));
			}

			inline void OpenGL::blendFuncSeparate(Handle buf, BlendingFactor srcRGB, BlendingFactor dstRGB, BlendingFactor srcAlpha, BlendingFactor dstAlpha)
			{
				checkErrors(glBlendFuncSeparatei(buf, static_cast<GLenum>(srcRGB), static_cast<GLenum>(dstRGB), static_cast<GLenum>(srcAlpha), static_cast<GLenum>(dstAlpha)));
			}

			inline void OpenGL::blendFunc(Handle buf, const BlendingFactor sfactor, const BlendingFactor dfactor)
			{
				checkErrors(glBlendFunci(buf, static_cast<GLenum>(sfactor), static_cast<GLenum>(dfactor)));
			}

			inline void OpenGL::drawElementsIndirect(PrimitiveMode mode, DrawElementsIndirectCommand & indirect)
			{
				const auto type = GL_INT;
				checkErrors(glDrawElementsIndirect(static_cast<GLenum>(mode), type, reinterpret_cast<const GLvoid *>(&indirect)));
			}

			inline void OpenGL::beginQueryIndexed(QueryObjectType target, Handle index, Handle id)
			{
				checkErrors(glBeginQueryIndexed(static_cast<GLenum>(target), index, id));
			}

			inline void OpenGL::endQueryIndexed(QueryObjectType target, Handle index)
			{
				checkErrors(glEndQueryIndexed(static_cast<GLenum>(target), index));
			}

			inline auto OpenGL::getQueryIndexed(QueryObjectType target, Handle index, QueryObjectTargetParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetQueryIndexediv(static_cast<GLenum>(target), index, static_cast<GLenum>(pname), reinterpret_cast<GLint *>(&params)));
				return std::move(params);
			}

			inline auto OpenGL::getSubroutineUniformLocation(Handle program, ShaderType shadertype, const std::string & name) -> int
			{
				return checkErrors(glGetSubroutineUniformLocation(program, static_cast<GLenum>(shadertype), name.data()));
			}

			inline auto OpenGL::getSubroutineIndex(Handle program, ShaderType shadertype, const std::string & name) -> Handle
			{
				return checkErrors(glGetSubroutineIndex(program, static_cast<GLenum>(shadertype), name.data()));
			}

			inline auto OpenGL::getActiveSubroutineName(Handle program, ShaderType shadertype, Handle index) -> std::string
			{
				const auto bufsize = std::size_t{ 4096 };
				auto length = std::size_t{ 0 };
				auto name = std::string(bufsize, '\0');
				checkErrors(glGetActiveSubroutineName(program, static_cast<GLenum>(shadertype), index, static_cast<GLsizei>(bufsize), reinterpret_cast<GLsizei *>(&length), name.data()));
				return std::move(name);
			}

			inline auto OpenGL::getActiveSubroutineUniformName(Handle program, ShaderType shadertype, Handle index) -> std::string
			{
				const auto bufsize = std::size_t{ 4096 };
				auto length = std::size_t{ 0 };
				auto name = std::string(bufsize, '\0');
				checkErrors(glGetActiveSubroutineUniformName(program, static_cast<GLenum>(shadertype), index, static_cast<GLsizei>(bufsize), reinterpret_cast<GLsizei *>(&length), name.data()));
				return std::move(name);
			}

			inline auto OpenGL::getActiveSubroutineUniform(Handle program, ShaderType shadertype, Handle index, ShaderSubroutineUniformParameter pname) -> std::vector<int>
			{
				const auto maxSize = 512;
				auto values = std::vector<int>(maxSize);
				checkErrors(glGetActiveSubroutineUniformiv(program, static_cast<GLenum>(shadertype), index, static_cast<GLenum>(pname), values.data()));
				return std::move(values);
			}

			inline void OpenGL::uniformSubroutines(ShaderType shadertype, const std::vector<unsigned int> & indices)
			{
				checkErrors(glUniformSubroutinesuiv(static_cast<GLenum>(shadertype), indices.size(), indices.data()));
			}

			inline auto OpenGL::getUniformSubroutine(ShaderType shadertype, int location) -> std::vector<unsigned int>
			{
				const auto maxSize = 512;
				auto values = std::vector<unsigned int>(maxSize);
				checkErrors(glGetUniformSubroutineuiv(static_cast<GLenum>(shadertype), location, values.data()));
				return std::move(values);
			}

			inline auto OpenGL::getProgramStage(Handle program, ShaderType shadertype, ShaderSubroutineParameter pname) -> int
			{
				auto values = 0;
				checkErrors(glGetProgramStageiv(program, static_cast<GLenum>(shadertype), static_cast<GLenum>(pname), &values));
				return std::move(values);
			}

			inline void OpenGL::patchParameter(PatchParameter pname, int value)
			{
				checkErrors(glPatchParameteri(static_cast<GLenum>(pname), value));
			}

			inline void OpenGL::patchParameter(PatchParameter pname, const std::vector<float> & values)
			{
				checkErrors(glPatchParameterfv(static_cast<GLenum>(pname), values.data()));
			}

			inline void OpenGL::drawArraysIndirect(PrimitiveMode mode, DrawArraysIndirectCommand & indirect)
			{
				checkErrors(glDrawArraysIndirect(static_cast<GLenum>(mode), reinterpret_cast<const void *>(&indirect)));
			}

			inline auto OpenGL::genTransformFeedbacks(std::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glGenTransformFeedbacks(static_cast<GLsizei>(n), ids.data()));
				return std::move(ids);
			}

			inline void OpenGL::deleteTransformFeedbacks(const std::vector<Handle> & ids)
			{
				checkErrors(glDeleteTransformFeedbacks(ids.size(), ids.data()));
			}

			inline auto OpenGL::isTransformFeedback(Handle id) -> bool
			{
				return checkErrors(glIsTransformFeedback(id));
			}

			inline void OpenGL::bindTransformFeedback(Handle id)
			{
				const auto target = GL_TRANSFORM_FEEDBACK;
				checkErrors(glBindTransformFeedback(target, id));
			}

			inline void OpenGL::pauseTransformFeedback()
			{
				checkErrors(glPauseTransformFeedback());
			}

			inline void OpenGL::resumeTransformFeedback()
			{
				checkErrors(glResumeTransformFeedback());
			}

			inline void OpenGL::drawTransformFeedback(PrimitiveMode mode, Handle id)
			{
				checkErrors(glDrawTransformFeedback(static_cast<GLenum>(mode), id));
			}

			inline void OpenGL::drawTransformFeedbackStream(PrimitiveMode mode, Handle id, Handle stream)
			{
				checkErrors(glDrawTransformFeedbackStream(static_cast<GLenum>(mode), id, stream));
			}

			inline void OpenGL::minSampleShading(float value)
			{
				checkErrors(glMinSampleShading(value));
			}

			//	inline void OpenGL::vertexAttribL1d(unsigned int /*index*/, double /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL2d(unsigned int /*index*/, double /*v0*/, double /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL3d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL4d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/, double /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL1dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL2dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL3dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL4dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribLPointer(unsigned int /*index*/, int /*size*/, GLenum /*type*/, GLsizei /*stride*/, const void * /*pointer*/) { static_assert(false, "Not implemented yet."); }
			
			inline void OpenGL::depthRange(float nearVal, float farVal)
			{
				checkErrors(glDepthRangef(nearVal, farVal));
			}

			//	inline void OpenGL::getVertexAttribLdv(unsigned int /*index*/, GLenum /*pname*/, double * /*params*/) { static_assert(false, "Not implemented yet."); }
			
			inline void OpenGL::clearDepth(float depth)
			{
				checkErrors(glClearDepth(depth));
			}

			//	inline void OpenGL::getFloati_v(GLenum /*target*/, unsigned int /*index*/, float * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getDoublei_v(GLenum /*target*/, unsigned int /*index*/, double * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::shaderBinary(GLsizei /*count*/, const unsigned int * /*shaders*/, GLenum /*binaryFormat*/, const void * /*binary*/, GLsizei /*length*/) { static_assert(false, "Not implemented yet."); }
			
			inline void OpenGL::releaseShaderCompiler()
			{
				checkErrors(glReleaseShaderCompiler());
			}

			//	inline unsigned int OpenGL::createShaderProgramv(GLenum /*type*/, GLsizei /*count*/, const char ** /*strings*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programParameteri(unsigned int /*program*/, GLenum /*pname*/, int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genProgramPipelines(GLsizei /*n*/, unsigned int * /*pipelines*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteProgramPipelines(GLsizei /*n*/, const unsigned int * /*pipelines*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isProgramPipeline(unsigned int /*pipeline*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindProgramPipeline(unsigned int /*pipeline*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::useProgramStages(unsigned int /*pipeline*/, GLbitfield /*stages*/, unsigned int /*program*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::activeShaderProgram(unsigned int /*pipeline*/, unsigned int /*program*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramBinary(unsigned int /*program*/, GLsizei /*bufsize*/, GLsizei * /*length*/, GLenum * /*binaryFormat*/, void * /*binary*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programBinary(unsigned int /*program*/, GLenum /*binaryFormat*/, const void * /*binary*/, GLsizei /*length*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1f(unsigned int /*program*/, int /*location*/, float /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2f(unsigned int /*program*/, int /*location*/, float /*v0*/, float /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3f(unsigned int /*program*/, int /*location*/, float /*v0*/, float /*v1*/, float /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4f(unsigned int /*program*/, int /*location*/, float /*v0*/, float /*v1*/, float /*v2*/, float /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1i(unsigned int /*program*/, int /*location*/, int /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2i(unsigned int /*program*/, int /*location*/, int /*v0*/, int /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3i(unsigned int /*program*/, int /*location*/, int /*v0*/, int /*v1*/, int /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4i(unsigned int /*program*/, int /*location*/, int /*v0*/, int /*v1*/, int /*v2*/, int /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1ui(unsigned int /*program*/, int /*location*/, unsigned int /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2ui(unsigned int /*program*/, int /*location*/, int /*v0*/, unsigned int /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3ui(unsigned int /*program*/, int /*location*/, int /*v0*/, int /*v1*/, unsigned int /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4ui(unsigned int /*program*/, int /*location*/, int /*v0*/, int /*v1*/, int /*v2*/, unsigned int /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1iv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2iv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3iv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4iv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform1uiv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform2uiv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform3uiv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniform4uiv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix2fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix3fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix4fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix2x3fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix3x2fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix2x4fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix4x2fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix3x4fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::programUniformMatrix4x3fv(unsigned int /*program*/, int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramPipelineiv(unsigned int /*pipeline*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramPipelineInfoLog(unsigned int /*pipeline*/, GLsizei /*bufSize*/, GLsizei * /*length*/, char * /*infoLog*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getShaderPrecisionFormat(GLenum /*shaderType*/, GLenum /*precisionType*/, int * /*range*/, int * /*precision*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::validateProgramPipeline(unsigned int /*pipeline*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::depthRangeArrayv(unsigned int /*first*/, GLsizei /*count*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::depthRangeIndexed(unsigned int /*index*/, double /*nearVal*/, double /*farVal*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::viewportArrayv(unsigned int /*first*/, GLsizei /*count*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::viewportIndexedf(unsigned int /*index*/, float /*x*/, float /*y*/, float /*w*/, float /*h*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::viewportIndexedfv(unsigned int /*index*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::scissorArrayv(unsigned int /*first*/, GLsizei /*count*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::scissorIndexed(unsigned int /*index*/, int /*left*/, int /*bottom*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::scissorIndexedv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::getActiveAtomicCounterBufferiv(unsigned int /*program*/, unsigned int /*bufferIndex*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::memoryBarrier(GLbitfield /*barriers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texStorage1D(GLenum /*target*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texStorage2D(GLenum /*target*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texStorage3D(GLenum /*target*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindImageTexture(unsigned int /*unit*/, unsigned int /*texture*/, int /*level*/, bool /*layered*/, int /*layer*/, GLenum /*access*/, GLenum /*format*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawArraysInstancedBaseInstance(GLenum /*mode*/, int /*first*/, GLsizei /*count*/, GLsizei /*primcount*/, unsigned int /*baseinstance*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawElementsInstancedBaseInstance(GLenum /*mode*/, GLsizei /*count*/, GLenum /*type*/, const void * /*indices*/, GLsizei /*primcount*/, unsigned int /*baseinstance*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawElementsInstancedBaseVertexBaseInstance(GLenum /*mode*/, GLsizei /*count*/, GLenum /*type*/, void * /*indices*/, GLsizei /*primcount*/, int /*basevertex*/, unsigned int /*baseinstance*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawTransformFeedbackInstanced(GLenum /*mode*/, unsigned int /*id*/, GLsizei /*primcount*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawTransformFeedbackStreamInstanced(GLenum /*mode*/, unsigned int /*id*/, unsigned int /*stream*/, GLsizei /*primcount*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getInternalformativ(GLenum /*target*/, GLenum /*internalformat*/, GLenum /*pname*/, GLsizei /*bufSize*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::clearBufferSubData(GLenum /*target*/, GLenum /*internalformat*/, GLintptr /*offset*/, GLsizeiptr /*size*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearBufferData(GLenum /*target*/, GLenum /*internalformat*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateBufferSubData(unsigned int /*buffer*/, GLintptr /*offset*/, GLsizeiptr /*length*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateBufferData(unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramInterfaceiv(unsigned int /*program*/, GLenum /*programInterface*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline unsigned int OpenGL::getProgramResourceIndex(unsigned int /*program*/, GLenum /*programInterface*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramResourceName(unsigned int /*program*/, GLenum /*programInterface*/, unsigned int /*index*/, GLsizei /*bufSize*/, GLsizei * /*length*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramResourceiv(unsigned int /*program*/, GLenum /*programInterface*/, unsigned int /*index*/, GLsizei /*propCount*/, const GLenum * /*props*/, GLsizei /*bufSize*/, GLsizei * /*length*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline int OpenGL::getProgramResourceLocation(unsigned int /*program*/, GLenum /*programInterface*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline int OpenGL::getProgramResourceLocationIndex(unsigned int /*program*/, GLenum /*programInterface*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::shaderStorageBlockBinding(unsigned int /*program*/, unsigned int /*storageBlockIndex*/, unsigned int /*storageBlockBinding*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getPointerv(GLenum /*pname*/, void ** /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texBufferRange(GLenum /*target*/, GLenum /*internalFormat*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLsizeiptr /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureView(unsigned int /*texture*/, GLenum /*target*/, unsigned int /*origtexture*/, GLenum /*internalformat*/, unsigned int /*minlevel*/, unsigned int /*numlevels*/, unsigned int /*minlayer*/, unsigned int /*numlayers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texStorage2DMultisample(GLenum /*target*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texStorage3DMultisample(GLenum /*target*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateTexSubImage(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateTexImage(unsigned int /*texture*/, int /*level*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferParameteri(GLenum /*target*/, GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getFramebufferParameteriv(GLenum /*target*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribFormat(unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribIFormat(unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribLFormat(unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindVertexBuffer(unsigned int /*bindingindex*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLintptr /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribBinding(unsigned int /*attribindex*/, unsigned int /*bindingindex*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexBindingDivisor(unsigned int /*bindingindex*/, unsigned int /*divisor*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::multiDrawArraysIndirect(GLenum /*mode*/, const void * /*indirect*/, GLsizei /*drawcount*/, GLsizei /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::multiDrawArraysIndirectCount(GLenum /*mode*/, const void * /*indirect*/, GLintptr /*drawcount*/, GLintptr /*maxdrawcount*/, GLsizei /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::multiDrawElementsIndirect(GLenum /*mode*/, GLenum /*type*/, const void * /*indirect*/, GLsizei /*drawcount*/, GLsizei /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::multiDrawElementsIndirectCount(GLenum /*mode*/, GLenum /*type*/, const void * /*indirect*/, GLintptr /*drawcount*/, GLsizei /*maxdrawcount*/, GLsizei /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::dispatchCompute(unsigned int /*num_groups_x*/, unsigned int /*num_groups_y*/, unsigned int /*num_groups_z*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::dispatchComputeIndirect(GLintptr /*indirect*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateSubFramebuffer(GLenum /*target*/, GLsizei /*numAttachments*/, const GLenum * /*attachments*/, int /*x*/, int /*y*/, int /*width*/, int /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateFramebuffer(GLenum /*target*/, GLsizei /*numAttachments*/, const GLenum * /*attachments*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyImageSubData(unsigned int /*srcName*/, GLenum /*srcTarget*/, int /*srcLevel*/, int /*srcX*/, int /*srcY*/, int /*srcZ*/, unsigned int /*dstName*/, GLenum /*dstTarget*/, int /*dstLevel*/, int /*dstX*/, int /*dstY*/, int /*dstZ*/, GLsizei /*srcWidth*/, GLsizei /*srcHeight*/, GLsizei /*srcDepth*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::debugMessageCallback(GLDEBUGPROC callback, const void * userParam)
			{
				checkErrors(glDebugMessageCallback(callback, userParam));
			}

			inline void OpenGL::debugMessageControl(const SourceDebugMessage source, const TypeDebugMessage type, const SeverityDebugMessage severity, const std::vector<unsigned int> & ids, bool enabled)
			{
				if (ids.size() > 0) {
					checkErrors(glDebugMessageControl(static_cast<GLenum>(source), static_cast<GLenum>(type), static_cast<GLenum>(severity), static_cast<GLsizei>(ids.size()), ids.data(), enabled));
				}
				else {
					checkErrors(glDebugMessageControl(static_cast<GLenum>(source), static_cast<GLenum>(type), static_cast<GLenum>(severity), 0, nullptr, enabled));
				}
			}
			//	inline void OpenGL::debugMessageInsert(GLenum /*source*/, GLenum /*type*/, unsigned int /*id*/, GLenum /*severity*/, GLsizei /*length*/, const char * /*message*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pushDebugGroup(GLenum /*source*/, unsigned int /*id*/, GLsizei /*length*/, const char * /*message*/) { static_assert(false, "Not implemented yet."); }
			
			inline void OpenGL::popDebugGroup()
			{
				checkErrors(glPopDebugGroup());
			}

			//	inline void OpenGL::objectLabel(GLenum /*identifier*/, unsigned int /*name*/, GLsizei /*length*/, const char * /*label*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::objectPtrLabel(void * /*ptr*/, GLsizei /*length*/, const char * /*label*/) { static_assert(false, "Not implemented yet."); }
			//	inline unsigned int OpenGL::getDebugMessageLog(unsigned int /*count*/, GLsizei /*bufSize*/, GLenum * /*sources*/, GLenum * /*types*/, unsigned int * /*ids*/, GLenum * /*severities*/, GLsizei * /*lengths*/, char * /*messageLog*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getObjectLabel(GLenum /*identifier*/, unsigned int /*name*/, GLsizei /*bifSize*/, GLsizei * /*length*/, char * /*label*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getObjectPtrLabel(void * /*ptr*/, GLsizei /*bifSize*/, GLsizei * /*length*/, char * /*label*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getInternalformati64v(GLenum /*target*/, GLenum /*internalformat*/, GLenum /*pname*/, GLsizei /*bufSize*/, GLint64 * /*params*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::bindBuffersRange(GLenum /*target*/, unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*buffers*/, const GLintptr * /*offsets*/, const GLintptr * /*sizes*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindBuffersBase(GLenum /*target*/, unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*buffers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bufferStorage(GLenum /*target*/, GLsizeiptr /*size*/, const void * /*data*/, GLbitfield /*flags*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindTextures(unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*textures*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindSamplers(unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*samplers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearTexSubImage(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearTexImage(unsigned int /*texture*/, int /*level*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindImageTextures(unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*textures*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindVertexBuffers(unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*buffers*/, const GLintptr * /*offsets*/, const GLsizei * /*strides*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::enableVertexArrayAttrib(unsigned int /*vaobj*/, unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::disableVertexArrayAttrib(unsigned int /*vaobj*/, unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedBufferData(unsigned int /*buffer*/, GLsizei /*size*/, const void * /*data*/, GLenum /*usage*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedBufferSubData(unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*size*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void * OpenGL::mapNamedBufferRange(unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*length*/, GLbitfield /*access*/) { static_assert(false, "Not implemented yet."); }
			//	inline void * OpenGL::mapNamedBuffer(unsigned int /*buffer*/, GLenum /*access*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::flushMappedNamedBufferRange(unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*length*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::unmapNamedBuffer(unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyNamedBufferSubData(unsigned int /*readBuffer*/, unsigned int /*writeBuffer*/, GLintptr /*readOffset*/, GLintptr /*writeOffset*/, GLsizei /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedBufferParameteriv(unsigned int /*buffer*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedBufferParameteri64v(unsigned int /*buffer*/, GLenum /*pname*/, GLint64 * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedBufferSubData(unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*size*/, void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedBufferPointerv(unsigned int /*buffer*/, GLenum /*pname*/, void ** /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnUniformfv(unsigned int /*program*/, int /*location*/, GLsizei /*bufSize*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnUniformiv(unsigned int /*program*/, int /*location*/, GLsizei /*bufSize*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnUniformuiv(unsigned int /*program*/, int /*location*/, GLsizei /*bufSize*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnUniformdv(unsigned int /*program*/, int /*location*/, GLsizei /*bufSize*/, double * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureSubImage3D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureSubImage2D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureSubImage1D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, GLsizei /*width*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTextureSubImage3D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTextureSubImage2D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTextureSubImage1D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTextureSubImage3D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTextureSubImage2D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTextureSubImage1D(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, GLsizei /*width*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureBuffer(unsigned int /*texture*/, GLenum /*internalformat*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameterf(unsigned int /*texture*/, GLenum /*pname*/, float /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameteri(unsigned int /*texture*/, GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameterfv(unsigned int /*texture*/, GLenum /*pname*/, const float * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameteriv(unsigned int /*texture*/, GLenum /*pname*/, const int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameterIiv(unsigned int /*texture*/, GLenum /*pname*/, const int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureParameterIuiv(unsigned int /*texture*/, GLenum /*pname*/, const unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::generateTextureMipmap(unsigned int /*texture*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureParameterfv(unsigned int /*texture*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureParameteriv(unsigned int /*texture*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureParameterIiv(unsigned int /*texture*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureParameterIuiv(unsigned int /*texture*/, GLenum /*pname*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureLevelParameterfv(unsigned int /*texture*/, int /*level*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureLevelParameteriv(unsigned int /*texture*/, int /*level*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnTexImage(GLenum /*target*/, int /*level*/, GLenum /*format*/, GLenum /*type*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureImage(unsigned int /*texture*/, int /*level*/, GLenum /*format*/, GLenum /*type*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getnCompressedTexImage(GLenum /*target*/, int /*level*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getCompressedTextureImage(unsigned int /*texture*/, int /*level*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::readnPixels(int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLenum /*type*/, GLsizei /*bufSize*/, void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferReadBuffer(unsigned int /*framebuffer*/, GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blitNamedFramebuffer(unsigned int /*readFramebuffer*/, unsigned int /*drawFramebuffer*/, int /*srcX0*/, int /*srcY0*/, int /*srcX1*/, int /*srcY1*/, int /*dstX0*/, int /*dstY0*/, int /*dstX1*/, int /*dstY1*/, GLbitfield /*mask*/, GLenum /*filter*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferDrawBuffer(unsigned int /*framebuffer*/, GLenum /*buf*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferDrawBuffers(unsigned int /*framebuffer*/, GLsizei /*n*/, const GLenum * /*bufs*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearNamedFramebufferiv(unsigned int /*framebuffer*/, GLenum /*buffer*/, int /*drawbuffer*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearNamedFramebufferuiv(unsigned int /*framebuffer*/, GLenum /*buffer*/, int /*drawbuffer*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearNamedFramebufferfv(unsigned int /*framebuffer*/, GLenum /*buffer*/, int /*drawbuffer*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearNamedFramebufferfi(unsigned int /*framebuffer*/, GLenum /*buffer*/, int /*drawbuffer*/, float /*depth*/, int /*stencil*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedRenderbufferStorageMultisample(unsigned int /*renderbuffer*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedRenderbufferStorage(unsigned int /*renderbuffer*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferRenderbuffer(unsigned int /*framebuffer*/, GLenum /*attachment*/, GLenum /*renderbuffertarget*/, unsigned int /*renderbuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferTexture(unsigned int /*framebuffer*/, GLenum /*attachment*/, unsigned int /*texture*/, int /*level*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferTextureLayer(unsigned int /*framebuffer*/, GLenum /*attachment*/, unsigned int /*texture*/, int /*level*/, int /*layer*/) { static_assert(false, "Not implemented yet."); }
			//	inline GLenum OpenGL::checkNamedFramebufferStatus(unsigned int /*framebuffer*/, GLenum /*target*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedFramebufferAttachmentParameteriv(unsigned int /*framebuffer*/, GLenum /*attachment*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedRenderbufferParameteriv(unsigned int /*renderbuffer*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline GLenum OpenGL::getGraphicsResetStatus() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createBuffers(GLsizei /*n*/, unsigned int * /*buffers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedBufferStorage(unsigned int /*buffer*/, GLsizei /*size*/, const void * /*data*/, GLbitfield /*flags*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearNamedBufferData(unsigned int /*buffer*/, GLenum /*internalformat*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createProgramPipelines(GLsizei /*n*/, unsigned int * /*pipelines*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::memoryBarrierByRegion(GLbitfield /*barriers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindTextureUnit(unsigned int /*unit*/, unsigned int /*texture*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createTextures(GLenum /*target*/, GLsizei /*n*/, unsigned int * /*textures*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createSamplers(GLsizei /*n*/, unsigned int * /*samplers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureBufferRange(unsigned int /*texture*/, GLenum /*internalformat*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTextureSubImage(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLenum /*type*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getCompressedTextureSubImage(unsigned int /*texture*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLsizei /*bufSize*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureStorage1D(unsigned int /*texture*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureStorage2D(unsigned int /*texture*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureStorage3D(unsigned int /*texture*/, GLsizei /*levels*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureStorage2DMultisample(unsigned int /*texture*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::textureStorage3DMultisample(unsigned int /*texture*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createFramebuffers(GLsizei /*n*/, unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::namedFramebufferParameteri(unsigned int /*framebuffer*/, GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getNamedFramebufferParameteriv(unsigned int /*framebuffer*/, GLenum /*pname*/, int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createRenderbuffers(GLsizei /*n*/, unsigned int * /*renderbuffers*/) { static_assert(false, "Not implemented yet."); }
			
			inline void OpenGL::textureBarrier()
			{
				checkErrors(glTextureBarrier());
			}

			//	inline void OpenGL::createVertexArrays(GLsizei /*n*/, unsigned int * /*arrays*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayElementBuffer(unsigned int /*vaobj*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayAttribFormat(unsigned int /*vaobj*/, unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayAttribIFormat(unsigned int /*vaobj*/, unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayAttribLFormat(unsigned int /*vaobj*/, unsigned int /*attribindex*/, int /*size*/, GLenum /*type*/, unsigned int /*relativeoffset*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayVertexBuffer(unsigned int /*vaobj*/, unsigned int /*bindingindex*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*stride*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayVertexBuffers(unsigned int /*vaobj*/, unsigned int /*first*/, GLsizei /*count*/, const unsigned int * /*buffers*/, const GLintptr * /*offsets*/, const GLsizei * /*strides*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayAttribBinding(unsigned int /*vaobj*/, unsigned int /*attribindex*/, unsigned int /*bindingindex*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexArrayBindingDivisor(unsigned int /*vaobj*/, unsigned int /*bindingindex*/, unsigned int /*divisor*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexArrayiv(unsigned int /*vaobj*/, GLenum /*pname*/, int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexArrayIndexed64iv(unsigned int /*vaobj*/, unsigned int /*index*/, GLenum /*pname*/, GLint64 * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexArrayIndexediv(unsigned int /*vaobj*/, unsigned int /*index*/, GLenum /*pname*/, int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::createTransformFeedbacks(GLsizei /*n*/, unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::transformFeedbackBufferRange(unsigned int /*xfb*/, unsigned int /*index*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLsizei /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::transformFeedbackBufferBase(unsigned int /*xfb*/, unsigned int /*index*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clipControl(GLenum /*origin*/, GLenum /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateNamedFramebufferSubData(unsigned int /*framebuffer*/, GLsizei /*numAttachments*/, const GLenum * /*attachments*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::invalidateNamedFramebufferData(unsigned int /*framebuffer*/, GLsizei /*numAttachments*/, const GLenum * /*attachments*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTransformFeedbackiv(unsigned int /*xfb*/, GLenum /*pname*/, int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTransformFeedbacki_v(unsigned int /*xfb*/, GLenum /*pname*/, unsigned int /*index*/, int * /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTransformFeedbacki64_v(unsigned int /*xfb*/, GLenum /*pname*/, unsigned int /*index*/, GLint64 * /*param*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::specializeShader(unsigned int /*shader*/, const char * /*pEntryPoint​*/, unsigned int /*numSpecializationConstants​*/, const unsigned int * /*pConstantIndex*/, const unsigned int * /*pConstantValue*/​) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::polygonOffsetClamp(float /*factor*/, float /*units*/, float /*clamp*/) { static_assert(false, "Not implemented yet."); }

		} // namespace opengl
	} // namespace renderer
} // namespace ece
