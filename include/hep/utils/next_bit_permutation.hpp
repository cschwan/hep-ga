#ifndef HEP_IMPLEMENTATION_NEXT_BIT_PERMUTATION_HPP
#define HEP_IMPLEMENTATION_NEXT_BIT_PERMUTATION_HPP

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

#include <cstddef>

namespace hep
{

/**
 * Computes the next lexicographical bit permutation with the same number of
 * bits set in \c permutation. For example, this function realizes the following
 * mapping:
 *   - \f$ 0001_2 \mapsto 0010_2 \f$
 *   - \f$ 0010_2 \mapsto 0100_2 \f$
 *   - \f$ 1001_2 \mapsto 1010_2 \f$
 */
constexpr std::size_t next_bit_permutation(std::size_t permutation)
{
#define v permutation
#define t ((v | (v - 1)) + 1)

	return t | ((((t & -t) / (v & -v)) >> 1) - 1);

#undef t
#undef v
}

}

#endif
