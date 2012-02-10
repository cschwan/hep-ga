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

#include <hep/grade.hpp>

namespace hep
{

template
	<std::size_t N, typename T, std::size_t P, std::size_t Q, std::size_t L>
inline multi_vector<T, P, Q, N> grade(multi_vector<T, P, Q, L> const& mv)
{
	return multi_vector<T, P, Q, N>(mv);
}

}

#endif
