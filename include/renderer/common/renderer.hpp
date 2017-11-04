#ifndef RENDERER_HPP
#define RENDERER_HPP

namespace ece
{
	class Renderer
	{
	public:
		Renderer() = default;
		Renderer(const Renderer & copy) = default;
		Renderer(Renderer && move) = default;

		~Renderer() = default;

		Renderer & operator=(const Renderer & copy) = default;
		Renderer & operator=(Renderer && move) = default;

	private:

	};
}

#endif // RENDERER_HPP
