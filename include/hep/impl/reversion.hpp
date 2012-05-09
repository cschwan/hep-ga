#ifndef HEP_IMPL_REVERSION_HPP
#define HEP_IMPL_REVERSION_HPP

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

#include <hep/utils/pop_count.hpp>
#include <hep/inline.hpp>
#include <hep/reversion.hpp>

namespace hep
{

template <typename E>
hep_inline reversion<E>::reversion(E const& expr)
	: expr(expr)
{
}

template <typename E>
template <int index>
hep_inline typename E::algebra::scalar_type reversion<E>::at() const
{
	constexpr int grade = pop_count(index);
	constexpr int sign = (((((grade * (grade - 1)) / 2) % 2) == 1) ? -1 : 1);

	return typename E::algebra::scalar_type(sign) * expr.template at<index>();
}

template <typename E>
hep_inline reversion<E> reverse(E const& expr)
{
	return reversion<E>(expr);
}

}

#endif
