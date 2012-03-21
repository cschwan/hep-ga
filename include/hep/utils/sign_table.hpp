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

#include <type_traits>

namespace hep
{

/// \cond DOXYGEN_IGNORE
template <typename A, int i, int j, int loop_k, int grade>
struct recursive_sign_table
{
#define k               (A::dim() - loop_k)
#define is_bit_set(x)   (((x) & (1 << k)) != 0)
#define i_pop_count     (grade + (is_bit_set(i) ? -1 : 0))
#define condition_1     (is_bit_set(j))
#define condition_2     (is_bit_set(i) && (k >= A::p()))
#define condition_3     (i_pop_count & 1)
#define this_sign       ((condition_1 && (condition_2 != condition_3)) ? -1 : 1)

	typedef std::integral_constant<int, this_sign *
		recursive_sign_table<A, i, j, loop_k - 1, i_pop_count>::type::value>
		type;

#undef this_sign
#undef condition_3
#undef condition_2
#undef condition_1
#undef i_pop_count
#undef is_bit_set
#undef k
};

template <typename A, int i, int j, int grade>
struct recursive_sign_table<A, i, j, 0, grade>
{
	typedef std::integral_constant<int, 1> type;
};
/// \endcond

/**
 * Returns the sign for multiplication of components \c i and \c j of two
 * multi-vectors from algebra \c A.
 */
template <typename A, int i, int j>
constexpr typename A::scalar_type sign_table()
{
	return recursive_sign_table<A, i, j, A::dim(), pop_count(i)>::type::value;
}

}

#endif
