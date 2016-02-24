#pragma once

#pragma warning( push )
#pragma warning( disable: 4251 )

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else   
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <map>
#include <vector>
#include <memory>

#include "Component.hpp"

namespace cmp
{
	class MYLIBRARY_EXPORT ComponentPool
	{
	public:
		ComponentPool();
		~ComponentPool();

		std::shared_ptr<std::vector<std::shared_ptr<AbstractComponent>>> access(const std::string& typeIn);
		void addList(const std::string& typeIn);

	private:
		std::map<std::string, std::shared_ptr<std::vector<std::shared_ptr<AbstractComponent>>>> components;
	};
}

#pragma warning( pop )