#ifndef HEP_GA_OUTER_PRODUCT_HPP
#define HEP_GA_OUTER_PRODUCT_HPP

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
 * Predicate for the \ref outer_product expresson class.
 */
struct outer_product_predicate
{
	static constexpr bool check(int lhs, int rhs)
	{
		// check if resulting grade is the biggest possible one
		return hep::pop_count(lhs ^ rhs) ==
			(hep::pop_count(lhs) + hep::pop_count(rhs));
	}
};

/**
 * \ingroup expressions
 *
 * Expression class for outer products.
 *
 * \see operator^()
 */
template <typename L, typename R>
using outer_product = common_product<outer_product_predicate, L, R>;

/**
 * \ingroup main
 *
 * Returns the outer product for expressions \c lhs and \c rhs.
 *
 * Let \c lhs be the expression \f$ L \f$ and \c rhs be \f$ R \f$. Then the
 * outer product is defined as
 * \f[
 *     L \wedge R = \sum_{l,r} \langle \langle L \rangle_l \langle R \rangle_r
 *                  \rangle_{l+r}
 * \f]
 */
template <typename L, typename R>
hep_inline outer_product<L, R> operator^(L const& lhs, R const& rhs)
{
	return outer_product<L, R>(lhs, rhs);
}

}

#endif
