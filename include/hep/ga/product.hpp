#ifndef HEP_GA_PRODUCT_HPP
#define HEP_GA_PRODUCT_HPP

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

#include <hep/ga/common_product.hpp>
#include <hep/ga/inline.hpp>

namespace hep
{

/**
 * \ingroup predicates
 *
 * Predicate for the geometric product.
 *
 * \see operator*()
 */
struct product_predicate
{
	static constexpr bool check(int, int)
	{
		// include every possible component
		return true;
	}
};

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Expression class for geometric products.
 */
template <typename L, typename R>
using product = common_product<product_predicate, L, R>;

/**
 * Operator returning an expression object for the geometric product of
 * expressions \c lhs and \c rhs. The geometric product for two blades \f$ A_n
 * \f$ and \f$ B_m \f$ is written as \f$ A_n B_m \f$ and is computed
 * component-wise by making use of of the contraction rule for basis vectors.
 * For example, the geometric products of two vectors \f$ e_1, e_2 \in
 * \mathcal{G}(1,1) \f$ are:
 *   - \f$ e_1 e_2 = e_1 \wedge e_2 \f$
 *   - \f$ e_2 e_1 = - e_1 \wedge e_2 \f$
 *   - \f$ e_1 e_1 = 1 \f$
 *   - \f$ e_2 e_2 = -1 \f$
 */
template <typename L, typename R>
hep_inline product<L, R> operator*(L const& lhs, R const& rhs)
{
	return product<L, R>(lhs, rhs);
}

/**
 * @}
 */

}

#endif
