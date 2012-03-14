#ifndef HEP_ALGEBRA_HPP
#define HEP_ALGEBRA_HPP

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
 * Class representing a specific geometric algebra \f$ \mathcal{G}_{p,q} \f$.
 * \c P determines the number of basis-vectors \f$ e_i \f$ squaring to \f$ +1
 * \f$, \c Q the number of basis-vectors squaring to \f$ -1 \f$:
 * \f[
 *     e_i^2 = \begin{cases}
 *                 +1 \quad \forall \; 0 \le i < p \\
 *                 -1 \quad \forall \; p \le i < p+q
 *             \end{cases}
 * \f]
 * \c T is the type which is used for numerical operations. \c T does not
 * neccessarily need to be an intrinsic type like \c float or \c double, but it
 * has to support the multiplication and addition operator. Furthermore,
 * \code T(0.0) \endcode must be a valid expression.
 */
template <typename T, int P, int Q>
struct algebra
{
	/**
	 * Type definition for using \c T.
	 */
	typedef T scalar_type;

	/**
	 * The number of basis-vectors squaring to \f$ +1 \f$.
	 */
	static constexpr int p();

	/**
	 * The number of basis-vectors squaring to \f$ -1 \f$.
	 */
	static constexpr int q();

	/**
	 * The number of all basis-vectors.
	 */
	static constexpr int dim();
};

}

#include <hep/impl/algebra.hpp>

#endif
