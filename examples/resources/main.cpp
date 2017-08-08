#include <iostream>
#include <cmath>
#include <ctime>

#include "log\service_logger.hpp"
#include "log\logger.hpp"
#include "resource\resource_manager.hpp"

class IntResource : public ece::Resource
{
public:
	IntResource() : Resource(), value(rand()%10) {}

	int getValue() const { return this->value; }

private:
	int value;
};

class IntLoader : public ece::ResourceLoader
{
public:
	virtual ece::ResourceHandler load(const std::string & identifier) const override
	{
		return ece::ResourceHandler(std::make_shared<IntResource>());
	}
};

class IntUnloader : public ece::ResourceUnloader
{
public:
	virtual void unload(ece::ResourceHandler & handler) const override
	{
		(*handler).reset();
	}
};

int main()
{
	ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
	srand(static_cast<unsigned int>(time(nullptr)));

	ece::ResourceManager manager;

	manager.registerLoader("int", std::make_shared<IntLoader>());
	manager.registerUnloader("int", std::make_shared<IntUnloader>());

	manager.loadResource("random.int");
	auto & resource1 = manager.getResource("random.int");
	
	auto & resourceUnbind = std::static_pointer_cast<IntResource>(resource1.lock());
	std::cout << "Resource is: " << resourceUnbind->getValue() << std::endl;

	manager.unloadResource("random.int");
	manager.clear();

	manager.loadResource("random.int");

	return EXIT_SUCCESS;
}