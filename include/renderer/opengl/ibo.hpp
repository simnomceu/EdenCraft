#ifndef IBO_HPP
#define IBO_HPP

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	class IBO
	{
	public:
		IBO();
		IBO(const IBO & copy) noexcept = default;
		IBO(IBO && move) noexcept = default;

		IBO & operator=(const IBO & copy) noexcept = default;
		IBO & operator=(IBO && move) noexcept = default;

		inline void bind() const;
		inline void bufferData(const std::vector<unsigned int> & data, const BufferUsage usage);

		inline Handle getHandle() const;

	private:
		Handle _handle;
	};
}

#include "renderer/opengl/ibo.inl"

#endif // IBO_HPP