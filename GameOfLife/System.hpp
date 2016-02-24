#pragma once

#include <map>
#include <memory>

#include "IComponent.hpp"
#include "ComponentUser.hpp"
#include "EntityUser.hpp"
#include "Philosopher.hpp"
#include "ResourceManager.hpp"
#include "Message.hpp"
#include "Communicable.hpp"

namespace core
{
	namespace sys
	{
		class System : public core::cmp::ComponentUser, public core::ent::EntityUser, public core::cmn::Philosopher<core::rsc::ResourceManager>, public core::com::Communicable
		{
		public:
			System();
			virtual ~System();

			virtual void update(std::shared_ptr<core::com::Message> messageIn) = 0;
			virtual void render() = 0;

		protected:
		};
	}
}