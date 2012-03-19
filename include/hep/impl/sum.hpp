#ifndef HEP_IMPL_SUM_HPP
#define HEP_IMPL_SUM_HPP

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

#include <hep/sum.hpp>
#include <hep/list/find.hpp>

namespace hep
{

template <typename L, typename R>
inline sum<L, R>::sum(L const& lhs, R const& rhs)
	: lhs(lhs), rhs(rhs)
{
}

template <typename L, typename R>
template <int index>
inline typename L::algebra::scalar_type sum<L, R>::at() const
{
	// add components together. if a certain expression does not contain a
	// component represented by `index', leave it out
	return lhs_at<index>(found<typename L::list, index>()) + 
		rhs_at<index>(found<typename R::list, index>());
}

template <typename L, typename R>
template <int index>
inline typename L::algebra::scalar_type sum<L, R>::lhs_at(std::true_type) const
{
	return lhs.at<index>();
}

template <typename L, typename R>
template <int index>
inline typename L::algebra::scalar_type sum<L, R>::lhs_at(std::false_type) const
{
	return 0.0;
}

template <typename L, typename R>
template <int index>
inline typename L::algebra::scalar_type sum<L, R>::rhs_at(std::true_type) const
{
	return rhs.at<index>();
}

template <typename L, typename R>
template <int index>
inline typename L::algebra::scalar_type sum<L, R>::rhs_at(std::false_type) const
{
	return 0.0;
}

template <typename L, typename R>
inline sum<L, R> operator+(L const& lhs, R const& rhs)
{
	return sum<L, R>(lhs, rhs);
}

}

#endif
