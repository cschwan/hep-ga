#ifndef HEP_IMPLEMENTATION_PRODUCT_HPP
#define HEP_IMPLEMENTATION_PRODUCT_HPP

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

#include <hep/product.hpp>
#include <hep/utils/index_representation.hpp>
#include <hep/utils/pop_count.hpp>
#include <hep/utils/sign_table.hpp>

namespace hep
{

template <typename A, std::size_t L1, std::size_t L2>
multi_vector<A, grade_list_product(L1, L2, A::dim())> operator*(
	multi_vector<A, L1> const& lhs,
	multi_vector<A, L2> const& rhs
) {
	constexpr std::size_t result_list = grade_list_product(L1, L2, A::dim());
	constexpr std::size_t size = 1 << A::dim();

	multi_vector<A, result_list> result;

	// loop over every possible element of a multi-vector of the type (P,Q) ...
	for (std::size_t i = 0; i != size; ++i)
	{
		// but veto access to componenents of lhs which do not exist ...
		if (!(L1 & (1 << pop_count(i))))
		{
			continue;
		}

		for (std::size_t j = 0; j != size; ++j)
		{
			// and do the same for rhs
			if (!(L2 & (1 << pop_count(j))))
			{
				continue;
			}

			std::size_t index_ij =
				index_representation(i ^ j, result_list, A::dim());
			std::size_t index_i = index_representation(i, L1, A::dim());
			std::size_t index_j = index_representation(j, L2, A::dim());

			result[index_ij] +=
				sign_table<A>(i, j) * lhs[index_i] * rhs[index_j];
		}
	}

	return result;
}

}

#endif
