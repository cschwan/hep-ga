#ifndef HEP_EVAL_HPP
#define HEP_EVAL_HPP

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

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Explicitly evaluates the given expression \c expr to the corresponding
 * multi_vector. This is typically used in conjunction with the \c auto keyword,
 * e.g.:
 * \code
 * typedef hep::algebra<double,3,0> space_algebra;
 * typedef hep::list<1,2,4> vectors;
 * typedef hep::multi_vector<space_algebra, vectors> vector;
 *
 * vector v1 = { 1.0, 2.0, 3.0 };
 * vector v2 = { 2.0, 3.0, 4.0 };
 * vector v3 = { 3.0, 4.0, 5.0 };
 *
 * // expr is of type hep:sum<vector, hep:sum<vector, vector>>, components are
 * // not computed at this point
 * auto expr = v1 + v2 + v3;
 *
 * // sum is of type 'vector', the computations are done right here
 * auto sum = hep::eval(expr);
 * \endcode
 */
template <typename E>
multi_vector<typename E::algebra, typename E::list> eval(E const& expr);

/**
 * @}
 */

}

#include <hep/impl/eval.hpp>

#endif
