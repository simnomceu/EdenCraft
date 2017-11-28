#ifndef PIMPL_HPP
#define PIMPL_HPP

#include <memory>
#include <functional>

namespace ece
{
	template <class Impl, class Deleter = std::function<void(Impl*)>, class Copier = std::function<Impl*(Impl*)>>
	class Pimpl
	{
	public:
		constexpr Pimpl() noexcept = default;
		Pimpl(Impl * impl, Deleter && deleter, Copier && copier);
		Pimpl(const Pimpl & copy) noexcept;
		Pimpl(Pimpl && move) noexcept = default;

		~Pimpl() = default;

		Pimpl & operator=(const Pimpl & copy);
		Pimpl & operator=(Pimpl && move) noexcept = default;

		const Impl * operator->() const noexcept;
		Impl * operator->() noexcept;

	protected:
		std::unique_ptr<Impl, Deleter> impl; // opaque pointer
		Copier copier;

		Pimpl clone() const;
	};

	template <class Impl, class... Args>
	Pimpl<Impl> makePimpl(Args &&... args);

	template <class Impl>
	void defaultDelete(Impl * impl) noexcept;

	template <class Impl>
	Impl * defaultCopy(Impl * impl) noexcept;
}

#include "utility/pattern/pimpl.inl"

#endif // PIMPL_HPP
