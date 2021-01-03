#include "libjpeg/pch.hpp"
#include "libjpeg/config.hpp"

namespace ece
{
	namespace libjpeg
	{
		namespace loader
		{
			class ECE_LIBJPEG_API LoaderJPEG : public Loader, public Saver
			{
			public:
				/**
				 * @fn LoaderJPEG() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				LoaderJPEG() noexcept = default;

				/**
				 * @fn LoaderJPEG(const LoaderJPEG & copy) noexcept
				 * @param[in] copy The LoaderJPEG to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				LoaderJPEG(const LoaderJPEG & copy) noexcept = default;

				/**
				 * @fn LoaderJPEG(LoaderJPEG && move) noexcept
				 * @param[in] move The LoaderJPEG to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				LoaderJPEG(LoaderJPEG && move) noexcept = default;

				/**
				 * @fn ~LoaderJPEG() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~LoaderJPEG() noexcept = default;

				/**
				 * @fn LoaderJPEG & operator=(const LoaderJPEG & copy) noexcept
				 * @param[in] copy The LoaderJPEG to copy from.
				 * @return The LoaderJPEG copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				LoaderJPEG & operator=(const LoaderJPEG & copy) noexcept = default;

				/**
				 * @fn LoaderJPEG & operator=(LoaderJPEG && move) noexcept
				 * @param[in] move The LoaderJPEG to move.
				 * @return The LoaderJPEG moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				LoaderJPEG & operator=(LoaderJPEG && move) noexcept = default;

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
	} // namespace libjpeg
} // namespace ece