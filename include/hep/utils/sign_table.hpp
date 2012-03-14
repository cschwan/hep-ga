#ifndef HEP_UTILS_SIGN_TABLE_HPP
#define HEP_UTILS_SIGN_TABLE_HPP

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

#include <hep/utils/pop_count.hpp>

namespace hep
{

/// \cond DOXYGEN_IGNORE
template <typename A>
constexpr int recursive_sign_table(int i, int j, int k, int grade)
{
	// constexpr functions do not support variables, so we have to use the
	// preprocessor instead to write readable code
#define is_bit_set(x)   (((x) & (1 << k)) != 0)
#define i_pop_count     (grade + (is_bit_set(i) ? -1 : 0))
#define condition_1     (is_bit_set(j))
#define condition_2     (is_bit_set(i) && (k >= A::p()))
#define condition_3     (i_pop_count & 1)

	// k is the loop variable; we start with 0 and end the recursion if k is P+Q
	return (k == A::dim()) ? 1 : (
		((condition_1 && (condition_2 != condition_3)) ? -1 : 1) *
		recursive_sign_table<A>(i, j, k + 1, i_pop_count)
	);

#undef condition_3
#undef condition_2
#undef condition_1
#undef i_pop_count
#undef is_bit_set
}
/// \endcond

/**
 * Returns the sign for multiplication of components \c i and \c j of two
 * multi-vectors from algebra \c A.
 */
template <typename A>
constexpr typename A::scalar_type sign_table(int i, int j)
{
	return typename A::scalar_type(
		recursive_sign_table<A>(i, j, 0, pop_count(i))
	);
}

}

#endif
