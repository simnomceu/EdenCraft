#include <iostream>

#include "window/common.hpp"
#include "renderer/common.hpp"
#include "core/resource.hpp"
#include "renderer/resource.hpp"

namespace ece
{
	using renderer::TextureTypeTarget;
}

int main()
{
	ece::WindowedApplication app;
	auto window = app.addWindow<ece::RenderWindow>();
	window.lock()->setContextMaximumVersion(ece::Version<2>{4, 6});

	window.lock()->onWindowClosed.connect([&app]() {
		app.stop();
	});
	window.lock()->onWindowOpened.connect([&window]() {
		window.lock()->setTitle("Bubble Volley");
		window.lock()->setFullscreen(true);

		auto blue0 = ece::makeResource<ece::Texture2D>("blue0");
		blue0->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "assets/0b.bmp");
	});

	app.run();

	return EXIT_SUCCESS;
}