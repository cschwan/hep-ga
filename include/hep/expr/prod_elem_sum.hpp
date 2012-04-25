#ifndef HEP_EXPR_PROD_ELEM_SUM_HPP
#define HEP_EXPR_PROD_ELEM_SUM_HPP

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

#include <hep/expr/prod_elem_cond_sum.hpp>
#include <hep/expr/prod_elem_sum_list.hpp>
#include <hep/inline.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup internals
 * @{
 */

/**
 * Helper class for performing the sum appearing in product-like expressions.
 */
template <typename List, typename C>
struct prod_elem_sum
{
	/**
	 * 
	 */
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <typename List, typename C>
template <int index, typename L, typename R>
hep_inline  typename L::algebra::scalar_type prod_elem_sum<List, C>::at(
	L const& lhs,
	R const& rhs
) {
	// find all components in L::list that multiply with those in R::list to
	// index; multiply the actual components, sum up and return result

	// Idea: i ^ j = index  <=>  j = i ^ index
	//
	// 1. Take first element from L::list and assign to i
	// 2. XOR with index
	// 3. find result in R::list
	//    a) if found, multiply corresonding components together with the entry
	//       of sign_table and add it to function result
	// 4. goto 1. and repeat with remaining elements in L::list

	// next list containing a new tuple of indices contributing to the sum
	typedef typename prod_elem_sum_list<typename List::next, typename R::list,
		C, index>::type NextList;

	// type of the right-hand side of the sum
	typedef prod_elem_sum<NextList, C> Rhs;

	// if NextList is not empty, there are remaining terms to sum
	constexpr bool enable_rhs = !std::is_same<NextList, list<>>::value;

	constexpr int i = List::value();
	constexpr int j = List::value() ^ index;

	return prod_elem_cond_sum<enable_rhs>::template at<i, j, Rhs>(lhs, rhs);
}

/**
 * @}
 */

}

#endif
