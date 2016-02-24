#pragma once

#include <memory>
#include <mutex>

#include "ISharedElement.hpp"

namespace core
{
	namespace cmn
	{
		template<class T>
		class SharedElement : public ISharedElement
		{
		public:
			SharedElement(const std::shared_ptr<T> elementIn);
			SharedElement(const SharedElement& copyIn);
			~SharedElement();

			virtual void lock();
			virtual void unlock();
			std::shared_ptr<T>& get();
			std::shared_ptr<std::mutex>& getLock();

		private:
			std::shared_ptr<T> element;
			std::shared_ptr<std::mutex> mutex;
		};

		template<class T>
		SharedElement<T>::SharedElement(const std::shared_ptr<T> elementIn) : element(elementIn), mutex(new std::mutex())
		{
		}

		template<class T>
		SharedElement<T>::SharedElement(const SharedElement & copyIn) : element(copyIn->get()), mutex(copyIn.getElement())
		{
		}

		template<class T>
		SharedElement<T>::~SharedElement()
		{
		}

		template<class T>
		void SharedElement<T>::lock()
		{
			this->mutex->lock();
		}

		template<class T>
		void SharedElement<T>::unlock()
		{
			this->mutex->unlock();
		}

		template<class T>
		std::shared_ptr<T>& SharedElement<T>::get()
		{
			return this->element;
		}

		template<class T>
		std::shared_ptr<std::mutex>& SharedElement<T>::getLock()
		{
			return this->mutex;
		}
	}
}