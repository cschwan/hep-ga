#ifndef HEP_IMPL_INNER_PRODUCT_HPP
#define HEP_IMPL_INNER_PRODUCT_HPP

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

#include <hep/expr/prod_elem_sum.hpp>
#include <hep/expr/prod_elem_sum_list.hpp>
#include <hep/inner_product.hpp>

namespace hep
{

template <typename L, typename R>
HEP_INLINE inner_product<L, R>::inner_product(L const& lhs, R const& rhs)
	: lhs(lhs), rhs(rhs)
{
}

template <typename L, typename R>
template <int index>
HEP_INLINE typename L::algebra::scalar_type inner_product<L, R>::at() const
{
	typedef typename prod_elem_sum_list<typename L::list, typename R::list,
		inner_product_pred, index>::type List;

	return prod_elem_sum<List, inner_product_pred>::template
		at<index>(lhs, rhs);
}

template <typename L, typename R>
HEP_INLINE inner_product<L, R> inner_prod(L const& lhs, R const& rhs)
{
	return inner_product<L, R>(lhs, rhs);
}

}

#endif
