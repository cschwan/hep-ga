#ifndef HEP_PRODUCT_HPP
#define HEP_PRODUCT_HPP

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

#include <hep/expr/predicates.hpp>
#include <hep/list/multiply.hpp>
#include <hep/expression.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup expressions
 */

/**
 * Expression class for geometric products. The geometric product for two blades
 * \f$ A_n \f$ and \f$ B_m \f$ is written as \f$ A_n B_m \f$ and is computed
 * component-wise by making use of of the contraction rule for basis vectors.
 * For example, the geometric products of two vectors \f$ \gamma_1, \gamma_2
 * \in \mathcal{G}_{3,0} \f$ is: \f$ \gamma_1 \gamma_1 = 1 \f$.
 */
template <typename L, typename R>
class product : public expression<typename L::algebra,
	typename multiply<product_pred, typename L::list, typename R::list>::type>
{
	static_assert (std::is_same<typename L::algebra, typename
		R::algebra>::value,
		"product of multi-vectors from different algebras requested");

public:
	/**
	 * Constructor for a product expression computing the geometric product of
	 * the expression \c lhs with \c rhs.
	 */
	product(L const& lhs, R const& rhs);

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	typename L::algebra::scalar_type at() const;

private:
	/**
	 * Left-hand side expression.
	 */
	L const& lhs;

	/**
	 * Right-hand side expression.
	 */
	R const& rhs;
};

/**
 * Product operator returning an expression object for the geometric product of
 * expressions \c lhs and \c rhs.
 */
template <typename L, typename R>
product<L, R> operator*(L const& lhs, R const& rhs);

/**
 * @}
 */

}

#include <hep/impl/product.hpp>

#endif
