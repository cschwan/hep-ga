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
#include <hep/inline.hpp>
#include <hep/unary_expression.hpp>

namespace
{

template <bool>
struct sign
{
	template <typename T>
	static hep_inline T get(T const& value)
	{
		return value;
	}
};

template <>
struct sign<true>
{
	template <typename T>
	static hep_inline T get(T const& value)
	{
		return -value;
	}
};

}

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Expression class for reversions.
 */
template <typename E>
class reversion : public unary_expression<E, typename E::algebra,
	typename E::list>
{
public:
	/**
	 * Constructor. This simply calls the contructor of the parent class.
	 */
	hep_inline reversion(E const& expr)
		: unary_expression<E, typename E::algebra, typename E::list>(expr)
	{
	}

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	hep_inline typename E::algebra::scalar_type at() const
	{
		constexpr int grade = pop_count(index);
		constexpr bool value = (((grade * (grade - 1)) / 2) % 2) == 1;

		return sign<value>::get(this->expr.template at<index>());
	}
};

/**
 * Reversion operator returning an expression object for the reversion of
 * expression \c expr.
 */
template <typename E>
hep_inline reversion<E> operator~(E const& expr)
{
	return reversion<E>(expr);
}

/**
 * @}
 */

}

#endif
