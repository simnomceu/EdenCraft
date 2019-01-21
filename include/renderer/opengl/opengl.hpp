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
				template <std::size_t Size, typename enabled = std::enable_if_t<(Size > 0 && Size <= 4)>> static inline void vertexAttribP(Handle index, PackedVertexAttribType type, bool normalized, unsigned int value);

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

				static inline void vertexAttribPointer(const int location, const std::size_t size, const DataType type, const bool normalized, const std::size_t stride, const std::size_t offset = 0);
				static inline void enableVertexAttribArray(const int location);
				static inline void disableVertexAttribArray(const int location);
				static inline void enable(const Capability cap);
				static inline void disable(const Capability cap);
				static inline void enableIndexed(const Capability cap, const unsigned short int index);
				static inline void disableIndexed(const Capability cap, const unsigned short int index);
				static inline void primitiveRestartIndex(std::size_t index);
				static inline void drawArrays(const PrimitiveMode mode, const int first, const std::size_t count);
				static inline void multiDrawArrays(PrimitiveMode mode, const std::vector<int> & first, const std::vector<std::size_t> & count, std::size_t drawcount);
				static inline void drawElements(const PrimitiveMode mode, const std::size_t count, const int offset);
				static inline void multiDrawElements(PrimitiveMode mode, const std::vector<std::size_t> & count, const std::vector<std::size_t *> & indices, std::size_t drawcount);
				static inline void drawRangeElements(PrimitiveMode mode, std::size_t start, std::size_t end, std::size_t count, const std::size_t * indices);
				static inline void drawArraysInstanced(const PrimitiveMode mode, const int first, const std::size_t count, const std::size_t primcount);
				static inline void drawElementsInstanced(const PrimitiveMode mode, const std::size_t count, const int offset, const std::size_t primcount);
				static inline void drawElementsBaseVertex(PrimitiveMode mode, std::size_t count, std::vector<std::size_t> & indices, int basevertex);
				static inline void drawRangeElementsBaseVertex(PrimitiveMode mode, std::size_t start, std::size_t end, std::size_t count, std::vector<std::size_t> & indices, int basevertex);
				static inline void drawElementsInstancedBaseVertex(PrimitiveMode mode, std::size_t count, std::vector<std::size_t> & indices, std::size_t primcount, int basevertex);
				static inline void multiDrawElementsBaseVertex(PrimitiveMode mode, const std::vector<std::size_t> & count, const std::vector<std::size_t *> & indices, std::size_t drawcount, const std::vector<int> & basevertex);
				static inline auto genBuffers() -> Handle;
				static inline auto genBuffers(const int count) -> std::vector<Handle>;
				static inline void deleteBuffer(const Handle buffer);
				static inline void deleteBuffers(const std::vector<Handle> & buffers);
				static inline void bindBuffer(const BufferType type, const Handle handle);
				static inline void bindBufferRange(IndexedBufferTarget target, Handle index, Handle buffer, int offset, std::size_t size);
				static inline void bindBufferBase(IndexedBufferTarget target, Handle index, Handle buffer);
				template<class C, typename enabled = std::enable_if_t<contiguous_container_v<C> && is_container_v<C>>>
				static inline void bufferData(const BufferType type, const C & data, const BufferUsage usage, const int offset = 0);
				template <class E>
				static inline void bufferData(const BufferType type, const std::size_t size, const BufferUsage usage, int offset = 0);
				template<class C, typename enabled = std::enable_if_t<contiguous_container_v<C> && is_container_v<C>>>
				static inline void bufferSubData(BufferType target, int offset, std::size_t size, const C & data);
				static inline auto mapBufferRange(BufferType target, int offset, std::size_t length, MapBufferRangeAccessFlag access) -> void *;
				static inline auto mapBuffer(BufferType target, MapBufferAccessFlag access) -> void *;
				static inline void flushMappedBufferRange(BufferType target, int offset, std::size_t length);
				static inline auto unmapBuffer(BufferType target) -> bool;
				static inline void copyBufferSubData(BufferType readTarget, BufferType writeTarget, int readOffset, int writeOffset, std::size_t size);
				static inline auto genVertexArrays() -> Handle;
				static inline auto genVertexArrays(const int count) -> std::vector<Handle>;
				static inline void deleteVertexArrays(std::size_t n, const std::vector<Handle> & arrays);
				static inline void bindVertexArray(const Handle handle);
				static inline auto isBuffer(Handle buffer) -> bool;
				static inline auto getBufferParameteriv(BufferType target, BufferParameter value) -> int;
				static inline auto getBufferParameteri64v(BufferType target, BufferParameter value) -> int64_t;
				template <class T> static inline auto getBufferSubData(BufferType target, int offset, std::size_t size) -> std::vector<T>;
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
				static inline auto genQueries(std::size_t n) -> std::vector<Handle>;
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
				static inline auto getUniformIndices(Handle program, std::size_t uniformCount) -> UniformBlock;
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
				template <class T, unsigned int S> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const std::array<T, S> & v);
				template<> inline void uniform<float, 1>(int location, std::size_t count, const std::array<float, 1> & value);
				template<> inline void uniform<float, 2>(int location, std::size_t count, const std::array<float, 2> & value);
				template<> inline void uniform<float, 3>(int location, std::size_t count, const std::array<float, 3> & value);
				template<> inline void uniform<float, 4>(int location, std::size_t count, const std::array<float, 4> & value);
				template<> inline void uniform<int, 1>(int location, std::size_t count, const std::array<int, 1> & value);
				template<> inline void uniform<int, 2>(int location, std::size_t count, const std::array<int, 2> & value);
				template<> inline void uniform<int, 3>(int location, std::size_t count, const std::array<int, 3> & value);
				template<> inline void uniform<int, 4>(int location, std::size_t count, const std::array<int, 4> & value);
				template<> inline void uniform<unsigned int, 1>(int location, std::size_t count, const std::array<unsigned int, 1> & value);
				template<> inline void uniform<unsigned int, 2>(int location, std::size_t count, const std::array<unsigned int, 2> & value);
				template<> inline void uniform<unsigned int, 3>(int location, std::size_t count, const std::array<unsigned int, 3> & value);
				template<> inline void uniform<unsigned int, 4>(int location, std::size_t count, const std::array<unsigned int, 4> & value);
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
				template <class T, unsigned int M, unsigned int N> static inline void uniform([[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 2> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 3> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 4> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 3> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 2> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 4> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 2> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 4> & v);
				template<> inline void uniform(const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 3> & v);
				static inline void uniformBlockBinding(Handle program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding);
				static inline void transformFeedbackVaryings(Handle program, std::size_t count, const std::vector<std::string> & varyings, VaryingBufferMode bufferMode);
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
				static inline void texImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, PixelFormat format, PixelDataType type, const void * data);
				static inline void texImage2D(const TextureTypeTarget target, const unsigned int level, const PixelInternalFormat internalFormat, const std::size_t width, const std::size_t height, const PixelFormat format, const PixelDataType type, const void * data);
				static inline void texImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, std::size_t width, PixelFormat format, PixelDataType type, const void * data);
				static inline void copyTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, int x, int y, std::size_t width, std::size_t height);
				static inline void copyTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, int x, int y, std::size_t width);
				static inline void texSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, std::size_t  width, std::size_t  height, std::size_t depth, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void texSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, std::size_t width, std::size_t height, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void texSubImage1D(TargetTexture1D target, int level, int xoffset, std::size_t width, PixelFormat format, PixelDataType type, const void * pixels);
				static inline void copyTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, std::size_t width, std::size_t height);
				static inline void copyTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, int x, int y, std::size_t width, std::size_t height);
				static inline void copyTexSubImage1D(TargetTexture1D target, int level, int xoffset, int x, int y, std::size_t width);
				static inline void compressedTexImage3D(TargetTexture3D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, std::size_t imageSize, const void * data);
				static inline void compressedTexImage2D(TextureTypeTarget target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t imageSize, const void * data);
				static inline void compressedTexImage1D(TargetTexture1D target, int level, PixelInternalFormat internalFormat, std::size_t width, std::size_t imageSize, const void * data);
				static inline void compressedTexSubImage3D(TargetTexture3D target, int level, int xoffset, int yoffset, int zoffset, std::size_t width, std::size_t height, std::size_t depth, PixelFormat format, std::size_t imageSize, const void * data);
				static inline void compressedTexSubImage2D(TextureTypeTarget target, int level, int xoffset, int yoffset, std::size_t width, std::size_t height, PixelFormat format, std::size_t imageSize, const void * data);
				static inline void compressedTexSubImage1D(TargetTexture1D target, int level, int xoffset, std::size_t width, PixelFormat format, std::size_t imageSize, const void * data);
				static inline void texImage3DMultisample(TargetTextureMultisample target, std::size_t samples, PixelInternalFormat internalFormat, std::size_t width, std::size_t height, std::size_t depth, bool fixedSamplelLocations);
				static inline void texImage2DMultisample(TargetTextureMultisample target, std::size_t samples, PixelInternalFormat internalformat, std::size_t width, std::size_t height, bool fixedsamplelocations);
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
				static inline auto readPixels(int x, int y, std::size_t width, std::size_t height, PixelFormat format, DataType type) -> void *;
				static inline void readBuffer(ColorBuffer mode);
				static inline void blitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, Bitfield mask, ImageFilter filter);
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
				static inline void clear(const Bitfield mask);
				static inline void clearColor(const float r, const float g, const float b, const float a);
				static inline void clearDepth(double depth);
				static inline void clearStencil(int s);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<int> & value);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<unsigned int> & value);
				static inline void clearBuffer(BufferKind buffer, Handle drawbuffer, const std::vector<float> & value);
				static inline void clearBuffer(GLenum buffer, int drawbuffer, float depth, int stencil);
				static inline void bindFramebuffer(FramebufferTarget target, Handle framebuffer);
				static inline void deleteFramebuffers(std::vector<Handle> & framebuffers);
				static inline auto genFramebuffers(std::size_t n) -> std::vector<Handle>;
				static inline void bindRenderbuffer(Handle renderbuffer);
				static inline void deleteRenderbuffers(std::vector<Handle> & renderbuffers);
				static inline auto genRenderbuffers(std::size_t n) -> std::vector<Handle>;
				static inline void renderbufferStorageMultisample(std::size_t samples, PixelFormat internalformat, std::size_t width, std::size_t height);
				static inline void renderbufferStorage(PixelFormat internalformat, std::size_t width, std::size_t height);
				static inline void framebufferRenderbuffer(FramebufferTarget target, FramebufferAttachment attachment, unsigned int renderbuffer);
				static inline void framebufferTexture(FramebufferTarget target, FramebufferAttachment attachment, Handle texture, int level);
				static inline void framebufferTexture1D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level);
				static inline void framebufferTexture2D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level);
				static inline void framebufferTexture3D(FramebufferTarget target, FramebufferAttachment attachment, FramebufferTargetTexture textarget, Handle texture, int level, int layer);
				static inline void framebufferTextureLayer(FramebufferTarget target, FramebufferAttachment attachment, Handle texture, int level, int layer);
				static inline auto checkFramebufferStatus(FramebufferTarget target) -> FramebufferStatus;
				static inline auto isFramebuffer(Handle framebuffer) -> bool;
				static inline auto getFramebufferAttachmentParameter(FramebufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameter pname) -> int;
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
				static inline auto genSamplers(std::size_t n) -> std::vector<Handle>;
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
				static inline void vertexAttribDivisor(const int index, const std::size_t divisor);

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
				static inline auto genTransformFeedbacks(std::size_t n) -> std::vector<Handle>;
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
				static inline void shaderBinary(const std::vector<Handle> & shaders, BinaryFormat binaryFormat, const void * binary, std::size_t length);
				static inline void releaseShaderCompiler();
				static inline auto createShaderProgram(ShaderType type, std::vector<std::string> & strings) -> Handle;
				static inline void programParameter(Handle program, ProgramHint pname, int value);
				static inline auto genProgramPipelines(std::size_t n) -> std::vector<Handle>;
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
				template <class T, unsigned int S> static inline void programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const std::array<T, S> & v);
				template <> inline void programUniform<float, 1>(Handle program, const int location, std::size_t count, const std::array<float, 1> & v);
				template <> inline void programUniform<float, 2>(Handle program, const int location, std::size_t count, const std::array<float, 2> & v);
				template <> inline void programUniform<float, 3>(Handle program, const int location, std::size_t count, const std::array<float, 3> & v);
				template <> inline void programUniform<float, 4>(Handle program, const int location, std::size_t count, const std::array<float, 4> & v);
				template <> inline void programUniform<int, 1>(Handle program, const int location, std::size_t count, const std::array<int, 1> & v);
				template <> inline void programUniform<int, 2>(Handle program, const int location, std::size_t count, const std::array<int, 2> & v);
				template <> inline void programUniform<int, 3>(Handle program, const int location, std::size_t count, const std::array<int, 3> & v);
				template <> inline void programUniform<int, 4>(Handle program, const int location, std::size_t count, const std::array<int, 4> & v);
				template <> inline void programUniform<unsigned int, 1>(Handle program, const int location, std::size_t count, const std::array<unsigned int, 1> & v);
				template <> inline void programUniform<unsigned int, 2>(Handle program, const int location, std::size_t count, const std::array<unsigned int, 2> & v);
				template <> inline void programUniform<unsigned int, 3>(Handle program, const int location, std::size_t count, const std::array<unsigned int, 3> & v);
				template <> inline void programUniform<unsigned int, 4>(Handle program, const int location, std::size_t count, const std::array<unsigned int, 4> & v);
				template <class T, unsigned int M, unsigned int N> static inline void programUniform([[maybe_unused]] Handle program, [[maybe_unused]] const int location, [[maybe_unused]] std::size_t count, [[maybe_unused]] const bool transpose, [[maybe_unused]] const Matrix<T, M, N> & v);
				template <> inline void programUniform<float, 2, 2>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 2> & v);
				template <> inline void programUniform<float, 3, 3>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 3> & v);
				template <> inline void programUniform<float, 4, 4>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 4> & v);
				template <> inline void programUniform<float, 2, 3>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 3> & v);
				template <> inline void programUniform<float, 3, 2>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 2> & v);
				template <> inline void programUniform<float, 2, 4>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 2, 4> & v);
				template <> inline void programUniform<float, 4, 2>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 2> & v);
				template <> inline void programUniform<float, 3, 4>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 3, 4> & v);
				template <> inline void programUniform<float, 4, 3>(Handle program, const int location, std::size_t count, const bool transpose, const Matrix<float, 4, 3> & v);
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
				static inline void scissorIndexed(Handle index, int left, int bottom, std::size_t width, std::size_t height);
				static inline void scissorIndexed(Handle index, const std::array<int, 4> & v);

				//		static inline void getActiveAtomicCounterBufferiv(unsigned int program, unsigned int bufferIndex, GLenum pname, int *params);
				//		static inline void memoryBarrier(GLbitfield barriers);
				//		static inline void texStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
				//		static inline void texStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
				//		static inline void texStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
				//		static inline void bindImageTexture(unsigned int unit, unsigned int texture, int level, bool layered, int layer, GLenum access, GLenum format);
				//		static inline void drawArraysInstancedBaseInstance(GLenum mode, int first, GLsizei count, GLsizei primcount, unsigned int baseinstance);
				//		static inline void drawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount, unsigned int baseinstance);
				//		static inline void drawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, void *indices, GLsizei primcount, int basevertex, unsigned int baseinstance);
				//		static inline void drawTransformFeedbackInstanced(GLenum mode, unsigned int id, GLsizei primcount);
				//		static inline void drawTransformFeedbackStreamInstanced(GLenum mode, unsigned int id, unsigned int stream, GLsizei primcount);
				//		static inline void getInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, int *params);

				//		static inline void clearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
				//		static inline void clearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
				//		static inline void invalidateBufferSubData(unsigned int buffer, GLintptr offset, GLsizeiptr length);
				//		static inline void invalidateBufferData(unsigned int buffer);
				//		static inline void getProgramInterfaceiv(unsigned int program, GLenum programInterface, GLenum pname, int * params);
				//		static inline unsigned int getProgramResourceIndex(unsigned int program, GLenum programInterface, const char * name);
				//		static inline void getProgramResourceName(unsigned int program, GLenum programInterface, unsigned int index, GLsizei bufSize, GLsizei * length, char * name);
				//		static inline void getProgramResourceiv(unsigned int program, GLenum programInterface, unsigned int index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, int * params);
				//		static inline int getProgramResourceLocation(unsigned int program, GLenum programInterface, const char * name);
				//		static inline int getProgramResourceLocationIndex(unsigned int program, GLenum programInterface, const char * name);
				//		static inline void shaderStorageBlockBinding(unsigned int program, unsigned int storageBlockIndex, unsigned int storageBlockBinding);
				//		static inline void getPointerv(GLenum pname, void ** params);
				//		static inline void texBufferRange(GLenum target, GLenum internalFormat, unsigned int buffer, GLintptr offset, GLsizeiptr size);
				//		static inline void textureView(unsigned int texture, GLenum target, unsigned int origtexture, GLenum internalformat, unsigned int minlevel, unsigned int numlevels, unsigned int minlayer, unsigned int numlayers);
				//		static inline void texStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, bool fixedsamplelocations);
				//		static inline void texStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, bool fixedsamplelocations);
				//		static inline void invalidateTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth);
				static inline void invalidateTexImage(Handle texture, int level);
				//		static inline void framebufferParameteri(GLenum target, GLenum pname, int param);
				//		static inline void getFramebufferParameteriv(GLenum target, GLenum pname, int *params);
				//		static inline void vertexAttribFormat(unsigned int attribindex, int size, GLenum type, bool normalized, unsigned int relativeoffset);
				//		static inline void vertexAttribIFormat(unsigned int attribindex, int size, GLenum type, unsigned int relativeoffset);
				//		static inline void vertexAttribLFormat(unsigned int attribindex, int size, GLenum type, unsigned int relativeoffset);
				//		static inline void bindVertexBuffer(unsigned int bindingindex, unsigned int buffer, GLintptr offset, GLintptr stride);
				//		static inline void vertexAttribBinding(unsigned int attribindex, unsigned int bindingindex);
				//		static inline void vertexBindingDivisor(unsigned int bindingindex, unsigned int divisor);
				//		static inline void multiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
				//		static inline void multiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride);
				//		static inline void multiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
				//		static inline void multiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
				//		static inline void dispatchCompute(unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z);
				//		static inline void dispatchComputeIndirect(GLintptr indirect);
				//		static inline void invalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, int x, int y, int width, int height);
				//		static inline void invalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments);
				//		static inline void copyImageSubData(unsigned int srcName, GLenum srcTarget, int srcLevel, int srcX, int srcY, int srcZ, unsigned int dstName, GLenum dstTarget, int dstLevel, int dstX, int dstY, int dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
				static inline void debugMessageCallback(GLDEBUGPROC callback, const void * userParam);
				static inline void debugMessageControl(const SourceDebugMessage source, const TypeDebugMessage type, const SeverityDebugMessage severity, const std::vector<unsigned int> & ids, bool enabled);
				//		static inline void debugMessageInsert(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char *message);
				//		static inline void pushDebugGroup(GLenum source, unsigned int id, GLsizei length, const char * message);
				static inline void popDebugGroup();
				//		static inline void objectLabel(GLenum identifier, unsigned int name, GLsizei length, const char * label);
				//		static inline void objectPtrLabel(void * ptr, GLsizei length, const char * label);
				//		static inline unsigned int getDebugMessageLog(unsigned int count, GLsizei bufSize, GLenum *sources, GLenum *types, unsigned int *ids, GLenum *severities, GLsizei *lengths, char *messageLog);
				//		static inline void getObjectLabel(GLenum identifier, unsigned int name, GLsizei bifSize, GLsizei * length, char * label);
				//		static inline void getObjectPtrLabel(void * ptr, GLsizei bifSize, GLsizei * length, char * label);
				//		static inline void getInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);

				//		static inline void bindBuffersRange(GLenum target, unsigned int first, GLsizei count, const unsigned int *buffers, const GLintptr *offsets, const GLintptr *sizes);
				//		static inline void bindBuffersBase(GLenum target, unsigned int first, GLsizei count, const unsigned int *buffers);
				//		static inline void bufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
				//		static inline void bindTextures(unsigned int first, GLsizei count, const unsigned int *textures);
				//		static inline void bindSamplers(unsigned int first, GLsizei count, const unsigned int *samplers);
				//		static inline void clearTexSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
				//		static inline void clearTexImage(unsigned int texture, int level, GLenum format, GLenum type, const void * data);
				//		static inline void bindImageTextures(unsigned int first, GLsizei count, const unsigned int *textures);
				//		static inline void bindVertexBuffers(unsigned int first, GLsizei count, const unsigned int *buffers, const GLintptr *offsets, const GLsizei *strides);

				//		static inline void enableVertexArrayAttrib(unsigned int vaobj, unsigned int index);
				//		static inline void disableVertexArrayAttrib(unsigned int vaobj, unsigned int index);
				//		static inline void namedBufferData(unsigned int buffer, GLsizei size, const void *data, GLenum usage);
				//		static inline void namedBufferSubData(unsigned int buffer, GLintptr offset, GLsizei size, const void *data);
				//		static inline void * mapNamedBufferRange(unsigned int buffer, GLintptr offset, GLsizei length, GLbitfield access);
				//		static inline void * mapNamedBuffer(unsigned int buffer, GLenum access);
				//		static inline void flushMappedNamedBufferRange(unsigned int buffer, GLintptr offset, GLsizei length);
				static inline auto unmapNamedBuffer(Handle buffer) -> bool;
				//		static inline void copyNamedBufferSubData(unsigned int readBuffer, unsigned int writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizei size);
				//		static inline void getNamedBufferParameteriv(unsigned int buffer, GLenum pname, int * params);
				//		static inline void getNamedBufferParameteri64v(unsigned int buffer, GLenum pname, GLint64 * params);
				//		static inline void getNamedBufferSubData(unsigned int buffer, GLintptr offset, GLsizei size, void *data);
				//		static inline void getNamedBufferPointerv(unsigned int buffer, GLenum pname, void ** params);
				//		static inline void getnUniformfv(unsigned int program, int location, GLsizei bufSize, float *params);
				//		static inline void getnUniformiv(unsigned int program, int location, GLsizei bufSize, int *params);
				//		static inline void getnUniformuiv(unsigned int program, int location, GLsizei bufSize, unsigned int *params);
				//		static inline void getnUniformdv(unsigned int program, int location, GLsizei bufSize, double *params);
				//		static inline void textureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
				//		static inline void textureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
				//		static inline void textureSubImage1D(unsigned int texture, int level, int xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
				//		static inline void copyTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, GLsizei width, GLsizei height);
				//		static inline void copyTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, int x, int y, GLsizei width, GLsizei height);
				//		static inline void copyTextureSubImage1D(unsigned int texture, int level, int xoffset, int x, int y, GLsizei width);
				//		static inline void compressedTextureSubImage3D(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
				//		static inline void compressedTextureSubImage2D(unsigned int texture, int level, int xoffset, int yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
				//		static inline void compressedTextureSubImage1D(unsigned int texture, int level, int xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
				//		static inline void textureBuffer(unsigned int texture, GLenum internalformat, unsigned int buffer);
				//		static inline void textureParameterf(unsigned int texture, GLenum pname, float param);
				//		static inline void textureParameteri(unsigned int texture, GLenum pname, int param);
				//		static inline void textureParameterfv(unsigned int texture, GLenum pname, const float *param);
				//		static inline void textureParameteriv(unsigned int texture, GLenum pname, const int *param);
				//		static inline void textureParameterIiv(unsigned int texture, GLenum pname, const int *params);
				//		static inline void textureParameterIuiv(unsigned int texture, GLenum pname, const unsigned int *params);
				
				static inline void generateTextureMipmap(Handle texture);

				//		static inline void getTextureParameterfv(unsigned int texture, GLenum pname, float *params);
				//		static inline void getTextureParameteriv(unsigned int texture, GLenum pname, int *params);
				//		static inline void getTextureParameterIiv(unsigned int texture, GLenum pname, int *params);
				//		static inline void getTextureParameterIuiv(unsigned int texture, GLenum pname, unsigned int *params);
				//		static inline void getTextureLevelParameterfv(unsigned int texture, int level, GLenum pname, float *params);
				//		static inline void getTextureLevelParameteriv(unsigned int texture, int level, GLenum pname, int *params);
				//		static inline void getnTexImage(GLenum target, int level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
				//		static inline void getTextureImage(unsigned int texture, int level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
				//		static inline void getnCompressedTexImage(GLenum target, int level, GLsizei bufSize, void *pixels);
				//		static inline void getCompressedTextureImage(unsigned int texture, int level, GLsizei bufSize, void *pixels);
				//		static inline void readnPixels(int x, int y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
				//		static inline void namedFramebufferReadBuffer(unsigned int framebuffer, GLenum mode);
				//		static inline void blitNamedFramebuffer(unsigned int readFramebuffer, unsigned int drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, GLbitfield mask, GLenum filter);
				//		static inline void namedFramebufferDrawBuffer(unsigned int framebuffer, GLenum buf);
				//		static inline void namedFramebufferDrawBuffers(unsigned int framebuffer, GLsizei n, const GLenum *bufs);
				//		static inline void clearNamedFramebufferiv(unsigned int framebuffer, GLenum buffer, int drawbuffer, const int *value);
				//		static inline void clearNamedFramebufferuiv(unsigned int framebuffer, GLenum buffer, int drawbuffer, const unsigned int *value);
				//		static inline void clearNamedFramebufferfv(unsigned int framebuffer, GLenum buffer, int drawbuffer, const float *value);
				//		static inline void clearNamedFramebufferfi(unsigned int framebuffer, GLenum buffer, int drawbuffer, float depth, int stencil);
				//		static inline void namedRenderbufferStorageMultisample(unsigned int renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
				//		static inline void namedRenderbufferStorage(unsigned int renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
				//		static inline void namedFramebufferRenderbuffer(unsigned int framebuffer, GLenum attachment, GLenum renderbuffertarget, unsigned int renderbuffer);
				//		static inline void namedFramebufferTexture(unsigned int framebuffer, GLenum attachment, unsigned int texture, int level);
				//		static inline void namedFramebufferTextureLayer(unsigned int framebuffer, GLenum attachment, unsigned int texture, int level, int layer);
				//		static inline GLenum checkNamedFramebufferStatus(unsigned int framebuffer, GLenum target);
				//		static inline void getNamedFramebufferAttachmentParameteriv(unsigned int framebuffer, GLenum attachment, GLenum pname, int *params);
				//		static inline void getNamedRenderbufferParameteriv(unsigned int renderbuffer, GLenum pname, int *params);
				//		static inline GLenum getGraphicsResetStatus();
				//		static inline void createBuffers(GLsizei n, unsigned int *buffers);
				//		static inline void namedBufferStorage(unsigned int buffer, GLsizei size, const void * data, GLbitfield flags);
				//		static inline void clearNamedBufferData(unsigned int buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
				//		static inline void createProgramPipelines(GLsizei n, unsigned int *pipelines);
				//		static inline void memoryBarrierByRegion(GLbitfield barriers);
				//		static inline void bindTextureUnit(unsigned int unit, unsigned int texture);
				//		static inline void createTextures(GLenum target, GLsizei n, unsigned int *textures);
				//		static inline void createSamplers(GLsizei n, unsigned int *samplers);
				//		static inline void textureBufferRange(unsigned int texture, GLenum internalformat, unsigned int buffer, GLintptr offset, GLsizei size);
				//		static inline void getTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
				//		static inline void getCompressedTextureSubImage(unsigned int texture, int level, int xoffset, int yoffset, int zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
				//		static inline void textureStorage1D(unsigned int texture, GLsizei levels, GLenum internalformat, GLsizei width);
				//		static inline void textureStorage2D(unsigned int texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
				//		static inline void textureStorage3D(unsigned int texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
				//		static inline void textureStorage2DMultisample(unsigned int texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, bool fixedsamplelocations);
				//		static inline void textureStorage3DMultisample(unsigned int texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, bool fixedsamplelocations);
				//		static inline void createFramebuffers(GLsizei n, unsigned int *ids);
				//		static inline void namedFramebufferParameteri(unsigned int framebuffer, GLenum pname, int param);
				//		static inline void getNamedFramebufferParameteriv(unsigned int framebuffer, GLenum pname, int *param);
				//		static inline void createRenderbuffers(GLsizei n, unsigned int *renderbuffers);
				static inline void textureBarrier();
				//		static inline void createVertexArrays(GLsizei n, unsigned int *arrays);
				//		static inline void vertexArrayElementBuffer(unsigned int vaobj, unsigned int buffer);
				//		static inline void vertexArrayAttribFormat(unsigned int vaobj, unsigned int attribindex, int size, GLenum type, bool normalized, unsigned int relativeoffset);
				//		static inline void vertexArrayAttribIFormat(unsigned int vaobj, unsigned int attribindex, int size, GLenum type, unsigned int relativeoffset);
				//		static inline void vertexArrayAttribLFormat(unsigned int vaobj, unsigned int attribindex, int size, GLenum type, unsigned int relativeoffset);
				//		static inline void vertexArrayVertexBuffer(unsigned int vaobj, unsigned int bindingindex, unsigned int buffer, GLintptr offset, GLsizei stride);
				//		static inline void vertexArrayVertexBuffers(unsigned int vaobj, unsigned int first, GLsizei count, const unsigned int *buffers, const GLintptr *offsets, const GLsizei *strides);
				//		static inline void vertexArrayAttribBinding(unsigned int vaobj, unsigned int attribindex, unsigned int bindingindex);
				//		static inline void vertexArrayBindingDivisor(unsigned int vaobj, unsigned int bindingindex, unsigned int divisor);
				//		static inline void getVertexArrayiv(unsigned int vaobj, GLenum pname, int *param);
				//		static inline void getVertexArrayIndexed64iv(unsigned int vaobj, unsigned int index, GLenum pname, GLint64 *param);
				//		static inline void getVertexArrayIndexediv(unsigned int vaobj, unsigned int index, GLenum pname, int *param);
				//		static inline void createTransformFeedbacks(GLsizei n, unsigned int *ids);
				//		static inline void transformFeedbackBufferRange(unsigned int xfb, unsigned int index, unsigned int buffer, GLintptr offset, GLsizei size);
				//		static inline void transformFeedbackBufferBase(unsigned int xfb, unsigned int index, unsigned int buffer);
				//		static inline void clipControl(GLenum origin, GLenum depth);
				//		static inline void invalidateNamedFramebufferSubData(unsigned int framebuffer, GLsizei numAttachments, const GLenum *attachments, int x, int y, GLsizei width, GLsizei height);
				//		static inline void invalidateNamedFramebufferData(unsigned int framebuffer, GLsizei numAttachments, const GLenum *attachments);
				//		static inline void getTransformFeedbackiv(unsigned int xfb, GLenum pname, int *param);
				//		static inline void getTransformFeedbacki_v(unsigned int xfb, GLenum pname, unsigned int index, int *param);
				//		static inline void getTransformFeedbacki64_v(unsigned int xfb, GLenum pname, unsigned int index, GLint64 *param);

				//		static inline void specializeShader(unsigned int shader, const char *pEntryPoint​, unsigned int numSpecializationConstants​, const unsigned int *pConstantIndex​, const unsigned int *pConstantValue​);
				//		static inline void polygonOffsetClamp(float factor, float units, float clamp);
			} //namespace OpengL
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#include "renderer/opengl/opengl.inl"

#endif // OPENGL_HPP
