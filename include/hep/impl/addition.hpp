#ifndef HEP_IMPL_ADDITION_HPP
#define HEP_IMPL_ADDITION_HPP

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

#include <hep/addition.hpp>
#include <hep/utils/binomial_coefficient.hpp>

namespace hep
{

/**
 * 
 */
template <typename A, std::size_t L1, std::size_t L2>
multi_vector<A, L1 | L2> operator+(
	multi_vector<A, L1> const& lhs,
	multi_vector<A, L2> const& rhs
) {
	multi_vector<A, L1 | L2> result;

	std::size_t index = 0;
	std::size_t index1 = 0;
	std::size_t index2 = 0;

	for (std::size_t i = 0; i != A::dim() + 1; ++i)
	{
		// if grade is contained in neither lists, continue
		if (!((1 << i) & (L1 | L2)))
		{
			continue;
		}

		// iterate over every component of grade i
		for (std::size_t j = 0; j != binomial_coefficient(A::dim(), i); ++j)
		{
			typename A::value_type const value1 =
				(((1 << i) & L1) ? lhs[index1++] : typename A::value_type(0.0));
			typename A::value_type const value2 =
				(((1 << i) & L2) ? rhs[index2++] : typename A::value_type(0.0));

			result[index++] = value1 + value2;
		}
	}

	return result;
}

}

#endif
