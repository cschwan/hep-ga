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

template <typename List, int index>
struct sum
{
	template <typename L, typename R>
	hep_inline static typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return lhs.template at<List::value>() *
			rhs.template at<List::value ^ index>() +
			sum<typename List::next, index>::at(lhs, rhs);
	}
};

template <int element, int index>
struct sum<hep::list<element>, index>
{
	template <typename L, typename R>
	hep_inline static typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return lhs.template at<element>() * rhs.template at<element ^ index>();
	}
};

template <typename P, typename N, int index>
struct difference
{
	template <typename L, typename R>
	hep_inline static typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return sum<P, index>::at(lhs, rhs) - sum<N, index>::at(lhs, rhs);
	}
};

template <typename P, int index>
struct difference<P, hep::list<>, index>
{
	template <typename L, typename R>
	hep_inline static typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return sum<P, index>::at(lhs, rhs);
	}
};

template <typename N, int index>
struct difference<hep::list<>, N, index>
{
	template <typename L, typename R>
	hep_inline static typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return -sum<N, index>::at(lhs, rhs);
	}
};

template <typename A, typename L, typename R, typename P, int index, int sign>
struct components
{
#define i ( L::value )
#define j ( L::value ^ index )

	typedef typename std::conditional<
		// check if there is a component with index j in R so that i ^ j = index
		(hep::find<R>(j) != -1) &&
		// check if this tuple contributes to this type of product
		(P::check(i, j)) &&
		// check if this tuple has the requested sign
		(hep::sign_table<A, i, j>() == sign),

		// condition is fulfilled : add i to list and continue with the
		// remaining indices
		typename components<A, typename L::next, R, P, index, sign>::type::
			template push_front<i>::type,

		// condition is not fulfilled: skip i and continue with the remaining
		// elements
		typename components<A, typename L::next, R, P, index, sign>::type
	>::type type;

#undef j
#undef i
};

template <typename A, typename R, typename P, int index, int sign>
struct components<A, hep::list<>, R, P, index, sign>
{
	typedef hep::list<> type;
};

}

namespace hep
{

template <typename P, typename L, typename R>
hep_inline common_product<P, L, R>::common_product(L const& lhs, R const& rhs)
	: binary_expression<L, R, product_list<P, L, R>>(lhs, rhs)
{
}

template <typename P, typename L, typename R>
template <int index>
hep_inline typename L::algebra::scalar_type common_product<P, L, R>::at() const
{
	// list with components in L contributing to the product with POSITIVE sign
	typedef typename components<typename L::algebra, typename L::list,
		typename R::list, P, index, +1>::type positive;

	// list with components in L contributing to the product with NEGATIVE sign
	typedef typename components<typename L::algebra, typename L::list,
		typename R::list, P, index, -1>::type negative;

	// subtract the sum of positive components from sum of negative components
	return ::difference<positive, negative, index>::at(this->lhs, this->rhs);
}

}

#endif
