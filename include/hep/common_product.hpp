#ifndef HEP_COMMON_PRODUCT_HPP
#define HEP_COMMON_PRODUCT_HPP

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

#include <hep/list/multiply.hpp>
#include <hep/binary_expression.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 */

/**
 * List containing the components for the product of subexpressions of type \c L
 * and \c R with predicate \c P.
 */
template <typename P, typename L, typename R>
using product_list =
	typename multiply<typename L::list, typename R::list, P>::type;

/**
 * Parent class for geometric product-like product expressions. The product is
 * computed for a subexpression of types \c L and \c R. The specific form is
 * determined by a predicate \c P. This must be a class containing a public
 * static constexpr function called \c check taking two integers representing
 * the indices of the multiplied basis blades and returning a boolean signaling
 * whether this component product is included or not:
 * \code
 * struct my_predicate
 * {
 *     static constexpr bool check(int lhs, int rhs)
 *     {
 *         // check if l.at<lhs>() * r.at<rhs>() contributes to the product.
 *         // this is usually done by checking if the resulting grade lhs ^ rhs
 *         // is included in the product
 *     }
 * };
 * \endcode
 * The fact that all type of products can be written in this general form with
 * a special predicate was first noticed by Jaap Suter \cite JaapSuterVital.
 */
template <typename P, typename L, typename R>
class common_product : public binary_expression<L, R, product_list<P, L, R>>
{
public:
	/**
	 * Constructor. This simply calls the contructor of the parent class.
	 */
	common_product(L const& lhs, R const& rhs);

	/**
	 * Performs the computation of the component represented by \c index and
	 * returns it.
	 */
	template <int index>
	typename L::algebra::scalar_type at() const;
};

/**
 * @}
 */

}

#include <hep/impl/common_product.hpp>

#endif
