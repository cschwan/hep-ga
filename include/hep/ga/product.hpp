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
 * Predicate for the \ref product expression class.
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
 * \ingroup expressions
 *
 * Expression class for geometric products.
 *
 * \see operator*()
 */
template <typename L, typename R>
using product = common_product<product_predicate, L, R>;

/**
 * \ingroup main
 *
 * Returns the geometric product for expressions \c lhs and \c rhs.
 *
 * Let \f$ L \f$ be the expression \c lhs and \f$ R \f$ be \c rhs. Then the
 * geometric product is defined in terms of blades as
 * \f[
 *     L R = \sum_{l,r} \sum_{j=0}^{\min (l,r)} \langle \langle L \rangle_l
 *           \langle R \rangle_r \rangle_{|l-r|+2j}
 * \f]
 */
template <typename L, typename R>
hep_inline product<L, R> operator*(L const& lhs, R const& rhs)
{
	return product<L, R>(lhs, rhs);
}

}

#endif
