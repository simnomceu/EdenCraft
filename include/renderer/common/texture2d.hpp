#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	/**
	 * @class Texture2D
	 * @brief OpenGL 2D texture.
	 */
	class Texture2D
	{
	public:
		/**
		 * @fn Texture2D() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		inline Texture2D() noexcept;

		/**
		 * @fn Texture2D(const Texture2D & copy)
		 * @param[in] copy The texture to copy from.
		 * @brief Default copy constructor.
		 * throw
		 */
		inline Texture2D(const Texture2D & copy);

		/**
		 * @fn Texture2D(Texture2D && move) noexcept
		 * @param[in] move The texture to move.
		 * @brief Default move constructor.
		 * throw noexcept
		 */
		inline Texture2D(Texture2D && move) noexcept;

		/**
		 * @fn ~Texture2D() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Texture2D() noexcept = default;

		/**
		 * @fn Texture2D & operator=(const Texture2D & copy)
		 * @param[in] copy The texture to copy from.
		 * @return The texture copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Texture2D & operator=(const Texture2D & copy);

		/**
		 * @fn Texture2D & operator=(Texture2D && move) noexcept
		 * @param[in] move The texture to move.
		 * @return The texture moved.
		 * @bried Default move assignment operator.
		 * @throw noexcept
		 */
		Texture2D & operator=(Texture2D && move) noexcept;

		void loadFromFile(const TextureTypeTarget type, const std::string & filename);

		inline const std::string & getFilename() const;
		inline const std::vector<std::byte> & getData() const;
		inline unsigned int getWidth() const;
		inline unsigned int getHeight() const;
		inline TextureTypeTarget getType() const;
		inline Handle getHandle() const;

		inline void bind(const TextureTarget target);
		void update();
		void terminate();

	private:
		/**
		 * @property _filename
		 * @brief 
		 */
		std::string _filename;

		/**
		 * @property _data
		 * @brief The pixels of the texture.
		 */
		std::vector<std::byte> _data;

		/**
		 * @property _width
		 * @brief The width of the texture.
		 */
		unsigned int _width;

		/**
		 * @property _height
		 * @brief The height of the texture.
		 */
		unsigned int _height;

		/**
		 * @property _type
		 * @brief Type of texture used.
		 */
		TextureTypeTarget _type;

		/**
		 * @property _handle
		 * @brief The texture handle to use for any OpenGL call.
		 */
		Handle _handle;
	};
}

#include "renderer/common/texture2d.inl"

#endif // TEXTURE_HPP