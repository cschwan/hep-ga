#ifndef HEP_IMPL_COMMON_SUM_HPP
#define HEP_IMPL_COMMON_SUM_HPP

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

#include <hep/list/find.hpp>
#include <hep/common_sum.hpp>
#include <hep/inline.hpp>

namespace
{

template <bool enable_lhs, bool enable_rhs, bool sign>
struct conditional_common_sum;

template <>
struct conditional_common_sum<true, true, true>
{
	template <int index, typename L, typename R>
	static hep_inline typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return lhs.template at<index>() - rhs.template at<index>();
	}
};

template <>
struct conditional_common_sum<true, true, false>
{
	template <int index, typename L, typename R>
	static hep_inline typename L::algebra::scalar_type at(
		L const& lhs,
		R const& rhs
	) {
		return lhs.template at<index>() + rhs.template at<index>();
	}
};

template <>
template <bool sign>
struct conditional_common_sum<true, false, sign>
{
	template <int index, typename L, typename R>
	static hep_inline typename L::algebra::scalar_type at(
		L const& lhs,
		R const&
	) {
		return lhs.template at<index>();
	}
};

template <>
struct conditional_common_sum<false, true, true>
{
	template <int index, typename L, typename R>
	static hep_inline typename L::algebra::scalar_type at(
		L const&,
		R const& rhs
	) {
		return -rhs.template at<index>();
	}
};

template <>
struct conditional_common_sum<false, true, false>
{
	template <int index, typename L, typename R>
	static hep_inline typename L::algebra::scalar_type at(
		L const&,
		R const& rhs
	) {
		return rhs.template at<index>();
	}
};

}

namespace hep
{

template <bool sign, typename L, typename R>
hep_inline common_sum<sign, L, R>::common_sum(L const& lhs, R const& rhs)
	: binary_expression<L, R, sum_list<L, R>>(lhs, rhs)
{
}

template <bool sign, typename L, typename R>
template <int index>
hep_inline typename L::algebra::scalar_type common_sum<sign, L, R>::at() const
{
#define enable_lhs (find<typename L::list>(index) != -1)
#define enable_rhs (find<typename R::list>(index) != -1)

	return conditional_common_sum<enable_lhs, enable_rhs, sign>::
		template at<index>(this->lhs, this->rhs);

#undef enable_rhs
#undef enable_lhs
}

}

#endif
