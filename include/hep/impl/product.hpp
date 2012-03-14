#ifndef HEP_IMPL_PRODUCT_HPP
#define HEP_IMPL_PRODUCT_HPP

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

#include <hep/product.hpp>
#include <hep/utils/find.hpp>
#include <hep/utils/sign_table.hpp>

namespace hep
{

/// \cond DOXYGEN_IGNORE
template <int i, int j, typename L, typename R>
typename L::algebra::scalar_type product_at(
	L const& lhs,
	R const& rhs,
	std::true_type
) {
	return sign_table<typename L::algebra>(i, j) * lhs.template at<i>() *
		rhs.template at<j>();
}

template <int i, int j, typename L, typename R>
typename L::algebra::scalar_type product_at(L const&, R const&, std::false_type)
{
	return 0.0;
}

template <typename List>
struct summation
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type perform(L const& lhs, R const& rhs);
};

template <>
struct summation<list<>>
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type perform(L const&, R const&);
};

template <int index, typename L, typename R>
typename L::algebra::scalar_type summation<list<>>::perform(L const&, R const&)
{
	return 0.0;
}

template <typename List>
template <int index, typename L, typename R>
typename L::algebra::scalar_type summation<List>::perform(
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

	return product_at<i, j>(lhs, rhs, found<typename R::list, j>()) +
		summation<typename List::next>::template perform<index>(lhs, rhs);
}
/// \endcond

template <typename L, typename R>
product<L, R>::product(L const& lhs, R const& rhs)
	: lhs(lhs), rhs(rhs)
{
}

template <typename L, typename R>
template <int index>
typename L::algebra::scalar_type product<L, R>::at() const
{
	// delegate computation in order to use partial template specialization
	return summation<typename L::list>::template perform<index>(lhs, rhs);
}

template <typename L, typename R>
inline product<L, R> operator*(L const& lhs, R const& rhs)
{
	return product<L, R>(lhs, rhs);
}

}

#endif
