#ifndef HEP_GA_ALGEBRA_HPP
#define HEP_GA_ALGEBRA_HPP

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
 * \ingroup main
 *
 * Class representing the geometric algebra \f$ \mathcal{G}(p,q) \f$. The
 * integer \c P determines the number of basis-vectors \f$ e_i \f$ squaring to
 * \f$ +1 \f$ and \c Q the number of basis-vectors squaring to \f$ -1 \f$:
 * \f[
 *     e_i^2 = \begin{cases}
 *                 +1 \quad \forall \; 0 \le i < p \\
 *                 -1 \quad \forall \; p \le i < p+q
 *             \end{cases}
 * \f]
 * The type \c T is used for numerical operations. This type does not
 * neccessarily need to be an intrinsic type like \c float or \c double, but it
 * must support multiplication, division, addition and subtraction. A further
 * requirement is that a \c double literal must be convertible to \c T, i.e.
 * expressions like <tt>T(0.0)</tt>, <tt>T(1.0)</tt> must be valid.
 *
 * Examples for common algebras are:
 * \code
 * // Geometric Algebra for the euclidean (2 dimensional) plane
 * typedef hep::algebra<double, 2, 0> eucl_2d;
 *
 * // Geometric Algebra for the euclidean (3 dimensional) space
 * typedef hep::algebra<double, 3, 0> eucl_3d;
 *
 * // Space Time Algebra with signature (+,-,-,-)
 * typedef hep::algebra<double, 1, 3> sta;
 * \endcode
 */
template <typename T, int P, int Q>
struct algebra
{
	/**
	 * Type definition for \c T, for access from outside the class.
	 */
	typedef T scalar_type;

	/**
	 * The number of basis-vectors \f$ e_i \f$ with \f$ 0 \le i < p \f$ squaring
	 * to \f$ +1 \f$.
	 */
	static constexpr int p = P;

	/**
	 * The number of basis-vectors \f$ e_i \f$ with \f$ 0 \le i < p \f$ squaring
	 * to \f$ -1 \f$.
	 */
	static constexpr int q = Q;

	/**
	 * The dimension of the algebra, i.e. the number of all basis-vectors.
	 */
	static constexpr int dim = P + Q;
};

}

#endif
