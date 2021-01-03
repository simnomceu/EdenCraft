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

			template <ece::size_t Size, typename enabled>
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

			inline void OpenGL::vertexAttribPointer(const int location, const ece::size_t size, const DataType type, const bool normalized, const ece::size_t stride, const ece::offset_t offset)
			{
				checkErrors(glVertexAttribPointer(location, static_cast<GLint>(size), static_cast<GLenum>(type), normalized, static_cast<GLsizei>(stride), reinterpret_cast<GLvoid *>(static_cast<unsigned long long>(offset))));
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

			inline void OpenGL::primitiveRestartIndex(ece::size_t index)
			{
				checkErrors(glPrimitiveRestartIndex(static_cast<GLuint>(index)));
			}

			inline void OpenGL::drawArrays(const PrimitiveMode mode, const int first, const ece::size_t count)
			{
				checkErrors(glDrawArrays(static_cast<GLenum>(mode), first, static_cast<GLsizei>(count)));
			}

			inline void OpenGL::multiDrawArrays(PrimitiveMode mode, const std::vector<int> & first, const std::vector<ece::size_t> & count, ece::size_t drawcount)
			{
				checkErrors(glMultiDrawArrays(static_cast<GLenum>(mode), first.data(), reinterpret_cast<const GLsizei *>(count.data()), static_cast<GLsizei>(drawcount)));
			}

			template <typename T>
			inline void OpenGL::drawElements(const PrimitiveMode mode, const ece::size_t count, const int offset)
			{
				constexpr auto type = getType<T>();
				auto byteOffset = offset * sizeof(T);
				checkErrors(glDrawElements(static_cast<GLenum>(mode), static_cast<GLsizei>(count), static_cast<GLenum>(type), reinterpret_cast<GLvoid *>(static_cast<unsigned long long>(byteOffset))));
			}

			template <typename T>
			inline void OpenGL::multiDrawElements(PrimitiveMode mode, const std::vector<ece::size_t> & count, const std::vector<ece::size_t *> & indices, ece::size_t drawcount)
			{
				constexpr auto type = getType<T>();
				checkErrors(glMultiDrawElements(static_cast<GLenum>(mode), reinterpret_cast<const GLsizei *>(count.data()), static_cast<GLenum>(type), reinterpret_cast<const GLvoid * const *>(indices.data()), static_cast<GLsizei>(drawcount)));
			}

			template <typename T>
			inline void OpenGL::drawRangeElements(PrimitiveMode mode, ece::size_t start, ece::size_t end, ece::size_t count, const ece::size_t * indices)
			{
				constexpr auto type = getType<T>();
				checkErrors(glDrawRangeElements(static_cast<GLenum>(mode), start, end, count, static_cast<GLenum>(type), static_cast<const GLvoid *>(indices)));
			}

			inline void OpenGL::drawArraysInstanced(const PrimitiveMode mode, const int first, const ece::size_t count, const ece::size_t primcount)
            {
                checkErrors(glDrawArraysInstanced(static_cast<GLenum>(mode), first, count, static_cast<GLsizei>(primcount)));
            }

			template <typename T>
            inline void OpenGL::drawElementsInstanced(const PrimitiveMode mode, const ece::size_t count, ece::offset_t offset, const ece::size_t primcount)
            {
				constexpr auto type = getType<T>();
				checkErrors(glDrawElementsInstanced(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), reinterpret_cast<GLvoid *>(offset), static_cast<GLsizei>(primcount)));
            }

			template <typename T>
            inline void OpenGL::drawElementsBaseVertex(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, int basevertex)
			{
				constexpr auto type = getType<T>();
				checkErrors(glDrawElementsBaseVertex(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), reinterpret_cast<GLvoid *>(indices.data()), basevertex));
			}

			template <typename T>
			inline void OpenGL::drawRangeElementsBaseVertex(PrimitiveMode mode, ece::size_t start, ece::size_t end, ece::size_t count, std::vector<ece::size_t> & indices, int basevertex)
			{
				constexpr auto type = getType<T>();
				checkErrors(glDrawRangeElementsBaseVertex(static_cast<GLenum>(mode), start, end, count, static_cast<GLenum>(type), reinterpret_cast<GLvoid *>(indices.data()), basevertex));
			}

			template <typename T>
			inline void OpenGL::drawElementsInstancedBaseVertex(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, ece::size_t primcount, int basevertex)
			{
				constexpr auto type = getType<T>();
				checkErrors(glDrawElementsInstancedBaseVertex(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), reinterpret_cast<GLvoid *>(indices.data()), static_cast<GLsizei>(primcount), basevertex));
			}

			template <typename T>
			inline void OpenGL::multiDrawElementsBaseVertex(PrimitiveMode mode, const std::vector<ece::size_t> & count, const std::vector<ece::size_t *> & indices, ece::size_t drawcount, const std::vector<int> & basevertex)
			{
				constexpr auto type = getType<T>();
				checkErrors(glMultiDrawElementsBaseVertex(static_cast<GLenum>(mode), reinterpret_cast<const GLsizei *>(count.data()), static_cast<GLenum>(type), reinterpret_cast<const GLvoid * const *>(indices.data()), drawcount, basevertex.data()));
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

			inline void OpenGL::bindBufferRange(IndexedBufferTarget target, Handle index, Handle buffer, int offset, ece::size_t size)
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
			inline void OpenGL::bufferData(const BufferType type, const ece::size_t size, const BufferUsage usage, const int /*offset*/)
			{
				checkErrors(glBufferData(static_cast<GLenum>(type), size * sizeof(E), nullptr, static_cast<GLenum>(usage)));
			}

			template <class C, typename enabled>
			inline void OpenGL::bufferSubData(BufferType target, int offset, ece::size_t size, const C & data)
			{
				checkErrors(glBufferSubData(static_cast<GLenum>(target), offset, size, reinterpret_cast<GLvoid *>(data.data())));
			}

			inline auto OpenGL::mapBufferRange(BufferType target, int offset, ece::size_t length, MapBufferRangeAccessFlag access) -> void *
			{
				return checkErrors(glMapBufferRange(static_cast<GLenum>(target), offset, length, static_cast<GLbitfield>(access)));
			}

			inline auto OpenGL::mapBuffer(BufferType target, MapBufferAccessFlag access) -> void *
			{
				return checkErrors(glMapBuffer(static_cast<GLenum>(target), static_cast<GLbitfield>(access)));
			}

			inline void OpenGL::flushMappedBufferRange(BufferType target, int offset, ece::size_t length)
			{
				return checkErrors(glFlushMappedBufferRange(static_cast<GLenum>(target), offset, length));
			}

			inline auto OpenGL::unmapBuffer(BufferType target) -> bool
			{
				return checkErrors(glUnmapBuffer(static_cast<GLenum>(target)));
			}

			inline void OpenGL::copyBufferSubData(BufferType readTarget, BufferType writeTarget, int readOffset, int writeOffset, ece::size_t size)
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

			inline void OpenGL::deleteVertexArrays(ece::size_t n, const std::vector<Handle> & arrays)
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
			inline auto OpenGL::getBufferSubData(BufferType target, int offset, ece::size_t size) -> std::vector<T>
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

			inline auto OpenGL::genQueries(ece::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>{};
				checkErrors(glGenQueries(n, reinterpret_cast<GLuint *>(ids.data())));
				return ids;
			}

			inline void OpenGL::deleteQueries(const std::vector<Handle> & ids)
			{
				checkErrors(glDeleteQueries(static_cast<ece::size_t>(ids.size()), ids.data()));
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
				const auto bufSize = ece::size_t{ 4096 };

				auto length = ece::size_t{ 0 };
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
				const auto bufSize = ece::size_t{ 4096 };

				auto length = ece::size_t{ 0 };
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

			inline auto OpenGL::getUniformIndices(Handle program, ece::size_t uniformCount) -> UniformBlock
			{
				auto result = UniformBlock();
				result.names.resize(uniformCount);
				result.indices.resize(uniformCount);
				checkErrors(glGetUniformIndices(program, uniformCount, reinterpret_cast<const GLchar **>(result.names.data()), reinterpret_cast<GLuint *>(result.indices.data())));
				return std::move(result);
			}

			inline auto OpenGL::getActiveUniformName(Handle program, unsigned int uniformIndex) -> std::string
			{
				const auto bufSize = ece::size_t{ 4096 };

				auto length = ece::size_t{ 0 };
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
				return { name.substr(0, length), static_cast<UniformDataType>(type), static_cast<ece::size_t>(size) };
			}

			inline auto OpenGL::getActiveUniforms(Handle program, const std::vector<unsigned int> & uniformIndices, UniformDataType pname) -> std::vector<int>
			{
				auto params = std::vector<int>(uniformIndices.size(), 0);
				checkErrors(glGetActiveUniformsiv(program, static_cast<ece::size_t>(uniformIndices.size()), uniformIndices.data(), static_cast<GLenum>(pname), params.data()));
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
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const std::array<T, S> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template<>
			inline void OpenGL::uniform<float, 1>(int location, ece::size_t count, const std::array<float, 1> & value)
			{
				checkErrors(glUniform1fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 2>(int location, ece::size_t count, const std::array<float, 2> & value)
			{
				checkErrors(glUniform2fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 3>(int location, ece::size_t count, const std::array<float, 3> & value)
			{
				checkErrors(glUniform3fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<float, 4>(int location, ece::size_t count, const std::array<float, 4> & value)
			{
				checkErrors(glUniform4fv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 1>(int location, ece::size_t count, const std::array<int, 1> & value)
			{
				checkErrors(glUniform1iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 2>(int location, ece::size_t count, const std::array<int, 2> & value)
			{
				checkErrors(glUniform2iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 3>(int location, ece::size_t count, const std::array<int, 3> & value)
			{
				checkErrors(glUniform3iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<int, 4>(int location, ece::size_t count, const std::array<int, 4> & value)
			{
				checkErrors(glUniform4iv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 1>(int location, ece::size_t count, const std::array<unsigned int, 1> & value)
			{
				checkErrors(glUniform1uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 2>(int location, ece::size_t count, const std::array<unsigned int, 2> & value)
			{
				checkErrors(glUniform2uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 3>(int location, ece::size_t count, const std::array<unsigned int, 3> & value)
			{
				checkErrors(glUniform3uiv(location, count, value.data()));
			}

			template<>
			inline void OpenGL::uniform<unsigned int, 4>(int location, ece::size_t count, const std::array<unsigned int, 4> & value)
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
			inline void OpenGL::uniform([[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v)
			{
				static_assert("No existing specialization for OpenGL::uniform.");
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 2> & v)
			{
				checkErrors(glUniformMatrix2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 3> & v)
			{
				checkErrors(glUniformMatrix3fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 4> & v)
			{
				checkErrors(glUniformMatrix4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 3> & v)
			{
				checkErrors(glUniformMatrix2x3fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 2> & v)
			{
				checkErrors(glUniformMatrix3x2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 4> & v)
			{
				checkErrors(glUniformMatrix2x4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 2> & v)
			{
				checkErrors(glUniformMatrix4x2fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 4> & v)
			{
				checkErrors(glUniformMatrix3x4fv(location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 3> & v)
			{
				checkErrors(glUniformMatrix4x3fv(location, count, transpose, v.data()));
			}

			inline void OpenGL::uniformBlockBinding(Handle program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding)
			{
				checkErrors(glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding));
			}

			inline void OpenGL::transformFeedbackVaryings(Handle program, ece::size_t count, const std::vector<std::string> & varyings, VaryingBufferMode bufferMode)
			{

				auto varyingsPtr = std::vector<const char*>{};
				for (const auto & string : varyings) {
					varyingsPtr.push_back(string.data());
				}
				checkErrors(glTransformFeedbackVaryings(program, count, reinterpret_cast<const GLchar **>(&varyingsPtr), static_cast<GLenum>(bufferMode)));
			}

			inline auto OpenGL::getTransformFeedbackVarying(Handle program, unsigned int index) -> VaryingInfo
			{
				const auto bufSize = ece::size_t{ 4096 };

				auto length = ece::size_t{ 0 };
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
				const auto bufSize = ece::size_t{ 16384 };

				auto length = ece::size_t{ 0 };
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
                return infoLog.substr(0, static_cast<ece::size_t>(size));
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

			inline void OpenGL::texImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * data)
			{
				checkErrors(glTexImage3D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLsizei>(depth), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::texImage2D(const TextureTypeTarget target, const unsigned int level, const PixelInternalFormat internalFormat, const ece::size_t width, const ece::size_t height, const PixelFormat format, const PixelDataType type, const void * data)
			{
				auto levelSec = (target == TextureTypeTarget::TEXTURE_RECTANGLE || target == TextureTypeTarget::PROXY_TEXTURE_RECTANGLE) ? 0 : level;
				checkErrors(glTexImage2D(static_cast<GLenum>(target), levelSec, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), static_cast<GLsizei>(height), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::texImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, ece::size_t width, PixelFormat format, PixelDataType type, const void * data)
			{
				checkErrors(glTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			inline void OpenGL::copyTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, int x, int y, ece::size_t width, ece::size_t height)
			{
				checkErrors(glCopyTexImage2D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), x, y, width, height, 0));
			}

			inline void OpenGL::copyTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, int x, int y, ece::size_t width)
			{
				checkErrors(glCopyTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), x, y, width, 0));
			}

			inline void OpenGL::texSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, ece::size_t  width, ece::size_t  height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLsizei>(depth), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::texSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::texSubImage1D(TargetTexture1D target, int level, int xoffset, ece::size_t width, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTexSubImage1D(static_cast<GLenum>(target), level, xoffset, static_cast<GLsizei>(width), static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::copyTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, ece::size_t width, ece::size_t height)
			{
				checkErrors(glCopyTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, x, y, width, height));
			}

			inline void OpenGL::copyTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, int x, int y, ece::size_t width, ece::size_t height)
			{
				checkErrors(glCopyTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, x, y, width, height));
			}

			inline void OpenGL::copyTexSubImage1D(TargetTexture1D target, int level, int xoffset, int x, int y, ece::size_t width)
			{
				checkErrors(glCopyTexSubImage1D(static_cast<GLenum>(target), level, xoffset, x, y, width));
			}

			inline void OpenGL::compressedTexImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage3D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, height, depth, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage2D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, height, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexImage1D(static_cast<GLenum>(target), level, static_cast<unsigned int>(internalFormat), width, 0, imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage3D(static_cast<GLenum>(target), level, xoffset, yoffset, zoffset, width, height, depth, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage2D(static_cast<GLenum>(target), level, xoffset, yoffset, width, height, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::compressedTexSubImage1D(TargetTexture1D target, int level, int xoffset, ece::size_t width, PixelFormat format, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTexSubImage1D(static_cast<GLenum>(target), level, xoffset, width, static_cast<unsigned int>(format), imageSize, data));
			}

			inline void OpenGL::texImage3DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedSamplelLocations)
			{
				checkErrors(glTexImage3DMultisample(static_cast<GLenum>(target), samples, static_cast<unsigned int>(internalFormat), width, height, depth, fixedSamplelLocations));
			}

			inline void OpenGL::texImage2DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, bool fixedSamplelLocations)
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
				checkErrors(glDeleteTextures(static_cast<ece::size_t>(textures.size()), textures.data()));
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

			inline auto OpenGL::readPixels(int x, int y, ece::size_t width, ece::size_t height, PixelFormat format, DataType type) -> void *
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
				checkErrors(glDrawBuffers(static_cast<ece::size_t>(bufs.size()), reinterpret_cast<const GLenum *>(bufs.data())));
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
			
			inline auto OpenGL::genFramebuffers(ece::size_t n) -> std::vector<Handle>
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

			inline auto OpenGL::genRenderbuffers(ece::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glGenRenderbuffers(n, reinterpret_cast<GLuint *>(ids.data())));
				return std::move(ids);
			}

			inline void OpenGL::renderbufferStorageMultisample(ece::size_t samples, PixelFormat internalformat, ece::size_t width, ece::size_t height)
			{
				const auto target = GL_RENDERBUFFER;
				checkErrors(glRenderbufferStorageMultisample(target, static_cast<GLsizei>(samples), static_cast<GLenum>(internalformat), static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}
			
			inline void OpenGL::renderbufferStorage(PixelFormat internalformat, ece::size_t width, ece::size_t height)
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
				const auto maxSize = ece::size_t{ 16 };
				auto data = std::vector<unsigned char>(maxSize);
				checkErrors(glGetBooleanv(static_cast<GLenum>(pname), reinterpret_cast<GLboolean *>(data.data())));
				return std::vector<bool>(data.begin(), data.end());
			}

			static inline auto OpenGL::getDouble(Parameter pname) -> std::vector<double>
			{
				const auto maxSize = ece::size_t{ 16 };
				auto data = std::vector<double>(maxSize);
				checkErrors(glGetDoublev(static_cast<GLenum>(pname), reinterpret_cast<GLdouble *>(data.data())));
				return std::move(data);
			}

			static inline auto OpenGL::getFloat(Parameter pname) -> std::vector<float>
			{
				const auto maxSize = ece::size_t{ 16 };
				auto data = std::vector<float>(maxSize);
				checkErrors(glGetFloatv(static_cast<GLenum>(pname), reinterpret_cast<GLfloat *>(data.data())));
				return std::move(data);
			}

			inline auto OpenGL::getInteger(Parameter pname) -> std::vector<int>
			{
				const auto maxSize = ece::size_t{ 16 };
				auto data = std::vector<int>(maxSize);
				checkErrors(glGetIntegerv(static_cast<GLenum>(pname), data.data()));
				return std::move(data);
			}

			inline auto OpenGL::getInteger64(Parameter pname) -> std::vector<std::int64_t>
			{
				const auto maxSize = ece::size_t{ 16 };
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
				auto result = checkErrors(glIsEnabled(static_cast<GLenum>(cap)));
				return result == GL_TRUE;
			}

			inline auto OpenGL::isEnabled(Capability cap, unsigned int index) -> bool
			{
				auto result = checkErrors(glIsEnabledi(static_cast<GLenum>(cap), index));
				return result == GL_TRUE;
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

			inline auto OpenGL::genSamplers(ece::size_t n) -> std::vector<Handle>
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
				checkErrors(glDeleteSamplers(static_cast<ece::size_t>(samplers.size()), samplers.data()));
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
				const auto maxSize = ece::size_t{ 16 };
				auto params = std::vector<float>(maxSize);
				checkErrors(glGetSamplerParameterfv(sampler, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <> inline auto OpenGL::getSamplerParameter<int>(Handle sampler, SamplerParameter pname) -> std::vector<int>
			{
				const auto maxSize = ece::size_t{ 16 };
				auto params = std::vector<int>(maxSize);
				checkErrors(glGetSamplerParameteriv(sampler, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <> inline auto OpenGL::getSamplerParameter<unsigned int>(Handle sampler, SamplerParameter pname) -> std::vector<unsigned int>
			{
				const auto maxSize = ece::size_t{ 16 };
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

			inline void OpenGL::vertexAttribDivisor(const int index, const ece::size_t divisor)
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
				const auto bufsize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
				auto name = std::string(bufsize, '\0');
				checkErrors(glGetActiveSubroutineName(program, static_cast<GLenum>(shadertype), index, static_cast<GLsizei>(bufsize), reinterpret_cast<GLsizei *>(&length), name.data()));
				return std::move(name);
			}

			inline auto OpenGL::getActiveSubroutineUniformName(Handle program, ShaderType shadertype, Handle index) -> std::string
			{
				const auto bufsize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
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
				checkErrors(glUniformSubroutinesuiv(static_cast<GLenum>(shadertype), static_cast<ece::size_t>(indices.size()), indices.data()));
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

			inline auto OpenGL::genTransformFeedbacks(ece::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glGenTransformFeedbacks(static_cast<GLsizei>(n), ids.data()));
				return std::move(ids);
			}

			inline void OpenGL::deleteTransformFeedbacks(const std::vector<Handle> & ids)
			{
				checkErrors(glDeleteTransformFeedbacks(static_cast<ece::size_t>(ids.size()), ids.data()));
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

			inline void OpenGL::depthRange(float nearVal, float farVal)
			{
				checkErrors(glDepthRangef(nearVal, farVal));
			}

			inline void OpenGL::clearDepth(float depth)
			{
				checkErrors(glClearDepth(depth));
			}

			inline auto OpenGL::getFloat(Parameter target, unsigned int index) -> float
			{
				auto data = 0.0f;
				checkErrors(glGetFloati_v(static_cast<GLenum>(target), index, &data));
				return std::move(data);
			}

			inline auto OpenGL::getDouble(Parameter target, unsigned int index) -> double
			{
				auto data = 0.0;
				checkErrors(glGetDoublei_v(static_cast<GLenum>(target), index, &data));
				return std::move(data);
			}

			inline void OpenGL::shaderBinary(const std::vector<Handle> & shaders, BinaryFormat binaryFormat, const void * binary, ece::size_t length)
			{
				checkErrors(glShaderBinary(static_cast<GLsizei>(shaders.size()), shaders.data(), static_cast<GLenum>(binaryFormat), binary, static_cast<GLsizei>(length)));
			}
			
			inline void OpenGL::releaseShaderCompiler()
			{
				checkErrors(glReleaseShaderCompiler());
			}

			inline auto OpenGL::createShaderProgram(ShaderType type, std::vector<std::string> & strings) -> Handle
			{
				auto stringsPtr = std::vector<const char*>{};
				for (const auto & string : strings) {
					stringsPtr.push_back(string.data());
				}
				return checkErrors(glCreateShaderProgramv(static_cast<GLenum>(type), static_cast<ece::size_t>(strings.size()), reinterpret_cast<const GLchar **>(&stringsPtr)));
			}

			inline void OpenGL::programParameter(Handle program, ProgramHint pname, int value)
			{
				checkErrors(glProgramParameteri(program, static_cast<GLenum>(pname), value));
			}

			inline auto OpenGL::genProgramPipelines(ece::size_t n) -> std::vector<Handle>
			{
				auto pipelines = std::vector<Handle>(n);
				checkErrors(glGenProgramPipelines(n, pipelines.data()));
				return std::move(pipelines);
			}

			inline void OpenGL::deleteProgramPipelines(const std::vector<Handle> & pipelines)
			{
				checkErrors(glDeleteProgramPipelines(static_cast<ece::size_t>(pipelines.size()), pipelines.data()));
			}

			inline auto OpenGL::isProgramPipeline(Handle pipeline) -> bool
			{
				return checkErrors(glIsProgramPipeline(pipeline));
			}
			
			inline void OpenGL::bindProgramPipeline(Handle pipeline)
			{
				checkErrors(glBindProgramPipeline(pipeline));
			}
			
			inline void OpenGL::useProgramStages(Handle pipeline, ProgramStageBitfield stages, Handle program)
			{
				checkErrors(glUseProgramStages(pipeline, static_cast<GLenum>(stages), program));
			}

			inline void OpenGL::activeShaderProgram(Handle pipeline, Handle program)
			{
				checkErrors(glActiveShaderProgram(pipeline, program));
			}

			inline auto OpenGL::getProgramBinary(Handle program) -> ProgramBinary
			{
				const auto bufsize = ece::size_t{ 8192 };
				auto result = ProgramBinary();
				checkErrors(glGetProgramBinary(program, bufsize, reinterpret_cast<GLsizei *>(&result.length), reinterpret_cast<GLenum *>(&result.binaryFormat), result.binary));
				return std::move(result);
			}

			inline void OpenGL::programBinary(Handle program, ProgramBinary & binary)
			{
				checkErrors(glProgramBinary(program, binary.binaryFormat, binary.binary, binary.length));
			}

			template <class T, unsigned int S>
			inline void OpenGL::programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] const std::array<T, S> & v)
			{
				static_assert("No existing specialization for OpenGL::programUniform.");
			}

			template <>
			inline void OpenGL::programUniform<float, 1>(Handle program, const int location, const std::array<float, 1> & v)
			{
				checkErrors(glProgramUniform1f(program, location, v[0]));
			}

			template <>
			inline void OpenGL::programUniform<float, 2>(Handle program, const int location, const std::array<float, 2> & v)
			{
				checkErrors(glProgramUniform2f(program, location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::programUniform<float, 3>(Handle program, const int location, const std::array<float, 3> & v)
			{
				checkErrors(glProgramUniform3f(program, location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::programUniform<float, 4>(Handle program, const int location, const std::array<float, 4> & v)
			{
				checkErrors(glProgramUniform4f(program, location, v[0], v[1], v[2], v[3]));
			}

			template <>
			inline void OpenGL::programUniform<int, 1>(Handle program, const int location, const std::array<int, 1> & v)
			{
				checkErrors(glProgramUniform1i(program, location, v[0]));
			}

			template <>
			inline void OpenGL::programUniform<int, 2>(Handle program, const int location, const std::array<int, 2> & v)
			{
				checkErrors(glProgramUniform2i(program, location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::programUniform<int, 3>(Handle program, const int location, const std::array<int, 3> & v)
			{
				checkErrors(glProgramUniform3i(program, location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::programUniform<int, 4>(Handle program, const int location, const std::array<int, 4> & v)
			{
				checkErrors(glProgramUniform4i(program, location, v[0], v[1], v[2], v[3]));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 1>(Handle program, const int location, const std::array<unsigned int, 1> & v)
			{
				checkErrors(glProgramUniform1ui(program, location, v[0]));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 2>(Handle program, const int location, const std::array<unsigned int, 2> & v)
			{
				checkErrors(glProgramUniform2ui(program, location, v[0], v[1]));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 3>(Handle program, const int location, const std::array<unsigned int, 3> & v)
			{
				checkErrors(glProgramUniform3ui(program, location, v[0], v[1], v[2]));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 4>(Handle program, const int location, const std::array<unsigned int, 4> & v)
			{
				checkErrors(glProgramUniform4ui(program, location, v[0], v[1], v[2], v[3]));
			}

			template <class T, unsigned int S>
			inline void OpenGL::programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const std::array<T, S> & v)
			{
				static_assert("No existing specialization for OpenGL::programUniform.");
			}

			template <>
			inline void OpenGL::programUniform<float, 1>(Handle program, const int location, ece::size_t count, const std::array<float, 1> & v)
			{
				checkErrors(glProgramUniform1fv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 2>(Handle program, const int location, ece::size_t count, const std::array<float, 2> & v)
			{
				checkErrors(glProgramUniform2fv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 3>(Handle program, const int location, ece::size_t count, const std::array<float, 3> & v)
			{
				checkErrors(glProgramUniform3fv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 4>(Handle program, const int location, ece::size_t count, const std::array<float, 4> & v)
			{
				checkErrors(glProgramUniform4fv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<int, 1>(Handle program, const int location, ece::size_t count, const std::array<int, 1> & v)
			{
				checkErrors(glProgramUniform1iv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<int, 2>(Handle program, const int location, ece::size_t count, const std::array<int, 2> & v)
			{
				checkErrors(glProgramUniform2iv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<int, 3>(Handle program, const int location, ece::size_t count, const std::array<int, 3> & v)
			{
				checkErrors(glProgramUniform3iv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<int, 4>(Handle program, const int location, ece::size_t count, const std::array<int, 4> & v)
			{
				checkErrors(glProgramUniform4iv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 1>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 1> & v)
			{
				checkErrors(glProgramUniform1uiv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 2>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 2> & v)
			{
				checkErrors(glProgramUniform2uiv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 3>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 3> & v)
			{
				checkErrors(glProgramUniform3uiv(program, location, count, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<unsigned int, 4>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 4> & v)
			{
				checkErrors(glProgramUniform4uiv(program, location, count, v.data()));
			}

			template <class T, unsigned int M, unsigned int N>
			inline void OpenGL::programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v)
			{
				static_assert("No existing specialization for OpenGL::programUniform.");
			}

			template <>
			inline void OpenGL::programUniform<float, 2, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 2> & v)
			{
				checkErrors(glProgramUniformMatrix2fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 3, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 3> & v)
			{
				checkErrors(glProgramUniformMatrix3fv(program, location, count, transpose, v.data()));
			}
			
			template <>
			inline void OpenGL::programUniform<float, 4, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 4> & v)
			{
				checkErrors(glProgramUniformMatrix4fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 2, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 3> & v)
			{
				checkErrors(glProgramUniformMatrix2x3fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 3, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 2> & v)
			{
				checkErrors(glProgramUniformMatrix3x2fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 2, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 4> & v)
			{
				checkErrors(glProgramUniformMatrix2x4fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 4, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 2> & v)
			{
				checkErrors(glProgramUniformMatrix4x2fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 3, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 4> & v)
			{
				checkErrors(glProgramUniformMatrix3x4fv(program, location, count, transpose, v.data()));
			}

			template <>
			inline void OpenGL::programUniform<float, 4, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 3> & v)
			{
				checkErrors(glProgramUniformMatrix4x3fv(program, location, count, transpose, v.data()));
			}

			inline auto OpenGL::getProgramPipeline(Handle pipeline, ProgramPipelineProperty pname) -> int
			{
				auto params = 0;
				checkErrors(glGetProgramPipelineiv(pipeline, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getProgramPipelineInfoLog(Handle pipeline) -> std::string
			{
				const auto bufSize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
				auto infoLog = std::string(4096, '\0');
				checkErrors(glGetProgramPipelineInfoLog(pipeline, bufSize, reinterpret_cast<GLsizei *>(&length), infoLog.data()));
				infoLog.resize(length);
				return std::move(infoLog);
			}

			inline auto OpenGL::getShaderPrecisionFormat(ShaderType shaderType, ShaderPrecisionType precisionType) -> ShaderPrecisionFormat
			{
				auto precisionFormat = ShaderPrecisionFormat();
				checkErrors(glGetShaderPrecisionFormat(static_cast<GLenum>(shaderType), static_cast<GLenum>(precisionType), precisionFormat.range.data(), &precisionFormat.precision));
				return std::move(precisionFormat);
			}

			inline void OpenGL::validateProgramPipeline(Handle pipeline)
			{
				checkErrors(glValidateProgramPipeline(pipeline));
			}

			inline void OpenGL::depthRangeArray(Handle first, const std::vector<std::array<double, 2>> & v)
			{
				checkErrors(glDepthRangeArrayv(first, static_cast<ece::size_t>(v.size()), v[0].data()));
			}
			
			inline void OpenGL::depthRangeIndexed(Handle index, double nearVal, double farVal)
			{
				checkErrors(glDepthRangeIndexed(index, nearVal, farVal));
			}

			inline void OpenGL::viewportArray(Handle first, const std::vector<std::array<float, 4>> & v)
			{
				checkErrors(glViewportArrayv(first, static_cast<ece::size_t>(v.size()), v[0].data()));
			}

			inline void OpenGL::viewportIndexed(Handle index, float x, float y, float w, float h)
			{
				checkErrors(glViewportIndexedf(index, x, y, w, h));
			}
			
			inline void OpenGL::viewportIndexed(Handle index, const std::array<float, 4> & v)
			{
				checkErrors(glViewportIndexedfv(index, v.data()));
			}
			
			inline void OpenGL::scissorArray(Handle first, const std::vector<std::array<int, 4>> & v)
			{
				checkErrors(glScissorArrayv(first, static_cast<ece::size_t>(v.size()), v[0].data()));
			}
			
			inline void OpenGL::scissorIndexed(Handle index, int left, int bottom, ece::size_t width, ece::size_t height)
			{
				checkErrors(glScissorIndexed(index, left, bottom, width, height));
			}

			inline void OpenGL::scissorIndexed(Handle index, const std::array<int, 4> & v)
			{
				checkErrors(glScissorIndexedv(index, v.data()));
			}

			inline auto OpenGL::getActiveAtomicCounterBuffer(Handle program, Handle bufferIndex, AtomicCounterBufferParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetActiveAtomicCounterBufferiv(program, bufferIndex, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			inline void OpenGL::memoryBarrier(Barrier barriers)
			{
				checkErrors(glMemoryBarrier(static_cast<GLbitfield>(barriers)));
			}

			inline void OpenGL::texStorage1D(TargetTexture1D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width)
			{
				checkErrors(glTexStorage1D(static_cast<GLenum>(target), levels, static_cast<GLenum>(internalformat), width));
			}

			inline void OpenGL::texStorage2D(TargetTexture2D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height)
			{
				checkErrors(glTexStorage2D(static_cast<GLenum>(target), levels, static_cast<GLenum>(internalformat), width, height));
			}

			inline void OpenGL::texStorage3D(TargetTexture3D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth)
			{
				checkErrors(glTexStorage3D(static_cast<GLenum>(target), levels, static_cast<GLenum>(internalformat), width, height, depth));
			}

			inline void OpenGL::bindImageTexture(Handle unit, Handle texture, int level, bool layered, int layer, MapBufferAccessFlag access, PixelInternalFormat format)
			{
				checkErrors(glBindImageTexture(unit, texture, level, layered, layer, static_cast<GLenum>(access), static_cast<GLenum>(format)));
			}

			inline void OpenGL::drawArraysInstancedBaseInstance(PrimitiveMode mode, int first, ece::size_t count, ece::size_t primcount, unsigned int baseinstance)
			{
				checkErrors(glDrawArraysInstancedBaseInstance(static_cast<GLenum>(mode), first, count, primcount, baseinstance));
			}
			
			inline void OpenGL::drawElementsInstancedBaseInstance(PrimitiveMode mode, ece::size_t count, const std::vector<ece::size_t> & indices, ece::size_t primcount, unsigned int baseinstance)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawElementsInstancedBaseInstance(static_cast<GLenum>(mode), count, type, reinterpret_cast<const GLvoid *>(indices.data()), primcount, baseinstance));
			}
			
			inline void OpenGL::drawElementsInstancedBaseVertexBaseInstance(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, ece::size_t primcount, int basevertex, unsigned int baseinstance)
			{
				const auto type = GL_UNSIGNED_INT;
				checkErrors(glDrawElementsInstancedBaseVertexBaseInstance(static_cast<GLenum>(mode), count, type, reinterpret_cast<GLvoid *>(indices.data()), primcount, basevertex, baseinstance));
			}

			inline void OpenGL::drawTransformFeedbackInstanced(PrimitiveMode mode, Handle id, ece::size_t primcount)
			{
				checkErrors(glDrawTransformFeedbackInstanced(static_cast<GLenum>(mode), id, primcount));
			}
			
			inline void OpenGL::drawTransformFeedbackStreamInstanced(PrimitiveMode mode, Handle id, Handle stream, ece::size_t primcount)
			{
				checkErrors(glDrawTransformFeedbackStreamInstanced(static_cast<GLenum>(mode), id, stream, primcount));
			}
			
			inline auto OpenGL::getInternalformat(TextureTarget target, PixelInternalFormat internalformat, InternalFormatInformation pname) -> std::vector<int>
			{
				const auto bufsize = ece::size_t{ 32 };
				
				auto params = std::vector<int>{};
				checkErrors(glGetInternalformativ(static_cast<GLenum>(target), static_cast<GLenum>(internalformat), static_cast<GLenum>(pname), bufsize, params.data()));
				return std::move(params);
			}

			template <class T>
			inline void OpenGL::clearBufferSubData(BufferType target, PixelInternalFormat internalformat, int offset, ece::size_t size, PixelFormat format, DataType type, const std::vector<T> & data)
			{
				checkErrors(glClearBufferSubData(static_cast<GLenum>(target), static_cast<GLenum>(internalformat), reinterpret_cast<GLintptr>(&offset), reinterpret_cast<GLsizeiptr>(&size), static_cast<GLenum>(format), static_cast<GLenum>(type), data.data()));
			}

			template <class T>
			inline void OpenGL::clearBufferData(BufferType target, PixelInternalFormat internalformat, PixelFormat format, DataType type, const std::vector<T> & data)
			{
				checkErrors(glClearBufferData(static_cast<GLenum>(target), static_cast<GLenum>(internalformat), static_cast<GLenum>(format), static_cast<GLenum>(type), data.data()));
			}
			
			inline void OpenGL::invalidateBufferSubData(Handle buffer, int offset, ece::size_t length)
			{
				checkErrors(glInvalidateBufferSubData(buffer, reinterpret_cast<GLintptr>(&offset), reinterpret_cast<GLsizeiptr>(&length)));
			}
		
			inline void OpenGL::invalidateBufferData(Handle buffer)
			{
				checkErrors(glInvalidateBufferData(buffer));
			}
			
			inline auto OpenGL::getProgramInterface(Handle program, ProgramInterface programInterface, ProgramInterfaceProperty pname) -> int
			{
				auto params = 0;
				checkErrors(glGetProgramInterfaceiv(program, static_cast<GLenum>(programInterface), static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getProgramResourceIndex(Handle program, ProgramInterface programInterface, const std::string & name) -> Handle
			{
				return checkErrors(glGetProgramResourceIndex(program, static_cast<GLenum>(programInterface), name.data()));
			}

			inline auto OpenGL::getProgramResourceName(Handle program, ProgramInterface programInterface, Handle index) -> std::string
			{
				const auto bufSize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
				auto name = std::string(bufSize, '\0');

				checkErrors(glGetProgramResourceName(program, static_cast<GLenum>(programInterface), index, bufSize, reinterpret_cast<GLsizei *>(&length), name.data()));
				name.resize(length);
				return std::move(name);
			}

			inline auto OpenGL::getProgramResource(Handle program, ProgramInterface programInterface, unsigned int index, const std::vector<ProgramInterfaceProperty> & props) -> std::vector<int>
			{
				const auto bufSize = ece::size_t{ 128 };
				auto length = std::size_t{ 0 };
				auto params = std::vector<int>(bufSize);

				checkErrors(glGetProgramResourceiv(program, static_cast<GLenum>(programInterface), index, static_cast<ece::size_t>(props.size()), reinterpret_cast<const GLenum *>(props.data()), bufSize, reinterpret_cast<GLsizei *>(length), params.data()));
				params.resize(length);
				return std::move(params);
			}

			inline auto OpenGL::getProgramResourceLocation(Handle program, ProgramInterface programInterface, const std::string & name) -> int
			{
				return checkErrors(glGetProgramResourceLocation(program, static_cast<GLenum>(programInterface), name.data()));
			}

			inline auto OpenGL::getProgramResourceLocationIndex(Handle program, ProgramInterface programInterface, const std::string & name) -> int
			{
				return checkErrors(glGetProgramResourceLocationIndex(program, static_cast<GLenum>(programInterface), name.data()));
			}
			
			inline void OpenGL::shaderStorageBlockBinding(Handle program, unsigned int storageBlockIndex, unsigned int storageBlockBinding)
			{
				checkErrors(glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding));
			}

			inline auto OpenGL::getPointer(Pointer pname) -> void *
			{
				auto params = static_cast<void *>(0);
				checkErrors(glGetPointerv(static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline void OpenGL::texBufferRange(PixelInternalFormat internalFormat, Handle buffer, int offset, ece::size_t size)
			{
				const auto target = GL_TEXTURE_BUFFER;
				checkErrors(glTexBufferRange(target, static_cast<GLenum>(internalFormat), buffer, reinterpret_cast<GLintptr>(&offset), reinterpret_cast<GLsizeiptr>(&size)));
			}

			inline void OpenGL::textureView(Handle texture, TextureTarget target, TextureTarget origtexture, PixelInternalFormat internalformat, unsigned int minlevel, unsigned int numlevels, unsigned int minlayer, unsigned int numlayers)
			{
				checkErrors(glTextureView(texture, static_cast<GLenum>(target), static_cast<GLuint>(origtexture), static_cast<GLenum>(internalformat), minlevel, numlevels, minlayer, numlayers));
			}

			inline void OpenGL::texStorage2DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, bool fixedsamplelocations)
			{
				checkErrors(glTexStorage2DMultisample(static_cast<GLenum>(target), samples, static_cast<GLenum>(internalformat), width, height, fixedsamplelocations));
			}

			inline void OpenGL::texStorage3DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedsamplelocations)
			{
				checkErrors(glTexStorage3DMultisample(static_cast<GLenum>(target), samples, static_cast<GLenum>(internalformat), width, height, depth, fixedsamplelocations));
			}
			
			inline void OpenGL::invalidateTexSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth)
			{
				checkErrors(glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth));
			}
			
			inline void OpenGL::invalidateTexImage(Handle texture, int level)
			{
				checkErrors(glInvalidateTexImage(texture, level));
			}

			inline void OpenGL::framebufferParameter(FramebufferTarget target, FramebufferParameter pname, int param)
			{
				checkErrors(glFramebufferParameteri(static_cast<GLenum>(target), static_cast<GLenum>(pname), param));
			}

			inline auto OpenGL::getFramebufferParameter(FramebufferTarget target, FramebufferParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetFramebufferParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline void OpenGL::vertexAttribFormat(Handle attribindex, int size, DataType type, bool normalized, unsigned int relativeoffset)
			{
				checkErrors(glVertexAttribFormat(attribindex, size, static_cast<GLenum>(type), normalized, relativeoffset));
			}

			inline void OpenGL::vertexAttribIFormat(Handle attribindex, int size, DataType type, unsigned int relativeoffset)
			{
				checkErrors(glVertexAttribIFormat(attribindex, size, static_cast<GLenum>(type), relativeoffset));
			}

			inline void OpenGL::vertexAttribLFormat(Handle attribindex, int size, DataType type, unsigned int relativeoffset)
			{
				checkErrors(glVertexAttribLFormat(attribindex, size, static_cast<GLenum>(type), relativeoffset));
			}

			inline void OpenGL::bindVertexBuffer(Handle bindingindex, Handle buffer, int offset, int stride)
			{
				checkErrors(glBindVertexBuffer(bindingindex, buffer, offset, stride));
			}
			
			inline void OpenGL::vertexAttribBinding(unsigned int attribindex, unsigned int bindingindex)
			{
				checkErrors(glVertexAttribBinding(attribindex, bindingindex));
			}

			inline void OpenGL::vertexBindingDivisor(unsigned int bindingindex, unsigned int divisor)
			{
				checkErrors(glVertexBindingDivisor(bindingindex, divisor));
			}

			inline void OpenGL::multiDrawArraysIndirect(PrimitiveMode mode, const std::vector<DrawArraysIndirectCommand> & indirect, ece::size_t drawcount, ece::size_t stride)
			{
				checkErrors(glMultiDrawArraysIndirect(static_cast<GLenum>(mode), reinterpret_cast<const GLvoid *>(indirect.data()), drawcount, stride));
			}

			inline void OpenGL::multiDrawArraysIndirectCount(PrimitiveMode mode, const std::vector<DrawArraysIndirectCommand> & indirect, int drawcount, ece::size_t maxdrawcount, ece::size_t stride)
			{
				checkErrors(glMultiDrawArraysIndirectCount(static_cast<GLenum>(mode), reinterpret_cast<const GLvoid *>(indirect.data()), reinterpret_cast<GLintptr>(&drawcount), maxdrawcount, stride));
			}

			inline void OpenGL::multiDrawElementsIndirect(PrimitiveMode mode, DataType type, const std::vector<DrawElementsIndirectCommand> & indirect, ece::size_t drawcount, ece::size_t stride)
			{
				checkErrors(glMultiDrawElementsIndirect(static_cast<GLenum>(mode), static_cast<GLenum>(type), reinterpret_cast<const GLvoid *>(indirect.data()), drawcount, stride));
			}

			inline void OpenGL::multiDrawElementsIndirectCount(PrimitiveMode mode, DataType type, const std::vector<DrawElementsIndirectCommand> & indirect, int drawcount, ece::size_t maxdrawcount, ece::size_t stride)
			{
				checkErrors(glMultiDrawElementsIndirectCount(static_cast<GLenum>(mode), static_cast<GLenum>(type), reinterpret_cast<const GLvoid *>(indirect.data()), reinterpret_cast<GLintptr>(&drawcount), maxdrawcount, stride));
			}

			inline void OpenGL::dispatchCompute(unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z)
			{
				checkErrors(glDispatchCompute(num_groups_x, num_groups_y, num_groups_z));
			}
			
			inline void OpenGL::dispatchComputeIndirect(int indirect)
			{
				checkErrors(glDispatchComputeIndirect(reinterpret_cast<GLintptr>(&indirect)));
			}

			inline void OpenGL::invalidateSubFramebuffer(FramebufferTarget target, const std::vector<FramebufferAttachment> & attachments, int x, int y, int width, int height)
			{
				checkErrors(glInvalidateSubFramebuffer(static_cast<GLenum>(target), static_cast<ece::size_t>(attachments.size()), reinterpret_cast<const GLenum *>(attachments.data()), x, y, width, height));
			}

			inline void OpenGL::invalidateFramebuffer(FramebufferTarget target, const std::vector<FramebufferAttachment> & attachments)
			{
				checkErrors(glInvalidateFramebuffer(static_cast<GLenum>(target), static_cast<ece::size_t>(attachments.size()), reinterpret_cast<const GLenum *>(attachments.data())));
			}

			inline void OpenGL::copyImageSubData(Handle srcName, TextureTarget srcTarget, int srcLevel, int srcX, int srcY, int srcZ, Handle dstName, TextureTarget dstTarget, int dstLevel, int dstX, int dstY, int dstZ, ece::size_t srcWidth, ece::size_t srcHeight, ece::size_t srcDepth)
			{
				checkErrors(glCopyImageSubData(srcName, static_cast<GLenum>(srcTarget), srcLevel, srcX, srcY, srcZ, dstName, static_cast<GLenum>(dstTarget), dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth));
			}

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

			inline void OpenGL::debugMessageInsert(SourceDebugMessage source, TypeDebugMessage type, Handle id, SeverityDebugMessage severity, const std::string & message)
			{
				checkErrors(glDebugMessageInsert(static_cast<GLenum>(source), static_cast<GLenum>(type), id, static_cast<GLenum>(severity), static_cast<ece::size_t>(message.size()), message.data()));
			}
			
			inline void OpenGL::pushDebugGroup(SourceDebugMessage source, Handle id, const std::string & message)
			{
				checkErrors(glPushDebugGroup(static_cast<GLenum>(source), id, static_cast<ece::size_t>(message.size()), message.data()));
			}
			
			inline void OpenGL::popDebugGroup()
			{
				checkErrors(glPopDebugGroup());
			}

			inline void OpenGL::objectLabel(Identifier identifier, Handle name, const std::string & label)
			{
				checkErrors(glObjectLabel(static_cast<GLenum>(identifier), name, static_cast<ece::size_t>(label.size()), label.data()));
			}

			inline void OpenGL::objectPtrLabel(void * ptr, const std::string & label)
			{
				checkErrors(glObjectPtrLabel(ptr, static_cast<ece::size_t>(label.size()), label.data()));
			}

			inline auto OpenGL::getDebugMessageLog(ece::size_t count) -> std::vector<DebugMessage>
			{
				const auto bufSize = ece::size_t{ 4096 };
				auto sources = std::vector<SourceDebugMessage>(count);
				auto types = std::vector<TypeDebugMessage>(count);
				auto ids = std::vector<Handle>(count);
				auto severities = std::vector<SeverityDebugMessage>(count);
				auto lengths = std::vector<ece::size_t>(count);
				auto messageLog = std::vector<std::string>(count, std::string(bufSize, '\0'));

				auto size = checkErrors(glGetDebugMessageLog(count, bufSize, reinterpret_cast<GLenum *>(sources.data()), reinterpret_cast<GLenum *>(types.data()), reinterpret_cast<GLuint *>(ids.data()), reinterpret_cast<GLenum *>(severities.data()), reinterpret_cast<GLsizei *>(lengths.data()), reinterpret_cast<GLchar *>(messageLog[0].data())));

				auto messages = std::vector<DebugMessage>(size);
				for (auto i = ece::size_t{ 0 }; i < size; ++i) {
					messages[i].source = sources[i];
					messages[i].type = types[i];
					messages[i].id = ids[i];
					messages[i].severity = severities[i];
					messages[i].message = messageLog[i].substr(0, lengths[i]);
				}
				return std::move(messages);
			}

			inline auto OpenGL::getObjectLabel(Identifier identifier, Handle name) -> std::string
			{
				const auto bifSize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
				auto label = std::string(bifSize, '\0');
				checkErrors(glGetObjectLabel(static_cast<GLenum>(identifier), name, bifSize, reinterpret_cast<GLsizei *>(&length), label.data()));
				label.resize(length);
				return std::move(label);
			}

			inline auto OpenGL::getObjectPtrLabel(void * ptr) -> std::string
			{
				const auto bifSize = ece::size_t{ 4096 };
				auto length = ece::size_t{ 0 };
				auto label = std::string(bifSize, '\0');
				checkErrors(glGetObjectPtrLabel(ptr, bifSize, reinterpret_cast<GLsizei *>(&length), label.data()));
				label.resize(length);
				return std::move(label);
			}
			
			inline auto OpenGL::getInternalformat64(TextureTarget target, PixelInternalFormat internalformat, InternalFormatInformation pname) -> std::vector<std::int64_t>
			{
				const auto bufsize = ece::size_t{ 32 };

				auto params = std::vector<std::int64_t>{};
				checkErrors(glGetInternalformati64v(static_cast<GLenum>(target), static_cast<GLenum>(internalformat), static_cast<GLenum>(pname), bufsize, params.data()));
				return std::move(params);
			}

			inline void OpenGL::bindBuffersRange(IndexedBufferTarget target, Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes)
			{
				checkErrors(glBindBuffersRange(static_cast<GLenum>(target), first, count, reinterpret_cast<const GLuint *>(buffers.data()), reinterpret_cast<const GLintptr *>(offsets.data()), reinterpret_cast<const GLintptr *>(sizes.data())));
			}

			inline void OpenGL::bindBuffersBase(IndexedBufferTarget target, Handle first, const std::vector<Handle> & buffers)
			{
				checkErrors(glBindBuffersBase(static_cast<GLenum>(target), first, static_cast<ece::size_t>(buffers.size()), reinterpret_cast<const GLuint *>(buffers.data())));
			}

			template <class T>
			inline void OpenGL::bufferStorage(BufferType target, const std::vector<T> & data, BufferDataUsage flags)
			{
				checkErrors(glBufferStorage(static_cast<GLenum>(target), data.size() * sizeof(T), data.data(), static_cast<GLbitfield>(flags)));
			}

			inline void OpenGL::bindTextures(Handle first, const std::vector<Handle> & textures)
			{
				checkErrors(glBindTextures(first, static_cast<ece::size_t>(textures.size()), reinterpret_cast<const GLuint *>(textures.data())));
			}

			inline void OpenGL::bindSamplers(Handle first, const std::vector<Handle> & samplers)
			{
				checkErrors(glBindSamplers(first, static_cast<ece::size_t>(samplers.size()), reinterpret_cast<const GLuint *>(samplers.data())));
			}

			template <class T>
			inline void OpenGL::clearTexSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, DataType type, const std::vector<T> & data)
			{
				checkErrors(glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<GLenum>(format), static_cast<GLenum>(type), reinterpret_cast<const GLvoid *>(data.data())));
			}

			template <class T>
			inline void OpenGL::clearTexImage(Handle texture, int level, PixelFormat format, DataType type, const std::vector<T> & data)
			{
				checkErrors(glClearTexImage(texture, level, static_cast<GLenum>(format), static_cast<GLenum>(type), reinterpret_cast<const GLvoid *>(data.data())));
			}

			inline void OpenGL::bindImageTextures(Handle first, const std::vector<Handle> & textures)
			{
				checkErrors(glBindImageTextures(first, static_cast<ece::size_t>(textures.size()), reinterpret_cast<const GLuint *>(textures.data())));
			}

			inline void OpenGL::bindVertexBuffers(Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes)
			{
				checkErrors(glBindVertexBuffers(first, count, reinterpret_cast<const GLuint *>(buffers.data()), reinterpret_cast<const GLintptr *>(offsets.data()), reinterpret_cast<const GLsizei *>(sizes.data())));
			}

			inline void OpenGL::enableVertexArrayAttrib(Handle vaobj, unsigned int index)
			{
				checkErrors(glEnableVertexArrayAttrib(vaobj, index));
			}

			inline void OpenGL::disableVertexArrayAttrib(Handle vaobj, unsigned int index)
			{
				checkErrors(glDisableVertexArrayAttrib(vaobj, index));
			}

			inline void OpenGL::namedBufferData(Handle buffer, ece::size_t size, const void * data, BufferUsage usage)
			{
				checkErrors(glNamedBufferData(buffer, size, data, static_cast<GLenum>(usage)));
			}

			inline void OpenGL::namedBufferSubData(Handle buffer, int offset, ece::size_t size, const void * data)
			{
				checkErrors(glNamedBufferSubData(buffer, reinterpret_cast<GLintptr>(&offset), size, data));
			}

			inline auto OpenGL::mapNamedBufferRange(Handle buffer, int offset, ece::size_t length, MapBufferRangeAccessFlag access) -> void *
			{
				return checkErrors(glMapNamedBufferRange(buffer, reinterpret_cast<GLintptr>(&offset), length, static_cast<GLbitfield>(access)));
			}

			inline auto OpenGL::mapNamedBuffer(Handle buffer, MapBufferRangeAccessFlag access) -> void *
			{
				return checkErrors(glMapNamedBuffer(buffer, static_cast<GLbitfield>(access)));
			}
			
			inline void OpenGL::flushMappedNamedBufferRange(Handle buffer, int offset, ece::size_t length)
			{
				checkErrors(glFlushMappedNamedBufferRange(buffer, reinterpret_cast<GLintptr>(&offset), length))
			}
			
			inline auto OpenGL::unmapNamedBuffer(Handle buffer) -> bool
			{
				return checkErrors(glUnmapNamedBuffer(buffer));
			}

			inline void OpenGL::copyNamedBufferSubData(Handle readBuffer, Handle writeBuffer, int readOffset, int writeOffset, ece::size_t size)
			{
				checkErrors(glCopyNamedBufferSubData(readBuffer, writeBuffer, reinterpret_cast<GLintptr>(&readOffset), reinterpret_cast<GLintptr>(&writeOffset), size));
			}

			inline auto OpenGL::getNamedBufferParameter(Handle buffer, BufferParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetNamedBufferParameteriv(buffer, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getNamedBufferParameter64(Handle buffer, BufferParameter pname) ->std::int64_t
			{
				auto params = std::int64_t{ 0 };
				checkErrors(glGetNamedBufferParameteri64v(buffer, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getNamedBufferSubData(Handle buffer, int offset, ece::size_t size) -> void *
			{
				auto data = reinterpret_cast<void *>(0);
				checkErrors(glGetNamedBufferSubData(buffer, reinterpret_cast<GLintptr>(&offset), size, data));
				return std::move(data);
			}

			inline auto OpenGL::getNamedBufferPointer(Handle buffer) -> void *
			{
				const auto pname = GL_BUFFER_MAP_POINTER;

				auto params = reinterpret_cast<void *>(0);
				checkErrors(glGetNamedBufferPointerv(buffer, pname, &params));
				return std::move(params);
			}
			
			template <class T>
			inline auto OpenGL::getnUniform([[maybe_unused]] Handle program, [[maybe_unused]] int location, [[maybe_unused]] ece::size_t bufSize) -> std::vector<T>
			{
				static_assert("No existing specialization for OpenGL::getnUniform.");
			}

			template <> inline auto OpenGL::getnUniform<float>(Handle program, int location, ece::size_t bufSize) -> std::vector<float>
			{
				auto params = std::vector<float>(bufSize);
				checkErrors(glGetnUniformfv(program, location, bufSize, reinterpret_cast<GLfloat *>(params.data())));
				return std::move(params);
			}

			template <> inline auto OpenGL::getnUniform<int>(Handle program, int location, ece::size_t bufSize) -> std::vector<int>
			{
				auto params = std::vector<int>(bufSize);
				checkErrors(glGetnUniformiv(program, location, bufSize, reinterpret_cast<GLint *>(params.data())));
				return std::move(params);
			}

			template <> inline auto OpenGL::getnUniform<unsigned int>(Handle program, int location, ece::size_t bufSize) -> std::vector<unsigned int>
			{
				auto params = std::vector<unsigned int>(bufSize);
				checkErrors(glGetnUniformuiv(program, location, bufSize, reinterpret_cast<GLuint *>(params.data())));
				return std::move(params);
			}

			template <> inline auto OpenGL::getnUniform<double>(Handle program, int location, ece::size_t bufSize) -> std::vector<double>
			{
				auto params = std::vector<double>(bufSize);
				checkErrors(glGetnUniformdv(program, location, bufSize, reinterpret_cast<GLdouble *>(params.data())));
				return std::move(params);
			}

			inline void OpenGL::textureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t  width, ece::size_t  height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * pixels)
			{
				checkErrors(glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::textureSubImage2D(Handle texture, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, PixelDataType type, const void *pixels)
			{
				checkErrors(glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}

			inline void OpenGL::textureSubImage1D(Handle texture, int level, int xoffset, ece::size_t width, PixelFormat format, PixelDataType type, const void *pixels)
			{
				checkErrors(glTextureSubImage1D(texture, level, xoffset, width, static_cast<GLenum>(format), static_cast<GLenum>(type), pixels));
			}
			
			inline void OpenGL::copyTextureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, ece::size_t width, ece::size_t height)
			{
				checkErrors(glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height));
			}

			inline void OpenGL::copyTextureSubImage2D(Handle texture, int level, int xoffset, int yoffset, int x, int y, ece::size_t width, ece::size_t height)
			{
				checkErrors(glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height));
			}

			inline void OpenGL::copyTextureSubImage1D(Handle texture, int level, int xoffset, int x, int y, ece::size_t width)
			{
				checkErrors(glCopyTextureSubImage1D(texture, level, xoffset, x, y, width));
			}
			
			inline void OpenGL::compressedTextureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, ece::size_t imageSize, const void * data)
			{
				checkErrors(glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<GLenum>(format), imageSize, data));
			}
			
			inline void OpenGL::compressedTextureSubImage2D(Handle texture, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, ece::size_t imageSize, const void *data)
			{
				checkErrors(glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, static_cast<GLenum>(format), imageSize, data));
			}

			inline void OpenGL::compressedTextureSubImage1D(Handle texture, int level, int xoffset, ece::size_t width, PixelFormat format, ece::size_t imageSize, const void *data)
			{
				checkErrors(glCompressedTextureSubImage1D(texture, level, xoffset, width, static_cast<GLenum>(format), imageSize, data));
			}
			
			inline void OpenGL::textureBuffer(Handle texture, PixelInternalFormat internalformat, Handle buffer)
			{
				return checkErrors(glTextureBuffer(texture, static_cast<GLenum>(internalformat), buffer));
			}

			inline void OpenGL::textureParameter(TextureTarget texture, TextureParameter pname, float param)
			{
				checkErrors(glTextureParameterf(static_cast<GLenum>(texture), static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::textureParameter(TextureTarget texture, TextureParameter pname, int param)
			{
				checkErrors(glTextureParameteri(static_cast<GLenum>(texture), static_cast<GLenum>(pname), param));
			}

			inline void OpenGL::textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<float> & param)
			{
				checkErrors(glTextureParameterfv(static_cast<GLenum>(texture), static_cast<GLenum>(pname), param.data()));
			}

			inline void OpenGL::textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<int> & param)
			{
				checkErrors(glTextureParameteriv(static_cast<GLenum>(texture), static_cast<GLenum>(pname), param.data()));
			}

			inline void OpenGL::textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<unsigned int> & param)
			{
				checkErrors(glTextureParameterIuiv(static_cast<GLenum>(texture), static_cast<GLenum>(pname), param.data()));
			}
			
			inline void OpenGL::generateTextureMipmap(Handle texture)
			{
				checkErrors(glGenerateTextureMipmap(texture));
			}

			template <class T>
			inline auto OpenGL::getTextureParameter(Handle texture, TextureParameter pname) -> std::vector<T>
			{
				static_assert("No existing specialization for OpenGL::getTextureParameter.");
			}

			template <>
			inline auto OpenGL::getTextureParameter<float>(Handle texture, TextureParameter pname) -> std::vector<float>
			{
				auto params = std::vector<float>{};
				checkErrors(glGetTextureParameterfv(texture, static_cast<GLenum>(pname), reinterpret_cast<GLfloat *>(params.data())));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTextureParameter<int>(Handle texture, TextureParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetTextureParameteriv(texture, static_cast<GLenum>(pname), reinterpret_cast<GLint *>(params.data())));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTextureParameter<unsigned int>(Handle texture, TextureParameter pname) -> std::vector<unsigned int>
			{
				auto params = std::vector<unsigned int>{};
				checkErrors(glGetTextureParameterIuiv(texture, static_cast<GLenum>(pname), reinterpret_cast<GLuint *>(params.data())));
				return std::move(params);
			}

			template <class T>
			inline auto OpenGL::getTextureLevelParameter(Handle texture, int level, TextureLevelParameter pname) -> std::vector<T>
			{
				static_assert("No existing specialization for OpenGL::getTextureLevelParameter.");
			}

			template <>
			inline auto OpenGL::getTextureLevelParameter<float>(Handle texture, int level, TextureLevelParameter pname) -> std::vector<float>
			{
				auto params = std::vector<float>{};
				checkErrors(glGetTextureLevelParameterfv(texture, level, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}

			template <>
			inline auto OpenGL::getTextureLevelParameter<int>(Handle texture, int level, TextureLevelParameter pname) -> std::vector<int>
			{
				auto params = std::vector<int>{};
				checkErrors(glGetTextureLevelParameteriv(texture, level, static_cast<GLenum>(pname), params.data()));
				return std::move(params);
			}
			
			inline auto OpenGL::getnTexImage(TextureTarget target, int level, PixelFormat format, DataType type, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<int>(bufSize).data()); // TODO: should be not working.
				checkErrors(glGetnTexImage(static_cast<GLenum>(target), level, static_cast<GLenum>(format), static_cast<GLenum>(type), bufSize, pixels));
				return std::move(pixels);
			}
			
			inline auto OpenGL::getTextureImage(Handle texture, int level, PixelFormat format, DataType type, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<int>(bufSize).data()); // TODO: should be not working.
				checkErrors(glGetTextureImage(texture, level, static_cast<GLenum>(format), static_cast<GLenum>(type), bufSize, pixels));
				return std::move(pixels);
			}
			
			inline auto OpenGL::getnCompressedTexImage(TextureTarget target, int level, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<int>(bufSize).data()); // TODO: should be not working.
				checkErrors(glGetnCompressedTexImage(static_cast<GLenum>(target), level, bufSize, pixels));
				return std::move(pixels);
			}
			
			inline auto OpenGL::getCompressedTextureImage(Handle texture, int level, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<int>(bufSize).data()); // TODO: should be not working.
				checkErrors(glGetCompressedTextureImage(texture, level, bufSize, pixels));
				return std::move(pixels);
			}
			
			inline auto OpenGL::readnPixels(int x, int y, ece::size_t width, ece::size_t height, PixelFormat format, DataType type, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(std::vector<float>(bufSize).data()); // TODO: should be not working.
				checkErrors(glReadnPixels(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height), static_cast<GLenum>(format), static_cast<GLenum>(type), bufSize, pixels));
				return std::move(pixels);
			}
			
			inline void OpenGL::namedFramebufferReadBuffer(Handle framebuffer, ColorBuffer mode)
			{
				checkErrors(glNamedFramebufferReadBuffer(framebuffer, static_cast<GLenum>(mode)));
			}

			inline void OpenGL::blitNamedFramebuffer(Handle readFramebuffer, Handle drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, Bitfield mask, ImageFilter filter)
			{
				checkErrors(glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, static_cast<GLbitfield>(mask), static_cast<GLenum>(filter)));
			}
		
			inline void OpenGL::namedFramebufferDrawBuffer(Handle framebuffer, ColorBuffer buf)
			{
				checkErrors(glNamedFramebufferDrawBuffer(framebuffer, static_cast<GLenum>(buf)));
			}

			inline void OpenGL::namedFramebufferDrawBuffers(Handle framebuffer, const std::vector<ColorBuffer> & bufs)
			{
				checkErrors(glNamedFramebufferDrawBuffers(framebuffer, static_cast<ece::size_t>(bufs.size()), reinterpret_cast<const GLenum *>(bufs.data())));
			}
			
			inline void OpenGL::clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<int> & value)
			{
				checkErrors(glClearNamedFramebufferiv(framebuffer, static_cast<GLenum>(buffer), drawbuffer, reinterpret_cast<const GLint *>(value.data())));
			}
			
			inline void OpenGL::clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<unsigned int> & value)
			{
				checkErrors(glClearNamedFramebufferuiv(framebuffer, static_cast<GLenum>(buffer), drawbuffer, reinterpret_cast<const GLuint *>(value.data())));
			}
			
			inline void OpenGL::clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<float>value)
			{
				checkErrors(glClearNamedFramebufferfv(framebuffer, static_cast<GLenum>(buffer), drawbuffer, reinterpret_cast<const GLfloat *>(value.data())));
			}
			
			inline void OpenGL::clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, float depth, int stencil)
			{
				checkErrors(glClearNamedFramebufferfi(framebuffer, static_cast<GLenum>(buffer), drawbuffer, depth, stencil));
			}
			
			inline void OpenGL::namedRenderbufferStorageMultisample(Handle renderbuffer, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height)
			{
				checkErrors(glNamedRenderbufferStorageMultisample(renderbuffer, samples, static_cast<GLenum>(internalformat), width, height));
			}
			
			inline void OpenGL::namedRenderbufferStorage(Handle renderbuffer, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height)
			{
				checkErrors(glNamedRenderbufferStorage(renderbuffer, static_cast<GLenum>(internalformat), width, height));
			}
			
			inline void OpenGL::namedFramebufferRenderbuffer(Handle framebuffer, FramebufferAttachment attachment, unsigned int renderbuffer)
			{
				const auto renderbuffertarget = GL_RENDERBUFFER;
				checkErrors(glNamedFramebufferRenderbuffer(framebuffer, static_cast<GLenum>(attachment), renderbuffertarget, renderbuffer));
			}
			
			inline void OpenGL::namedFramebufferTexture(Handle framebuffer, FramebufferAttachment attachment, Handle texture, int level)
			{
				checkErrors(glNamedFramebufferTexture(framebuffer, static_cast<GLenum>(attachment), texture, level));
			}
			
			inline void OpenGL::namedFramebufferTextureLayer(Handle framebuffer, FramebufferAttachment attachment, Handle texture, int level, int layer)
			{
				checkErrors(glNamedFramebufferTextureLayer(framebuffer, static_cast<GLenum>(attachment), texture, level, layer));
			}
			
			inline auto OpenGL::checkNamedFramebufferStatus(Handle framebuffer, FramebufferTarget target) -> FramebufferStatus
			{
				auto result = checkErrors(glCheckNamedFramebufferStatus(framebuffer, static_cast<GLenum>(target)));
				return std::move(static_cast<FramebufferStatus>(result));
			}

			inline auto OpenGL::getNamedFramebufferAttachmentParameter(Handle framebuffer, FramebufferAttachment attachment, FramebufferAttachmentParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetNamedFramebufferAttachmentParameteriv(framebuffer, static_cast<GLenum>(attachment), static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getNamedRenderbufferParameter(Handle renderbuffer, RenderbufferParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetNamedRenderbufferParameteriv(renderbuffer, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}
			
			inline auto OpenGL::getGraphicsResetStatus() -> GraphicResetStatus 
			{
				auto result = checkErrors(glGetGraphicsResetStatus());
				return std::move(static_cast<GraphicResetStatus>(result));
			}
			
			inline auto OpenGL::createBuffers(ece::size_t n) -> std::vector<Handle>
			{
				auto buffers = std::vector<Handle>(n);
				checkErrors(glCreateBuffers(n, reinterpret_cast<GLuint *>(buffers.data())));
				return std::move(buffers);
			}
			
			template <class T>
			inline void OpenGL::namedBufferStorage(Handle buffer, const std::vector<T> & data, BufferDataUsage flags)
			{
				checkErrors(glNamedBufferStorage(buffer, data.size() * sizeof(T), data.data(), static_cast<GLbitfield>(flags)));
			}

			template <class T>
			inline void OpenGL::clearNamedBufferData(BufferType buffer, PixelInternalFormat internalformat, PixelFormat format, DataType type, const std::vector<T> & data)
			{
				checkErrors(glClearNamedBufferData(static_cast<GLenum>(buffer), static_cast<GLenum>(internalformat), static_cast<GLenum>(format), static_cast<GLenum>(type), reinterpret_cast<const void *>(data.data())));
			}
			
			inline auto OpenGL::createProgramPipelines(ece::size_t n) -> std::vector<Handle>
			{
				auto pipelines = std::vector<Handle>(n);
				checkErrors(glCreateProgramPipelines(n, reinterpret_cast<GLuint *>(pipelines.data())));
				return std::move(pipelines);
			}

			inline void OpenGL::memoryBarrierByRegion(BarrierByRegion barriers)
			{
				checkErrors(glMemoryBarrierByRegion(static_cast<GLbitfield>(barriers)));
			}

			inline void OpenGL::bindTextureUnit(Handle unit, Handle texture)
			{
				checkErrors(glBindTextureUnit(unit, texture));
			}

			inline auto OpenGL::createTextures(TextureTarget target, ece::size_t n) -> std::vector<Handle>
			{
				auto textures = std::vector<Handle>(n);
				checkErrors(glCreateTextures(static_cast<GLenum>(target), n, reinterpret_cast<GLuint *>(textures.data())));
				return std::move(textures);
			}

			inline auto OpenGL::createSamplers(ece::size_t n) -> std::vector<Handle>
			{
				auto samplers = std::vector<Handle>(n);
				checkErrors(glCreateSamplers(n, reinterpret_cast<GLuint *>(samplers.data())));
				return std::move(samplers);
			}
			
			inline void OpenGL::textureBufferRange(Handle texture, PixelInternalFormat internalFormat, Handle buffer, int offset, ece::size_t size)
			{
				checkErrors(glTextureBufferRange(texture, static_cast<GLenum>(internalFormat), buffer, reinterpret_cast<GLintptr>(&offset), size));
			}

			inline auto OpenGL::getTextureSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, DataType type, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(0);
				checkErrors(glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, static_cast<GLenum>(format), static_cast<GLenum>(type), bufSize, pixels));
				return std::move(pixels);
			}

			inline auto OpenGL::getCompressedTextureSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, ece::size_t bufSize) -> void *
			{
				auto pixels = reinterpret_cast<void *>(0);
				checkErrors(glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels));
				return std::move(pixels);
			}
			
			inline void OpenGL::textureStorage1D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width)
			{
				checkErrors(glTextureStorage1D(texture, levels, static_cast<GLenum>(internalformat), width));
			}
			
			inline void OpenGL::textureStorage2D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height)
			{
				checkErrors(glTextureStorage2D(texture, levels, static_cast<GLenum>(internalformat), width, height));
			}
			
			inline void OpenGL::textureStorage3D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth)
			{
				checkErrors(glTextureStorage3D(texture, levels, static_cast<GLenum>(internalformat), width, height, depth));
			}
			
			inline void OpenGL::textureStorage2DMultisample(Handle texture, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, bool fixedsamplelocations)
			{
				checkErrors(glTextureStorage2DMultisample(texture, samples, static_cast<GLenum>(internalformat), width, height, fixedsamplelocations));
			}
			
			inline void OpenGL::textureStorage3DMultisample(Handle texture, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedsamplelocations)
			{
				checkErrors(glTextureStorage3DMultisample(texture, samples, static_cast<GLenum>(internalformat), width, height, depth, fixedsamplelocations));
			}

			inline auto OpenGL::createFramebuffers(ece::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glCreateFramebuffers(n, ids.data()));
				return std::move(ids);
			}

			inline void OpenGL::namedFramebufferParameteri(Handle framebuffer, FramebufferParameter pname, int param)
			{
				checkErrors(glNamedFramebufferParameteri(framebuffer, static_cast<GLenum>(pname), param));
			}

			inline auto OpenGL::getNamedFramebufferParameter(Handle framebuffer, FramebufferParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetNamedFramebufferParameteriv(framebuffer, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::createRenderbuffers(ece::size_t n) -> std::vector<Handle>
			{
				auto renderbuffers = std::vector<Handle>(n);
				checkErrors(glCreateRenderbuffers(n, renderbuffers.data()));
				return std::move(renderbuffers);
			}
			
			inline void OpenGL::textureBarrier()
			{
				checkErrors(glTextureBarrier());
			}

			inline auto OpenGL::createVertexArrays(ece::size_t n) -> std::vector<Handle>
			{
				auto arrays = std::vector<Handle>(n);
				checkErrors(glCreateVertexArrays(n, arrays.data()));
				return std::move(arrays);
			}

			inline void OpenGL::vertexArrayElementBuffer(Handle vaobj, Handle buffer)
			{
				checkErrors(glVertexArrayElementBuffer(vaobj, buffer));
			}

			inline void OpenGL::vertexArrayAttribFormat(Handle vaobj, Handle attribindex, int size, DataType type, bool normalized, unsigned int relativeoffset)
			{
				checkErrors(glVertexArrayAttribFormat(vaobj, attribindex, size, static_cast<GLenum>(type), normalized, relativeoffset));
			}

			inline void OpenGL::vertexArrayAttribIFormat(Handle vaobj, Handle attribindex, int size, DataType type, unsigned int relativeoffset)
			{
				checkErrors(glVertexArrayAttribIFormat(vaobj, attribindex, size, static_cast<GLenum>(type), relativeoffset));
			}

			inline void OpenGL::vertexArrayAttribLFormat(Handle vaobj, Handle attribindex, int size, DataType type, unsigned int relativeoffset)
			{
				checkErrors(glVertexArrayAttribLFormat(vaobj, attribindex, size, static_cast<GLenum>(type), relativeoffset));
			}

			inline void OpenGL::vertexArrayVertexBuffer(Handle vaobj, Handle bindingindex, Handle buffer, int offset, ece::size_t stride)
			{
				checkErrors(glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, reinterpret_cast<GLintptr>(&offset), stride));
			}
			
			inline void OpenGL::vertexArrayVertexBuffers(Handle vaobj, Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes)
			{
				checkErrors(glVertexArrayVertexBuffers(vaobj, first, count, reinterpret_cast<const GLuint *>(buffers.data()), reinterpret_cast<const GLintptr *>(offsets.data()), reinterpret_cast<const GLsizei *>(sizes.data())));
			}
			
			inline void OpenGL::vertexArrayAttribBinding(Handle vaobj, unsigned int attribindex, unsigned int bindingindex)
			{
				checkErrors(glVertexArrayAttribBinding(vaobj, attribindex, bindingindex));
			}

			inline void OpenGL::vertexArrayBindingDivisor(Handle vaobj, unsigned int bindingindex, unsigned int divisor)
			{
				checkErrors(glVertexArrayBindingDivisor(vaobj, bindingindex, divisor));
			}

			inline auto OpenGL::getVertexArray(Handle vaobj) -> int
			{
				const auto pname = GL_ELEMENT_ARRAY_BUFFER_BINDING;

				auto params = 0;
				checkErrors(glGetVertexArrayiv(vaobj, pname, &params));
				return std::move(params);
			}

			inline auto OpenGL::getVertexArrayIndexed64(Handle vaobj, Handle index, VertexAttribParameter pname) -> std::int64_t
			{
				auto param = std::int64_t{ 0 };
				checkErrors(glGetVertexArrayIndexed64iv(vaobj, index, static_cast<GLenum>(pname), &param));
				return std::move(param);
			}

			inline auto OpenGL::getVertexArrayIndexed(Handle vaobj, Handle index, VertexAttribParameter pname) -> int
			{
				auto param = 0;
				checkErrors(glGetVertexArrayIndexediv(vaobj, index, static_cast<GLenum>(pname), &param));
				return std::move(param);
			}
			
			inline auto OpenGL::createTransformFeedbacks(ece::size_t n) -> std::vector<Handle>
			{
				auto ids = std::vector<Handle>(n);
				checkErrors(glCreateTransformFeedbacks(n, reinterpret_cast<GLuint *>(ids.data())));
				return std::move(ids);
			}
			
			inline void OpenGL::transformFeedbackBufferRange(Handle xfb, Handle index, Handle buffer, int offset, ece::size_t size)
			{
				checkErrors(glTransformFeedbackBufferRange(xfb, index, buffer, offset, size));
			}

			inline void OpenGL::transformFeedbackBufferBase(Handle xfb, Handle index, Handle buffer)
			{
				checkErrors(glTransformFeedbackBufferBase(xfb, index, buffer));
			}
			
			inline void OpenGL::clipControl(ClipControl origin, ClipControlDepthMode depth)
			{
				checkErrors(glClipControl(static_cast<GLenum>(origin), static_cast<GLenum>(depth)));
			}
			
			inline void OpenGL::invalidateNamedFramebufferSubData(Handle framebuffer, const std::vector<FramebufferAttachment> & attachments, int x, int y, int width, int height)
			{
				checkErrors(glInvalidateNamedFramebufferSubData(framebuffer, static_cast<ece::size_t>(attachments.size()), reinterpret_cast<const GLenum *>(attachments.data()), x, y, width, height));
			}

			inline void OpenGL::invalidateNamedFramebufferData(Handle framebuffer, const std::vector<FramebufferAttachment> & attachments)
			{
				checkErrors(glInvalidateNamedFramebufferData(framebuffer, static_cast<ece::size_t>(attachments.size()), reinterpret_cast<const GLenum *>(attachments.data())));
			}

			inline auto OpenGL::getTransformFeedback(Handle xfb, TransformFeedbackParameter pname) -> int
			{
				auto params = 0;
				checkErrors(glGetTransformFeedbackiv(xfb, static_cast<GLenum>(pname), &params));
				return std::move(params);
			}

			inline auto OpenGL::getTransformFeedback(Handle xfb, TransformFeedbackParameter pname, Handle index) -> int
			{
				auto params = 0;
				checkErrors(glGetTransformFeedbacki_v(xfb, static_cast<GLenum>(pname), index, &params));
				return std::move(params);
			}
			
			inline auto OpenGL::getTransformFeedback64(Handle xfb, TransformFeedbackParameter pname, Handle index) -> std::int64_t
			{
				auto params = std::int64_t{ 0 };
				checkErrors(glGetTransformFeedbacki64_v(xfb, static_cast<GLenum>(pname), index, &params));
				return std::move(params);
			}

			inline void OpenGL::specializeShader(Handle shader, const std::string & pEntryPoint, const std::vector<Handle> & pConstantIndex, const std::vector<Handle> & pConstantValue)
			{
				checkErrors(glSpecializeShader(shader, pEntryPoint.data(), static_cast<ece::size_t>(pConstantIndex.size()), reinterpret_cast<const GLuint *>(pConstantIndex.data()), reinterpret_cast<const GLuint *>(pConstantValue.data())));
			}
			
			inline void OpenGL::polygonOffsetClamp(float factor, float units, float clamp)
			{
				checkErrors(glPolygonOffsetClamp(factor, units, clamp))
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
