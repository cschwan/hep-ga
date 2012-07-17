#ifndef HEP_GA_COMMON_PRODUCT_HPP
#define HEP_GA_COMMON_PRODUCT_HPP

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

#include <hep/ga/list/list.hpp>
#include <hep/ga/list/merge.hpp>
#include <hep/ga/binary_expression.hpp>
#include <hep/ga/inline.hpp>

#include <type_traits>

namespace
{

template <typename L, typename R, typename P>
struct multiply
{
	typedef typename hep::merge<
		typename hep::merge<
			typename std::conditional<
				P::check(L::value, R::value),
				hep::list<L::value ^ R::value>,
				hep::list<>
			>::type,
			typename multiply<typename L::next, R, P>::type
		>::type,
		typename multiply<L, typename R::next, P>::type
	>::type type;
};

template <typename R, typename P>
struct multiply<hep::list<>, R, P>
{
	typedef hep::list<> type;
};

template <typename L, typename P>
struct multiply<L, hep::list<>, P>
{
	typedef hep::list<> type;
};

template <typename P, typename L, typename R>
using product_list =
	typename multiply<typename L::list, typename R::list, P>::type;

}

namespace hep
{

/**
 * \defgroup predicates Predicates for product expressions
 *
 * A predicate is a class containing a <tt>public static constexpr</tt> function
 * \c check taking two integers representing the components of the multiplied
 * multi-vectors and returning a boolean signaling whether this subexpression is
 * included or not:
 * \code
 * struct my_predicate
 * {
 *     static constexpr bool check(int lhs, int rhs)
 *     {
 *         // check if l.at<lhs>() * r.at<rhs>() contributes to the product.
 *         // this is usually done by checking if the resulting component
 *         // lhs ^ rhs is included in the product
 *     }
 * };
 * \endcode
 * The fact that all type of products can be written in this general form with
 * a special predicate was first noticed by Jaap Suter \cite JaapSuterVital.
 * Using the predicate class, the every product is calculated in the following
 * way (pseudo-code):
 * \code
 * typedef ... algebra;
 * typedef ... list_a;
 * typedef ... list_b;
 * typedef ... list_c;
 *
 * hep::expression<algebra, list_a> a;
 * hep::expression<algebra, list_b> b;
 * hep::expression<algebra, list_c> c;
 *
 * for (int i : list_a)
 * {
 *     for (int j : list_b)
 *     {
 *         if ((hep::find<list_c>(i ^j) != -1) && my_predicate::check(i, j))
 *         {
 *             c.at<i ^ j> += hep::sign_table<i, j>() * a.at<i>() * b.at<j>();
 *         }
 *     }
 * }
 * \endcode
 */

/**
 * \ingroup expressions
 *
 * Parent class for geometric product-like product expressions. The product is
 * computed for expressions of types \c L and \c R. The specific form of the
 * product is determined by a \ref predicates "predicate" \c P.
 */
template <typename P, typename L, typename R>
class common_product : public binary_expression<L, R, product_list<P, L, R>>
{
public:
	/**
	 * Constructor for a common_product of expressions \c lhs and \c rhs.
	 */
	hep_inline common_product(L const& lhs, R const& rhs)
		: binary_expression<L, R, product_list<P, L, R>>(lhs, rhs)
	{
	}

	/**
	 * Performs the computation of the component represented by \c index and
	 * returns it.
	 */
	template <int index>
	typename L::algebra::scalar_type at() const;
};

}

#include <hep/ga/impl/common_product.hpp>

#endif
