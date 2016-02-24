#pragma once

#include <memory>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Engine.hpp"
#include "Communicable.hpp"
#include "Limiter.hpp"
#include "FiniteStateMachine.hpp"
#include "ISharedElement.hpp"
#include "AbstractEngineFactory.hpp"

#include "Event.inl"

namespace core
{
	class Application: public core::cmn::Limiter
	{
	public:
		Application();
		~Application();

		void initialize();
		void run();

	protected:
		template<class T> void registerEngine(const std::string& typeIn);
		template<class T> void addEngine(const bool activeIn, const int refreshRateIn, const std::string& idAccountIn);

		virtual void loadEngineType() = 0;
		virtual void loadSystemType() = 0;
		virtual void loadComponentType() = 0; // TODO pattern NVI ?

		virtual void loadEngines() = 0;

		std::shared_ptr<core::st::FiniteStateMachine> fsm;

		std::map<std::string, std::shared_ptr<core::eng::Engine>> engines;
		bool running;

		sf::RenderWindow window;
		std::shared_ptr<std::queue<app::def::Event>> waitingEvents;
		std::shared_ptr<std::mutex> lockEvents;

		std::unordered_map<std::string, std::shared_ptr<core::cmn::ISharedElement>> elements;

	private:
		core::eng::AbstractEngineFactory engineFactory;
	};

	template<class T>
	void Application::registerEngine(const std::string & typeIn)
	{
		this->engineFactory.registerFactory<T>(typeIn);
	}

	template<class T>
	void Application::addEngine(const bool activeIn, const int refreshRateIn, const std::string & idAccountIn)
	{
		if (this->engines.find(idAccountIn) == this->engines.end()) {
			this->engines[idAccountIn] = this->engineFactory.build<T>(activeIn, refreshRateIn, idAccountIn);
		}
		else {
			throw new std::exception("You have already created an engine with the same id.");
		}
	}
}
