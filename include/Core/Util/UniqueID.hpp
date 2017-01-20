#ifndef UNIQUEID_HPP
#define UNIQUEID_HPP

#include <deque>

namespace ece
{
	class UniqueID : private std::deque<unsigned int>
	{
	public:
		using std::deque<unsigned int>::size;
		using std::deque<unsigned int>::clear;

		UniqueID();
		UniqueID(const unsigned int start);
		UniqueID(const UniqueID & copy) = default;
		UniqueID(UniqueID && move) = default;
		~UniqueID() = default;

		UniqueID & operator=(const UniqueID & copy) = default;
		UniqueID & operator=(UniqueID && move) = default;

		unsigned int next();
		void restack(const unsigned int value);
	};
}

#endif // UNIQUEID_HPP