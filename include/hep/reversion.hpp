#ifndef HEP_REVERSION_HPP
#define HEP_REVERSION_HPP

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

#include <hep/utils/pop_count.hpp>
#include <hep/expression.hpp>
#include <hep/inline.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Expression class for reversion.
 */
template <typename E>
class reversion : public expression<typename E::algebra, typename E::list>
{
public:
	/**
	 * Constructor for a reversion expression reversing expression \c expr.
	 */
	hep_inline reversion(E const& expr)
		: expr(expr)
	{
	}

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	hep_inline typename E::algebra::scalar_type at() const
	{
#define grade (pop_count(index))
#define sign ((((grade * (grade - 1)) / 2) % 2) == 1)

		return sign ? -expr.template at<index>() : expr.template at<index>();

#undef sign
#undef grade
	}

private:
	/**
	 * The expression which is reversed.
	 */
	E const& expr;
};

/**
 * Reversion operator returning an expression object for the reversion of
 * expression \c expr.
 */
template <typename E>
hep_inline reversion<E> reverse(E const& expr)
{
	return reversion<E>(expr);
}

/**
 * @}
 */

}

#endif
