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
 * An implementation for multi-vectors of a geometric algebra represented by
 * \c A which must be a hep::algebra.
 *
 * \section component_storage_layout Component Storage Layout
 *
 * With the template parameter \c L it is possible to select which grades are
 * included in the multi-vector. For example, the following type includes the
 * scalar and bivector parts:
 * \code
 * typedef hep::algebra<float, 2, 0> eucl_plane;
 * typedef hep::multi_vector<eucl_plane, 1+4> complex;
 *
 * complex a = { 1.0f, 2.0f };
 * \endcode
 * The scalar part is set to \c 1.0f, the bivector to \c 2.0f. Note that in
 * general, the multi-vector's basis-blades are initialized in ascending
 * grade-order. Components which are not specified are default initialized.
 *
 * \tparam A Algebra. See documentation of hep::algebra
 * \tparam L Grade list. Bits which are set signal that the corresponding blades
 *         are included in the multi-vector. For example, \c 1 means scalar,
 *         \c 2 means vector, \c 4 bivector and so on
 */
template <typename A, std::size_t L>
class multi_vector
{
	static_assert (L != 0, "grade list is zero");

	static_assert (L < (1u << (A::dim() + 1)),
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
	multi_vector(multi_vector<A, L> const& object) = default;

	/**
	 * Component read-/write-access operator.
	 */
	typename A::value_type& operator[](std::size_t index);

	/**
	 * Component read-access operator.
	 */
	typename A::value_type const& operator[](std::size_t index) const;

private:
	/**
	 * Array storing the components of this multi-vector.
	 */
	typename A::value_type components[num_of_components(A::dim(), L)];
};

}

#include <hep/impl/multi_vector.hpp>

#endif
