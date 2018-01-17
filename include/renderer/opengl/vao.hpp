#ifndef VAO_HPP
#define VAO_HPP

#include "renderer/opengl/vbo.hpp"

namespace ece
{
	class VAO
	{
	public:
		VAO();
		VAO(const VAO & copy) = default;
		VAO(VAO && move) = default;

		~VAO() = default;

		VAO & operator=(const VAO & copy) = default;
		VAO & operator=(VAO && move) = default;

		void bind() const;
		template<class T> void addAttribute(const int location, const int size, const bool normalized, const int offset, 
							const BufferType type, const std::vector<T> & data, const BufferUsage usage);
		template<class T> void addAttributeWithoutBuffer(const int location, const int size, const bool normalized, const int offset,
			const BufferType type, std::vector<T> & data, const BufferUsage usage);

	private:
		VAOHandle _handle;
	};
}

#include "renderer/opengl/vao.inl"

#endif // VAO_HPP
