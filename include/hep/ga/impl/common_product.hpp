#ifndef HEP_GA_IMPL_COMMON_PRODUCT_HPP
#define HEP_GA_IMPL_COMMON_PRODUCT_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011-2012,2015  Christopher Schwan
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

#include <hep/ga/list/find.hpp>
#include <hep/ga/utils/sign_table.hpp>
#include <hep/ga/common_product.hpp>
#include <hep/ga/wrapper.hpp>

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
	// i = L::value
	// j = L::value ^ index

	using type = std::conditional_t<
		// check if there is a component with index j in R so that i ^ j = index
		(hep::find<R>(L::value ^ index) != -1) &&
		// check if this tuple contributes to this type of product
		(P::check(L::value, L::value ^ index)) &&
		// check if this tuple has the requested sign
		(hep::sign_table<A, L::value, L::value ^ index>() == sign),

		// condition is fulfilled : add i to list and continue with the
		// remaining indices
		hep::push_front_t<L::value, typename components<A, typename L::next, R, P, index, sign>::type>,

		// condition is not fulfilled: skip i and continue with the remaining
		// elements
		typename components<A, typename L::next, R, P, index, sign>::type
	>;
};

template <typename A, typename R, typename P, int index, int sign>
struct components<A, hep::list<>, R, P, index, sign>
{
	using type = hep::list<>;
};

}

namespace hep
{

template <typename P, typename L, typename R>
template <int index>
hep_inline typename L::algebra::scalar_type common_product<P, L, R>::at() const
{
	// list with components in L contributing to the product with POSITIVE sign
	using positive = typename components<typename L::algebra, typename L::list,
		typename R::list, P, index, +1>::type;

	// list with components in L contributing to the product with NEGATIVE sign
	using negative = typename components<typename L::algebra, typename L::list,
		typename R::list, P, index, -1>::type;

	// subtract the sum of positive components from sum of negative components
	return ::difference<positive, negative, index>::at(this->lhs, this->rhs);
}

/// \cond DOXYGEN_IGNORE

// the following two classes enable all products containing (exactly one)
// literal, e.g. '2.0 * v' with v being an arbitrary multi-vector

template <typename P, typename L>
class common_product<P, L, typename L::algebra::scalar_type> :
	public common_product<P, L, wrapper<typename L::algebra>>
{
public:
	hep_inline common_product(
		L const& lhs,
		typename L::algebra::scalar_type const& rhs
	)
		: common_product<P, L, wrapper<typename L::algebra>>(lhs, rhs)
	{
	}
};

template <typename P, typename R>
class common_product<P, typename R::algebra::scalar_type, R> :
	public common_product<P, wrapper<typename R::algebra>, R>
{
public:
	hep_inline common_product(
		typename R::algebra::scalar_type const& lhs,
		R const& rhs
	)
		: common_product<P, wrapper<typename R::algebra>, R>(lhs, rhs)
	{
	}
};
/// \endcond

}

#endif
