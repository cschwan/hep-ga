#ifndef HEP_COMMON_SUM_HPP
#define HEP_COMMON_SUM_HPP

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

#include <hep/list/merge.hpp>
#include <hep/binary_expression.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * List containing the components for the sum/difference of subexpressions of
 * type \c L and \c R.
 */
template <typename L, typename R>
using sum_list = typename merge<typename L::list, typename R::list>::type;

/**
 * Parent class for sum of difference of two subexpressions of type \c L and
 * \c R. \c sign determines wether the components should subtracted or summed.
 */
template <bool sign, typename L, typename R>
class common_sum : public binary_expression<L, R, sum_list<L, R>>
{
public:
	/**
	 * Constructor. This simply calls the contructor of the parent class.
	 */
	common_sum(L const& lhs, R const& rhs);

	/**
	 * Performs the computation of the component represented by \c index and
	 * returns it.
	 */
	template <int index>
	typename L::algebra::scalar_type at() const;
};

/**
 * @}
 */

}

#include <hep/impl/common_sum.hpp>

#endif
