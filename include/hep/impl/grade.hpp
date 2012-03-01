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
#include <hep/utils/binomial_coefficient.hpp>
#include <hep/utils/num_of_components.hpp>
#include <hep/utils/trailing_zeroes.hpp>

namespace hep
{

template
	<std::size_t N, typename T, std::size_t P, std::size_t Q, std::size_t L>
multi_vector<T, P, Q, N> grade(multi_vector<T, P, Q, L> const& mv)
{
	std::size_t index = 0;

	std::size_t bits = N;
	std::size_t next_bits;

	multi_vector<T, P, Q, N> result;

	// iterate over every grade, represented by the position of the only bit set
	// in `grade'
	do
	{
		// remove least significant bit in `bits'
		next_bits = bits & (bits - 1);

		// contains a single bit whose position represents the grade
		std::size_t grade = bits ^ next_bits;

		// get number of components for the current grade
		std::size_t length =
			binomial_coefficient(P + Q, trailing_zeroes(grade));

		// index where we will copy from
		std::size_t source_index = num_of_components(P + Q, L & (grade - 1));

		// is that grade contained in object?
		bool non_zero = (grade & L) != 0;

		// copy components or zeroes for the length computed before
		for (std::size_t i = 0; i != length; ++i)
		{
			result[i + index] = non_zero ? mv[source_index + i] : T(0.0);
		}

		bits = next_bits;
		index += length;
	}
	while (next_bits != 0);

	return result;
}

}

#endif
