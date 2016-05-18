#pragma once

#include "ECS.hpp"

namespace ECS
{
	class BaseComponent
	{
	public:
		BaseComponent() = default;
		virtual ~BaseComponent() = 0;

		void setOwner(EntityUUID ownerID);
		void SetRelativeID(ComponentID relativeID);

		const EntityUUID getOwner();
		const ComponentID getRelativeID();

	protected:
		virtual void onLinked();
		virtual void onUnlinked();
		virtual void onUpdate();

	private:
		EntityUUID _ownerID;
		ComponentID _relativeID;
	};
}