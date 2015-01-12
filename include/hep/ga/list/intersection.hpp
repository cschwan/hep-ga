#ifndef HEP_GA_LIST_INTERSECTION_HPP
#define HEP_GA_LIST_INTERSECTION_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2012,2015  Christopher Schwan
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
 * Computes the intersection of two lists \c L and \c R which both have to be
 * \ref list. Example:
 * \code
 * using one = hep::list<0,1,2>;
 * using two = hep::list<1,2,3>;
 * using result = typename hep::intersection<one, two>::type;
 * \endcode
 * The definition of \c result is equal to the following
 * \code
 * using result = hep::list<1,2>;
 * \endcode
 * because \c 1 and \c 2 appear in both lists.
 */
template <typename L, typename R>
struct intersection
{
	/**
	 * The result of the \ref intersection operation.
	 */
	using type = typename std::conditional<L::value == R::value,
		push_front_t<L::value, typename intersection<typename L::next, typename R::next>::type>,
		typename std::conditional<
			L::value < R::value,
			typename intersection<typename L::next, R>::type,
			typename intersection<L, typename R::next>::type
		>::type>::type;
};

/// \cond DOYXGEN_IGNORE
template <typename L>
struct intersection<L, list<>>
{
	using type = list<>;
};

template <typename R>
struct intersection<list<>, R>
{
	using type = list<>;
};

template <>
struct intersection<list<>, list<>>
{
	using type = list<>;
};
/// \endcond

/**
 * @}
 */

}

#endif
