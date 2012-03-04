#ifndef HEP_GRADE_HPP
#define HEP_GRADE_HPP

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

#include <hep/multi_vector.hpp>

#include <cstddef>

namespace hep
{

/**
 * This is the grade-projection operation. If you want to extract certain grades
 * of a multi_vector you can use this function, e.g.:
 * \code
 * hep::multi_vector<float, 2, 0, 1+4> complex_number = { 1.0f, 2.0f };
 *
 * // scalar
 * auto real_part = hep::grade<1>(complex_number);
 * // bivector
 * auto imag_part = hep::grade<4>(complex_number);
 * \endcode
 */
template <std::size_t N, typename A, std::size_t L>
multi_vector<A, N> grade(multi_vector<A, L> const& mv);

}

#include <hep/impl/grade.hpp>

#endif
