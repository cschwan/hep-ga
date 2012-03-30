#ifndef HEP_IMPL_SELECTION_HPP
#define HEP_IMPL_SELECTION_HPP

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

#include <hep/selection.hpp>

namespace hep
{

template <typename E, int... indices>
selection<E, indices...>::selection(E const& expr)
	: expr(expr)
{
}

template <typename E, int... indices>
template <int index>
typename E::algebra::scalar_type selection<E, indices...>::at() const
{
	static_assert (find<list<indices...>>(index) != -1,
		"required component does not exist");

	return expr.template at<index>();
}

template <int... indices, typename E>
selection<E, indices...> select(E const& expr)
{
	return selection<E, indices...>(expr);
}

}

#endif
