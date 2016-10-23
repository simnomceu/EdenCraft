#pragma once

#include "Core\Window\WindowManager.hpp"

namespace Utils
{
	class WindowServiceLocator
	{
	public:
		static void provide(WindowManager * service);

		static WindowManager & getService();
		
		static void stopService();

	private:
		static WindowManager * service;
	};
}