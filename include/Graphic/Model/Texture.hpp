#ifndef TEXTURE_HPP
#define TEXTURE_HPP

namespace ece
{
	class Texture
	{
	public:
		Texture() = default;
		Texture(const Texture & copy) = default;
		Texture(Texture && move) = default;

		~Texture() = default;

		Texture & operator=(const Texture & copy) = default;
		Texture & operator=(Texture && move) = default;
	};
}

#endif // TEXTURE_HPP