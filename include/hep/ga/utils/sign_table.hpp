#ifndef HEP_GA_UTILS_SIGN_TABLE_HPP
#define HEP_GA_UTILS_SIGN_TABLE_HPP

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

#include <hep/ga/utils/pop_count.hpp>

#include <type_traits>

namespace
{

template <typename A>
constexpr int sign_table(int i, int j, int k, int grade)
{
#define kth_bit_set(x)  (((x) & (1 << k)) != 0)
#define pop_count_i     (grade + (kth_bit_set(i) ? -1 : 0))
#define condition_1     (kth_bit_set(j))
#define condition_2     (kth_bit_set(i) && (k >= A::p))
#define condition_3     (pop_count_i & 1)
#define this_sign       ((condition_1 && (condition_2 != condition_3)) ? -1 : 1)

	return (k == A::dim) ? 1 : this_sign *
		sign_table<A>(i, j, k + 1, pop_count_i);

#undef this_sign
#undef condition_3
#undef condition_2
#undef condition_1
#undef pop_count_i
#undef kth_bit_set
};

}

namespace hep
{

/**
 * \addtogroup utils
 * @{
 */

/**
 * Returns the sign for multiplication of components \c i and \c j of two
 * multi-vectors from algebra \c A.
 */
template <typename A, int i, int j>
constexpr int sign_table()
{
	// wrapping with std::integral_constant forces compile-time evaluation
	return std::integral_constant<int,
		::sign_table<A>(i, j, 0, pop_count(i))>::value;
}

/**
 * @}
 */

}

#endif
