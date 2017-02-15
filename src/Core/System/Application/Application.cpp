#include "Core\System\Application\Application.hpp"

#include "Core\Window\Window\VideoMode.hpp"

#include <iostream>

namespace ece
{
	Application::Application(): windows(), running(false)
	{
	}

	Application::~Application()
	{
		for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
			it->get()->close();
		}
		this->windows.clear();
	}

	void Application::run()
	{
		this->start();
		while (this->isRunning()) {
			this->processEvents();
			this->update();
			this->render();
		}
	}

	void Application::stop()
	{
		this->running = false;
	}

	void Application::addWindow(const WindowSetting & setting)
	{
		this->windows.push_back(std::make_unique<BaseWindow>(setting));
	}

	const bool Application::isRunning() const
	{
		return this->running;
	}

	void Application::start()
	{
		for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
			it->get()->open(VideoMode());
		}
		this->running = true;
	}
}