#ifndef HEP_GA_IMPL_MULTI_VECTOR_HPP
#define HEP_GA_IMPL_MULTI_VECTOR_HPP

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

#include <hep/ga/list/list.hpp>
#include <hep/ga/inline.hpp>
#include <hep/ga/multi_vector.hpp>

#include <type_traits>

namespace
{

template <typename List>
struct assignment
{
	template <typename L, typename R>
	static hep_inline void perform(L& lhs, R const& rhs)
	{
		lhs.template at<List::value>() = rhs.template at<List::value>();
		assignment<typename List::next>::perform(lhs, rhs);
	}
};

template <>
struct assignment<hep::list<>>
{
	template <typename L, typename R>
	static hep_inline void perform(L const&, R const&)
	{
	}
};

}

namespace hep
{

template <typename A, typename L>
template <typename E>
hep_inline multi_vector<A, L>::multi_vector(E const& expression)
{
	static_assert (std::is_same<L, typename E::list>(),
		"assignment of expression to multi_vector with different components");

	assignment<L>::perform(*this, expression);
}

}

#endif
