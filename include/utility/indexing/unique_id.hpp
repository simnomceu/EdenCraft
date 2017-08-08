#ifndef UNIQUE_ID_HPP
#define UNIQUE_ID_HPP

#include <deque>

namespace ece
{
	class UniqueID : private std::deque<unsigned int>
	{
	public:
		using std::deque<unsigned int>::size;
		using std::deque<unsigned int>::clear;

		inline UniqueID();
		inline UniqueID(const unsigned int start);
		UniqueID(const UniqueID & copy) = default;
		UniqueID(UniqueID && move) = default;
		~UniqueID() = default;

		UniqueID & operator=(const UniqueID & copy) = default;
		UniqueID & operator=(UniqueID && move) = default;

		unsigned int next();
		void restack(const unsigned int value);
	};
}

#include "indexing\unique_id.inl"

#endif // UNIQUE_ID_HPP