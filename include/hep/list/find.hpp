#ifndef HEP_LIST_FIND_HPP
#define HEP_LIST_FIND_HPP

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

namespace
{

template <typename L>
constexpr int recursive_find(int index, int at)
{
	return (L::value() == index) ? at : ((L::value() < index ?
		recursive_find<typename L::next>(index, at + 1) : -1));
}

template <>
constexpr int recursive_find<hep::list<>>(int, int)
{
	return -1;
}

}

namespace hep
{

/**
 * \addtogroup list
 * @{
 */

/**
 * Finds the index in the hep::list specified with \c L and returns the
 * position or \c -1 if not found.
 */
template <typename L>
constexpr int find(int index)
{
	return recursive_find<L>(index, 0);
}

/**
 * @}
 */

}

#endif
