#ifndef VBO_HPP
#define VBO_HPP

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	class VBO
	{
	public:
		VBO(const BufferType type);
		VBO();
		VBO(const VBO & copy) = default;
		VBO(VBO && move) = default;

		~VBO() = default;

		VBO & operator=(const VBO & copy) = default;
		VBO & operator=(VBO && move) = default;

		void bind();
		template<class T> void bufferData(const std::vector<T> & data, const BufferUsage usage);

		inline void setType(const BufferType type);
		inline Handle getHandle() const;

	private:
		Handle _handle;
		BufferType _type;
	};
}

#include "renderer/opengl/vbo.inl"

#endif // VBO_HPP
