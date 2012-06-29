#ifndef HEP_IMPL_INTERSECTION_HPP
#define HEP_IMPL_INTERSECTION_HPP

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
 * Computes the intersection of two lists \c L1 and \c L2. Only elements which
 * appear both in \c L1 and \c L2 are stored in the result. Example:
 * \code
 * typedef hep::list<0,1,2> one;
 * typedef hep::list<1,2,3> two;
 * typedef hep::intersection<one, two>::type result;
 * \endcode
 * The definition of \c result is equal to the following:
 * \code
 * typedef hep::list<1,2> result;
 * \endcode
 */
template <typename L1, typename L2>
struct intersection
{
	/**
	 * The result of the operation.
	 */
	typedef typename std::conditional<L1::value == L2::value,
		typename intersection<typename L1::next, typename L2::next>::type::
			template push_front<L1::value>::type,
		typename std::conditional<L1::value < L2::value,
			typename intersection<typename L1::next, L2>::type,
			typename intersection<L1, typename L2::next>::type>::type>::type
		type;
};

/// \cond DOYXGEN_IGNORE
template <typename L1>
struct intersection<L1, list<>>
{
	typedef list<> type;
};

template <typename L2>
struct intersection<list<>, L2>
{
	typedef list<> type;
};

template <>
struct intersection<list<>, list<>>
{
	typedef list<> type;
};
/// \endcond

/**
 * @}
 */

}

#endif
