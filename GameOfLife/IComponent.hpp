#pragma once

namespace core
{
	namespace cmp
	{
		// ============================================================================================================
		/**
		  * @brief Alias of integer indexation keys.
		  */
		// ============================================================================================================
		using EntityID = int;
		using ComponentType = int;
		using ComponentID = int;

		// ============================================================================================================
		/**
		  * @class IComponent <<Interface>>
		  * @brief Basic class for all the components of the ECS.
		  */
		// ============================================================================================================
		class IComponent
		{
		public:
			virtual ~IComponent() {}

			virtual EntityID getOwner() const = 0;
			virtual ComponentType getType() const = 0;
			virtual ComponentID getID() const = 0;
		};
	}
}