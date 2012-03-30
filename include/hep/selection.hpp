#ifndef HEP_SELECTION_HPP
#define HEP_SELECTION_HPP

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

#include <hep/list/list.hpp>
#include <hep/expression.hpp>

namespace hep
{

/**
 * 
 */
template <typename E, int... indices>
class selection : public expression<typename E::algebra, list<indices...>>
{
public:
	/**
	 * 
	 */
	selection(E const& expr);

	/**
	 * 
	 */
	template <int index>
	typename E::algebra::scalar_type at() const;

private:
	E const& expr;
};

/**
 * 
 */
template <int... indices, typename E>
selection<E, indices...> select(E const& expr);

}

#include <hep/impl/selection.hpp>

#endif
