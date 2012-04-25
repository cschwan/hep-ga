#ifndef HEP_NEGATION_HPP
#define HEP_NEGATION_HPP

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

#include <hep/expression.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Expression class for negation.
 */
template <typename R>
class negation : public expression<typename R::algebra, typename R::list>
{
public:
	/**
	 * Constructs an expression changes the sign of every component of the
	 * expression \c rhs.
	 */
	negation(R const& rhs);

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	typename R::algebra::scalar_type at() const;

private:
	/**
	 * Right-hand side expression.
	 */
	R const& rhs;
};

/**
 * Negation operator returning an expression object for the negative of
 * the expression \c rhs.
 */
template <typename R>
negation<R> operator-(R const& rhs);

/**
 * @}
 */

}

#include <hep/impl/negation.hpp>

#endif
