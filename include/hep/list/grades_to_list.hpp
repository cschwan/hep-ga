#ifndef HEP_LIST_GRADES_TO_LIST_HPP
#define HEP_LIST_GRADES_TO_LIST_HPP

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

#include <hep/list/grade_to_list.hpp>
#include <hep/list/list.hpp>
#include <hep/list/merge.hpp>

namespace hep
{

/**
 * \addtogroup list
 * @{
 */

/// \cond DOXYGEN_IGNORE
template <typename A, int... grades>
struct grades_to_list;

template <typename A>
struct grades_to_list<A>
{
	typedef list<> type;
};
/// \endcond

/**
 * Returns the component list for every grade specified  in \c grades in algebra
 * \c A. Example:
 * \code
 * typedef hep::algebra<double, 3, 0> algebra;
 * typedef hep::grade_to_list<algebra, 1,2>::type result;
 * \endcode
 * This is equivalent to the following definition:
 * \code
 * typedef hep::list<1,2,3,4,5,6> result;
 * \endcode
 */
template <typename A, int grade1, int... grades>
struct grades_to_list<A, grade1, grades...>
{
	/**
	 * The result of this operation.
	 */
	typedef typename merge<typename grade_to_list<A, grade1>::type,
		typename grades_to_list<A, grades...>::type>::type type;
};

/**
 * @}
 */

}

#endif
