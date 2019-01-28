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

#ifndef PIMPL_HPP
#define PIMPL_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/pattern/holdable.hpp"

namespace ece
{
    namespace utility
    {
        namespace pattern
        {
			struct EmptyPimpl {
				constexpr EmptyPimpl() {}
			};
			constexpr EmptyPimpl emptyPimpl;

        	/**
        	 * @class Pimpl
        	 * @tparam Impl The implementation to use.
        	 * @tparam Deleter A deleter to free the implementation memory.
        	 * @tparam Copier A copier to allow copy operation of the implementation.
        	 * @brief Pimpl idiom implementation to hide implementation details of an interface.
        	 */
        	template <class Impl>
        	class Pimpl
        	{
        	public:
        		/**
        		 * @fn Pimpl()
        		 * @brief
        		 * @throw noexcept
        		 */
        		Pimpl() noexcept;

				constexpr Pimpl(EmptyPimpl) noexcept {}

        		/**
        		 * @fn Pimpl(const Pimpl & copy)
        		 * @param[in] copy The pimpl to copy from.
        		 * @brief Default copy constructor.
        		 * To copy the implementation, the copier set will be used.
        		 * @throw noexcept
        		 */
        		Pimpl(const Pimpl & copy);

        		/**
        		 * @fn Pimpl(Pimpl && move)
        		 * @param[in] move The pimpl to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept.
        		 */
				Pimpl(Pimpl && move) noexcept;

				explicit Pimpl(const Impl & rhs);

				explicit Pimpl(Impl && rhs);

        		/**
        		 * @fn Pimpl & operator=(const Pimpl & copy)
        		 * @param[in] copy The pimpl to copy from.
        		 * @return The pimpl copied.
        		 * @brief Default copy assignment operator.
        		 * @throw
        		 */
        		Pimpl & operator=(const Pimpl & copy);

        		/**
        		 * @fn Pimpl & operator=(Pimpl && move)
        		 * @param[in] move The pimpl to move.
        		 * @return The pimpl moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept.
        		 */
        		Pimpl & operator=(Pimpl && move) noexcept;

				auto operator*() const;

        		/**
        		* @fn Impl * operator->()
        		* @return The implementation.
        		* @brief Get the hidden implementation.
        		* @throw noexcept
        		*/
        		auto operator->() const noexcept;

				auto get() const noexcept;

				explicit operator bool() const noexcept;

				void swap(Pimpl & rhs) noexcept;

        	protected:
        		/**
        		 * @property _impl
        		 * @brief The hidden implementation.
        		 */
        		Holdable * _impl; // opaque pointer

				template <class ImplBis, class... Args>
				friend auto makePimpl(Args &&... args);
        	};

        	/**
        	 * @fn Pimpl<Impl> makePimpl(Args &&... args)
        	 * @tparam Impl The type of implementation to use.
        	 * @tparam Args The type of arguments to forward to the constructor.
        	 * @param[in] args The arguments to forward to the constructor.
        	 * @return A pimpl of the implementation built.
        	 * @brief Allocate memory and build a pimpl of the implementation.
        	 * @throw bad_alloc
        	 */
        	/*template <class Impl, class... Args>
        	Pimpl<Impl> makePimpl(Args &&... args);*/

			template <class Impl>
			void swap(Pimpl<Impl> & lhs, Pimpl<Impl> & rhs) noexcept;
        } // namespace pattern
    } // namespace utility
} // namespace ece

#include "utility/pattern/pimpl.inl"

#endif // PIMPL_HPP
