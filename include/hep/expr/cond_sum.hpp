#ifndef HEP_EXPR_COND_SUM_HPP
#define HEP_EXPR_COND_SUM_HPP

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

namespace hep
{

/// \cond DOXYGEN_IGNORE
template <bool enable_lhs, bool enable_rhs>
struct cond_sum;

template <>
struct cond_sum<true, true>
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <int index, typename L, typename R>
HEP_INLINE typename L::algebra::scalar_type cond_sum<true, true>::at(
	L const& lhs,
	R const& rhs
) {
	return lhs.template at<index>() + rhs.template at<index>();
}

template <>
struct cond_sum<true, false>
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const&);
};

template <int index, typename L, typename R>
HEP_INLINE typename L::algebra::scalar_type cond_sum<true, false>::at(
	L const& lhs,
	R const&
) {
	return lhs.template at<index>();
}

template <>
struct cond_sum<false, true>
{
	template <int index, typename L, typename R>
	static typename L::algebra::scalar_type at(L const& lhs, R const& rhs);
};

template <int index, typename L, typename R>
HEP_INLINE typename L::algebra::scalar_type cond_sum<false, true>::at(
	L const&,
	R const& rhs
) {
	return rhs.template at<index>();
}
/// \endcond

}

#endif
