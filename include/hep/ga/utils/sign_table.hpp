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
constexpr int sign_table(int i, int j, int grade)
{
	int result = 1;

	for (int k = 0; k != A::dim; ++k)
	{
		bool const kth_bit_set_of_i = (i & (1 << k)) != 0;
		bool const kth_bit_set_of_j = (j & (1 << k)) != 0;

		grade -= kth_bit_set_of_i ? 1 : 0;

		bool const condition2 = kth_bit_set_of_i && (k >= A::p);
		bool const condition3 = grade & 1;

		result *= (kth_bit_set_of_j && (condition2 != condition3)) ? -1 : 1;
	}

	return result;
}

}

namespace hep
{

/**
 * \ingroup utils
 *
 * Returns the sign for multiplication of components \c i and \c j of two
 * multi-vectors from algebra \c A.
 */
template <typename A, int i, int j>
constexpr int sign_table()
{
	// wrapping with std::integral_constant forces compile-time evaluation
	return std::integral_constant<int,
		::sign_table<A>(i, j, pop_count(i))>::value;
}

}

#endif
