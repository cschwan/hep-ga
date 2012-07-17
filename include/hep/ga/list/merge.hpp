#ifndef HEP_GA_LIST_MERGE_HPP
#define HEP_GA_LIST_MERGE_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2012  Christopher Schwan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <hep/ga/list/list.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup lists
 * @{
 */

/**
 * Adds two sorted lists \c L and \c R together. The result contains the
 * elements of both lists, without duplicates and sorted in ascending order.
 * Example:
 * \code
 * typedef hep::list<1, 2, 3, 4> one;
 * typedef hep::list<2, 4, 5, 6> two;
 *
 * typedef hep::merge<one, two>::type result;
 * \endcode
 * The result is identical to the definition of the following type:
 * \code
 * typedef hep::list<1, 2, 3, 4, 5, 6> result;
 * \endcode
 */
template <typename L, typename R>
struct merge
{
	/**
	 * Result of the \ref merge operation.
	 */
	typedef typename merge<
		typename std::conditional<L::value <= R::value, typename L::next, L>
			::type,
		typename std::conditional<L::value < R::value, R, typename R::next>
			::type
	>::type::template push_front<(L::value < R::value) ? L::value : R::value>
		::type type;
};

/// \cond DOXYGEN_IGNORE
template <typename L>
struct merge<L, list<>>
{
	typedef typename merge<typename L::next, list<>>::type::
		template push_front<L::value>::type type;
};

template <typename R>
struct merge<list<>, R>
{
	typedef typename merge<list<>, typename R::next>::type::
		template push_front<R::value>::type type;
};

template <>
struct merge<list<>, list<>>
{
	typedef list<> type;
};
/// \endcond

/**
 * @}
 */

}

#endif
