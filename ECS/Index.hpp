#pragma once

#include <map>
#include <string>


namespace ECS
{
	template <typename BaseType>
	class Index
	{
	public:
		static std::shared_ptr<Index<BaseType>> getInstance();

		~Index();

		template <typename Type> void registerElement();
		template <typename Type> const int getIndex();

		template <typename Type> bool isRegistered();

		template <typename Type> void unregisterElement();

	private:
		std::map<std::string, int> _index;

		Index();
		static std::shared_ptr<Index<BaseType>> _instance;
	};
}

#include "Index.inl"