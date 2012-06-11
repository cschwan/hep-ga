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

#include <hep/list/find.hpp>
#include <hep/expression.hpp>
#include <hep/inline.hpp>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * An implementation for multi-vectors of a geometric algebra represented by
 * \c A which must be of type \ref algebra. The template parameter \c L must be
 * a \ref list and is used to specify the components which should be included
 * in this multi_vector. This list also specifies the order of components. For
 * example, the following type includes the scalar component and the bivector
 * component of a multi-vector in \f$ \mathcal{G}(2,0) \f$:
 * \code
 * typedef hep::algebra<float, 2, 0> euclidean_plane;
 * typedef hep::list<0, 3> scalar_bivector;
 * typedef hep::multi_vector<euclidean_plane, scalar_bivector> complex;
 *
 * complex a = { 1.0f, 2.0f };
 * \endcode
 * The scalar part is set to \c 1.0f, the bivector to \c 2.0f. Note that the
 * component list must be sorted and thus the scalar component (component with
 * index \c 0) has to be specified before the bivector component (with index
 * \c 3) in the initialization of \c a.
 */
template <typename A, typename L>
class multi_vector : public expression<A, L>
{
public:
	/**
	 * Constructor. This constructor is used to initialize all of the
	 * multi_vector's components. Note that unspecified components will be
	 * default-initialized (i.e. to zero for built-in types). Furthermore note
	 * that you have to specify the components in one-to-one correspondence
	 * with the component-list. See class documentation for an example.
	 * 
	 * \param components Components of the multi-vector
	 */
	template <typename ... Args>
	multi_vector(Args ... components)
		: components{components...}
	{
	}

	/**
	 * Component-constructor. This initializes the first component with \c value
	 * and default initializes all remaining components. The purpose of this
	 * constructor is to prevent the expression-contructor which would yield in
	 * a compiler error.
	 */
	multi_vector(typename A::scalar_type const& value)
		: components{value}
	{
	}

	/**
	 * Expression-constructor.
	 */
	template <typename E>
	multi_vector(E const& expression);

	/**
	 * Read-/Write-access operator.
	 */
	typename A::scalar_type& operator[](unsigned at)
	{
		return components[at];
	}

	/**
	 * Read-access operator.
	 */
	typename A::scalar_type const& operator[](unsigned at) const
	{
		return components[at];
	}

	/**
	 * Literal-index read-access operator. This member function is primarily
	 * intended for use with expression templates in this library.
	 */
	template <int index>
	hep_inline typename A::scalar_type const& at() const
	{
		static_assert (find<L>(index) != -1, "component does not exist");
		return components[find<L>(index)];
	}

	/**
	 * Literal-index read-/write-access operator. This member function is
	 * primarily intended for use with expression templates in this library.
	 */
	template <int index>
	hep_inline typename A::scalar_type& at()
	{
		static_assert (find<L>(index) != -1, "component does not exist");
		return components[find<L>(index)];
	}

private:
	/**
	 * Array storing the components of this multi-vector. The size of this array
	 * is equal to the number of elements in \c L.
	 */
	typename A::scalar_type components[L::size];
};

/**
 * @}
 */

}

#include <hep/impl/multi_vector.hpp>

#endif
