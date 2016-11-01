#include <deque>

namespace ece
{
	class UniqueID: private std::deque<unsigned int>
	{
	public:
		using std::deque<unsigned int>::size;

		UniqueID();
		UniqueID(const unsigned int start);

		unsigned int next();
		void restack(const unsigned int value);
	};
}
