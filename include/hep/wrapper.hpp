#ifndef HEP_WRAPPER_HPP
#define HEP_WRAPPER_HPP

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

#include <hep/list/list.hpp>
#include <hep/expression.hpp>
#include <hep/inline.hpp>

namespace hep
{

/**
 * \ingroup expressions
 *
 * Wrapper class for literals providing a component list and its algebra. This
 * enables one to write code similar to the following snippet:
 * \snippet wrapper.cpp product_with_scalar
 */
template <typename A>
class wrapper : public expression<A, hep::list<0>>
{
public:
	/**
	 * Constructor.
	 */
	hep_inline wrapper(typename A::scalar_type const& scalar)
		: scalar(scalar)
	{
	}

	/**
	 * Returns the scalar if \c index is \c 0. Other indices will result in a
	 * compilation failure.
	 */
	template <int index>
	hep_inline typename A::scalar_type at() const
	{
		static_assert (index == 0, "component does not exist");

		return scalar;
	}

private:
	/**
	 * The scalar.
	 */
	typename A::scalar_type scalar;
};

}

#endif
