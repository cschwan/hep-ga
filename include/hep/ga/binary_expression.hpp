#ifndef HEP_GA_BINARY_EXPRESSION_HPP
#define HEP_GA_BINARY_EXPRESSION_HPP

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
 * Parent class for all binary operations. Both the left-hand operand of type
 * \c L and the right-hand operand of type \c R must be an \ref expression. The
 * component list \c List of the resultant expression must be a \ref list.
 */
template <typename L, typename R, typename List>
class binary_expression : public expression<typename L::algebra, List>
{
	static_assert (
		std::is_same<typename L::algebra, typename R::algebra>::value,
		"expression for different algebras is undefined"
	);

public:
	/**
	 * Constructor. This sets the left- and right-hand operands \c lhs and
	 * \c rhs.
	 */
	hep_inline binary_expression(L const& lhs, R const& rhs)
		: lhs(lhs)
		, rhs(rhs)
	{
	}

protected:
	/**
	 * Left-hand operand of this expression.
	 */
	expression_ref<L> lhs;

	/**
	 * Right-hand operand of this expression.
	 */
	expression_ref<R> rhs;
};

}

#endif
