#include <stack>

namespace ece
{
	class UniqueID: private std::stack<unsigned int>
	{
	public:
		UniqueID();
		UniqueID(const unsigned int start);

		unsigned int next();
		void restack(const unsigned int value);
	};
}
