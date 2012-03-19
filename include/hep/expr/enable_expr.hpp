#ifndef HEP_EXPR_ENABLE_EXPR_HPP
#define HEP_EXPR_ENABLE_EXPR_HPP

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

#include <hep/expression.hpp>

namespace hep
{

/**
 * 
 */
template <bool condition>
struct enable_expr
{
	/**
	 * 
	 */
	template <int index, typename T>
	static typename T::algebra::scalar_type at(T const& expr);
};

template <bool condition>
template <int index, typename T>
inline typename T::algebra::scalar_type enable_expr<condition>::at(T const&
	expr)
{
	return expr.template at<index>();
}

/// \cond DOXYGEN_IGNORE
template <>
struct enable_expr<false>
{
	template <int index, typename T>
	static typename T::algebra::scalar_type at(T const&);
};

template <int index, typename T>
inline typename T::algebra::scalar_type enable_expr<false>::at(T const&)
{
	return 0.0;
}
/// \endcond

}

#endif
