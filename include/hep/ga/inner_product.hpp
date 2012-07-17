#ifndef HEP_GA_INNER_PRODUCT_HPP
#define HEP_GA_INNER_PRODUCT_HPP

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

#include <hep/ga/utils/pop_count.hpp>
#include <hep/ga/common_product.hpp>
#include <hep/ga/inline.hpp>

namespace hep
{

/**
 * \ingroup predicates
 *
 * Predicate for the inner product.
 *
 * \see inner_prod()
 */
struct inner_product_predicate
{
	static constexpr bool check(int lhs, int rhs)
	{
#define grade_lhs hep::pop_count(lhs)
#define grade_rhs hep::pop_count(rhs)
#define grade_result hep::pop_count(lhs ^ rhs)

		// check if resultant grade is the smallest possible one
		return grade_result == ((grade_lhs > grade_rhs) ?
			(grade_lhs - grade_rhs) : (grade_rhs - grade_lhs));

#undef grade_result
#undef grade_rhs
#undef grade_lhs
	}
};

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Expression class for inner products.
 */
template <typename L, typename R>
using inner_product = common_product<inner_product_predicate, L, R>;

/**
 * Function returning an expression object for the inner product of expressions
 * \c lhs and \c rhs. For blades \f$ A_n \f$ and \f$ B_m \f$ of grade \f$ n,
 * m \f$ the inner product is defined as
 * \f[
 *     A_n \cdot B_m = \left\langle A_n B_m \right\rangle_{|n - m|}
 * \f]
 * i.e. it is the lowest grade element of the geometric product.
 */
template <typename L, typename R>
hep_inline inner_product<L, R> inner_prod(L const& lhs, R const& rhs)
{
	return inner_product<L, R>(lhs, rhs);
}

/**
 * @}
 */

}

#endif
