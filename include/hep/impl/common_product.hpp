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

#include <hep/expr/prod_elem_sum.hpp>
#include <hep/expr/prod_elem_sum_list.hpp>
#include <hep/common_product.hpp>
#include <hep/inline.hpp>

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
