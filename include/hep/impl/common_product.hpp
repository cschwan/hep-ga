#ifndef HEP_IMPL_COMMON_PRODUCT_HPP
#define HEP_IMPL_COMMON_PRODUCT_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011-2012  Christopher Schwan
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

#include <hep/list/find.hpp>
#include <hep/list/list.hpp>
#include <hep/utils/sign_table.hpp>
#include <hep/common_product.hpp>
#include <hep/inline.hpp>

namespace
{

template <typename L, typename R, typename C, int index>
struct prod_elem_sum_list
{
#define hep_i         ( L::value() )
#define hep_j         ( L::value() ^ index )
#define hep_condition ( (hep::find<R>(hep_j) != -1) && C::check(hep_i, hep_j) )

	// sub-list of L satisfying i ^ j = index, with i being the first element of
	// L and j somewhere in R
	typedef typename std::conditional<hep_condition, L, typename
		prod_elem_sum_list<typename L::next, R, C, index>::type>::type type;

#undef hep_condition
#undef hep_j
#undef hep_i
};

template <typename R, typename C, int index>
struct prod_elem_sum_list<hep::list<>, R, C, index>
{
	// L is empty so there is no i satisfying the condition C
	typedef hep::list<> type;
};

template <bool enable_rhs>
struct prod_elem_cond_sum
{
	template <int i, int j, typename Rhs, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <bool enable_rhs>
template <int i, int j, typename Rhs, typename L, typename R>
hep_inline typename L::algebra::scalar_type prod_elem_cond_sum<enable_rhs>::at(
	L const& lhs,
	R const& rhs
) {
	return hep::sign_table<typename L::algebra, i, j>() *
		lhs.template at<i>() *
		rhs.template at<j>() + Rhs::template at<i ^ j>(lhs, rhs);
}

template <>
struct prod_elem_cond_sum<false>
{
	template <int i, int j, typename Rhs, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <int i, int j, typename Rhs, typename L, typename R>
hep_inline typename L::algebra::scalar_type prod_elem_cond_sum<false>::at(
	L const& lhs,
	R const& rhs
) {
	return hep::sign_table<typename L::algebra, i, j>() *
		lhs.template at<i>() * rhs.template at<j>();
}

template <typename List, typename C>
struct prod_elem_sum
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <typename List, typename C>
template <int index, typename L, typename R>
hep_inline typename L::algebra::scalar_type prod_elem_sum<List, C>::at(
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
	constexpr bool enable_rhs = !std::is_same<NextList, hep::list<>>::value;

	constexpr int i = List::value();
	constexpr int j = List::value() ^ index;

	return prod_elem_cond_sum<enable_rhs>::template at<i, j, Rhs>(lhs, rhs);
}

}

namespace hep
{

template <typename P, typename L, typename R>
hep_inline common_product<P, L, R>::common_product(L const& lhs, R const& rhs)
	: lhs(lhs), rhs(rhs)
{
}

template <typename P, typename L, typename R>
template <int index>
hep_inline typename L::algebra::scalar_type common_product<P, L, R>::at() const
{
	typedef typename prod_elem_sum_list<typename L::list, typename R::list, P,
		index>::type List;

	// delegate computation in order to use partial template specialization
	return prod_elem_sum<List, P>::template at<index>(lhs, rhs);
}

}

#endif
