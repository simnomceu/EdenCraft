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

#include "renderer/opengl/opengl_extension.hpp"
#include "renderer/debug/debugging.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using namespace debug;

			inline Version<2> & OpenGL::getLatestVersion() { return OpenGL::_latestVersion; }

			inline void OpenGL::setCurrentContext(const std::shared_ptr<BaseContext> & currentContext)
			{
				OpenGL::_currentContext.reset();
				OpenGL::_currentContext = currentContext;
			}

			template <class T>
			inline constexpr DataType OpenGL::dataType() { throw std::runtime_error("This type cannot be passed."); }

			template <>
			inline DataType OpenGL::dataType<short int>() { return DataType::SHORT; }

			template <>
			inline DataType OpenGL::dataType<unsigned short int>() { return DataType::UNSIGNED_SHORT; }

			template <>
			inline DataType OpenGL::dataType<int>() { return DataType::INT; }

			template <>
			inline DataType OpenGL::dataType<unsigned int>() { return DataType::UNSIGNED_INT; }

			template <>
			inline DataType OpenGL::dataType<float>() { return DataType::FLOAT; }

			template <>
			inline DataType OpenGL::dataType<double>() { return DataType::DOUBLE; }

			template <DataType Type>
			inline constexpr std::size_t OpenGL::dataTypeSize() { throw std::runtime_error("This type cannot be passed."); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::SHORT>() { return sizeof(short int); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::UNSIGNED_SHORT>() { return sizeof(unsigned short int); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::INT>() { return sizeof(int); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::UNSIGNED_INT>() { return sizeof(unsigned int); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::FLOAT>() { return sizeof(float); }

			template <>
			inline constexpr std::size_t OpenGL::dataTypeSize<DataType::DOUBLE>() { return sizeof(double); }

			inline void OpenGL::bindBuffer(const BufferType type, const Handle handle)
			{
				checkErrors(glBindBuffer(static_cast<GLenum>(type), handle));
			}

			inline void OpenGL::genVertexArrays(Handle & handle)
			{
				checkErrors(glGenVertexArrays(1, &handle));
			}

			inline void OpenGL::genVertexArrays(const int count, std::vector<Handle>& handles)
			{
				if (count != 0) {
					handles.resize(handles.size() + count);
					checkErrors(glGenVertexArrays(count, &handles.back() - count + 1));
				}
			}

			inline void OpenGL::bindVertexArray(const Handle handle)
			{
				checkErrors(glBindVertexArray(handle));
			}

			template <template <class, class...> class T, class E, class... TT, typename enabled>
			inline void OpenGL::bufferData(const BufferType type, const T<E, TT...> & data, const BufferUsage usage, const int offset)
			{
				checkErrors(glBufferData(static_cast<GLenum>(type), std::size(data) * sizeof(E), std::data(data) + offset, static_cast<GLenum>(usage)));
			}

			inline void OpenGL::vertexAttribPointer(const int location, const std::size_t size, const DataType type, const bool normalized, const std::size_t stride, const std::size_t offset)
			{
				checkErrors(glVertexAttribPointer(location, static_cast<GLint>(size), static_cast<GLenum>(type), normalized, static_cast<GLsizei>(stride), reinterpret_cast<GLvoid *>(offset)));
			}

			// New version

			inline ErrorGL OpenGL::getError() { return ErrorGL(glGetError()); }

			//	inline void OpenGL::vertexAttrib1f(unsigned int /*index*/, float /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib1s(unsigned int /*index*/, short /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib1d(unsigned int /*index*/, double /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI1i(unsigned int /*index*/, int /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI1ui(unsigned int /*index*/, unsigned int /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2f(unsigned int /*index*/, float /*v0*/, float /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2s(unsigned int /*index*/, short /*v0*/, short /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2d(unsigned int /*index*/, double /*v0*/, double /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI2i(unsigned int /*index*/, int /*v0*/, int /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI2ui(unsigned int /*index*/, unsigned int /*v0*/, unsigned int /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3f(unsigned int /*index*/, float /*v0*/, float /*v1*/, float /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3s(unsigned int /*index*/, short /*v0*/, short /*v1*/, short /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI3i(unsigned int /*index*/, int /*v0*/, int /*v1*/, int /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI3ui(unsigned int /*index*/, unsigned int /*v0*/, unsigned int /*v1*/, unsigned int /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4f(unsigned int /*index*/, float /*v0*/, float /*v1*/, float /*v2*/, float /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4s(unsigned int /*index*/, short /*v0*/, short /*v1*/, short /*v2*/, short /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/, double /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nub(unsigned int /*index*/, GLubyte /*v0*/, GLubyte /*v1*/, GLubyte /*v2*/, GLubyte /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4i(unsigned int /*index*/, int /*v0*/, int /*v1*/, int /*v2*/, int /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4ui(unsigned int /*index*/, unsigned int /*v0*/, unsigned int /*v1*/, unsigned int /*v2*/, unsigned int /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib1fv(unsigned int /*index*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib1sv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib1dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI1iv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI1uiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2fv(unsigned int /*index*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2sv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib2dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI2iv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI2uiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3fv(unsigned int /*index*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3sv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib3dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI3iv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI3uiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4fv(unsigned int /*index*/, const float * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4sv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4iv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4bv(unsigned int /*index*/, const GLbyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4ubv(unsigned int /*index*/, const GLubyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4usv(unsigned int /*index*/, const unsigned short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4uiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nbv(unsigned int /*index*/, const GLbyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nsv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Niv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nubv(unsigned int /*index*/, const GLubyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nusv(unsigned int /*index*/, const unsigned short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttrib4Nuiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4bv(unsigned int /*index*/, const GLbyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4ubv(unsigned int /*index*/, const GLubyte * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4sv(unsigned int /*index*/, const short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4usv(unsigned int /*index*/, const unsigned short * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4iv(unsigned int /*index*/, const int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribI4uiv(unsigned int /*index*/, const unsigned int * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribP1ui(unsigned int /*index*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribP2ui(unsigned int /*index*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribP3ui(unsigned int /*index*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribP4ui(unsigned int /*index*/, GLenum /*type*/, bool /*normalized*/, unsigned int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribPointer(unsigned int /*index*/, int /*size*/, GLenum /*type*/, bool /*normalized*/, GLsizei /*stride*/, const void * /*pointer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribIPointer(unsigned int /*index*/, int /*size*/, GLenum /*type*/, GLsizei /*stride*/, const void * /*pointer*/) { static_assert(false, "Not implemented yet."); }

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

			//	inline void OpenGL::primitiveRestartIndex(unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::drawArrays(const PrimitiveMode mode, const int first, const std::size_t count)
			{
				checkErrors(glDrawArrays(static_cast<GLenum>(mode), first, static_cast<GLsizei>(count)));
			}

			//	inline void OpenGL::multiDrawArrays(GLenum /*mode*/, const int * /*first*/, const GLsizei * /*count*/, GLsizei /*drawcount*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::drawElements(const PrimitiveMode mode, const std::size_t count, const DataType type, const int offset)
			{
				unsigned char * byteOffset = nullptr;
				byteOffset += offset * sizeof(unsigned int);
				checkErrors(glDrawElements(static_cast<GLenum>(mode), static_cast<GLsizei>(count), static_cast<GLenum>(type), byteOffset));
			}

			//	inline void OpenGL::multiDrawElements(GLenum /*mode*/, const GLsizei * /*count*/, GLenum /*type*/, const void * const * /*indices*/, GLsizei /*drawcount*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawRangeElements(GLenum /*mode*/, unsigned int /*start*/, unsigned int /*end*/, GLsizei /*count*/, GLenum /*type*/, const void * /*indices*/) { static_assert(false, "Not implemented yet."); }
			inline void OpenGL::drawArraysInstanced(const PrimitiveMode mode, const int first, const std::size_t count, const std::size_t primcount)
            {
                checkErrors(glDrawArraysInstanced(static_cast<GLenum>(mode), first, static_cast<GLsizei>(count), static_cast<GLsizei>(primcount)));
            }

            inline void OpenGL::drawElementsInstanced(const PrimitiveMode mode, const std::size_t count, const DataType type, const int offset, const std::size_t primcount)
            {
				unsigned char * byteOffset = nullptr;
				byteOffset += offset * sizeof(unsigned int);
				checkErrors(glDrawElementsInstanced(static_cast<GLenum>(mode), static_cast<GLsizei>(count), static_cast<GLenum>(type), byteOffset, static_cast<GLsizei>(primcount)));
            }

            //	inline void OpenGL::drawElementsBaseVertex(GLenum /*mode*/, GLsizei /*count*/, GLenum /*type*/, void * /*indices*/, int /*basevertex*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawRangeElementsBaseVertex(GLenum /*mode*/, unsigned int /*start*/, unsigned int /*end*/, GLsizei /*count*/, GLenum /*type*/, void * /*indices*/, int /*basevertex*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawElementsInstancedBaseVertex(GLenum /*mode*/, GLsizei /*count*/, GLenum /*type*/, void * /*indices*/, GLsizei /*primcount*/, int /*basevertex*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::multiDrawElementsBaseVertex(GLenum /*mode*/, const GLsizei * /*count*/, GLenum /*type*/, const void * const * /*indices*/, GLsizei /*drawcount*/, const int * /*basevertex*/) { static_assert(false, "Not implemented yet."); }

			inline Handle OpenGL::genBuffers()
			{
				Handle handle = 0;
				checkErrors(glGenBuffers(1, &handle));
				return handle;
			}

			inline std::vector<Handle> OpenGL::genBuffers(const int count)
			{
				std::vector<Handle> handles;
				if (count != 0) {
					handles.resize(handles.size() + count);
					checkErrors(glGenBuffers(count, &handles.back() - count + 1));
				}
				return handles;
			}

			inline void OpenGL::deleteBuffer(const Handle buffer)
			{
				checkErrors(glDeleteBuffers(1, &buffer));
			}

			inline void OpenGL::deleteBuffers(const std::vector<Handle> & buffers)
			{
				checkErrors(glDeleteBuffers(static_cast<GLsizei>(buffers.size()), buffers.data()));
			}

			//	inline void OpenGL::bindBuffer(GLenum /*target*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindBufferRange(GLenum /*target*/, unsigned int /*index*/, unsigned int /*buffer*/, GLintptr /*offset*/, GLsizeiptr /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindBufferBase(GLenum /*target*/, unsigned int /*index*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bufferData(GLenum /*target*/, GLsizeiptr /*size*/, const void * /*data*/, GLenum /*usage*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bufferSubData(GLenum /*target*/, GLintptr /*offset*/, GLsizeiptr /*size*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void * OpenGL::mapBufferRange(GLenum /*target*/, GLintptr /*offset*/, GLsizeiptr /*length*/, GLbitfield /*access*/) { static_assert(false, "Not implemented yet."); }
			//	inline void * OpenGL::mapBuffer(GLenum /*target*/, GLenum /*access*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::flushMappedBufferRange(GLenum /*target*/, GLintptr /*offset*/, GLsizeiptr /*length*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::unmapBuffer(GLenum /*target*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyBufferSubData(GLenum /*readTarget*/, GLenum /*writeTarget*/, GLintptr /*readOffset*/, GLintptr /*writeOffset*/, GLsizeiptr /*size*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genVertexArrays(GLsizei /*n*/, unsigned int * /*arrays*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteVertexArrays(GLsizei /*n*/, const unsigned int * /*arrays*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindVertexArray(unsigned int /*array*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isBuffer(unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBufferParameteriv(GLenum /*target*/, GLenum /*value*/, int * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBufferParameteri64v(GLenum /*target*/, GLenum /*value*/, GLint64 * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBufferSubData(GLenum /*target*/, GLintptr /*offset*/, GLsizeiptr /*size*/, void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBufferPointerv(GLenum /*target*/, GLenum /*pname*/, void ** /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isVertexArray(unsigned int /*array*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::depthRange(double /*nearVal*/, double /*farVal*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::viewport(const int x, const int y, const unsigned int width, const unsigned int height)
			{
				checkErrors(glViewport(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}

			//	inline void OpenGL::clampColor(GLenum /*target*/, GLenum /*clamp*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::provokingVertex(GLenum /*provokeMode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::beginConditionalRender(unsigned int /*id*/, GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::endConditionalRender() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::beginTransformFeedback(GLenum /*primitiveMode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::endTransformFeedback() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::beginQuery(GLenum /*target*/, unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::endQuery(GLenum /*target*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genQueries(GLsizei /*n*/, unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteQueries(GLsizei /*n*/, const unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isQuery(unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryiv(GLenum /*target*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryObjectiv(unsigned int /*id*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryObjectuiv(unsigned int /*id*/, GLenum /*pname*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryObjecti64v(unsigned int /*id*/, GLenum /*pname*/, GLint64 * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryObjectui64v(unsigned int /*id*/, GLenum /*pname*/, GLuint64 * /*params*/) { static_assert(false, "Not implemented yet."); }

			inline Handle OpenGL::createShader(const ShaderType type)
			{
				Handle shaderHandle = checkErrors(glCreateShader(static_cast<GLenum>(type)));
				return shaderHandle;
			}

			inline void OpenGL::shaderSource(const Handle handle, const std::string & source)
			{
				auto sourcePtr = source.data();
				checkErrors(glShaderSource(handle, 1, &sourcePtr, nullptr)); // TODO: add the length of the source
			}

			inline void OpenGL::shaderSource(const Handle handle, const std::vector<std::string>& source)
			{
				std::vector<const char*> sourcesPtr{};
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

			inline Handle OpenGL::createProgram()
			{
				Handle programHandle = checkErrors(glCreateProgram());
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

			//	inline void OpenGL::deleteProgram(unsigned int /*program*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveAttrib(unsigned int /*program*/, unsigned int /*index*/, GLsizei /*bufSize*/, GLsizei * /*length*/, int * /*size*/, GLenum * /*type*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline int OpenGL::getAttribLocation(unsigned int /*program*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindAttribLocation(unsigned int /*program*/, unsigned int /*index*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }

			inline Handle OpenGL::getUniformLocation(const Handle handle, const std::string & uniform)
			{
				Handle location = checkErrors(glGetUniformLocation(handle, uniform.data()));
				return std::move(location);
			}

			//	inline unsigned int OpenGL::getUniformBlockIndex(unsigned int /*program*/, const char * /*uniformBlockName*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveUniformBlockName(unsigned int /*program*/, unsigned int /*uniformBlockIndex*/, GLsizei /*bufSize*/, GLsizei * /*length*/, char * /*uniformBlockName*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveUniformBlockiv(unsigned int /*program*/, unsigned int /*uniformBlockIndex*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getUniformIndices(unsigned int /*program*/, GLsizei /*uniformCount*/, const char ** /*uniformNames*/, unsigned int * /*uniformIndices*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveUniformName(unsigned int /*program*/, unsigned int /*uniformIndex*/, GLsizei /*bufSize*/, GLsizei * /*length*/, char * /*uniformName*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveUniform(unsigned int /*program*/, unsigned int /*index*/, GLsizei /*bufSize*/, GLsizei * /*length*/, int * /*size*/, GLenum * /*type*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveUniformsiv(unsigned int /*program*/, GLsizei /*uniformCount*/, const unsigned int * /*uniformIndices*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }

			template <class T, unsigned int S>
			inline void OpenGL::uniform(const int /*location*/, const std::array<T, S> & /*v*/)
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

			//	inline void OpenGL::uniform1fv(int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform2fv(int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform3fv(int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform4fv(int /*location*/, GLsizei /*count*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform1iv(int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform2iv(int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform3iv(int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform4iv(int /*location*/, GLsizei /*count*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform1uiv(int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform2uiv(int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform3uiv(int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniform4uiv(int /*location*/, GLsizei /*count*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }

			template <class T, unsigned int M, unsigned int N>
			inline void OpenGL::uniform(const int location, const bool transpose, const Matrix<T, M, N> & v)
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

			//	inline void OpenGL::uniformMatrix2fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix3fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix4fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix2x3fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix3x2fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix2x4fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix4x2fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix3x4fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformMatrix4x3fv(int /*location*/, GLsizei /*count*/, bool /*transpose*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformBlockBinding(unsigned int /*program*/, unsigned int /*uniformBlockIndex*/, unsigned int /*uniformBlockBinding*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::transformFeedbackVaryings(unsigned int /*program*/, GLsizei /*count*/, const char ** /*varyings*/, GLenum /*bufferMode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTransformFeedbackVarying(unsigned int /*program*/, unsigned int /*index*/, GLsizei /*bufSize*/, GLsizei * /*length*/, GLsizei * /*size*/, GLenum * /*type*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::validateProgram(unsigned int /*program*/) { static_assert(false, "Not implemented yet."); }

			inline std::vector<int> OpenGL::getProgramiv(const Handle program, const ProgramParameter pname)
			{
				std::vector<int> result;
				if (pname == ProgramParameter::COMPUTE_WORK_GROUP_SIZE) {
					result.resize(3);
					checkErrors(glGetProgramiv(static_cast<GLuint>(program), static_cast<GLenum>(pname), result.data()));
				}
				else {
					int dummy;
					checkErrors(glGetProgramiv(static_cast<GLuint>(program), static_cast<GLenum>(pname), &dummy));
					result.push_back(std::move(dummy));
				}
				return std::move(result);
			}

			//	inline void OpenGL::bindFragDataLocation(unsigned int /*program*/, unsigned int /*colorNumber*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline int OpenGL::getFragDataLocation(unsigned int /*program*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isShader(unsigned int /*shader*/) { static_assert(false, "Not implemented yet."); }

			inline int OpenGL::getShaderiv(const Handle shader, const ShaderParameter pname)
            {
				int result;
				checkErrors(glGetShaderiv(static_cast<GLuint>(shader), static_cast<GLenum>(pname), &result));
				return std::move(result);
            }

			inline std::vector<Handle> OpenGL::getAttachedShaders(const Handle program)
			{
				std::vector<Handle> result;
				GLsizei size;

				std::array<GLuint, 6> shaders;
				checkErrors(glGetAttachedShaders(static_cast<GLuint>(program), 6, &size, shaders.data()));
				for (unsigned int i = 0; i < static_cast<unsigned int>(size); ++i) {
					result.push_back(std::move(static_cast<Handle>(shaders[i])));
				}

				return std::move(result);
			}

			inline std::string OpenGL::getShaderInfoLog(const Handle shader)
            {
                GLsizei size;
                char infoLog[512];
                checkErrors(glGetShaderInfoLog(static_cast<GLuint>(shader), 512, &size, static_cast<GLchar *>(infoLog)));
                return std::string(infoLog);
            }

            //	inline void OpenGL::getShaderSource(unsigned int /*shader*/, GLsizei /*bufSize*/, GLsizei * /*length*/, char * /*source*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribdv(unsigned int /*index*/, GLenum /*pname*/, double * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribfv(unsigned int /*index*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribiv(unsigned int /*index*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribIiv(unsigned int /*index*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribIuiv(unsigned int /*index*/, GLenum /*pname*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribPointerv(unsigned int /*index*/, GLenum /*pname*/, void ** /*pointer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getUniformfv(unsigned int /*program*/, int /*location*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getUniformiv(unsigned int /*program*/, int /*location*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getUniformuiv(unsigned int /*program*/, int /*location*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isProgram(unsigned int /*program*/) { static_assert(false, "Not implemented yet."); }

            inline std::string OpenGL::getProgramInfoLog(const Handle program)
            {
                GLsizei size;
                char infoLog[512];
                checkErrors(glGetProgramInfoLog(static_cast<GLuint>(program), 512, &size, static_cast<GLchar *>(infoLog)));
                return std::string(infoLog);
            }
			//	inline void OpenGL::getMultisamplefv(GLenum /*pname*/, unsigned int /*index*/, float * /*val*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::pointSize(const float size) { checkErrors(glPointSize(size)) }

			//	inline void OpenGL::pointParameterf(GLenum /*pname*/, float /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pointParameteri(GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pointParameterfv(GLenum /*pname*/, const float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pointParameteriv(GLenum /*pname*/, const int * /*params*/) { static_assert(false, "Not implemented yet."); }
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

			//	inline void OpenGL::polygonOffset(float /*factor*/, float /*units*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pixelStoref(GLenum /*pname*/, float /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pixelStorei(GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::activeTexture(const unsigned int texture)
			{
				if (static_cast<int>(texture) >= OpenGL::getInteger(Parameter::MAX_COMBINED_TEXTURE_IMAGE_UNITS)[0]) {
					throw std::runtime_error("This texture unit is not available ont this platform.");
				}
				checkErrors(glActiveTexture(static_cast<GLenum>(TextureUnit::TEXTURE0) + texture));
			}

			//	inline void OpenGL::texImage3D(GLenum /*target*/, int /*level*/, int /*internalFormat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, int /*border*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::texImage2D(const TextureTypeTarget target, const unsigned int level, const PixelInternalFormat internalFormat, const std::size_t width, const std::size_t height, const PixelFormat format, const PixelDataType type, const void * data)
			{
				auto levelSec = (target == TextureTypeTarget::TEXTURE_RECTANGLE || target == TextureTypeTarget::PROXY_TEXTURE_RECTANGLE) ? 0 : level;
				checkErrors(glTexImage2D(static_cast<GLenum>(target), levelSec, static_cast<unsigned int>(internalFormat), static_cast<GLsizei>(width), static_cast<GLsizei>(height), 0, static_cast<GLenum>(format), static_cast<GLenum>(type), data));
			}

			//	inline void OpenGL::texImage1D(GLenum /*target*/, int /*level*/, int /*internalFormat*/, GLsizei /*width*/, int /*border*/, GLenum /*format*/, GLenum /*type*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTexImage2D(GLenum /*target*/, int /*level*/, GLenum /*internalformat*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/, int /*border*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTexImage1D(GLenum /*target*/, int /*level*/, GLenum /*internalformat*/, int /*x*/, int /*y*/, GLsizei /*width*/, int /*border*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texSubImage3D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texSubImage2D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texSubImage1D(GLenum /*target*/, int /*level*/, int /*xoffset*/, GLsizei /*width*/, GLenum /*format*/, GLenum /*type*/, const void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTexSubImage3D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTexSubImage2D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::copyTexSubImage1D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*x*/, int /*y*/, GLsizei /*width*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexImage3D(GLenum /*target*/, int /*level*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, int /*border*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexImage2D(GLenum /*target*/, int /*level*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, int /*border*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexImage1D(GLenum /*target*/, int /*level*/, GLenum /*internalformat*/, GLsizei /*width*/, int /*border*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexSubImage3D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, int /*zoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexSubImage2D(GLenum /*target*/, int /*level*/, int /*xoffset*/, int /*yoffset*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::compressedTexSubImage1D(GLenum /*target*/, int /*level*/, int /*xoffset*/, GLsizei /*width*/, GLenum /*format*/, GLsizei /*imageSize*/, const void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texImage3DMultisample(GLenum /*target*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, GLsizei /*depth*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texImage2DMultisample(GLenum /*target*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/, bool /*fixedsamplelocations*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texBuffer(GLenum /*target*/, GLenum /*internalFormat*/, unsigned int /*buffer*/) { static_assert(false, "Not implemented yet."); }

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

			template <> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<float> & param)
			{
				checkErrors(glTexParameterfv(static_cast<GLenum>(target), static_cast<GLenum>(pname), param.data()));
			}

			template <> inline void OpenGL::texParameter(const TextureTarget target, const TextureParameter pname, const std::vector<int> & param)
			{
				checkErrors(glTexParameteriv(static_cast<GLenum>(target), static_cast<GLenum>(pname), param.data()));
			}

			//	inline void OpenGL::texParameterIiv(GLenum /*target*/, GLenum /*pname*/, const int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::texParameterIuiv(GLenum /*target*/, GLenum /*pname*/, const unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::generateMipmap(const MipmapTarget target)
			{
				checkErrors(glGenerateMipmap(static_cast<GLenum>(target)));
			}

			inline void OpenGL::bindTexture(const TextureTarget target, const Handle texture)
			{
				checkErrors(glBindTexture(static_cast<GLenum>(target), texture));
			}

			//	inline void OpenGL::deleteTextures(GLsizei /*n*/, const unsigned int * /*textures*/) { static_assert(false, "Not implemented yet."); }

			inline Handle OpenGL::genTexture()
			{
				Handle handle;
				checkErrors(glGenTextures(1, &handle));
				return handle;
			}

			inline std::vector<Handle> OpenGL::genTextures(const unsigned int n)
			{
				std::vector<Handle> handles;
				if (n != 0) {
					handles.resize(handles.size() + n);
					checkErrors(glGenTextures(n, &handles.back() - n + 1));
				}
				return handles;
			}

			//	inline void OpenGL::getTexParameterfv(GLenum /*target*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexParameteriv(GLenum /*target*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexParameterIiv(GLenum /*target*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexParameterIuiv(GLenum /*target*/, GLenum /*pname*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexLevelParameterfv(GLenum /*target*/, int /*level*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexLevelParameteriv(GLenum /*target*/, int /*level*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getTexImage(GLenum /*target*/, int /*level*/, GLenum /*format*/, GLenum /*type*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getCompressedTexImage(GLenum /*target*/, int /*level*/, void * /*pixels*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isTexture(unsigned int /*texture*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::hint(GLenum /*target*/, GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::readPixels(int /*x*/, int /*y*/, GLsizei /*width*/, GLsizei /*height*/, GLenum /*format*/, GLenum /*type*/, void * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::readBuffer(GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blitFramebuffer(int /*srcX0*/, int /*srcY0*/, int /*srcX1*/, int /*srcY1*/, int /*dstX0*/, int /*dstY0*/, int /*dstX1*/, int /*dstY1*/, GLbitfield /*mask*/, GLenum /*filter*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::scissor(const int x, const int y, const unsigned int width, const unsigned int height)
			{
				checkErrors(glScissor(x, y, static_cast<GLsizei>(width), static_cast<GLsizei>(height)));
			}

			//	inline void OpenGL::sampleCoverage(float /*value*/, bool /*invert*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::sampleMaski(unsigned int /*maskNumber*/, GLbitfield /*mask*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilFunc(GLenum /*func*/, int /*ref*/, unsigned int /*mask*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilFuncSeparate(GLenum /*face*/, GLenum /*func*/, int /*ref*/, unsigned int /*mask*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilOp(GLenum /*sfail*/, GLenum /*dpfail*/, GLenum /*dppass*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilOpSeparate(GLenum /*face*/, GLenum /*sfail*/, GLenum /*dpfail*/, GLenum /*dppass*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::depthFunc(const DepthFunctionCondition condition)
			{
				checkErrors(glDepthFunc(static_cast<GLenum>(condition)));
			}

			//	inline void OpenGL::blendEquation(GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendEquationSeparate(GLenum /*modeRGB*/, GLenum /*modeAlpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendFuncSeparate(GLenum /*srcRGB*/, GLenum /*dstRGB*/, GLenum /*srcAlpha*/, GLenum /*dstAlpha*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::blendFunc(const BlendingFactor sfactor, const BlendingFactor dfactor)
			{
				checkErrors(glBlendFunc(static_cast<GLenum>(sfactor), static_cast<GLenum>(dfactor)));
			}

			//	inline void OpenGL::blendColor(float /*red*/, float /*green*/, float /*blue*/, float /*alpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::logicOp(GLenum /*opcode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawBuffer(GLenum /*buf*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawBuffers(GLsizei /*n*/, const GLenum * /*bufs*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::colorMask(bool /*red*/, bool /*green*/, bool /*blue*/, bool /*alpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::colorMaski(unsigned int /*buf*/, bool /*red*/, bool /*green*/, bool /*blue*/, bool /*alpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::depthMask(bool /*flag*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilMask(unsigned int /*mask*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::stencilMaskSeparate(GLenum /*face*/, unsigned int /*mask*/) { static_assert(false, "Not implemented yet."); }

			inline void OpenGL::clear(const Bitfield mask)
			{
				checkErrors(glClear(GLbitfield(mask)));
			}

			inline void OpenGL::clearColor(const float r, const float g, const float b, const float a)
			{
				checkErrors(glClearColor(r, g, b, a));
			}

			//	inline void OpenGL::clearDepth(double /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearStencil(int /*s*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearBufferiv(GLenum /*buffer*/, int /*drawbuffer*/, const int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearBufferuiv(GLenum /*buffer*/, int /*drawbuffer*/, const unsigned int * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearBufferfv(GLenum /*buffer*/, int /*drawbuffer*/, const float * /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearBufferfi(GLenum /*buffer*/, int /*drawbuffer*/, float /*depth*/, int /*stencil*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindFramebuffer(GLenum /*target*/, unsigned int /*framebuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteFramebuffers(GLsizei /*n*/, unsigned int * /*framebuffers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genFramebuffers(GLsizei /*n*/, unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindRenderbuffer(GLenum /*target*/, unsigned int /*renderbuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteRenderbuffers(GLsizei /*n*/, unsigned int * /*renderbuffers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genRenderbuffers(GLsizei /*n*/, unsigned int * /*renderbuffers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::renderbufferStorageMultisample(GLenum /*target*/, GLsizei /*samples*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::renderbufferStorage(GLenum /*target*/, GLenum /*internalformat*/, GLsizei /*width*/, GLsizei /*height*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferRenderbuffer(GLenum /*target*/, GLenum /*attachment*/, GLenum /*renderbuffertarget*/, unsigned int /*renderbuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferTexture(GLenum /*target*/, GLenum /*attachment*/, unsigned int /*texture*/, int /*level*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferTexture1D(GLenum /*target*/, GLenum /*attachment*/, GLenum /*textarget*/, unsigned int /*texture*/, int /*level*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferTexture2D(GLenum /*target*/, GLenum /*attachment*/, GLenum /*textarget*/, unsigned int /*texture*/, int /*level*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferTexture3D(GLenum /*target*/, GLenum /*attachment*/, GLenum /*textarget*/, unsigned int /*texture*/, int /*level*/, int /*layer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::framebufferTextureLayer(GLenum /*target*/, GLenum /*attachment*/, unsigned int /*texture*/, int /*level*/, int /*layer*/) { static_assert(false, "Not implemented yet."); }
			//	inline GLenum OpenGL::checkFramebufferStatus(GLenum /*target*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isFramebuffer(unsigned int /*framebuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getFramebufferAttachmentParameteriv(GLenum /*target*/, GLenum /*attachment*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isRenderbuffer(unsigned int /*renderbuffer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getRenderbufferParameteriv(GLenum /*target*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::flush() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::finish() { static_assert(false, "Not implemented yet."); }
			//	inline GLsync OpenGL::fenceSync(GLenum /*condition*/, GLbitfield /*flags*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteSync(GLsync /*sync*/) { static_assert(false, "Not implemented yet."); }
			//	inline GLenum OpenGL::clientWaitSync(GLsync /*sync*/, GLbitfield /*flags*/, GLuint64 /*timeout*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::waitSync(GLsync /*sync*/, GLbitfield /*flags*/, GLuint64 /*timeout*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getSynciv(GLsync /*sync*/, GLenum /*pname*/, GLsizei /*bufSize*/, GLsizei * /*length*/, int * /*values*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isSync(GLsync /*sync*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBooleanv(GLenum /*pname*/, bool * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getDoublev(GLenum /*pname*/, double * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getFloatv(GLenum /*pname*/, float * /*data*/) { static_assert(false, "Not implemented yet."); }

			inline std::vector<int> OpenGL::getInteger(const Parameter parameter)
			{
				std::vector<int> tmp = { static_cast<int>(parameter) };
				checkErrors(glGetIntegerv(static_cast<GLenum>(parameter), tmp.data()));
				return tmp;
			}

			//	inline void OpenGL::getInteger64v(GLenum /*pname*/, GLint64 * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getBooleani_v(GLenum /*target*/, unsigned int /*index*/, bool * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getIntegeri_v(GLenum /*target*/, unsigned int /*index*/, int * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getInteger64i_v(GLenum /*target*/, unsigned int /*index*/, GLint64 * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isEnabled(GLenum /*cap*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isEnabledi(GLenum /*cap*/, unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }

			inline std::string OpenGL::getString(const InfoGL parameter)
			{
				const GLubyte * tmp = checkErrors(glGetString(static_cast<GLenum>(parameter)));
				return std::string(reinterpret_cast<const char *>(tmp));
			}

			//	inline const GLubyte * OpenGL::getStringi(GLenum /*name*/, unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::queryCounter(unsigned int /*id*/, GLenum /*target*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genSamplers(GLsizei /*n*/, unsigned int * /*samplers*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindSampler(unsigned int /*unit*/, unsigned int /*sampler*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameterf(unsigned int /*sampler*/, GLenum /*pname*/, float /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameteri(unsigned int /*sampler*/, GLenum /*pname*/, int /*param*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameterfv(unsigned int /*sampler*/, GLenum /*pname*/, const float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameteriv(unsigned int /*sampler*/, GLenum /*pname*/, const int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameterIiv(unsigned int /*sampler*/, GLenum /*pname*/, const int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::samplerParameterIuiv(unsigned int /*sampler*/, GLenum /*pname*/, const unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteSamplers(GLsizei /*n*/, const unsigned int * /*samplers*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isSampler(unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getSamplerParameterfv(unsigned int /*sampler*/, GLenum /*pname*/, float * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getSamplerParameteriv(unsigned int /*sampler*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getSamplerParameterIiv(unsigned int /*sampler*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getSamplerParameterIuiv(unsigned int /*sampler*/, GLenum /*pname*/, unsigned int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindFragDataLocationIndexed(unsigned int /*program*/, unsigned int /*colorNumber*/, unsigned int /*index*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline int OpenGL::getFragDataIndex(unsigned int /*program*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//
				inline void OpenGL::vertexAttribDivisor(const int index, const std::size_t divisor) { checkErrors(glVertexAttribDivisor(static_cast<GLuint>(index), static_cast<GLuint>(divisor))); }
			//
			//	inline void OpenGL::getUniformdv(unsigned int /*program*/, int /*location*/, double * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendEquationi(unsigned int /*buf*/, GLenum /*mode*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendEquationSeparatei(unsigned int /*buf*/, GLenum /*modeRGB*/, GLenum /*modeAlpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendFuncSeparatei(unsigned int /*buf*/, GLenum /*srcRGB*/, GLenum /*dstRGB*/, GLenum /*srcAlpha*/, GLenum /*dstAlpha*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::blendFunci(unsigned int /*buf*/, GLenum /*sfactor*/, GLenum /*dfactor*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawElementsIndirect(GLenum /*mode*/, GLenum /*type*/, const void * /*indirect*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::beginQueryIndexed(GLenum /*target*/, unsigned int /*index*/, unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::endQueryIndexed(GLenum /*target*/, unsigned int /*index*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getQueryIndexediv(GLenum /*target*/, unsigned int /*index*/, GLenum /*pname*/, int * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline int getSubroutineUniformLocation(unsigned int /*program*/, GLenum /*shadertype*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline unsigned int OpenGL::getSubroutineIndex(unsigned int /*program*/, GLenum /*shadertype*/, const char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveSubroutineName(unsigned int /*program*/, GLenum /*shadertype*/, unsigned int /*index*/, GLsizei /*bufsize*/, GLsizei * /*length*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveSubroutineUniformName(unsigned int /*program*/, GLenum /*shadertype*/, unsigned int /*index*/, GLsizei /*bufsize*/, GLsizei * /*length*/, char * /*name*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getActiveSubroutineUniformiv(unsigned int /*program*/, GLenum /*shadertype*/, unsigned int /*index*/, GLenum /*pname*/, int * /*values*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::uniformSubroutinesuiv(GLenum /*shadertype*/, GLsizei /*count*/, const unsigned int * /*indices*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getUniformSubroutineuiv(GLenum /*shadertype*/, int /*location*/, unsigned int * /*values*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getProgramStageiv(unsigned int /*program*/, GLenum /*shadertype*/, GLenum /*pname*/, int * /*values*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::patchParameteri(GLenum /*pname*/, int /*value*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::patchParameterfv(GLenum /*pname*/, const float * /*values*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawArraysIndirect(GLenum /*mode*/, const void * /*indirect*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::genTransformFeedbacks(GLsizei /*n*/, unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::deleteTransformFeedbacks(GLsizei /*n*/, const unsigned int * /*ids*/) { static_assert(false, "Not implemented yet."); }
			//	inline bool OpenGL::isTransformFeedback(unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::bindTransformFeedback(GLenum /*target*/, unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pauseTransformFeedback() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::resumeTransformFeedback() { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawTransformFeedback(GLenum /*mode*/, unsigned int /*id*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::drawTransformFeedbackStream(GLenum /*mode*/, unsigned int /*id*/, unsigned int /*stream*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::minSampleShading(float /*value*/) { static_assert(false, "Not implemented yet."); }
			//
			//	inline void OpenGL::vertexAttribL1d(unsigned int /*index*/, double /*v0*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL2d(unsigned int /*index*/, double /*v0*/, double /*v1*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL3d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL4d(unsigned int /*index*/, double /*v0*/, double /*v1*/, double /*v2*/, double /*v3*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL1dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL2dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL3dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribL4dv(unsigned int /*index*/, const double * /*v*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::vertexAttribLPointer(unsigned int /*index*/, int /*size*/, GLenum /*type*/, GLsizei /*stride*/, const void * /*pointer*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::depthRangef(float /*nearVal*/, float /*farVal*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getVertexAttribLdv(unsigned int /*index*/, GLenum /*pname*/, double * /*params*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::clearDepthf(float /*depth*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getFloati_v(GLenum /*target*/, unsigned int /*index*/, float * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::getDoublei_v(GLenum /*target*/, unsigned int /*index*/, double * /*data*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::shaderBinary(GLsizei /*count*/, const unsigned int * /*shaders*/, GLenum /*binaryFormat*/, const void * /*binary*/, GLsizei /*length*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::releaseShaderCompiler() { static_assert(false, "Not implemented yet."); }
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
			//	inline void OpenGL::debugMessageCallback(GLDEBUGPROC /*callback*/, const void * /*userParam*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::debugMessageControl(GLenum /*source*/, GLenum /*type*/, GLenum /*severity*/, GLsizei /*count*/, const unsigned int * /*ids*/, bool /*enabled*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::debugMessageInsert(GLenum /*source*/, GLenum /*type*/, unsigned int /*id*/, GLenum /*severity*/, GLsizei /*length*/, const char * /*message*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::pushDebugGroup(GLenum /*source*/, unsigned int /*id*/, GLsizei /*length*/, const char * /*message*/) { static_assert(false, "Not implemented yet."); }
			//	inline void OpenGL::popDebugGroup() { static_assert(false, "Not implemented yet."); }
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
			//	inline void OpenGL::textureBarrier() { static_assert(false, "Not implemented yet."); }
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
