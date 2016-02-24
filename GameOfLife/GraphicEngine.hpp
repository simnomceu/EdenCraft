#pragma once

#include "Engine.hpp"
#include "RenderUser.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace app
{
	namespace eng
	{
		class GraphicEngine : public core::eng::Engine, public core::cmn::RenderUser
		{
		public:
			GraphicEngine(const bool activeIn, const int refreshRateIn);
			~GraphicEngine();

			virtual void initialize();

		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);
			virtual void update();
			virtual void render();

		private:
			std::shared_ptr<std::string> screenBuffer;
		};
	}
}