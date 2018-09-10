#include <iostream>
#include <ctime>

#include "core/application.hpp"
#include "renderer/rendering.hpp"
#include "window/event.hpp"
#include "graphic/scene.hpp"
#include "graphic/renderable/particles_emitter.hpp"
#include "utility/time.hpp"
#include "core/resource/make_resource.hpp"
#include "utility/log.hpp"
#include "window/common.hpp"

namespace ece
{
	using graphic::renderable::ParticlesEmitter;
	using core::resource::makeResource;
}

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::Application app;

		ece::RenderWindow window;

		window.open();
		window.maximize();
		window.updateVideoMode();

		ece::WindowSetting settings;
		settings._position = ece::IntVector2u{ 10, 10 };
		settings._title = "Test";
		window.setSettings(settings);

		ece::Viewport viewport;
		viewport.resetViewport(ece::Rectangle<float>(0.0f, 0.0f, 1920.0f, 1080.0f));
		window.setViewport(viewport);

		ece::Scene scene;

		auto & camera = scene.getCamera();
		camera.setPerspective(45, /*window.getSize()[0] / window.getSize()[1]*/1920.0f / 1080.0f, 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
		scene.updateCamera();

		auto emitter = ece::makeResource<ece::ParticlesEmitter>("ParticlesEmitter", 500);
		scene.addObject(emitter);

		scene.prepare();
		ece::InputEvent event;
		ece::Chrono chrono;
		chrono.start();
		while (window.isOpened()) {
			window.clear(ece::BLACK);
			if (chrono.getElapsedTime() > 100) {
				emitter->update(chrono.reset() / 1000.0f);
			}
			scene.draw();
			window.display();

			if (window.pollEvent(event)) {

			}
		}
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return EXIT_SUCCESS;
}