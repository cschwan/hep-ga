#ifndef HEP_INNER_PRODUCT_HPP
#define HEP_INNER_PRODUCT_HPP

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

#include <hep/common_product.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Predicate for inner products, see inner_prod().
 */
struct inner_product_predicate
{
	/**
	 * Checks if for two expressions \c l and \c r the combination of
	 * <tt>l.at(lhs) * r.at(rhs)</tt> contributes to the inner product.
	 */
	static constexpr bool check(int lhs, int rhs);
};

constexpr bool inner_product_predicate::check(int lhs, int rhs)
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
 * Expression class for inner products. For blades \f$ A_n \f$ and \f$ B_m \f$
 * of grade \f$ n, m \f$ the inner product is defined as
 * \f[
 *     A_n \cdot B_m = \left< A_n B_m \right>_{|n - m|}
 * \f]
 * i.e. it is the lowest grade element of the geometric product.
 */
template <typename L, typename R>
using inner_product = common_product<inner_product_predicate, L, R>;

/**
 * Product operator returning an expression object for the inner product of
 * expressions \c lhs and \c rhs.
 */
template <typename L, typename R>
inner_product<L, R> inner_prod(L const& lhs, R const& rhs);

/**
 * @}
 */

}

#include <hep/impl/inner_product.hpp>

#endif
