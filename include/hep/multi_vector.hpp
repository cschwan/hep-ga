#ifndef HEP_MULTI_VECTOR_HPP
#define HEP_MULTI_VECTOR_HPP

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

#include <hep/utils/num_of_components.hpp>

#include <cstddef>

namespace hep
{

/**
 * \section introduction Introduction
 *
 * An implementation for multi-vectors of geometric algebra \f$ \mathcal{G}_{p,
 * q} \f$. The basis vectors \f$ e_0, e_1, \ldots, e_{p+q-1} \f$ satisfy the
 * following properties:
 * \f[
 *     e_i^2 = \begin{cases} +1 & \forall \, 0 \le i < p \\
 *                           -1 & \forall \, p \le i < p+q \end{cases}
 * \f]
 * For example, \f$ \mathcal{G}_{2,0} \f$ is the geometric algebra (GA) of the
 * euclidian plane, \f$ \mathcal{G}_{3,0} \f$ is the GA of euclidian space and
 * \f$ \mathcal{G}_{1,3} \f$ denotes the GA of Minkowski space with basis
 * vectors satisfying \f$ e_0^2 = +1 \f$, \f$ e_1^2 = -1 \f$, \f$ e_2^2 = -1 \f$
 * and \f$ e_3^2 = -1 \f$.
 *
 * \section component_storage_layout Component Storage Layout
 *
 * By the template parameter \c L it is possible to select which grades are
 * saved in the multi-vector. For example, the following type includes the
 * scalar and all bivector parts:
 * \code
 * typedef hep::multi_vector<float, 2, 0, 1+4> complex;
 *
 * complex a = { 1.0f, 2.0f };
 * \endcode
 * The scalar part is set to \c 1.0f, the bivector to \c 2.0f. Note that in
 * general, the multi-vector's basis-blades are initialized in ascending
 * grade-order. Components which are not specified are initialized to zero
 * (default C++ behavior).
 *
 * \tparam T Type used for components of the multi vector
 * \tparam P Number of basis vectors which square to \f$ +1 \f$
 * \tparam Q Number of basis vectors which square to \f$ -1 \f$
 * \tparam L Grade list. Bits which are set signal that the corresponding blades
 *         are included in the multi-vector. For example, \c 1 means scalar,
 *         \c 2 means vector, \c 4 bivector and so on
 */
template <typename T, std::size_t P, std::size_t Q, std::size_t L>
class multi_vector
{
	static_assert (P + Q > 0, "algebra dimension is zero");

	static_assert (L != 0, "grade list is zero");

	static_assert (L < (1 << (P + Q + 1)),
		"grade list contains grades higher than the algebra dimension");

public:
	/**
	 * Constructor. This constructor is used to initialize all of the
	 * multi-vector's components. Note that unspecified components will be
	 * default-initialized (i.e. to zero for built-in types). Furthmore note
	 * that you have to specify the components in the order described in the
	 * class description of multi_vector.
	 * 
	 * \param components Components of the multi-vector
	 */
	template <typename ... Args>
	multi_vector(Args ... components);

	/**
	 * Copy contructor.
	 */
	multi_vector(multi_vector<T, P, Q, L> const& object) = default;

	/**
	 * Grade selection contructor. This constructor takes a multi_vector with a
	 * different grade list \c N and selects only those which also appear in 
	 * this's grade list. Other grades are set to zero.
	 */
	template <std::size_t N>
	multi_vector(multi_vector<T, P, Q, N> const& object);

	/**
	 * Component read-/write-access operator.
	 */
	T& operator[](std::size_t index);

	/**
	 * Component read-access operator.
	 */
	T const& operator[](std::size_t index) const;

private:
	/**
	 * Array storing the components of this multi-vector.
	 */
	T components[num_of_components(P + Q, L)];
};

}

#include <hep/impl/multi_vector.hpp>

#endif
