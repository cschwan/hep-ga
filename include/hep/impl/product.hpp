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

#include <hep/common_product.hpp>
#include <hep/inline.hpp>

namespace hep
{

template <typename L, typename R>
hep_inline product<L, R> operator*(L const& lhs, R const& rhs)
{
	return product<L, R>(lhs, rhs);
}

}

#endif
