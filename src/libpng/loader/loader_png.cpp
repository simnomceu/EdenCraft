#include "libpng/pch.hpp"
#include "libpng/loader/loader_png.hpp"

#include "core/resource.hpp"
#include "libpng/extlibs/libpng.hpp"

namespace ece
{
	namespace libpng
	{
		namespace loader
		{
			std::vector<ResourceHandler> LoaderPNG::load(StreamInfoIn info)
			{
				std::vector<unsigned char> image;
				unsigned width, height;
				unsigned error = lodepng::decode(image, width, height, info.filename);

				//if there's an error, display it
				if (error) {
					ERROR << "decoder error " << error << ": " << lodepng_error_text(error) << flush;
				}

				auto resourceImage = ece::Image<ece::RGBA32>();
				resourceImage.resize(width, height);
				for (auto i = std::size_t{ 0 }; i < width * height * 4; i+=4) {
					resourceImage.data()[width * height - 1 - i / 4].r = image[i];
					resourceImage.data()[width * height - 1 - i / 4].g = image[i+1];
					resourceImage.data()[width * height - 1 - i / 4].b = image[i+2];
					resourceImage.data()[width * height - 1 - i / 4].a = image[i+3];
				}

				return { makeResource<ece::Image<ece::RGBA32>>(info.identifier, resourceImage) };
			}

			void LoaderPNG::save(StreamInfoOut info)
			{
				auto resourceImage = info.resources[0].get<Image<RGBA32>>();

				auto image = std::vector<unsigned char>(resourceImage->getWidth() * resourceImage->getHeight());

				for (auto i = std::size_t{ 0 }; i < resourceImage->getWidth() * resourceImage->getHeight() * 4; i+=4) {
					image[i] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].r;
					image[i+1] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].g;
					image[i+2] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].b;
					image[i+3] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].a;
				}

				unsigned error = lodepng::encode(info.filename, image, resourceImage->getWidth(), resourceImage->getHeight());

				//if there's an error, display it
				if (error) {
					ERROR << "encoder error " << error << ": " << lodepng_error_text(error) << flush;
				}
			}
		} // namespace loader
	} // namespace libpng
} // namespace ece