#ifndef HEP_LIST_GRADE_TO_LIST_HPP
#define HEP_LIST_GRADE_TO_LIST_HPP

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
#include <hep/utils/next_bit_permutation.hpp>

namespace
{

template <typename A, int grade, int component, int last_component>
struct grade_to_list_helper
{
	static_assert (grade <= A::dim(), "grade bigger than algebra dimension");

#define first_component ((1 << grade) - 1)
#define next_component (hep::next_bit_permutation(component))
#define last_component (first_component << (A::dim() - grade))

	typedef typename grade_to_list_helper<A, grade, next_component,
		last_component>::type::template push_front<component>::type type;

#undef last_component
#undef next_component
#undef first_component
};

template <typename A, int grade, int component>
struct grade_to_list_helper<A, grade, component, component>
{
	typedef hep::list<component> type;
};

}

namespace hep
{

/**
 * \addtogroup list
 * @{
 */

/**
 * Returns the component list for \c grade in algebra \c A. Example:
 * \code
 * typedef hep::algebra<double, 3, 0> algebra;
 * typedef hep::grade_to_list<algebra, 1>::type result;
 * \endcode
 * This is equivalent to the following definition:
 * \code
 * typedef hep::list<1,2,4> result;
 * \endcode
 */
template <typename A, int grade>
struct grade_to_list
{
	static_assert (grade <= A::dim(), "grade bigger than algebra dimension");

#define first_component ((1 << grade) - 1)
#define last_component (first_component << (A::dim() - grade))

	/**
	 * The result of this operation.
	 */
	typedef typename grade_to_list_helper<A, grade, first_component,
		last_component>::type type;

#undef last_component
#undef first_component
};

/**
 * @}
 */

}

#endif
