/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "utility/pattern/holder.hpp"

namespace ece
{
    namespace utility
    {
        namespace pattern
        {
			template <class Impl>
			Pimpl<Impl>::Pimpl() noexcept: _impl(new Holder<Impl>()) {}

        	template <class Impl>
			Pimpl<Impl>::Pimpl(const Pimpl<Impl> & copy)
			{
				*this = copy;
			}

			template <class Impl>
			Pimpl<Impl>::Pimpl(Pimpl<Impl> && move) noexcept
			{
				*this = std::move(move);
			}

			template <class Impl>
			Pimpl<Impl>::Pimpl(const Impl & rhs) {
				this->_impl = new Holder<Impl>(rhs);
			}

			template <class Impl>
			Pimpl<Impl>::Pimpl(Impl && rhs) {
				this->_impl = new Holder<Impl>(std::move(rhs));
			}

        	template <class Impl>
        	Pimpl<Impl> & Pimpl<Impl>::operator=(const Pimpl<Impl> & copy)
        	{
				auto * cloned = (copy ? copy._impl->clone() : nullptr);
				if (this->_impl) {
					this->_impl->destroy();
				}
				this->_impl = cloned;
				return *this;
        	}

			template <class Impl>
			Pimpl<Impl> & Pimpl<Impl>::operator=(Pimpl<Impl> && move) noexcept
			{
				this->swap(move);
				return *this;
			}

			template<class Impl>
			auto Pimpl<Impl>::operator*() const { return *this->get(); }

        	template<class Impl>
        	auto Pimpl<Impl>::operator->() const noexcept { return this->get(); }

			template <class Impl>
			auto Pimpl<Impl>::get() const noexcept { return static_cast<Impl*>(this->_impl->get()); }

			template <class Impl>
			Pimpl<Impl>::operator bool() const noexcept { return !!this->_impl; }

			template<class Impl>
			void Pimpl<Impl>::swap(Pimpl<Impl> & rhs) noexcept { std::swap(this->_impl, rhs._impl); }

        	template<class ImplBis, class ...Args>
        	auto makePimpl(Args && ...args)
			{
				auto result = Pimpl<ImplBis>{emptyPimpl};
				result._impl = new Holder<ImplBis>(std::forward<Args>(args)...);
				return std::move(result);
			}

			template <class Impl>
			void swap(Pimpl<Impl> & lhs, Pimpl<Impl> & rhs) noexcept
			{
				lhs.swap(rhs);
			}

        } // namespace pattern
    } // namespace utility
} // namespace ece
