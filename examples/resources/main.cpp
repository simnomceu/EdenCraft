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

#include "core/resource.hpp"
#include "core/format.hpp"
#include "core/application.hpp"

class Integer
{
public:
	Integer() : value(rand() % 10) {}

	int getValue() const { return this->value; }

private:
	int value;
};

class IntLoader : public ece::Loader, public ece::Saver
{
public:
	constexpr IntLoader() noexcept = default;
	IntLoader(const IntLoader &) noexcept = default;
	IntLoader(IntLoader &&) noexcept = default;

	~IntLoader() noexcept = default;

	IntLoader & operator=(const IntLoader &) noexcept = default;
	IntLoader & operator=(IntLoader &&) noexcept = default;

	virtual ece::ResourceHandler load(ece::StreamInfoIn info) override
	{
		return ece::makeResource<Integer>(info.identifier);
	}

	virtual void save(ece::StreamInfoOut info) override
	{
		info.resource.get<Integer>().content.reset();
	}
};


int main()
{
	try {
		auto app = ece::Application();
		srand(static_cast<unsigned int>(time(nullptr)));
	
		ece::ServiceFormatLocator().getService().registerLoader<IntLoader>("int");
		ece::ServiceFormatLocator().getService().registerSaver<IntLoader>("int");

		ece::ResourceLoader().loadFromString("random", "int", "");
		auto resource1 = ece::getResource<Integer>("random");

		ece::INFO << "Resource is: " << resource1->getValue() << ece::flush;

		auto backup = std::string();
		ece::ResourceLoader().saveToString(backup, resource1, "int");
		ece::ServiceResourceLocator::getService().clear();

		auto resource2 = ece::getResource<Integer>("random");
		ece::INFO << "Resource is: " << resource2->getValue() << ece::flush;
	}
	catch (const std::runtime_error & e) {
		ece::ERROR << e.what() << ece::flush;
	}
	catch (const std::exception & e) {
		ece::ERROR << e.what() << ece::flush;
	}

	return EXIT_SUCCESS;
}
