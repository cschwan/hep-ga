#ifndef HEP_GA_UNARY_EXPRESSION_HPP
#define HEP_GA_UNARY_EXPRESSION_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2012,2016  Christopher Schwan
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

#include <hep/ga/expression.hpp>
#include <hep/ga/expression_ref.hpp>
#include <hep/ga/inline.hpp>

#include <type_traits>

namespace hep
{

/**
 * \ingroup expressions
 *
 * Parent class for all unary operations. The operand of type \c E must be an
 * \ref expression. The component list \c L of the resultant expression must be
 * a \ref list.
 */
template <typename E, typename L>
class unary_expression : public expression<typename E::algebra, L>
{
public:
	/**
	 * Constructor. This sets the operand \c expr.
	 */
	hep_inline unary_expression(E const& expr)
		: expr(expr)
	{
	}

protected:
	/**
	 * The operand of this expression.
	 */
	expression_ref<E> expr;
};

}

#endif
