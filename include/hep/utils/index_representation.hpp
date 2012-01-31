#ifndef HEP_UTILS_INDEX_REPRESENTATION_HPP
#define HEP_UTILS_INDEX_REPRESENTATION_HPP

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

#include <hep/utils/binomial_coefficient.hpp>
#include <hep/utils/nth_bit_permutation_inverse.hpp>

#include <cstddef>

namespace hep
{

/// \cond DOXYGEN_IGNORE
constexpr std::size_t index_representation_loop(
	std::size_t bits,
	std::size_t grade_list,
	std::size_t n,
	std::size_t k
) {
#define in_grade_list ((1 << k) & grade_list)
#define end_of_recursion (k >= pop_count(bits))
#define do_recursion index_representation_loop(bits, grade_list, n, k + 1)

	return (
		end_of_recursion
			? nth_bit_permutation_inverse(bits)
			: ((in_grade_list ? binomial_coefficient(n, k) : 0) + do_recursion)
	);

#undef do_recursion
#undef end_of_recursion
#undef in_grade_list
}
/// \endcond

/**
 * Converts the bit representation \c bits for a component of a multi-vector to
 * an index representation. The \c dimension holds the sum of basis-vectors
 * \f$ P + Q \f$, the \c grade_list contains the contained basi-blades of the
 * multi-vector, for example:
 *   - \f$ 0001_2 \, \hat{=} \f$ multi-vector containing scalar
 *   - \f$ 0010_2 \, \hat{=} \f$ multi-vector containing vectors
 *   - \f$ 0011_2 \, \hat{=} \f$ multi-vector containing scalar and vectors
 *   - \f$ 0100_2 \, \hat{=} \f$ multi-vector containing trivectors
 */
constexpr std::size_t index_representation(
	std::size_t bits,
	std::size_t grade_list,
	std::size_t dimension
) {
	return index_representation_loop(bits, grade_list, dimension, 0);
}

}

#endif
