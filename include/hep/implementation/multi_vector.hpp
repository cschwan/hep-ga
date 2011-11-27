#ifndef HEP_IMPLEMENTATION_MULTI_VECTOR_HPP
#define HEP_IMPLEMENTATION_MULTI_VECTOR_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011  Christopher Schwan
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

#include <algorithm>

namespace hep
{

template <typename T, std::size_t P, std::size_t Q>
multi_vector<T, P, Q>::multi_vector()
{
	std::fill(m_components, m_components + no_of_components, T(0.0));
}

template <typename T, std::size_t P, std::size_t Q>
template <typename ... Args>
multi_vector<T, P, Q>::multi_vector(Args ... components)
	: m_components{components ...}
{
	static_assert(
		sizeof... (Args) == no_of_components,
		"not every component was specified"
	);
}

template <typename T, std::size_t P, std::size_t Q>
T& multi_vector<T, P, Q>::operator[](std::size_t index)
{
	return m_components[index];
}

template <typename T, std::size_t P, std::size_t Q>
T const& multi_vector<T, P, Q>::operator[](std::size_t index) const
{
	return m_components[index];
}

}

#endif
