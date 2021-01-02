#include "libjpeg/pch.hpp"
#include "libjpeg/loader/loader_jpeg.hpp"

#define TJE_IMPLEMENTATION
#include "core/resource.hpp"
#include "libjpeg/extlibs/jpeg_decoder.h"
#include "libjpeg/extlibs/tiny_jpeg.h"

namespace ece
{
	namespace libjpeg
	{
		namespace loader
		{
			std::vector<ResourceHandler> LoaderJPEG::load(StreamInfoIn info)
			{
				std::vector<unsigned char> image;

				Jpeg::Decoder decoder(image.data(), static_cast<std::size_t>(std::filesystem::file_size(info.filename)));
				auto error = decoder.GetResult();

				//if there's an error, display it
				if (error != Jpeg::Decoder::OK) {
					ERROR << "decoder error " << error << ": Could not read JPEG" << flush;
				}
				auto width = decoder.GetWidth();
				auto height = decoder.GetHeight();

				auto resourceImage = ece::Image<ece::RGBA32>();
				resourceImage.resize(width, height);
				for (auto i = 0; i < width * height * 4; i += 4) {
					resourceImage.data()[width * height - 1 - i / 4].r = image[i];
					resourceImage.data()[width * height - 1 - i / 4].g = image[i + 1];
					resourceImage.data()[width * height - 1 - i / 4].b = image[i + 2];
					resourceImage.data()[width * height - 1 - i / 4].a = image[i + 3];
				}

				return { makeResource<ece::Image<ece::RGBA32>>(info.identifier, resourceImage) };
			}

			void LoaderJPEG::save(StreamInfoOut info)
			{
				auto resourceImage = info.resources[0].get<Image<RGBA32>>();

				auto image = std::vector<unsigned char>(resourceImage->getWidth() * resourceImage->getHeight());

				for (auto i = std::size_t{ 0 }; i < resourceImage->getWidth() * resourceImage->getHeight() * 4; i += 4) {
					image[i] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].r;
					image[i + 1] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].g;
					image[i + 2] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].b;
					image[i + 3] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].a;
				}

				unsigned error = tje_encode_to_file(info.filename.data(), resourceImage->getWidth(), resourceImage->getHeight(), 4, image.data());

				//if there's an error, display it
				if (error) {
					ERROR << "encoder error " << error << ": could not write JPEG" << flush;
				}
			}
		} // namespace loader
	} // namespace libjpeg
} // namespace ece