#ifndef UNIQUEID_HPP
#define UNIQUEID_HPP

/**
* @file UniqueID.hpp
* @author IsiliBN (casa2pir@hotmail.fr)
* @date November, 2nd 2016
* @copyright ----------
* @brief A generator of unique IDs.
*
* A generator of unique IDs. It generates uniques IDs, and provide a service to take care about IDs not anymore in use.
*
**/

#include <deque>

/**
* @namespace ece
*
* A namespace to gather classes and functionalities of the core engine of EdenCraft.
*
**/
namespace ece
{
	/**
	 * @class UniqueID
	 * @extends std::deque<unsigned int<
	 * @brief Class which implements a generator of unique IDs.
	 *
	 * This class implements a generator of unique IDs. When an ID is not anymore used, it is added again to the distribution queue.
	 *
	 **/
	class UniqueID: private std::deque<unsigned int>
	{
	public:
		using std::deque<unsigned int>::size;

		UniqueID();
		UniqueID(const unsigned int start);
		UniqueID(const UniqueID & copy) = default;
		UniqueID(UniqueID && move) = default;

		UniqueID & operator=(const UniqueID & copy) = default;
		UniqueID & operator=(UniqueID && move) = default;

		unsigned int next();
		void restack(const unsigned int value);
	};
}

#endif // UNIQUEID_HPP