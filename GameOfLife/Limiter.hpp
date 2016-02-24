#pragma once

#include <ctime>

namespace core
{
	namespace cmn
	{
		class Limiter
		{
		public:
			Limiter(const int fpsIn);
			virtual ~Limiter();

			void begin();
			void wait();

		private:
			std::clock_t start;
			std::clock_t end;
			int fps;
		};
	}
}