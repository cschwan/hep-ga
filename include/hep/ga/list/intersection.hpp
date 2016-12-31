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

namespace
{

template <typename L, typename R>
struct intersection;

}

namespace hep
{

/**
 * \ingroup lists
 *
 * Computes the intersection of two lists \c L and \c R which both have to be
 * \ref list. Example:
 * \code
 * using one = hep::list<0,1,2>;
 * using two = hep::list<1,2,3>;
 * using result = hep::intersection_t<one, two>;
 * \endcode
 * The definition of \c result is equal to the following
 * \code
 * using result = hep::list<1,2>;
 * \endcode
 * because \c 1 and \c 2 appear in both lists.
 */
template <typename L, typename R>
using intersection_t = typename intersection<L, R>::type;

}

namespace
{

template <typename L, typename R>
struct intersection
{
	/**
	 * The result of the \ref intersection operation.
	 */
	using type = std::conditional_t<L::value == R::value,
		hep::push_front_t<L::value, hep::intersection_t<typename L::next, typename R::next>>,
		std::conditional_t<
			L::value < R::value,
			hep::intersection_t<typename L::next, R>,
			hep::intersection_t<L, typename R::next>
		>>;
};

/// \cond DOYXGEN_IGNORE
template <typename L>
struct intersection<L, hep::list<>>
{
	using type = hep::list<>;
};

template <typename R>
struct intersection<hep::list<>, R>
{
	using type = hep::list<>;
};

template <>
struct intersection<hep::list<>, hep::list<>>
{
	using type = hep::list<>;
};
/// \endcond

}

#endif
