#include "Application.hpp"

#include <iostream>
#include <thread>
#include <ctime>
#include <utility>

#include "Office.hpp"
#include "ComponentUser.hpp"
#include "SharedElement.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "ResourceManager.hpp"
#include "EntityUser.hpp"
#include "ResourceUser.hpp"
#include "RenderUser.hpp"
#include "Philosopher.hpp"

using namespace sf;
using namespace core;
using namespace core::com;
using namespace core::cmp;
using namespace core::cmn;
using namespace core::ent;
using namespace core::rsc;
using namespace core::eng;
using namespace core::st;

std::shared_ptr<ResourceManager> Philosopher<ResourceManager>::fork = nullptr;
std::shared_ptr<std::mutex> Philosopher<ResourceManager>::lockFork = nullptr;

template<class T> using Element = std::pair<std::string, std::shared_ptr<SharedElement<T>>>;

Application::Application() : Limiter(60), fsm(nullptr), engines(), running(true), window(), waitingEvents(new std::queue<app::def::Event>()), 
							lockEvents(new std::mutex), elements(), engineFactory()
{
	this->elements.insert(Element<Office>("office", std::make_shared<SharedElement<Office>>(std::make_shared<Office>(Office()))));
	Communicable::setOffice(std::static_pointer_cast<SharedElement<Office>>(this->elements["office"])->get(), 
							std::static_pointer_cast<SharedElement<Office>>(this->elements["office"])->getLock());

	this->elements.insert(Element<ComponentManager>("cm", std::make_shared<SharedElement<ComponentManager>>(std::make_shared<ComponentManager>(ComponentManager()))));
	ComponentUser::setComponentManager(std::static_pointer_cast<SharedElement<ComponentManager>>(this->elements["cm"])->get(),
									   std::static_pointer_cast<SharedElement<ComponentManager>>(this->elements["cm"])->getLock());


	this->elements.insert(Element<EntityManager>("em", std::make_shared<SharedElement<EntityManager>>(std::make_shared<EntityManager>(EntityManager()))));
	EntityUser::setEntityManager(std::static_pointer_cast<SharedElement<EntityManager>>(this->elements["em"])->get(),
								 std::static_pointer_cast<SharedElement<EntityManager>>(this->elements["em"])->getLock());


	this->elements.insert(Element<ResourceManager>("rm", std::make_shared<SharedElement<ResourceManager>>(std::make_shared<ResourceManager>(ResourceManager()))));
	ResourceUser::setResourceManager(std::static_pointer_cast<SharedElement<ResourceManager>>(this->elements["rm"])->get(),
									   std::static_pointer_cast<SharedElement<ResourceManager>>(this->elements["rm"])->getLock());
	Philosopher<ResourceManager>::setFork(std::static_pointer_cast<SharedElement<ResourceManager>>(this->elements["rm"])->get(),
											std::static_pointer_cast<SharedElement<ResourceManager>>(this->elements["rm"])->getLock());


	this->elements.insert(Element<sf::RenderTexture>("render", std::make_shared<SharedElement<sf::RenderTexture>>(std::shared_ptr<sf::RenderTexture>(new sf::RenderTexture()))));
	RenderUser::setRender(std::static_pointer_cast<SharedElement<sf::RenderTexture>>(this->elements["render"])->get(),
		std::static_pointer_cast<SharedElement<sf::RenderTexture>>(this->elements["render"])->getLock());

	this->fsm = std::shared_ptr<FiniteStateMachine>(new FiniteStateMachine());

	this->window.create(VideoMode(800, 600), "My window");
}

Application::~Application()
{
}

void Application::initialize()
{
	std::cout << "Initializing application ..." << std::endl;
	// TODO initialize application and memory loading : load types of component
	this->loadEngineType();
	this->loadSystemType();
	this->loadComponentType();

	this->loadEngines();

	for (auto it : this->engines) {
		it.second->initialize();
	}
}

void Application::run()
{
	std::cout << "Running application ..." << std::endl;
	std::vector<std::thread> engineThreads;
	for (auto it : this->engines) {
		engineThreads.push_back(std::thread(&Engine::run, it.second));
	}

	while (this->fsm->getCurrentState() != "stop") {
		this->begin();

		if (this->window.isOpen()) {
			sf::Event event;
			while (this->window.pollEvent(event))
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
				if (event.type == sf::Event::Closed) {
					this->window.close();
				}
				else if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Escape) {
						this->window.close();
					}
				}
			}
		}

		this->elements["em"]->lock();
		auto em = std::static_pointer_cast<SharedElement<EntityManager>>(this->elements["em"])->get();
		em->processMessages();
		this->elements["em"]->unlock();

		this->fsm->processMessages();

		this->wait();

		this->elements["render"]->lock();
		this->window.clear();
		auto render = std::static_pointer_cast<SharedElement<sf::RenderTexture>>(this->elements["render"])->get();
		this->window.draw(sf::Sprite(render->getTexture()));
		this->window.display();
		this->elements["render"]->unlock();
	}

	// synchronisation before closing application
	for (unsigned short int i = 0; i < engineThreads.size(); i++) {
		engineThreads[i].join();
	}
}
