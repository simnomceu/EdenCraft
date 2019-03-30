/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.
															`888   `Y88.
															 888   .d88'  .ooooo.   .oooo.o  .ooooo.  oooo  oooo  oooo d8b  .ooooo.   .ooooo.   .oooo.o
															 888ooo88P'  d88' `88b d88(  "8 d88' `88b `888  `888  `888""8P d88' `"Y8 d88' `88b d88(  "8
															 888`88b.    888ooo888 `"Y88b.  888   888  888   888   888     888       888ooo888 `"Y88b.
															 888  `88b.  888    .o o.  )88b 888   888  888   888   888     888   .o8 888    .o o.  )88b
															o888o  o888o `Y8bod8P' 8""888P' `Y8bod8P'  `V88V"V8P' d888b    `Y8bod8P' `Y8bod8P' 8""888P'



				This file is part of EdenCraft Engine - Resources sample.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "utility/log.hpp"
#include "core/resource.hpp"

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
	virtual ece::ResourceHandler load(const std::string & /*identifier*/) const override
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
	auto resource1 = manager.getResource("random.int");

	auto resourceUnbind = std::static_pointer_cast<IntResource>(resource1.lock());
	ece::INFO << "Resource is: " << resourceUnbind->getValue() << flush;
	ece::ServiceLoggerLocator::getService().logInfo("Resource is: " + std::to_string(resourceUnbind->getValue()));

	manager.unloadResource("random.int");
	manager.clear();

	manager.loadResource("random.int");

	return EXIT_SUCCESS;
}
