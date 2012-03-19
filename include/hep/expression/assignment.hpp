#ifndef HEP_EXPRESSION_ASSIGNMENT_HPP
#define HEP_EXPRESSION_ASSIGNMENT_HPP

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

namespace hep
{

/**
 * 
 */
template <typename List>
struct assignment
{
	/**
	 * 
	 */
	template <typename L, typename R>
	static void perform(L& lhs, R const& rhs);
};

template <typename List>
template <typename L, typename R>
inline void assignment<List>::perform(L& lhs, R const& rhs)
{
	// assign component with index specified in the first element of the
	// component list L ...
	lhs.template at<List::value()>() = rhs.template at<List::value()>();

	// and make recursion with L::next
	assignment<typename List::next>::perform(lhs, rhs);
}

/// \cond DOXYGEN_IGNORE
template <>
struct assignment<list<>>
{
	template <typename L, typename R>
	static void perform(L const&, R const&);
};

template <typename L, typename R>
inline void assignment<list<>>::perform(L const&, R const&)
{
}
/// \endcond

}

#endif
