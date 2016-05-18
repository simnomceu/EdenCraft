#include <iostream>
#include <memory>

#include "World.hpp"

class A : public ECS::Component<A> {
public: A(std::shared_ptr<ECS::Index<BaseComponent>> index): ECS::Component<A>(index) {}
};
class B: public ECS::Component<B>{};
class C: public ECS::Component<C>{};

int main()
{
	auto world = std::make_shared<ECS::World>();
	auto ent = world->createEntity();

	auto index = world->getComponentIndex();
	index->registerElement<A>();
	index->registerElement<B>();
	std::cout << index->getIndex<A>() << std::endl;
	if (index->isRegistered<B>()) {
		std::cout << index->getIndex<B>() << std::endl;
	}
	if (index->isRegistered<C>()) {
		std::cout << index->getIndex<C>() << std::endl;
	}
	std::cout << index->getIndex<C>() << std::endl;
	index->unregisterElement<B>();
	if (index->isRegistered<B>()) {
		std::cout << index->getIndex<B>() << std::endl;
	}

	auto entity = new ECS::Entity(world, 0);
	std::cout << entity->toString() << std::endl;
	auto componentA = entity->addComponent<A>();
	std::cout << entity->toString() << std::endl;
	entity->removeComponent<A>();
	std::cout << entity->toString() << std::endl;

	return EXIT_SUCCESS;
}