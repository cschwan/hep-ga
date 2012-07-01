#ifndef HEP_LIST_LIST_HPP
#define HEP_LIST_LIST_HPP

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

#include <type_traits>

namespace hep
{

/**
 * \defgroup lists Lists
 * @{
 */

/**
 * A list for components contained in an \ref expression, e.g. a
 * \ref multi_vector. The indices of the desired components must be given as a
 * type definition, for example:
 * \code
 * typedef hep::list<1, 2, 4, 8> vectors;
 * \endcode
 * \b Note: You always have to specify the components in \em ascending order and
 * \em without duplicates!
 */
template <int... C>
struct list
{
};

/**
 * @}
 */

}

namespace
{

template <typename L>
struct is_well_formed
{
	static constexpr bool value = L::value < L::next::value;
};

template <int component>
struct is_well_formed<hep::list<component>>
{
	static constexpr bool value = true;
};

}

namespace hep
{

/// \cond DOXYGEN_IGNORE
template <int component, int... C>
struct list<component, C...>
{
	typedef list<C...> next;

	static constexpr int size = sizeof... (C) + 1;

	static constexpr int value = component;

	template <int new_component>
	struct push_front
	{
		typedef list<new_component, component, C...> type;
	};

	static_assert (is_well_formed<list<component, C...>>::value,
		"list is malformed");
};

template <>
struct list<>
{
	static constexpr int size = 0;

	template <int new_component>
	struct push_front
	{
		typedef list<new_component> type;
	};
};
/// \endcond

}

#endif
