#ifndef HEP_GA_LIST_MERGE_HPP
#define HEP_GA_LIST_MERGE_HPP

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
struct merge;

}

namespace hep
{

/**
 * \ingroup lists
 *
 * Adds two sorted lists \c L and \c R together. The result contains the
 * elements of both lists, without duplicates and sorted in ascending order.
 * Example:
 * \code
 * using one = hep::list<1, 2, 3, 4>;
 * using two = hep::list<2, 4, 5, 6>;
 *
 * using result = typename hep::merge<one, two>::type;
 * \endcode
 * The result is identical to the definition of the following type:
 * \code
 * using result = hep::list<1, 2, 3, 4, 5, 6>;
 * \endcode
 */
template <typename L, typename R>
using merge_t = typename merge<L, R>::type;

}

namespace
{

template <typename L, typename R>
struct merge
{
	/**
	 * Result of the \ref merge operation.
	 */
	using type = hep::push_front_t<(L::value < R::value) ? L::value : R::value, hep::merge_t<
		std::conditional_t<L::value <= R::value, typename L::next, L>,
		std::conditional_t<L::value <  R::value, R, typename R::next>
	>>;
};

template <typename L>
struct merge<L, hep::list<>>
{
	using type = hep::push_front_t<L::value, hep::merge_t<typename L::next, hep::list<>>>;
};

template <typename R>
struct merge<hep::list<>, R>
{
	using type = hep::push_front_t<R::value, hep::merge_t<hep::list<>, typename R::next>>;
};

template <>
struct merge<hep::list<>, hep::list<>>
{
	using type = hep::list<>;
};

}

#endif
