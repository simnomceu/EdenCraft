#pragma once

#include <mutex>

namespace core
{
	namespace cmn
	{
		template<class T>
		class Philosopher
		{
		public:
			static void setFork(std::shared_ptr<T> forkIn, std::shared_ptr<std::mutex> lockForkIn);

			static void lock();
			static void unlock();
			static std::shared_ptr<T> getFork();
		private:
			static std::shared_ptr<T> fork;
			static std::shared_ptr<std::mutex> lockFork;
		};

		template<class T>
		void Philosopher<T>::setFork(std::shared_ptr<T> forkIn, std::shared_ptr<std::mutex> lockForkIn)
		{
			Philosopher<T>::fork = forkIn;
			Philosopher<T>::lockFork = lockForkIn;
		}

		template<class T>
		void Philosopher<T>::lock()
		{
			Philosopher<T>::lockFork->lock();
		}

		template<class T>
		void Philosopher<T>::unlock()
		{
			Philosopher<T>::lockFork->unlock();
		}

		template<class T>
		std::shared_ptr<T> Philosopher<T>::getFork()
		{
			return Philosopher<T>::fork;
		}
	}
}