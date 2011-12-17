#ifndef HEP_IMPLEMENTATION_POP_COUNT_HPP
#define HEP_IMPLEMENTATION_POP_COUNT_HPP

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

#include <hep/utils/binomial_coefficient.hpp>

#include <cstddef>

namespace hep
{

/// \cond DOXYGEN_IGNORE
constexpr std::size_t num_of_components_loop(
	std::size_t n,
	std::size_t grade_list,
	std::size_t k
) {
#define end_of_recursion ((1 << k) > grade_list)
#define in_grade_list ((1 << k) & grade_list)
#define do_recursion (num_of_components_loop(n, grade_list, k + 1))

	return (
		end_of_recursion
			? 0
			: ((in_grade_list ? binomial_coefficient(n, k) : 0) + do_recursion)
	);

#undef do_recursion
#undef in_grade_list
#undef end_of_recursion
}
/// \endcond

/**
 * Returns the number of components needed for multi-vector with the specified
 * \c grade_list and dimension \c n.
 */
constexpr std::size_t num_of_components(std::size_t n, std::size_t grade_list)
{
	return num_of_components_loop(n, grade_list, 0);
}

}

#endif
