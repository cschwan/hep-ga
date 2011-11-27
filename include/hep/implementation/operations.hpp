#ifndef HEP_IMPLEMENTATION_OPERATIONS_HPP
#define HEP_IMPLEMENTATION_OPERATIONS_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011  Christopher Schwan
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

#include <hep/operations.hpp>
#include <hep/sign_table.hpp>

namespace hep
{

template <typename T, std::size_t P, std::size_t Q>
multi_vector<T, P, Q> operator*(
	multi_vector<T, P, Q> const& lhs,
	multi_vector<T, P, Q> const& rhs
) {
	multi_vector<T, P, Q> result;
	constexpr std::size_t no_of_components = (1 << (P + Q));

	for (std::size_t i = 0; i != no_of_components; ++i)
	{
		for (std::size_t j = 0; j != no_of_components; ++j)
		{
			result[i ^ j] += sign_table<T, P, Q>(i, j) * lhs[i] * rhs[j];
		}
	}

	return result;
}

}

#endif
