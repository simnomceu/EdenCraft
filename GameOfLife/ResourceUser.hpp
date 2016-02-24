#pragma once

#include <memory>
#include <mutex>

#include "ResourceManager.hpp"

namespace core
{
	namespace rsc
	{
		class ResourceUser
		{
		public:
			static void setResourceManager(std::shared_ptr<ResourceManager> rmIn, std::shared_ptr<std::mutex> lockRmIn);

			void lockRM();
			void unlockRM();
			std::shared_ptr<ResourceManager> getRM();
		private:
			static std::shared_ptr<ResourceManager> rm;
			static std::shared_ptr<std::mutex> lockRm;
		};
	}
}
