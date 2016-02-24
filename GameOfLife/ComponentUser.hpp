#pragma once

#include <memory>
#include <mutex>

#include "ComponentManager.hpp"

namespace core
{
	namespace cmp
	{
		class ComponentUser
		{
		public:
			static void setComponentManager(std::shared_ptr<ComponentManager> cmIn, std::shared_ptr<std::mutex> lockCmIn);

			void lockCM();
			void unlockCM();
			std::shared_ptr<ComponentManager> getCM();
		private:
			static std::shared_ptr<ComponentManager> cm;
			static std::shared_ptr<std::mutex> lockCm;
		};
	}
}
