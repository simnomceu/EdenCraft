#ifndef VAO_HPP
#define VAO_HPP

#include "renderer/opengl/ibo.hpp"

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
		void bindIndexBuffer() const;

		template<class T> void addAttribute(const int location, const int size, const bool normalized, const int offset, 
							const BufferType type, const std::vector<T> & data, const BufferUsage usage);
		template<class T> void addAttributeWithoutBuffer(const int location, const int size, const bool normalized, const int offset,
			const BufferType type, std::vector<T> & data, const BufferUsage usage);
		void addIndices(const std::vector<unsigned int> & data, const BufferUsage usage);

		inline unsigned int getNbVertices() const;

	private:
		Handle _handle;
		unsigned int nbVertices;

		IBO _ibo;
	};
}

#include "renderer/opengl/vao.inl"

#endif // VAO_HPP
