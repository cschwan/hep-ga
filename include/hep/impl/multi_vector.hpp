#ifndef HEP_IMPLEMENTATION_MULTI_VECTOR_HPP
#define HEP_IMPLEMENTATION_MULTI_VECTOR_HPP

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

#include <hep/multi_vector.hpp>

namespace hep
{

template <typename A, std::size_t L>
template <typename ... Args>
multi_vector<A, L>::multi_vector(Args ... components)
	// initialize components with given arguments; if there are less arguments
	// than m_components has, the remaining elements will be set to zero
	: components{components ...}
{
}

template <typename A, std::size_t L>
typename A::value_type& multi_vector<A, L>::operator[](std::size_t index)
{
	return components[index];
}

template <typename A, std::size_t L>
typename A::value_type const& multi_vector<A, L>::operator[](std::size_t index)
const
{
	return components[index];
}

}

#endif
