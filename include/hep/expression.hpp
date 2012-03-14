#ifndef HEP_EXPRESSION_HPP
#define HEP_EXPRESSION_HPP

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
 * Base-class for all objects which may be expressions.
 */
template <typename A, typename L>
class expression
{
	static_assert (L::size() != 0, "list does not contain any components");

public:
	/**
	 * Algebra of the expression. See hep::algebra.
	 */
	typedef A algebra;

	/**
	 * The component list of the expression.
	 */
	typedef L list;
};

}

#endif
