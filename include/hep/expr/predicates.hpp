#ifndef HEP_EXPR_PREDICATES_HPP
#define HEP_EXPR_PREDICATES_HPP

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

#include <hep/utils/pop_count.hpp>

namespace hep
{

/**
 * \addtogroup internals
 * @{
 */

/**
 * Predicate for geometric products, see operator*().
 */
struct product_pred
{
	/**
	 * Checks if for two expressions \c l and \c r the combination of
	 * <tt>l.at(lhs) * r.at(rhs)</tt> contributes to the geometric product.
	 */
	static constexpr bool check(int, int);
};

constexpr bool product_pred::check(int, int)
{
	return true;
}

/**
 * Predicate for inner products, see inner_prod().
 */
struct inner_product_pred
{
	/**
	 * Checks if for two expressions \c l and \c r the combination of
	 * <tt>l.at(lhs) * r.at(rhs)</tt> contributes to the inner product.
	 */
	static constexpr bool check(int lhs, int rhs);
};

constexpr bool inner_product_pred::check(int lhs, int rhs)
{
#define hep_grade_lhs pop_count(lhs)
#define hep_grade_rhs pop_count(rhs)
#define hep_grade_result pop_count(lhs ^ rhs)

	// check if resultant grade is the smallest possible one
	return hep_grade_result == ((hep_grade_lhs > hep_grade_rhs) ?
		(hep_grade_lhs - hep_grade_rhs) : (hep_grade_rhs - hep_grade_lhs));

#undef hep_grade_result
#undef hep_grade_rhs
#undef hep_grade_lhs
}

/**
 * @}
 */

}

#endif
