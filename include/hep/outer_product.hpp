#ifndef HEP_OUTER_PRODUCT_HPP
#define HEP_OUTER_PRODUCT_HPP

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
#include <hep/inline.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Predicate for inner products, see inner_prod().
 */
struct outer_product_predicate
{
	/**
	 * Checks if for two expressions \c l and \c r the combination of
	 * <tt>l.at(lhs) * r.at(rhs)</tt> contributes to the outer product.
	 */
	static constexpr bool check(int lhs, int rhs)
	{
		// check if resultant grade is the biggest possible one
		return pop_count(lhs ^ rhs) == (pop_count(lhs) + pop_count(rhs));
	}
};

/**
 * Expression class for outer products. For blades \f$ A_n \f$ and \f$ B_m \f$
 * of grade \f$ n, m \f$ the outer product is defined as
 * \f[
 *     A_n \wedge B_m = \left< A_n B_m \right>_{n + m}
 * \f]
 * i.e. it is the biggest grade element of the geometric product.
 */
template <typename L, typename R>
using outer_product = common_product<outer_product_predicate, L, R>;

/**
 * Product operator returning an expression object for the outer product of
 * expressions \c lhs and \c rhs.
 */
template <typename L, typename R>
hep_inline outer_product<L, R> operator^(L const& lhs, R const& rhs)
{
	return outer_product<L, R>(lhs, rhs);
}

/**
 * @}
 */

}

#endif
