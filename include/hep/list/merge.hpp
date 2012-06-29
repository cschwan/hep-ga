#ifndef HEP_LIST_MERGE_HPP
#define HEP_LIST_MERGE_HPP

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

#include <hep/list/list.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup lists
 * @{
 */

/**
 * Adds two sorted lists \c T and \c S together. The result contains the
 * elements of both lists, without duplicates and sorted in ascending order.
 * Example:
 * \code
 * typedef hep::list<1, 2, 4, 8> one;
 * typedef hep:.list<3, 5, 6, 9, 10, 12> two;
 *
 * typedef hep::merge<one, two>::type result;
 * \endcode
 * The result is identical to the definition of the following type:
 * \code
 * typedef hep::list<1, 2, 3, 4, 5, 6, 8, 9, 10, 12> result;
 * \endcode
 */
template <typename T, typename S>
struct merge
{
	/**
	 * Result of this operation.
	 */
	typedef typename merge<
		typename std::conditional<(T::value <= S::value),
			typename T::next, T>::type,
		typename std::conditional<(T::value < S::value),
			S, typename S::next>::type
		>::type::template push_front<(T::value < S::value) ? T::value :
			S::value>::type type;
};

/// \cond DOXYGEN_IGNORE
template <typename T>
struct merge<T, list<>>
{
	typedef typename merge<typename T::next, list<>>::type::
		template push_front<T::value>::type type;
};

template <typename S>
struct merge<list<>, S>
{
	typedef typename merge<list<>, typename S::next>::type::
		template push_front<S::value>::type type;
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
