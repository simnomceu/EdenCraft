#include "libpng/extlibs/libpng.hpp"
#include "libpng/config.hpp"

namespace ece
{
	namespace loader
	{
		class ECE_LIBPNG_API LoaderPNG : public Loader, public Saver
		{
		public:
			/**
			 * @fn LoaderPNG() noexcept
			 * @brief Default constructor.
			 * @throw noexcept
			 */
			LoaderPNG() noexcept = default;

			/**
			 * @fn LoaderPNG(const LoaderPNG & copy) noexcept
			 * @param[in] copy The LoaderPNG to copy from.
			 * @brief Default copy constructor.
			 * @throw noexcept
			 */
			LoaderPNG(const LoaderPNG & copy) noexcept = default;

			/**
			 * @fn LoaderPNG(LoaderPNG && move) noexcept
			 * @param[in] move The LoaderPNG to move.
			 * @brief Default move constructor.
			 * @throw noexcept
			 */
			LoaderPNG(LoaderPNG && move) noexcept = default;

			/**
			 * @fn ~LoaderPNG() noexcept
			 * @brief Default destructor.
			 * @throw noexcept
			 */
			~LoaderPNG() noexcept = default;

			/**
			 * @fn LoaderPNG & operator=(const LoaderPNG & copy) noexcept
			 * @param[in] copy The LoaderPNG to copy from.
			 * @return The LoaderPNG copied.
			 * @brief Default copy assignment operator.
			 * @throw noexcept
			 */
			LoaderPNG & operator=(const LoaderPNG & copy) noexcept = default;

			/**
			 * @fn LoaderPNG & operator=(LoaderPNG && move) noexcept
			 * @param[in] move The LoaderPNG to move.
			 * @return The LoaderPNG moved.
			 * @brief Default move assignment operator.
			 * @throw noexcept
			 */
			LoaderPNG & operator=(LoaderPNG && move) noexcept = default;

			/**
			 * @fn void loadFromFile(const std::filesystem::path & filename)
			 * @param[in] filename The name of the file to load data from.
			 * @brief Load and parse data from a file.
			 * @throw
			 */
			virtual std::vector<ResourceHandler> load(StreamInfoIn info) override;

			/**
			 * @fn void saveToFile(const std::filesystem::path & filename)
			 * @param[out] filename The name of the file to save into.
			 * @brief Formate and save data into a file.
			 * @throw
			 */
			virtual void save(StreamInfoOut info) override;

			virtual auto isBinary() const noexcept -> bool override { return true; }
		};
	} // namespace loader
} // namespace ece