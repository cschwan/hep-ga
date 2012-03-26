#ifndef HEP_IMPL_GRADE_HPP
#define HEP_IMPL_GRADE_HPP

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
#include <hep/grade.hpp>
#include <hep/inline.hpp>

namespace hep
{

template <typename E, int... grades>
hep_inline grade_projection<E, grades...>::grade_projection(E const& expr)
	: expr(expr)
{
}

template <typename E, int... grades>
template <int index>
hep_inline typename E::algebra::scalar_type grade_projection<E, grades...>::at()
	const
{
	static_assert (find<list>(index) != -1, "component does not exist");

	return expr.template at<index>();
}

template <int... grades, typename E>
hep_inline grade_projection<E, grades...> grade(E const& expr)
{
	return grade_projection<E, grades...>(expr);
}

}

#endif
