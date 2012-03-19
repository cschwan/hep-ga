#ifndef HEP_IMPL_MULTI_VECTOR_HPP
#define HEP_IMPL_MULTI_VECTOR_HPP

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

#include <hep/expr/assignment.hpp>
#include <hep/list/find.hpp>
#include <hep/multi_vector.hpp>

#include <type_traits>

namespace hep
{

template <typename A, typename L>
template <typename ... Args>
multi_vector<A, L>::multi_vector(Args ... components)
	: components{components ...}
{
}

template <typename A, typename L>
multi_vector<A, L>::multi_vector(typename A::scalar_type const& value)
	: components{value}
{
}

template <typename A, typename L>
template <typename E>
multi_vector<A, L>::multi_vector(E const& expression)
{
	static_assert (std::is_same<L, typename E::list>(),
		"assignment of expression to multi_vector with different components");

	assignment<L>::perform(*this, expression);
}

template <typename A, typename L>
template <int index>
inline typename A::scalar_type const& multi_vector<A, L>::at() const
{
	static_assert (find<L>(index) != -1, "required component does not exist");

	return components[find<L>(index)];
}

template <typename A, typename L>
template <int index>
inline typename A::scalar_type& multi_vector<A, L>::at()
{
	static_assert (find<L>(index) != -1, "required component does not exist");

	return components[find<L>(index)];
}

}

#endif
