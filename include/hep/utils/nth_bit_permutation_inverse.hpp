#ifndef HEP_UTILS_NTH_BIT_PERMUTATION_INVERSE_HPP
#define HEP_UTILS_NTH_BIT_PERMUTATION_INVERSE_HPP

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

#include <hep/utils/next_bit_permutation.hpp>
#include <hep/utils/pop_count.hpp>

#include <cstddef>

namespace hep
{

/// \cond DOXYGEN_IGNORE
constexpr std::size_t nth_bit_permutation_inverse_loop(
	std::size_t permutation,
	std::size_t result,
	std::size_t k
) {
#define next_permutation (next_bit_permutation(permutation))

	return (permutation == result) ? k :
		nth_bit_permutation_inverse_loop(next_permutation, result, k + 1);

#undef next_permutation
}
/// \endcond

/**
 * Returns the number of necessary bit permutations needed to yield
 * \c permutation. For example:
 *   - \f$ 0100_2 \mapsto 2 \f$
 *   - \f$ 0011_2 \mapsto 0 \f$
 *   - \f$ 0101_2 \mapsto 1 \f$
 *   - \f$ 0110_2 \mapsto 2 \f$
 *   - \f$ 1001_2 \mapsto 3 \f$
 */
constexpr std::size_t nth_bit_permutation_inverse(std::size_t permutation)
{
#define first_n_bits_set(n) ((1 << n) - 1)
#define first_bits_set first_n_bits_set(pop_count(permutation))

	return nth_bit_permutation_inverse_loop(first_bits_set, permutation, 0);

#undef first_bits_set
#undef first_n_bits_set
}

}

#endif
