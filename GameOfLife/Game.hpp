#pragma once

#include "Application.hpp"

namespace app
{
	class Game : public core::Application
	{
	public:
		Game();
		~Game();
	
	protected:
		virtual void loadEngineType();
		virtual void loadSystemType();
		virtual void loadComponentType();

		virtual void loadEngines();
	};
}