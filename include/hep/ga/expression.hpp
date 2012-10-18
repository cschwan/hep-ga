#ifndef HEP_GA_EXPRESSION_HPP
#define HEP_GA_EXPRESSION_HPP

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

namespace hep
{

/**
 * \defgroup expressions Expressions
 */

/**
 * \ingroup expressions
 *
 * Parent-class for all expressions with \ref algebra \c A and \ref list
 * "component list" \c L. Inheriting classes are valid expressions if the
 * following member function is implemented:
 * \code
 * template <int index>
 * typename L::algebra::scalar_type at() const;
 * \endcode
 * For performance reasons the definition of \c at must also be defined inline
 * with \c hep_inline:
 * \code
 * template <int index>
 * hep_inline typename L::algebra::scalar_type at() const
 * {
 *     static_cast (is_valid(index), "component does not exist");
 *
 *     // ...
 * }
 * \endcode
 * The function \c at is used to evaluate the expression for the component
 * specified with \c index. If the expression is a composed one, i.e. \c at
 * calls \c at from another expression-object, and it limits the range of valid
 * components (e.g. a grade operator) it is responsible for checking if \c index
 * is valid. This is done using \c static_assert as shown above and a custom
 * function \c is_valid.
 *
 * Using compile-time constant component indices is the key for efficient
 * numerical operations in geometric algebra and was first used by Jaap Suter
 * \cite JaapSuterVital.
 */
template <typename A, typename L>
class expression
{
	static_assert (L::size != 0, "expression without any components");

public:
	/**
	 * The algebra of this expression.
	 */
	typedef A algebra;

	/**
	 * The component list of this expression.
	 */
	typedef L list;
};

}

#endif
