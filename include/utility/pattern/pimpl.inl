namespace ece
{
	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier>::Pimpl(Impl * impl, Deleter && deleter, Copier && copier) :
		impl(impl, std::forward<Deleter>(deleter)),
		copier(std::forward<Copier>(copier))
	{
	}

	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier>::Pimpl(const Pimpl & copy) noexcept : Pimpl(copy.clone())
	{
	}

	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier> & Pimpl<Impl, Deleter, Copier>::operator=(const Pimpl & copy)
	{
		if (this != &copy) {
			operator=(copy.clone());
		}
		return *this;
	}

	template<class Impl, class Deleter, class Copier>
	const Impl * Pimpl<Impl, Deleter, Copier>::operator->() const noexcept
	{
		return this->impl.get();
	}

	template<class Impl, class Deleter, class Copier>
	Impl * Pimpl<Impl, Deleter, Copier>::operator->() noexcept
	{
		return this->impl.get();
	}

	template<class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier> Pimpl<Impl, Deleter, Copier>::clone() const
	{
		if (this->impl) {
			return Pimpl(this->copier(this->impl.get()), this->impl.get_deleter(), this->copier);
		}
		else {
			return Pimpl(nullptr, this->impl.get_deleter(), this->copier);
		}
	}

	template<class Impl, class ...Args>
	Pimpl<Impl> makePimpl(Args && ...args)
	{
		return Pimpl<Impl>(new Impl(std::forward<Args>(args)...), &defaultDelete<Impl>, &defaultCopy<Impl>);
	}

	template<class Impl>
	void defaultDelete(Impl * impl) noexcept
	{
		delete impl;
	}

	template<class Impl>
	Impl * defaultCopy(Impl * impl) noexcept
	{
		return new Impl(*impl);
	}
}