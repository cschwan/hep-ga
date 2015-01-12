#ifndef HEP_GA_MULTI_VECTOR_HPP
#define HEP_GA_MULTI_VECTOR_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011-2012,2015  Christopher Schwan
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

#include <hep/ga/list/find.hpp>
#include <hep/ga/expression.hpp>
#include <hep/ga/inline.hpp>

namespace hep
{

/**
 * \ingroup expressions main
 *
 * An implementation for multi-vectors of a geometric algebra represented by an
 * \ref algebra \c A. The \ref list \c L specifies the components which should
 * be included in this multi_vector. This list also specifies the order of
 * components which is important for the component constructor.
 *
 * The following example demonstrates the use of a multi-vector in \f$
 * \mathcal{G}(2,0) \f$ including the scalar and the pseudo-scalar (bivector)
 * component:
 * \code
 * using euclidean_plane = hep::algebra<float, 2, 0>;
 * using scalar_bivector =  hep::list<0, 3>;
 * using complex = hep::multi_vector<euclidean_plane, scalar_bivector>;
 *
 * complex a = { 1.0f, 2.0f };
 * \endcode
 * The scalar part is set to \c 1.0f, the bivector to \c 2.0f. Note that the
 * component list must be sorted and thus the scalar component (component with
 * index \c 0) has to be specified before the bivector component (with index
 * \c 3) in the initialization of \c a. Further information can be found on the
 * page about \ref bitmap_representation.
 *
 * Note that this class is an \ref expression and therefore has the usual
 * <tt>at</tt> member function. This class is also the only expression having
 * a non-\c const version of \c at allowing to write using the component
 * indices:
 * \code
 * // set a to { 4.0f, 8.0f }
 * a.at<0>() = 4.0f;
 * a.at<3>() = 8.0f;
 *
 * // print the scalar component
 * std::cout << a.at<0>() << std::endl;
 * // print the pseudo-scalar component
 * std::cout << a.at<3>() << std::endl;
 * \endcode
 * Sometimes it is not possible to use constant indices, e.g.
 * \code
 * int index = 3;
 * a.at<index>() = 8.0f;
 * \endcode
 * will not work. In that case one has to use the array index operator
 * \code
 * int index = 1;
 * a[index] = 8.0f;
 * \endcode
 * Note that \c index is \c 1 because the pseudo-scalar component is the second
 * component is this multi-vector.
 */
template <typename A, typename L>
class multi_vector : public expression<A, L>
{
public:
	/**
	 * Constructor. This constructor is used to initialize the multi_vector's
	 * components. Note that unspecified components will be default-initialized
	 * (i.e. to zero for built-in types). Furthermore note that you have to
	 * specify the components in one-to-one correspondence with the
	 * component-list. See the class documentation for an example.
	 */
	template <typename ... Args>
	multi_vector(Args ... components)
		: components{components...}
	{
	}

	/**
	 * Component-constructor. This initializes the first component with \c value
	 * and default-initializes all remaining components. The purpose of this
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
	 * intended for use within template expressions in this library.
	 */
	template <int index>
	hep_inline typename A::scalar_type const& at() const
	{
		static_assert (find<L>(index) != -1, "component does not exist");

		return components[find<L>(index)];
	}

	/**
	 * Literal-index read-/write-access operator. This member function is
	 * primarily intended for use within templates expressions in this library.
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
	 * is equal to the number of entry of the \ref list \c L.
	 */
	typename A::scalar_type components[L::size];
};

}

#include <hep/ga/impl/multi_vector.hpp>

#endif
