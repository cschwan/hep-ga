#ifndef HEP_OPERATIONS_HPP
#define HEP_OPERATIONS_HPP

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
#include <hep/utils/grade_list_product.hpp>

#include <cstddef>

namespace hep
{

/**
 * Implements the Geometric Product of two multi-vectors \c lhs and \c rhs.
 *
 * \tparam T Type used for components of the multi vector
 * \tparam P Number of basis vectors which square to \f$ +1 \f$
 * \tparam Q Number of basis vectors which square to \f$ -1 \f$
 */
template
	< typename T
	, std::size_t P
	, std::size_t Q
	, std::size_t L1
	, std::size_t L2
	>
multi_vector<T, P, Q, grade_list_product(L1, L2, P + Q)> operator*(
	multi_vector<T, P, Q, L1> const& lhs,
	multi_vector<T, P, Q, L2> const& rhs
);

}

#include <hep/impl/operations.hpp>

#endif
