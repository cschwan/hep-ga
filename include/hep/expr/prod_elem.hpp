#ifndef HEP_EXPR_PROD_ELEM_HPP
#define HEP_EXPR_PROD_ELEM_HPP

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

#include <hep/utils/sign_table.hpp>

namespace hep
{

template <bool condition>
struct prod_elem
{
	template <int i, int j, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <bool condition>
template <int i, int j, typename L, typename R>
HEP_INLINE typename L::algebra::scalar_type prod_elem<condition>::at(
	L const& lhs,
	R const& rhs
) {
	return sign_table<typename L::algebra, i, j>() * lhs.template at<i>() *
		rhs.template at<j>();
}

/// \cond DOXYGEN_IGNORE
template <>
struct prod_elem<false>
{
	template <int i, int j, typename L, typename R>
	static typename L::algebra::scalar_type at(L const&, R const&);
};

template <int i, int j, typename L, typename R>
HEP_INLINE typename L::algebra::scalar_type prod_elem<false>::at(
	L const&,
	R const&
) {
	return 0.0;
}
/// \endcond

}

#endif
