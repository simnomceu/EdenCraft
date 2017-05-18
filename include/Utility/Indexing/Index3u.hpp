#ifndef INDEX3U_HPP
#define INDEX3U_HPP

namespace ece
{
	class Index3u
	{
	public:
		inline Index3u();
		inline Index3u(const int i, const int j, const int k);
		Index3u(const Index3u & copy) = default;
		Index3u(Index3u && move) = default;

		~Index3u() = default;

		Index3u & operator=(const Index3u & copy) = default;
		Index3u & operator=(Index3u && move) = default;

		inline int get(const int maxI, const int maxJ);
		inline void set(const int maxI, const int maxJ, const int index);

		unsigned int i;
		unsigned int j;
		unsigned int k;
	};
}

#include "Indexing\Index3u.inl"

#endif // INDEX3U_HPP
