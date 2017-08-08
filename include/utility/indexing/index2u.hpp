#ifndef INDEX2U_HPP
#define INDEX2U_HPP

namespace ece
{
	class Index2u
	{
	public:
		inline Index2u();
		inline Index2u(const int i, const int j);
		Index2u(const Index2u & copy) = default;
		Index2u(Index2u && move) = default;

		~Index2u() = default;

		Index2u & operator=(const Index2u & copy) = default;
		Index2u & operator=(Index2u && move) = default;

		inline int get(const int maxI);
		inline void set(const int maxI, const int index);

		unsigned int i;
		unsigned int j;
	};
}

#include "indexing\index2u.inl"

#endif // INDEX2U_HPP
