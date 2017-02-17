#include "Core\Graphic\GraphicModule.hpp"

#include "Core\Window\WindowModule.hpp"
#include "Core\Graphic\RenderingService.hpp"

#include <iostream>

namespace ece
{
	GraphicModule::GraphicModule() : Module()
	{
		this->dependencies.push_back(new WindowModule());

		this->services.push_back(new RenderingService());
	}
}