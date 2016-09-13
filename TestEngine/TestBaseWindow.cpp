#include "CppUnitTest.h"
#include "BaseWindow.hpp"
#include "Window.inl"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestEngine
{		
	TEST_CLASS(BaseWindow)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Window::BaseWindow window("Title", Window::TOOLBAR, Window::PRIMARY_MONITOR, Util::Rectangle<int>{100, 100, 480, 360});
			Assert::IsTrue(!window.isOpened());
		}

	};
}