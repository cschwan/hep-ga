#ifndef HEP_UTILS_GRADE_LIST_PRODUCT_HPP
#define HEP_UTILS_GRADE_LIST_PRODUCT_HPP

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

#include <hep/utils/trailing_zeroes.hpp>

#include <cstddef>

namespace hep
{

/// \cond DOXYGEN_IGNORE
constexpr std::size_t recursive_grade_list_product(
	std::size_t list_2,
	std::size_t list_a,
	std::size_t list_b,
	std::size_t n
) {
// remove least significant bit (lsb) in list_a, save result in hep_next_list_a
#define hep_next_list_a (list_a & (list_a - 1))

// remove lsb in list_b and save result in hep_next_list_b
#define hep_next_list_b (list_b & (list_b - 1))

// compute grade represented by lsb in list_a
#define hep_grade_a (hep::trailing_zeroes(list_a ^ hep_next_list_a))

// compute grade represented by lsb in list_b
#define hep_grade_b (hep::trailing_zeroes(list_b ^ hep_next_list_b))

// compute minimum grade possible
#define hep_min_grade ((hep_grade_a > hep_grade_b) ? \
	(hep_grade_a - hep_grade_b) : (hep_grade_b - hep_grade_a))

#define hep_grade_sum (hep_grade_a + hep_grade_b)

// compute maximum grade possible
#define hep_max_grade ((hep_grade_sum > n) ? (2 * n - hep_grade_sum) : \
	hep_grade_sum)

// generate every grade between min/max in steps of two
#define hep_grade_list_ab ((0x55555555 << hep_min_grade) & \
	((1 << (hep_max_grade + 1)) - 1))

#define hep_finished ((hep_next_list_a == 0) && (hep_next_list_b == 0))

	return hep_grade_list_ab | (hep_finished ? 0 : recursive_grade_list_product(
		list_2,
		((hep_next_list_b == 0) ? hep_next_list_a : list_a),
		((hep_next_list_b != 0) ? hep_next_list_b : list_2),
		n
	));

#undef hep_finished
#undef hep_grade_list_ab
#undef hep_max_grade
#undef hep_grade_sum
#undef hep_min_grade
#undef hep_grade_b
#undef hep_grade_a
#undef hep_next_list_b
#undef hep_next_list_a
}
/// \endcond

/**
 * Returns the grade (bit-)list of the product of operands \c list_1 and \c
 * list_2.
 */
constexpr std::size_t grade_list_product(
	std::size_t list_1,
	std::size_t list_2,
	std::size_t dimension
) {
	return recursive_grade_list_product(
		list_2,
		list_1,
		list_2,
		dimension
	);
}

}

#endif
