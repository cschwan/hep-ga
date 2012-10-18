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
 * Predicate for the \ref inner_product expresson class.
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
 * \ingroup expressions
 *
 * Expression class for inner products.
 *
 * \see inner_prod()
 */
template <typename L, typename R>
using inner_product = common_product<inner_product_predicate, L, R>;

/**
 * \ingroup main
 *
 * Returns the inner product (dot product) for expressions \c lhs and \c rhs.
 *
 * Let \c lhs be the expression \f$ L \f$ and \c rhs be \f$ R \f$. Then the
 * inner product is defined as
 * \f[
 *     L \cdot R = \sum_{l,r} \langle \langle L \rangle_l \langle R \rangle_r
 *                 \rangle_{|l-r|}
 * \f]
 * If both \f$ L \f$ and \f$ R \f$ are vectors with components \f$ L_i \f$ and
 * \f$ R_j \f$, the inner product is the well-known scalar-product from vector
 * calculus:
 * \f[
 *    L_i e^i \cdot R_j e^j = L_i R^i
 * \f]
 */
template <typename L, typename R>
hep_inline inner_product<L, R> inner_prod(L const& lhs, R const& rhs)
{
	return inner_product<L, R>(lhs, rhs);
}

}

#endif
