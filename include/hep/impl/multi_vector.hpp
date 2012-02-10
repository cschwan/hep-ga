#ifndef HEP_IMPLEMENTATION_MULTI_VECTOR_HPP
#define HEP_IMPLEMENTATION_MULTI_VECTOR_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011-2012  Christopher Schwan
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

#include <hep/multi_vector.hpp>
#include <hep/utils/binomial_coefficient.hpp>
#include <hep/utils/num_of_components.hpp>
#include <hep/utils/trailing_zeroes.hpp>

namespace hep
{

template <typename T, std::size_t P, std::size_t Q, std::size_t L>
template <typename ... Args>
multi_vector<T, P, Q, L>::multi_vector(Args ... components)
	// initialize components with given arguments; if there are less arguments
	// than m_components has, the remaining elements will be set to zero
	: components{components ...}
{
}

template <typename T, std::size_t P, std::size_t Q, std::size_t L>
template <std::size_t N>
multi_vector<T, P, Q, L>::multi_vector(
	multi_vector<T, P, Q, N> const& object
) {
	std::size_t index = 0;

	std::size_t bits = L;
	std::size_t next_bits;

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
		std::size_t source_index = num_of_components(P + Q, N & (grade - 1));

		// is that grade contained in object?
		bool non_zero = (grade & N) != 0;

		// copy components or zeroes for the length computed before
		for (std::size_t i = 0; i != length; ++i)
		{
			components[i + index] =
				non_zero ? object[source_index + i] : T(0.0);
		}

		bits = next_bits;
		index += length;
	}
	while (next_bits != 0);
}

template <typename T, std::size_t P, std::size_t Q, std::size_t L>
T& multi_vector<T, P, Q, L>::operator[](std::size_t index)
{
	return components[index];
}

template <typename T, std::size_t P, std::size_t Q, std::size_t L>
T const& multi_vector<T, P, Q, L>::operator[](std::size_t index) const
{
	return components[index];
}

}

#endif
