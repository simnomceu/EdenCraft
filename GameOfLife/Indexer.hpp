#pragma once

#include <map>

namespace core
{
	namespace cmp
	{
		class Indexer
		{
		public:
			Indexer();
			~Indexer();

			bool contains(const int keyIn) const;
			std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> get(const int keyIn);
			void add(const int keyIn, const int valueIn);
			void remove(const int keyIn);
			// return l'identifiant ou -1.
			int intersect(const std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator>& rightOperant, const int keyIn);

		private:
			std::multimap<int, int> index;
		};
	}
}