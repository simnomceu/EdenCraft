#pragma once

namespace core
{
	namespace cmn
	{
		class ISharedElement
		{
		public:
			virtual ~ISharedElement() {}

			virtual void lock() = 0;
			virtual void unlock() = 0;
		};
	}
}