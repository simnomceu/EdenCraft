#pragma once

#include <memory>

#include "IEngineFactory.hpp"

namespace core
{
	namespace eng
	{
		template<class T>
		class EngineFactory : public IEngineFactory
		{
		public:
			EngineFactory();
			~EngineFactory();

			std::shared_ptr<T> build(const bool activeIn, const int refreshRateIn);
		};

		template<class T>
		EngineFactory<T>::EngineFactory()
		{
		}

		template<class T>
		EngineFactory<T>::~EngineFactory()
		{
		}

		template<class T>
		std::shared_ptr<T> EngineFactory<T>::build(const bool activeIn, const int refreshRateIn)
		{
			return std::shared_ptr<T>(new T(activeIn, refreshRateIn));
		}
	}
}