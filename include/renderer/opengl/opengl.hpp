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

#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "renderer/opengl/opengl_exception.hpp"
#include "utility/mathematics.hpp"
#include "renderer/opengl/enum.hpp"
#include "utility/indexing.hpp"
#include "utility/container.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			class RenderContext;
		}

		namespace opengl
		{
			using rendering::RenderContext;

			namespace OpenGL
			{
				// OpenGL headers

				static inline auto getError() -> ErrorGL;

				template <class T> static inline void vertexAttrib(Handle index, T v);
				template <class T> static inline void vertexAttrib(Handle index, Vector2u<T> v);
				template <class T> static inline void vertexAttrib(Handle index, Vector3u<T> v);
				template <class T> static inline void vertexAttrib(Handle index, Vector4u<T> v);
				template <ece::size_t Size, typename enabled = std::enable_if_t<(Size > 0 && Size <= 4)>> static inline void vertexAttribP(Handle index, PackedVertexAttribType type, bool normalized, unsigned int value);

				template<> inline void vertexAttrib(Handle index, float v);
				template<> inline void vertexAttrib(Handle index, short v);
				template<> inline void vertexAttrib(Handle index, double v);
				template<> inline void vertexAttrib(Handle index, int v);
				template<> inline void vertexAttrib(Handle index, unsigned int v);
				template<> inline void vertexAttrib(Handle index, Vector2u<float> v);
				template<> inline void vertexAttrib(Handle index, Vector2u<short> v);
				template<> inline void vertexAttrib(Handle index, Vector2u<double> v);
				template<> inline void vertexAttrib(Handle index, Vector2u<int> v);
				template<> inline void vertexAttrib(Handle index, Vector2u<unsigned int> v);
				template<> inline void vertexAttrib(Handle index, Vector3u<float> v);
				template<> inline void vertexAttrib(Handle index, Vector3u<short> v);
				template<> inline void vertexAttrib(Handle index, Vector3u<double> v);
				template<> inline void vertexAttrib(Handle index, Vector3u<int> v);
				template<> inline void vertexAttrib(Handle index, Vector3u<unsigned int> v);
				template<> inline void vertexAttrib(Handle index, Vector4u<float> v);
				template<> inline void vertexAttrib(Handle index, Vector4u<short> v);
				template<> inline void vertexAttrib(Handle index, Vector4u<double> v);
				template<> inline void vertexAttrib(Handle index, Vector4u<int> v);
				template<> inline void vertexAttrib(Handle index, Vector4u<unsigned int> v);
				template<> inline void vertexAttrib(Handle index, std::array<std::byte, 4> v);

				static inline void vertexAttribPointer(const int location, const ece::size_t size, const DataType type, const bool normalized, const ece::size_t stride, const ece::offset_t offset = 0);
				static inline void enableVertexAttribArray(const int location);
				static inline void disableVertexAttribArray(const int location);
				static inline void enable(const Capability cap);
				static inline void disable(const Capability cap);
				static inline void enableIndexed(const Capability cap, const unsigned short int index);
				static inline void disableIndexed(const Capability cap, const unsigned short int index);
				static inline void primitiveRestartIndex(ece::size_t index);
				static inline void drawArrays(const PrimitiveMode mode, const int first, const ece::size_t count);
				static inline void multiDrawArrays(PrimitiveMode mode, const std::vector<int> & first, const std::vector<ece::size_t> & count, ece::size_t drawcount);
				static inline void drawElements(const PrimitiveMode mode, const ece::size_t count, const int offset);
				static inline void multiDrawElements(PrimitiveMode mode, const std::vector<ece::size_t> & count, const std::vector<ece::size_t *> & indices, ece::size_t drawcount);
				static inline void drawRangeElements(PrimitiveMode mode, ece::size_t start, ece::size_t end, ece::size_t count, const ece::size_t * indices);
				static inline void drawArraysInstanced(const PrimitiveMode mode, const int first, const ece::size_t count, const ece::size_t primcount);
				static inline void drawElementsInstanced(const PrimitiveMode mode, const ece::size_t count, ece::offset_t offset, const ece::size_t primcount);
				static inline void drawElementsBaseVertex(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, int basevertex);
				static inline void drawRangeElementsBaseVertex(PrimitiveMode mode, ece::size_t start, ece::size_t end, ece::size_t count, std::vector<ece::size_t> & indices, int basevertex);
				static inline void drawElementsInstancedBaseVertex(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, ece::size_t primcount, int basevertex);
				static inline void multiDrawElementsBaseVertex(PrimitiveMode mode, const std::vector<ece::size_t> & count, const std::vector<ece::size_t *> & indices, ece::size_t drawcount, const std::vector<int> & basevertex);
				static inline auto genBuffers() -> Handle;
				static inline auto genBuffers(const int count) -> std::vector<Handle>;
				static inline void deleteBuffer(const Handle buffer);
				static inline void deleteBuffers(const std::vector<Handle> & buffers);
				static inline void bindBuffer(const BufferType type, const Handle handle);
				static inline void bindBufferRange(IndexedBufferTarget target, Handle index, Handle buffer, int offset, ece::size_t size);
				static inline void bindBufferBase(IndexedBufferTarget target, Handle index, Handle buffer);
				template<class C, typename enabled = std::enable_if_t<contiguous_container_v<C> && is_container_v<C>>>
				static inline void bufferData(const BufferType type, const C & data, const BufferUsage usage, const int offset = 0);
				template <class E>
				static inline void bufferData(const BufferType type, const ece::size_t size, const BufferUsage usage, int offset = 0);
				template<class C, typename enabled = std::enable_if_t<contiguous_container_v<C> && is_container_v<C>>>
				static inline void bufferSubData(BufferType target, int offset, ece::size_t size, const C & data);
				static inline auto mapBufferRange(BufferType target, int offset, ece::size_t length, MapBufferRangeAccessFlag access) -> void *;
				static inline auto mapBuffer(BufferType target, MapBufferAccessFlag access) -> void *;
				static inline void flushMappedBufferRange(BufferType target, int offset, ece::size_t length);
				static inline auto unmapBuffer(BufferType target) -> bool;
				static inline void copyBufferSubData(BufferType readTarget, BufferType writeTarget, int readOffset, int writeOffset, ece::size_t size);
				static inline auto genVertexArrays() -> Handle;
				static inline auto genVertexArrays(const int count) -> std::vector<Handle>;
				static inline void deleteVertexArrays(ece::size_t n, const std::vector<Handle> & arrays);
				static inline void bindVertexArray(const Handle handle);
				static inline auto isBuffer(Handle buffer) -> bool;
				static inline auto getBufferParameteriv(BufferType target, BufferParameter value) -> int;
				static inline auto getBufferParameteri64v(BufferType target, BufferParameter value) -> int64_t;
				template <class T> static inline auto getBufferSubData(BufferType target, int offset, ece::size_t size) -> std::vector<T>;
				template <class T> static inline auto getBufferPointer(BufferType target) -> T *;
				static inline auto isVertexArray(Handle array) -> bool;
				static inline void depthRange(double nearVal, double farVal);
				static inline void viewport(const int x, const int y, const unsigned int width, const unsigned int height);
				static inline void clampColor(bool clamp);
				static inline void provokingVertex(ProvokeMode provokeMode);
				static inline void beginConditionalRender(Handle id, ConditionalRenderQueryMode mode);
				static inline void endConditionalRender();
				static inline void beginTransformFeedback(PrimitiveMode primitiveMode);
				static inline void endTransformFeedback();
				static inline void beginQuery(QueryObjectType target, Handle id);
				static inline void endQuery(QueryObjectType target);
				static inline auto genQueries(ece::size_t n) -> std::vector<Handle>;
				static inline void deleteQueries(const std::vector<Handle> & ids);
				static inline auto isQuery(Handle id) -> bool;
				static inline auto getQuery(QueryObjectType target, QueryObjectTypeParameter pname) -> std::vector<int>;
				template <typename T> static inline auto getQueryObject([[maybe_unused]] Handle id, [[maybe_unused]] QueryObjectTypeName pname) -> T;
				template<> inline auto getQueryObject(Handle id, QueryObjectTypeName pname) -> int;
				template<> inline auto getQueryObject(Handle id, QueryObjectTypeName pname) -> unsigned int;
				template<> inline auto getQueryObject(Handle id, QueryObjectTypeName pname) -> int64_t;
				template<> inline auto getQueryObject(Handle id, QueryObjectTypeName pname) -> uint64_t;
				static inline auto createShader(const ShaderType type) -> Handle;
				static inline void shaderSource(const Handle handle, const std::string & source);
				static inline void shaderSource(const Handle handle, const std::vector<std::string> & source);
				static inline void compileShader(const Handle handle);
				static inline void deleteShader(const Handle handle);
				static inline auto createProgram() -> Handle;
				static inline void attachShader(const Handle program, const Handle shader);
				static inline void detachShader(const Handle program, const Handle shader);
				static inline void linkProgram(const Handle handle);
				static inline void useProgram(const Handle handle);
				static inline void deleteProgram(Handle program);
				static inline auto getActiveAttrib(Handle program, unsigned int index) -> ProgramAttribute;
				static inline auto getAttribLocation(Handle program, const std::string & name) -> int;
				static inline void bindAttribLocation(Handle program, unsigned int index, const std::string & name);
				static inline auto getUniformLocation(const Handle handle, const std::string & name) -> Handle;
				static inline auto getUniformBlockIndex(Handle program, const std::string & uniformBlockName) -> unsigned int;
				static inline auto getActiveUniformBlockName(Handle program, unsigned int uniformBlockIndex) -> std::string;
				static inline auto getActiveUniformBlock(Handle program, unsigned int uniformBlockIndex, UniformBlockParameter pname) -> int;
				static inline auto getUniformIndices(Handle program, ece::size_t uniformCount) -> UniformBlock;
				static inline auto getActiveUniformName(Handle program, unsigned int uniformIndex) -> std::string;
				static inline auto getActiveUniform(const Handle program, const Handle index) -> UniformInfo;
				static inline auto getActiveUniforms(Handle program, const std::vector<unsigned int> & uniformIndices, UniformDataType pname) -> std::vector<int>;
				template <class T, unsigned int S> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] const std::array<T, S> & v);
				template<> inline void uniform<bool, 1>(const int location, const std::array<bool, 1> & v);
				template<> inline void uniform<float, 1>(const int location, const std::array<float, 1> & v);
				template<> inline void uniform<float, 2>(const int location, const std::array<float, 2> & v);
				template<> inline void uniform<float, 3>(const int location, const std::array<float, 3> & v);
				template<> inline void uniform<float, 4>(const int location, const std::array<float, 4> & v);
				template<> inline void uniform<int, 1>(const int location, const std::array<int, 1> & v);
				template<> inline void uniform<int, 2>(const int location, const std::array<int, 2> & v);
				template<> inline void uniform<int, 3>(const int location, const std::array<int, 3> & v);
				template<> inline void uniform<int, 4>(const int location, const std::array<int, 4> & v);
				template<> inline void uniform<unsigned int, 1>(const int location, const std::array<unsigned int, 1> & v);
				template<> inline void uniform<unsigned int, 2>(const int location, const std::array<unsigned int, 2> & v);
				template<> inline void uniform<unsigned int, 3>(const int location, const std::array<unsigned int, 3> & v);
				template<> inline void uniform<unsigned int, 4>(const int location, const std::array<unsigned int, 4> & v);
				template <class T, unsigned int S> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const std::array<T, S> & v);
				template<> inline void uniform<float, 1>(int location, ece::size_t count, const std::array<float, 1> & value);
				template<> inline void uniform<float, 2>(int location, ece::size_t count, const std::array<float, 2> & value);
				template<> inline void uniform<float, 3>(int location, ece::size_t count, const std::array<float, 3> & value);
				template<> inline void uniform<float, 4>(int location, ece::size_t count, const std::array<float, 4> & value);
				template<> inline void uniform<int, 1>(int location, ece::size_t count, const std::array<int, 1> & value);
				template<> inline void uniform<int, 2>(int location, ece::size_t count, const std::array<int, 2> & value);
				template<> inline void uniform<int, 3>(int location, ece::size_t count, const std::array<int, 3> & value);
				template<> inline void uniform<int, 4>(int location, ece::size_t count, const std::array<int, 4> & value);
				template<> inline void uniform<unsigned int, 1>(int location, ece::size_t count, const std::array<unsigned int, 1> & value);
				template<> inline void uniform<unsigned int, 2>(int location, ece::size_t count, const std::array<unsigned int, 2> & value);
				template<> inline void uniform<unsigned int, 3>(int location, ece::size_t count, const std::array<unsigned int, 3> & value);
				template<> inline void uniform<unsigned int, 4>(int location, ece::size_t count, const std::array<unsigned int, 4> & value);
				template <class T, unsigned int M, unsigned int N> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 2, 2> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 3, 3> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 4, 4> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 2, 3> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 3, 2> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 2, 4> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 4, 2> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 3, 4> & v);
				template<> inline void uniform(const int location, const bool transpose, const Matrix<float, 4, 3> & v);
				template <class T, unsigned int M, unsigned int N> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 2> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 3> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 4> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 3> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 2> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 4> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 2> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 4> & v);
				template<> inline void uniform(const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 3> & v);
				static inline void uniformBlockBinding(Handle program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding);
				static inline void transformFeedbackVaryings(Handle program, ece::size_t count, const std::vector<std::string> & varyings, VaryingBufferMode bufferMode);
				static inline auto getTransformFeedbackVarying(Handle program, unsigned int index) -> VaryingInfo;
				static inline void validateProgram(Handle program);
				static inline auto getProgram(const Handle program, const ProgramParameter pname) -> std::vector<int>;
				static inline void bindFragDataLocation(Handle program, unsigned int colorNumber, const std::string & name);
				static inline auto getFragDataLocation(Handle program, const std::string & name) -> int;
				static inline auto isShader(Handle shader) -> bool;
				static inline auto getShader(const Handle shader, const ShaderParameter pname) -> int;
				static inline auto getAttachedShaders(const Handle program) -> std::vector<Handle>;
				static inline auto getShaderInfoLog(const Handle shader) -> std::string;
				static inline auto getShaderSource(Handle shader) -> std::string;

				template <class T> static inline auto getVertexAttrib([[maybe_unused]] Handle index, [[maybe_unused]] VertexAttribParameter pname) -> T;
				template<> inline auto getVertexAttrib<double>(Handle index, VertexAttribParameter pname) -> double;
				template<> inline auto getVertexAttrib<float>(Handle index, VertexAttribParameter pname) -> float;
				template<> inline auto getVertexAttrib<int>(Handle index, VertexAttribParameter pname) -> int;
				template<> inline auto getVertexAttrib<unsigned int>(Handle index, VertexAttribParameter pname) -> unsigned int;
				static inline auto getVertexAttribPointer(Handle index) -> void *;
				template <typename T> static inline auto getUniform([[maybe_unused]] Handle program, [[maybe_unused]] int location) -> T;
				template<> inline auto getUniform(Handle program, int location) -> float;
				template<> inline auto getUniform(Handle program, int location) -> int;
				template<> inline auto getUniform(Handle program, int location) -> unsigned int;
				static inline auto isProgram(Handle program) -> bool;
				static inline auto getProgramInfoLog(const Handle program) -> std::string;
				static inline auto getMultisample(Handle index) -> FloatVector2u;
				static inline void pointSize(const float size);
				static inline void pointParameter(PointParameter pname, float param);
				static inline void pointParameter(PointParameter pname, int param);
				static inline void pointParameter(PointParameter pname, float & params);
				static inline void pointParameter(PointParameter pname, int & params);
				static inline void lineWidth(const float width);
				static inline void frontFace(const FrontFaceMode mode);
				static inline void cullFace(const CullFaceMode mode);
				static inline void polygonMode(const PolygonMode mode);
				static inline void polygonOffset(float factor, float units);
				static inline void pixelStore(PixelParameter pname, float param);
				static inline void pixelStore(PixelParameter pname, int param);
				static inline void activeTexture(const unsigned int texture);
				static inline void texImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * data);
				static inline void texImage2D(const TextureTypeTarget target, const unsigned int level, const PixelInternalFormat internalFormat, const ece::size_t width, const ece::size_t height, const PixelFormat format, const PixelDataType type, const void * data);
				static inline void texImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, ece::size_t width, PixelFormat format, PixelDataType type, const void * data);
				static inline void copyTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, int x, int y, ece::size_t width, ece::size_t height);
				static inline void copyTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, int x, int y, ece::size_t width);
				static inline void texSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, ece::size_t  width, ece::size_t  height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void texSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void texSubImage1D(TargetTexture1D target, int level, int xoffset, ece::size_t width, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void copyTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, ece::size_t width, ece::size_t height);
				static inline void copyTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, int x, int y, ece::size_t width, ece::size_t height);
				static inline void copyTexSubImage1D(TargetTexture1D target, int level, int xoffset, int x, int y, ece::size_t width);
				static inline void compressedTexImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, ece::size_t imageSize, const void * data);
				static inline void compressedTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t imageSize, const void * data);
				static inline void compressedTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t imageSize, const void * data);
				static inline void compressedTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, ece::size_t imageSize, const void * data);
				static inline void compressedTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, ece::size_t imageSize, const void * data);
				static inline void compressedTexSubImage1D(TargetTexture1D target, int level, int xoffset, ece::size_t width, PixelFormat format, ece::size_t imageSize, const void * data);
				static inline void texImage3DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalFormat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedSamplelLocations);
				static inline void texImage2DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, bool fixedsamplelocations);
				static inline void texBuffer(PixelInternalFormat internalFormat, Handle buffer);
				template <class T> static inline void texParameter(const TextureTarget target, const TextureParameter pname, const T param);
				template<> inline void texParameter(const TextureTarget target, const TextureParameter pname, const float param);
				template<> inline void texParameter(const TextureTarget target, const TextureParameter pname, const int param);
				template <class T> static inline void texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<T> & param);
				template <> inline void texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<float> & param);
				template <> inline void texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<int> & param);
				template <> inline void texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<unsigned int> & param);
				static inline void generateMipmap(const MipmapTarget target);
				static inline void bindTexture(const TextureTarget target, const Handle texture);
				static inline void deleteTextures(const std::vector<Handle> & textures);
				static inline auto genTexture() -> Handle;
				static inline auto genTextures(const unsigned int n) -> std::vector<Handle>;
				template <class T> static inline auto getTexParameter(TextureTarget target, TextureParameter pname) -> std::vector<T>;
				template <> inline auto getTexParameter<float>(TextureTarget target, TextureParameter pname) -> std::vector<float>;
				template <> inline auto getTexParameter<int>(TextureTarget target, TextureParameter pname) -> std::vector<int>;
				template <> inline auto getTexParameter<unsigned int>(TextureTarget target, TextureParameter pname) -> std::vector<unsigned int>;
				template <class T> static inline auto getTexLevelParameter(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<T>;
				template <> inline auto getTexLevelParameter<float>(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<float>;
				template <> inline auto getTexLevelParameter<int>(TextureTarget target, int level, TextureLevelParameter pname) -> std::vector<int>;
				static inline auto getTexImage(TextureTarget target, int level, PixelFormat format, DataType type) -> void *;
				static inline auto getCompressedTexImage(TextureTarget target, int level) -> void *;
				static inline auto isTexture(Handle texture) -> bool;
				static inline void hint(Hint target, HintMode mode);
				static inline auto readPixels(int x, int y, ece::size_t width, ece::size_t height, PixelFormat format, DataType type) -> void *;
				static inline void readBuffer(ColorBuffer mode);
				static inline void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BufferBit mask, InterpolationFilter filter);
				static inline void scissor(const int x, const int y, const unsigned int width, const unsigned int height);
				static inline void sampleCoverage(float value, bool invert);
				static inline void sampleMask(unsigned int maskNumber, std::bitset<32> mask);
				static inline void stencilFunc(DepthFunctionCondition func, int ref, unsigned int mask);
				static inline void stencilFuncSeparate(CullFaceMode face, DepthFunctionCondition func, int ref, unsigned int mask);
				static inline void stencilOp(TestCondition sfail, TestCondition dpfail, TestCondition dppass);
				static inline void stencilOpSeparate(CullFaceMode face, TestCondition sfail, TestCondition dpfail, TestCondition dppass);
				static inline void depthFunc(const DepthFunctionCondition condition);
				static inline void blendEquation(BlendEquationMode mode);
				static inline void blendEquationSeparate(BlendEquationMode modeRGB, BlendEquationMode modeAlpha);
				static inline void blendFuncSeparate(BlendingFactor srcRGB, BlendingFactor dstRGB, BlendingFactor srcAlpha, BlendingFactor dstAlpha);
				static inline void blendFunc(const BlendingFactor sfactor, const BlendingFactor dfactor);
				static inline void blendColor(float red, float green, float blue, float alpha);
				static inline void logicOp(LogicalOperation opcode);
				static inline void drawBuffer(ColorBuffer buf);
				static inline void drawBuffers(const std::vector<ColorBuffer> & bufs);
				static inline void colorMask(bool red, bool green, bool blue, bool alpha);
				static inline void colorMask(unsigned int buf, bool red, bool green, bool blue, bool alpha);
				static inline void depthMask(bool flag);
				static inline void stencilMask(unsigned int mask);
				static inline void stencilMaskSeparate(CullFaceMode face, unsigned int mask);
				static inline void clear(const BufferBit mask);
				static inline void clearColor(const float r, const float g, const float b, const float a);
				static inline void clearDepth(double depth);
				static inline void clearStencil(int s);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<int> & value);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<unsigned int> & value);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<float> & value);
				static inline void clearBuffer(GLenum buffer, int drawbuffer, float depth, int stencil);
				static inline void bindFramebuffer(FramebufferTarget target, Handle framebuffer);
				static inline void deleteFramebuffers(std::vector<Handle> & framebuffers);
				static inline auto genFramebuffers(ece::size_t n) -> std::vector<Handle>;
				static inline void bindRenderbuffer(Handle renderbuffer);
				static inline void deleteRenderbuffers(std::vector<Handle> & renderbuffers);
				static inline auto genRenderbuffers(ece::size_t n) -> std::vector<Handle>;
				static inline void renderbufferStorageMultisample(ece::size_t samples, PixelFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void renderbufferStorage(PixelFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void framebufferRenderbuffer(FramebufferTarget target, FramebufferAttachmentChannel attachment, unsigned int renderbuffer);
				static inline void framebufferTexture(FramebufferTarget target, FramebufferAttachmentChannel attachment, Handle texture, int level);
				static inline void framebufferTexture1D(FramebufferTarget target, FramebufferAttachmentChannel attachment, FramebufferTargetTexture textarget, Handle texture, int level);
				static inline void framebufferTexture2D(FramebufferTarget target, FramebufferAttachmentChannel attachment, FramebufferTargetTexture textarget, Handle texture, int level);
				static inline void framebufferTexture3D(FramebufferTarget target, FramebufferAttachmentChannel attachment, FramebufferTargetTexture textarget, Handle texture, int level, int layer);
				static inline void framebufferTextureLayer(FramebufferTarget target, FramebufferAttachmentChannel attachment, Handle texture, int level, int layer);
				static inline auto checkFramebufferStatus(FramebufferTarget target) -> FramebufferStatus;
				static inline auto isFramebuffer(Handle framebuffer) -> bool;
				static inline auto getFramebufferAttachmentParameter(FramebufferTarget target, FramebufferAttachmentChannel attachment, FramebufferAttachmentParameter pname) -> int;
				static inline auto isRenderbuffer(Handle renderbuffer) -> bool;
				static inline auto getRenderbufferParameter(RenderbufferParameter pname) -> int;
				static inline void flush();
				static inline void finish();
				static inline auto fenceSync() -> Sync;
				static inline void deleteSync(Sync sync);
				static inline auto clientWaitSync(Sync sync, const std::bitset<8> & flags, std::uint64_t timeout) -> SyncStatus;
				static inline void waitSync(Sync sync, const std::bitset<8> & flags);
				static inline auto getSync(Sync sync, SyncParameter pname) -> int;
				static inline auto isSync(Sync sync) -> bool;
				static inline auto getBoolean(Parameter pname) -> std::vector<bool>;
				static inline auto getDouble(Parameter pname) -> std::vector<double>;
				static inline auto getFloat(Parameter pname) -> std::vector<float>;
				static inline auto getInteger(Parameter pname) -> std::vector<int>;
				static inline auto getInteger64(Parameter pname) -> std::vector<std::int64_t>;
				static inline auto getBoolean(Parameter target, unsigned int index) -> bool;
				static inline auto getInteger(Parameter target, unsigned int index) -> int;
				static inline auto getInteger64(Parameter target, unsigned int index) -> std::int64_t;
				static inline auto isEnabled(Capability cap) -> bool;
				static inline auto isEnabled(Capability cap, unsigned int index) -> bool;
				static inline auto getString(InfoGL parameter) -> std::string;
				static inline auto getString(InfoGL name, unsigned int index) -> std::string;
				static inline void queryCounter(Handle id);
				static inline auto genSamplers(ece::size_t n) -> std::vector<Handle>;
				static inline void bindSampler(Handle unit, Handle sampler);
				static inline void samplerParameter(Handle sampler, SamplerParameter pname, float param);
				static inline void samplerParameter(Handle sampler, SamplerParameter pname, int param);
				static inline void samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<float> & params);
				static inline void samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<int> & params);
				static inline void samplerParameter(Handle sampler, SamplerParameter pname, const std::vector<unsigned int> & params);
				static inline void deleteSamplers(const std::vector<Handle> & samplers);
				static inline auto isSampler(Handle id) -> bool;
				template <class T> static inline auto getSamplerParameter(Handle sampler, SamplerParameter pname) -> std::vector<T>;
				template <> inline auto getSamplerParameter<float>(Handle sampler, SamplerParameter pname) -> std::vector<float>;
				template <> inline auto getSamplerParameter<int>(Handle sampler, SamplerParameter pname) -> std::vector<int>;
				template <> inline auto getSamplerParameter<unsigned int>(Handle sampler, SamplerParameter pname) -> std::vector<unsigned int>;
				static inline void bindFragDataLocationIndexed(Handle program, Handle colorNumber, Handle index, const std::string & name);
				static inline auto getFragDataIndex(Handle program, const std::string & name) -> int;
				static inline void vertexAttribDivisor(const int index, const ece::size_t divisor);

				template<> inline auto getUniform(Handle program, int location) -> double;
				static inline void blendEquation(Handle buf, BlendEquationMode mode);
				static inline void blendEquationSeparate(Handle buf, BlendEquationMode modeRGB, BlendEquationMode modeAlpha);
				static inline void blendFuncSeparate(Handle buf, BlendingFactor srcRGB, BlendingFactor dstRGB, BlendingFactor srcAlpha, BlendingFactor dstAlpha);
				static inline void blendFunc(Handle buf, const BlendingFactor sfactor, const BlendingFactor dfactor);
				static inline void drawElementsIndirect(PrimitiveMode mode, DrawElementsIndirectCommand & indirect);
				static inline void beginQueryIndexed(QueryObjectType target, Handle index, Handle id);
				static inline void endQueryIndexed(QueryObjectType target, Handle index);
				static inline auto getQueryIndexed(QueryObjectType target, Handle index, QueryObjectTargetParameter pname) -> int;
				static inline auto getSubroutineUniformLocation(Handle program, ShaderType shadertype, const std::string & name) -> int;
				static inline auto getSubroutineIndex(Handle program, ShaderType shadertype, const std::string & name) -> Handle;
				static inline auto getActiveSubroutineName(Handle program, ShaderType shadertype, Handle index) -> std::string;
				static inline auto getActiveSubroutineUniformName(Handle program, ShaderType shadertype, Handle index) -> std::string;
				static inline auto getActiveSubroutineUniform(Handle program, ShaderType shadertype, Handle index, ShaderSubroutineUniformParameter pname) -> std::vector<int>;
				static inline void uniformSubroutines(ShaderType shadertype, const std::vector<unsigned int> & indices);
				static inline auto getUniformSubroutine(ShaderType shadertype, int location) -> std::vector<unsigned int>;
				static inline auto getProgramStage(Handle program, ShaderType shadertype, ShaderSubroutineParameter pname) -> int;
				static inline void patchParameter(PatchParameter pname, int value);
				static inline void patchParameter(PatchParameter pname, const std::vector<float> & values);
				static inline void drawArraysIndirect(PrimitiveMode mode, DrawArraysIndirectCommand & indirect);
				static inline auto genTransformFeedbacks(ece::size_t n) -> std::vector<Handle>;
				static inline void deleteTransformFeedbacks(const std::vector<Handle> & ids);
				static inline auto isTransformFeedback(Handle id) -> bool;
				static inline void bindTransformFeedback(Handle id);
				static inline void pauseTransformFeedback();
				static inline void resumeTransformFeedback();
				static inline void drawTransformFeedback(PrimitiveMode mode, Handle id);
				static inline void drawTransformFeedbackStream(PrimitiveMode mode, Handle id, Handle stream);
				static inline void minSampleShading(float value);

				static inline void depthRange(float nearVal, float farVal);
				static inline void clearDepth(float depth);
				static inline auto getFloat(Parameter target, unsigned int index) -> float;
				static inline auto getDouble(Parameter target, unsigned int index) -> double;
				static inline void shaderBinary(const std::vector<Handle> & shaders, BinaryFormat binaryFormat, const void * binary, ece::size_t length);
				static inline void releaseShaderCompiler();
				static inline auto createShaderProgram(ShaderType type, std::vector<std::string> & strings) -> Handle;
				static inline void programParameter(Handle program, ProgramHint pname, int value);
				static inline auto genProgramPipelines(ece::size_t n) -> std::vector<Handle>;
				static inline void deleteProgramPipelines(const std::vector<Handle> & pipelines);
				static inline auto isProgramPipeline(Handle pipeline) -> bool;
				static inline void bindProgramPipeline(Handle pipeline);
				static inline void useProgramStages(Handle pipeline, ProgramStageBitfield stages, Handle program);
				static inline void activeShaderProgram(Handle pipeline, Handle program);
				static inline auto getProgramBinary(Handle program) -> ProgramBinary;
				static inline void programBinary(Handle program, ProgramBinary & binary);
				template <class T, unsigned int S> static inline void programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] const std::array<T, S> & v);
				template <> inline void programUniform<float, 1>(Handle program, const int location, const std::array<float, 1> & v);
				template <> inline void programUniform<float, 2>(Handle program, const int location, const std::array<float, 2> & v);
				template <> inline void programUniform<float, 3>(Handle program, const int location, const std::array<float, 3> & v);
				template <> inline void programUniform<float, 4>(Handle program, const int location, const std::array<float, 4> & v);
				template <> inline void programUniform<int, 1>(Handle program, const int location, const std::array<int, 1> & v);
				template <> inline void programUniform<int, 2>(Handle program, const int location, const std::array<int, 2> & v);
				template <> inline void programUniform<int, 3>(Handle program, const int location, const std::array<int, 3> & v);
				template <> inline void programUniform<int, 4>(Handle program, const int location, const std::array<int, 4> & v);
				template <> inline void programUniform<unsigned int, 1>(Handle program, const int location, const std::array<unsigned int, 1> & v);
				template <> inline void programUniform<unsigned int, 2>(Handle program, const int location, const std::array<unsigned int, 2> & v);
				template <> inline void programUniform<unsigned int, 3>(Handle program, const int location, const std::array<unsigned int, 3> & v);
				template <> inline void programUniform<unsigned int, 4>(Handle program, const int location, const std::array<unsigned int, 4> & v);
				template <class T, unsigned int S> static inline void programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const std::array<T, S> & v);
				template <> inline void programUniform<float, 1>(Handle program, const int location, ece::size_t count, const std::array<float, 1> & v);
				template <> inline void programUniform<float, 2>(Handle program, const int location, ece::size_t count, const std::array<float, 2> & v);
				template <> inline void programUniform<float, 3>(Handle program, const int location, ece::size_t count, const std::array<float, 3> & v);
				template <> inline void programUniform<float, 4>(Handle program, const int location, ece::size_t count, const std::array<float, 4> & v);
				template <> inline void programUniform<int, 1>(Handle program, const int location, ece::size_t count, const std::array<int, 1> & v);
				template <> inline void programUniform<int, 2>(Handle program, const int location, ece::size_t count, const std::array<int, 2> & v);
				template <> inline void programUniform<int, 3>(Handle program, const int location, ece::size_t count, const std::array<int, 3> & v);
				template <> inline void programUniform<int, 4>(Handle program, const int location, ece::size_t count, const std::array<int, 4> & v);
				template <> inline void programUniform<unsigned int, 1>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 1> & v);
				template <> inline void programUniform<unsigned int, 2>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 2> & v);
				template <> inline void programUniform<unsigned int, 3>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 3> & v);
				template <> inline void programUniform<unsigned int, 4>(Handle program, const int location, ece::size_t count, const std::array<unsigned int, 4> & v);
				template <class T, unsigned int M, unsigned int N> static inline void programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] ece::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v);
				template <> inline void programUniform<float, 2, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 2> & v);
				template <> inline void programUniform<float, 3, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 3> & v);
				template <> inline void programUniform<float, 4, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 4> & v);
				template <> inline void programUniform<float, 2, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 3> & v);
				template <> inline void programUniform<float, 3, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 2> & v);
				template <> inline void programUniform<float, 2, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 2, 4> & v);
				template <> inline void programUniform<float, 4, 2>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 2> & v);
				template <> inline void programUniform<float, 3, 4>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 3, 4> & v);
				template <> inline void programUniform<float, 4, 3>(Handle program, const int location, ece::size_t count, const bool transpose, const Matrix<float, 4, 3> & v);
				static inline auto getProgramPipeline(Handle pipeline, ProgramPipelineProperty pname) -> int;
				static inline auto getProgramPipelineInfoLog(Handle pipeline) -> std::string;
				static inline auto getShaderPrecisionFormat(ShaderType shaderType, ShaderPrecisionType precisionType) -> ShaderPrecisionFormat;
				static inline void validateProgramPipeline(Handle pipeline);
				static inline void depthRangeArray(Handle first, const std::vector<std::array<double, 2>> & v);
				static inline void depthRangeIndexed(Handle index, double nearVal, double farVal);
				static inline void viewportArray(Handle first, const std::vector<std::array<float, 4>> & v);
				static inline void viewportIndexed(Handle index, float x, float y, float w, float h);
				static inline void viewportIndexed(Handle index, const std::array<float, 4> & v);
				static inline void scissorArray(Handle first, const std::vector<std::array<int, 4>> & v);
				static inline void scissorIndexed(Handle index, int left, int bottom, ece::size_t width, ece::size_t height);
				static inline void scissorIndexed(Handle index, const std::array<int, 4> & v);

				static inline auto getActiveAtomicCounterBuffer(Handle program, Handle bufferIndex, AtomicCounterBufferParameter pname) -> std::vector<int>;
				static inline void memoryBarrier(Barrier barriers);
				static inline void texStorage1D(TargetTexture1D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width);
				static inline void texStorage2D(TargetTexture2D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void texStorage3D(TargetTexture3D target, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth);
				static inline void bindImageTexture(Handle unit, Handle texture, int level, bool layered, int layer, MapBufferAccessFlag access, PixelInternalFormat format);
				static inline void drawArraysInstancedBaseInstance(PrimitiveMode mode, int first, ece::size_t count, ece::size_t primcount, unsigned int baseinstance);
				static inline void drawElementsInstancedBaseInstance(PrimitiveMode mode, ece::size_t count, const std::vector<ece::size_t> & indices, ece::size_t primcount, unsigned int baseinstance);
				static inline void drawElementsInstancedBaseVertexBaseInstance(PrimitiveMode mode, ece::size_t count, std::vector<ece::size_t> & indices, ece::size_t primcount, int basevertex, unsigned int baseinstance);
				static inline void drawTransformFeedbackInstanced(PrimitiveMode mode, Handle id, ece::size_t primcount);
				static inline void drawTransformFeedbackStreamInstanced(PrimitiveMode mode, Handle id, Handle stream, ece::size_t primcount);
				static inline auto getInternalformat(TextureTarget target, PixelInternalFormat internalformat, InternalFormatInformation pname) -> std::vector<int>;

				template <class T> static inline void clearBufferSubData(BufferType target, PixelInternalFormat internalformat, int offset, ece::size_t size, PixelFormat format, DataType type, const std::vector<T> & data);
				template <class T> static inline void clearBufferData(BufferType target, PixelInternalFormat internalformat, PixelFormat format, DataType type, const std::vector<T> & data);
				static inline void invalidateBufferSubData(Handle buffer, int offset, ece::size_t length);
				static inline void invalidateBufferData(Handle buffer);
				static inline auto getProgramInterface(Handle program, ProgramInterface programInterface, ProgramInterfaceProperty pname) -> int;
				static inline auto getProgramResourceIndex(Handle program, ProgramInterface programInterface, const std::string & name) -> Handle;
				static inline auto getProgramResourceName(Handle program, ProgramInterface programInterface, Handle index) -> std::string;
				static inline auto getProgramResource(Handle program, ProgramInterface programInterface, unsigned int index, const std::vector<ProgramInterfaceProperty> & props) -> std::vector<int>;
				static inline auto getProgramResourceLocation(Handle program, ProgramInterface programInterface, const std::string & name) -> int;
				static inline auto getProgramResourceLocationIndex(Handle program, ProgramInterface programInterface, const std::string & name) -> int;
				static inline void shaderStorageBlockBinding(Handle program, unsigned int storageBlockIndex, unsigned int storageBlockBinding);
				static inline auto getPointer(Pointer pname) -> void *;
				static inline void texBufferRange(PixelInternalFormat internalFormat, Handle buffer, int offset, ece::size_t size);
				static inline void textureView(Handle texture, TextureTarget target, TextureTarget origtexture, PixelInternalFormat internalformat, unsigned int minlevel, unsigned int numlevels, unsigned int minlayer, unsigned int numlayers);
				static inline void texStorage2DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, bool fixedsamplelocations);
				static inline void texStorage3DMultisample(TargetTextureMultisample target, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedsamplelocations);
				static inline void invalidateTexSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth);
				static inline void invalidateTexImage(Handle texture, int level);
				static inline void framebufferParameter(FramebufferTarget target, FramebufferParameter pname, int param);
				static inline auto getFramebufferParameter(FramebufferTarget target, FramebufferParameter pname) -> int;
				static inline void vertexAttribFormat(Handle attribindex, int size, DataType type, bool normalized, unsigned int relativeoffset);
				static inline void vertexAttribIFormat(Handle attribindex, int size, DataType type, unsigned int relativeoffset);
				static inline void vertexAttribLFormat(Handle attribindex, int size, DataType type, unsigned int relativeoffset);
				static inline void bindVertexBuffer(Handle bindingindex, Handle buffer, int offset, int stride);
				static inline void vertexAttribBinding(unsigned int attribindex, unsigned int bindingindex);
				static inline void vertexBindingDivisor(unsigned int bindingindex, unsigned int divisor);
				static inline void multiDrawArraysIndirect(PrimitiveMode mode, const std::vector<DrawArraysIndirectCommand> & indirect, ece::size_t drawcount, ece::size_t stride);
				static inline void multiDrawArraysIndirectCount(PrimitiveMode mode, const std::vector<DrawArraysIndirectCommand> & indirect, int drawcount, ece::size_t maxdrawcount, ece::size_t stride);
				static inline void multiDrawElementsIndirect(PrimitiveMode mode, DataType type, const std::vector<DrawElementsIndirectCommand> & indirect, ece::size_t drawcount, ece::size_t stride);
				static inline void multiDrawElementsIndirectCount(PrimitiveMode mode, DataType type, const std::vector<DrawElementsIndirectCommand> & indirect, int drawcount, ece::size_t maxdrawcount, ece::size_t stride);
				static inline void dispatchCompute(unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z);
				static inline void dispatchComputeIndirect(int indirect);
				static inline void invalidateSubFramebuffer(FramebufferTarget target, const std::vector<FramebufferAttachmentChannel> & attachments, int x, int y, int width, int height);
				static inline void invalidateFramebuffer(FramebufferTarget target, const std::vector<FramebufferAttachmentChannel> & attachments);
				static inline void copyImageSubData(Handle srcName, TextureTarget srcTarget, int srcLevel, int srcX, int srcY, int srcZ, Handle dstName, TextureTarget dstTarget, int dstLevel, int dstX, int dstY, int dstZ, ece::size_t srcWidth, ece::size_t srcHeight, ece::size_t srcDepth);
				static inline void debugMessageCallback(GLDEBUGPROC callback, const void * userParam);
				static inline void debugMessageControl(const SourceDebugMessage source, const TypeDebugMessage type, const SeverityDebugMessage severity, const std::vector<unsigned int> & ids, bool enabled);
				static inline void debugMessageInsert(SourceDebugMessage source, TypeDebugMessage type, Handle id, SeverityDebugMessage severity, const std::string & message);
				static inline void pushDebugGroup(SourceDebugMessage source, Handle id, const std::string & message);
				static inline void popDebugGroup();
				static inline void objectLabel(Identifier identifier, Handle name, const std::string & label);
				static inline void objectPtrLabel(void * ptr, const std::string & label);
				static inline auto getDebugMessageLog(ece::size_t count) -> std::vector<DebugMessage>;
				static inline auto getObjectLabel(Identifier identifier, Handle name) -> std::string;
				static inline auto getObjectPtrLabel(void * ptr) -> std::string;
				static inline auto getInternalformat64(TextureTarget target, PixelInternalFormat internalformat, InternalFormatInformation pname) -> std::vector<std::int64_t>;

				static inline void bindBuffersRange(IndexedBufferTarget target, Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes);
				static inline void bindBuffersBase(IndexedBufferTarget target, Handle first, const std::vector<Handle> & buffers);
				template <class T> static inline void bufferStorage(BufferType target, const std::vector<T> & data, BufferDataUsage flags);
				static inline void bindTextures(Handle first, const std::vector<Handle> & textures);
				static inline void bindSamplers(Handle first, const std::vector<Handle> & samplers);
				template <class T> static inline void clearTexSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, DataType type, const std::vector<T> & data);
				template <class T> static inline void clearTexImage(Handle texture, int level, PixelFormat format, DataType type, const std::vector<T> & data);
				static inline void bindImageTextures(Handle first, const std::vector<Handle> & textures);
				static inline void bindVertexBuffers(Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes);

				static inline void enableVertexArrayAttrib(Handle vaobj, unsigned int index);
				static inline void disableVertexArrayAttrib(Handle vaobj, unsigned int index);
				static inline void namedBufferData(Handle buffer, ece::size_t size, const void * data, BufferUsage usage);
				static inline void namedBufferSubData(Handle buffer, int offset, ece::size_t size, const void * data);
				static inline auto mapNamedBufferRange(Handle buffer, int offset, ece::size_t length, MapBufferRangeAccessFlag access) -> void *;
				static inline auto mapNamedBuffer(Handle buffer, MapBufferRangeAccessFlag access) -> void *;
				static inline void flushMappedNamedBufferRange(Handle buffer, int offset, ece::size_t length);
				static inline auto unmapNamedBuffer(Handle buffer) -> bool;
				static inline void copyNamedBufferSubData(Handle readBuffer, Handle writeBuffer, int readOffset, int writeOffset, ece::size_t size);
				static inline auto getNamedBufferParameter(Handle buffer, BufferParameter pname) -> int;
				static inline auto getNamedBufferParameter64(Handle buffer, BufferParameter pname) -> std::int64_t;
				static inline auto getNamedBufferSubData(Handle buffer, int offset, ece::size_t size) -> void *;
				static inline auto getNamedBufferPointer(Handle buffer) -> void *;
				template <class T> static inline auto getnUniform([[maybe_unused]] Handle program, [[maybe_unused]] int location, [[maybe_unused]] ece::size_t bufSize) -> std::vector<T>;
				template <> inline auto getnUniform<float>(Handle program, int location, ece::size_t bufSize) -> std::vector<float>;
				template <> inline auto getnUniform<int>(Handle program, int location, ece::size_t bufSize) -> std::vector<int>;
				template <> inline auto getnUniform<unsigned int>(Handle program, int location, ece::size_t bufSize) -> std::vector<unsigned int>;
				template <> inline auto getnUniform<double>(Handle program, int location, ece::size_t bufSize) -> std::vector<double>;
				static inline void textureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t  width, ece::size_t  height, ece::size_t depth, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void textureSubImage2D(Handle texture, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, PixelDataType type, const void *pixels);
				static inline void textureSubImage1D(Handle texture, int level, int xoffset, ece::size_t width, PixelFormat format, PixelDataType type, const void *pixels);
				static inline void copyTextureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, ece::size_t width, ece::size_t height);
				static inline void copyTextureSubImage2D(Handle texture, int level, int xoffset, int yoffset, int x, int y, ece::size_t width, ece::size_t height);
				static inline void copyTextureSubImage1D(Handle texture, int level, int xoffset, int x, int y, ece::size_t width);
				static inline void compressedTextureSubImage3D(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, ece::size_t imageSize, const void * data);
				static inline void compressedTextureSubImage2D(Handle texture, int level, int xoffset, int yoffset, ece::size_t width, ece::size_t height, PixelFormat format, ece::size_t imageSize, const void *data);
				static inline void compressedTextureSubImage1D(Handle texture, int level, int xoffset, ece::size_t width, PixelFormat format, ece::size_t imageSize, const void *data);
				static inline void textureBuffer(Handle texture, PixelInternalFormat internalformat, Handle buffer);
				static inline void textureParameter(TextureTarget texture, TextureParameter pname, float param);
				static inline void textureParameter(TextureTarget texture, TextureParameter pname, int param);
				static inline void textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<float> & param);
				static inline void textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<int> & param);
				static inline void textureParameter(TextureTarget texture, TextureParameter pname, const std::vector<unsigned int> & param);
				
				static inline void generateTextureMipmap(Handle texture);

				template <class T> static inline auto getTextureParameter(Handle texture, TextureParameter pname) -> std::vector<T>;
				template <> inline auto getTextureParameter<float>(Handle texture, TextureParameter pname) -> std::vector<float>;
				template <> inline auto getTextureParameter<int>(Handle texture, TextureParameter pname) -> std::vector<int>;
				template <> inline auto getTextureParameter<unsigned int>(Handle texture, TextureParameter pname) -> std::vector<unsigned int>;
				template <class T> static inline auto getTextureLevelParameter(Handle texture, int level, TextureLevelParameter pname) -> std::vector<T>;
				template <> inline auto getTextureLevelParameter<float>(Handle texture, int level, TextureLevelParameter pname) -> std::vector<float>;
				template <> inline auto getTextureLevelParameter<int>(Handle texture, int level, TextureLevelParameter pname) -> std::vector<int>;
				static inline auto getnTexImage(TextureTarget target, int level, PixelFormat format, DataType type, ece::size_t bufSize) -> void *;
				static inline auto getTextureImage(Handle texture, int level, PixelFormat format, DataType type, ece::size_t bufSize) -> void *;
				static inline auto getnCompressedTexImage(TextureTarget target, int level, ece::size_t bufSize) -> void *;
				static inline auto getCompressedTextureImage(Handle texture, int level, ece::size_t bufSize) -> void *;
				static inline auto readnPixels(int x, int y, ece::size_t width, ece::size_t height, PixelFormat format, DataType type, ece::size_t bufSize) -> void *;
				static inline void namedFramebufferReadBuffer(Handle framebuffer, ColorBuffer mode);
				static inline void blitNamedFramebuffer(Handle readFramebuffer, Handle drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, BufferBit mask, InterpolationFilter filter);
				static inline void namedFramebufferDrawBuffer(Handle framebuffer, ColorBuffer buf);
				static inline void namedFramebufferDrawBuffers(Handle framebuffer, const std::vector<ColorBuffer> & bufs);
				static inline void clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<int> & value);
				static inline void clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<unsigned int> & value);
				static inline void clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, const std::vector<float>value);
				static inline void clearNamedFramebuffer(Handle framebuffer, BufferKind buffer, int drawbuffer, float depth, int stencil);
				static inline void namedRenderbufferStorageMultisample(Handle renderbuffer, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void namedRenderbufferStorage(Handle renderbuffer, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void namedFramebufferRenderbuffer(Handle framebuffer, FramebufferAttachmentChannel attachment, unsigned int renderbuffer);
				static inline void namedFramebufferTexture(Handle framebuffer, FramebufferAttachmentChannel attachment, Handle texture, int level);
				static inline void namedFramebufferTextureLayer(Handle framebuffer, FramebufferAttachmentChannel attachment, Handle texture, int level, int layer);
				static inline auto checkNamedFramebufferStatus(Handle framebuffer, FramebufferTarget target) -> FramebufferStatus;
				static inline auto getNamedFramebufferAttachmentParameter(Handle framebuffer, FramebufferAttachmentChannel attachment, FramebufferAttachmentParameter pname) -> int;
				static inline auto getNamedRenderbufferParameter(Handle renderbuffer, RenderbufferParameter pname) -> int;
				static inline auto getGraphicsResetStatus() -> GraphicResetStatus;
				static inline auto createBuffers(ece::size_t n) -> std::vector<Handle>;
				template <class T> static inline void namedBufferStorage(Handle buffer, const std::vector<T> & data, BufferDataUsage flags);
				template <class T> static inline void clearNamedBufferData(BufferType buffer, PixelInternalFormat internalformat, PixelFormat format, DataType type, const std::vector<T> & data);
				static inline auto createProgramPipelines(ece::size_t n) -> std::vector<Handle>;
				static inline void memoryBarrierByRegion(BarrierByRegion barriers);
				static inline void bindTextureUnit(Handle unit, Handle texture);
				static inline auto createTextures(TextureTarget target, ece::size_t n) -> std::vector<Handle>;
				static inline auto createSamplers(ece::size_t n) -> std::vector<Handle>;
				static inline void textureBufferRange(Handle texture, PixelInternalFormat internalFormat, Handle buffer, int offset, ece::size_t size);
				static inline auto getTextureSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, PixelFormat format, DataType type, ece::size_t bufSize) -> void *;
				static inline auto getCompressedTextureSubImage(Handle texture, int level, int xoffset, int yoffset, int zoffset, ece::size_t width, ece::size_t height, ece::size_t depth, ece::size_t bufSize) -> void *;
				static inline void textureStorage1D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width);
				static inline void textureStorage2D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height);
				static inline void textureStorage3D(Handle texture, ece::size_t levels, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth);
				static inline void textureStorage2DMultisample(Handle texture, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, bool fixedsamplelocations);
				static inline void textureStorage3DMultisample(Handle texture, ece::size_t samples, PixelInternalFormat internalformat, ece::size_t width, ece::size_t height, ece::size_t depth, bool fixedsamplelocations);
				static inline auto createFramebuffers(ece::size_t n) -> std::vector<Handle>;
				static inline void namedFramebufferParameteri(Handle framebuffer, FramebufferParameter pname, int param);
				static inline auto getNamedFramebufferParameter(Handle framebuffer, FramebufferParameter pname) -> int;
				static inline auto createRenderbuffers(ece::size_t n) -> std::vector<Handle>;
				static inline void textureBarrier();
				static inline auto createVertexArrays(ece::size_t n) -> std::vector<Handle>;
				static inline void vertexArrayElementBuffer(Handle vaobj, Handle buffer);
				static inline void vertexArrayAttribFormat(Handle vaobj, Handle attribindex, int size, DataType type, bool normalized, unsigned int relativeoffset);
				static inline void vertexArrayAttribIFormat(Handle vaobj, Handle attribindex, int size, DataType type, unsigned int relativeoffset);
				static inline void vertexArrayAttribLFormat(Handle vaobj, Handle attribindex, int size, DataType type, unsigned int relativeoffset);
				static inline void vertexArrayVertexBuffer(Handle vaobj, Handle bindingindex, Handle buffer, int offset, ece::size_t stride);
				static inline void vertexArrayVertexBuffers(Handle vaobj, Handle first, ece::size_t count, const std::vector<Handle> & buffers, const std::vector<int> & offsets, const std::vector<int> & sizes);
				static inline void vertexArrayAttribBinding(Handle vaobj, unsigned int attribindex, unsigned int bindingindex);
				static inline void vertexArrayBindingDivisor(Handle vaobj, unsigned int bindingindex, unsigned int divisor);
				static inline auto getVertexArray(Handle vaobj) -> int;
				static inline auto getVertexArrayIndexed64(Handle vaobj, Handle index, VertexAttribParameter pname) -> std::int64_t;
				static inline auto getVertexArrayIndexed(Handle vaobj, Handle index, VertexAttribParameter pname) -> int;
				static inline auto createTransformFeedbacks(ece::size_t n) -> std::vector<Handle>;
				static inline void transformFeedbackBufferRange(Handle xfb, Handle index, Handle buffer, int offset, ece::size_t size);
				static inline void transformFeedbackBufferBase(Handle xfb, Handle index, Handle buffer);
				static inline void clipControl(ClipControl origin, ClipControlDepthMode depth);
				static inline void invalidateNamedFramebufferSubData(Handle framebuffer, const std::vector<FramebufferAttachmentChannel> & attachments, int x, int y, int width, int height);
				static inline void invalidateNamedFramebufferData(Handle framebuffer, const std::vector<FramebufferAttachmentChannel> & attachments);
				static inline auto getTransformFeedback(Handle xfb, TransformFeedbackParameter pname) -> int;
				static inline auto getTransformFeedback(Handle xfb, TransformFeedbackParameter pname, Handle index) -> int;
				static inline auto getTransformFeedback64(Handle xfb, TransformFeedbackParameter pname, Handle index) -> std::int64_t;

				static inline void specializeShader(Handle shader, const std::string & pEntryPoint, const std::vector<Handle> & pConstantIndex, const std::vector<Handle> & pConstantValue);
				static inline void polygonOffsetClamp(float factor, float units, float clamp);
			} //namespace OpengL
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#include "renderer/opengl/opengl.inl"

#endif // OPENGL_HPP
