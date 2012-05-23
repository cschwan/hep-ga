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

namespace hep
{

/**
 * \defgroup list Lists
 * @{
 */

/// \cond DOXYGEN_IGNORE
template <int... C>
struct list;
/// \endcond

/**
 * A list for components contained in a hep::multi_vector. The indices of the
 * desired components have to be specified as a type definition, for example:
 * \code
 * typedef hep::list<1, 2, 4, 8> vectors;
 * \endcode
 * Note that you have to specify the components always in ascending order.
 */
template <int component, int... C>
struct list<component, C...>
{
	/**
	 * Type definition for internal use to iterate over the components in the
	 * list.
	 */
	typedef list<C...> next;

	/**
	 * The total number of components in this list.
	 */
	static constexpr int size()
	{
		return sizeof... (C) + 1;
	}

	/**
	 * The value of the first component in this list.
	 */
	static constexpr int value()
	{
		return component;
	}

	/**
	 * Adds \c new_element to the front of this list. Example:
	 * \code
	 * typedef hep::list<1, 2>::push_front<0>::type result;
	 * \endcode
	 * This will define a new type which is identical to
	 * \code
	 * typedef hep::list<0, 1, 2> result;
	 * \endcode
	 */
	template <int new_component>
	struct push_front
	{
		/**
		 * Result of this operation.
		 */
		typedef list<new_component, component, C...> type;
	};
};

/// \cond DOXYGEN_IGNORE
template <>
struct list<>
{
	static constexpr int size()
	{
		return 0;
	}

	template <int new_component>
	struct push_front
	{
		typedef list<new_component> type;
	};
};
/// \endcond

/**
 * @}
 */

}

#endif
