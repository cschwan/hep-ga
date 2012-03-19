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

#include <hep/expr/prod_elem.hpp>
#include <hep/list/find.hpp>
#include <hep/list/list.hpp>

namespace hep
{

template <typename List, typename Condition>
struct prod_elem_sum
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <typename List, typename Condition>
template <int index, typename L, typename R>
inline typename L::algebra::scalar_type prod_elem_sum<List, Condition>::at(
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

	constexpr int i = List::value();
	constexpr int j = List::value() ^ index;
	constexpr bool condition = (find<typename R::list>(j) != -1) &&
		Condition::check(i, j);

	return prod_elem<condition>::template at<i, j>(lhs, rhs) +
		prod_elem_sum<typename List::next, Condition>::template
		at<index>(lhs, rhs);
}

/// \cond DOXYGEN_IGNORE
template <typename Condition>
struct prod_elem_sum<list<>, Condition>
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const&, R const&);
};

template <typename Condition>
template <int index, typename L, typename R>
inline typename L::algebra::scalar_type prod_elem_sum<list<>, Condition>::at(
	L const&,
	R const&
) {
	return 0.0;
}
/// \endcond

}

#endif
