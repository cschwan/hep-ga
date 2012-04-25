#ifndef HEP_EXPR_PROD_ELEM_SUM_LIST_HPP
#define HEP_EXPR_PROD_ELEM_SUM_LIST_HPP

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

#include <hep/list/find.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup internals
 * @{
 */

/**
 * Finds the sub-list in \c L whose value multiplies with an element in the list
 * \c R to \c index and respects condition \c C. If no list is found, the result
 * is an empty list.
 */
template <typename L, typename R, typename C, int index>
struct prod_elem_sum_list
{
#define hep_i         ( L::value() )
#define hep_j         ( L::value() ^ index )
#define hep_condition ( (find<R>(hep_j) != -1) && C::check(hep_i, hep_j) )

	/**
	 * The result of this operation.
	 */
	typedef typename std::conditional<hep_condition, L, typename
		prod_elem_sum_list<typename L::next, R, C, index>::type>::type type;

#undef hep_condition
#undef hep_j
#undef hep_i
};

/// \cond DOXYGEN_IGNORE
template <typename R, typename C, int index>
struct prod_elem_sum_list<list<>, R, C, index>
{
	typedef list<> type;
};
/// \endcond

/**
 * @}
 */

}

#endif
