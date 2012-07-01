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

#include <hep/list/find.hpp>
#include <hep/list/list.hpp>
#include <hep/list/intersection.hpp>
#include <hep/list/merge.hpp>
#include <hep/utils/next_bit_permutation.hpp>
#include <hep/inline.hpp>
#include <hep/unary_expression.hpp>

namespace
{

template <typename A, int grade, int component, int last_component>
struct grade_to_list_helper
{
	typedef typename grade_to_list_helper<
		A, grade, hep::next_bit_permutation(component),
			((1 << grade) - 1) << (A::dim - grade)
	>::type::template push_front<component>::type type;
};

template <typename A, int grade, int component>
struct grade_to_list_helper<A, grade, component, component>
{
	typedef hep::list<component> type;
};

// TODO: merge grade_to_list with grade_to_list_helper once clang can compile
// default arguments depending on template parameters (see llvm bug #11851)
template <typename A, int grade>
struct grade_to_list
{
	typedef typename grade_to_list_helper<
		A, grade, (1 << grade) - 1, ((1 << grade) - 1) << (A::dim - grade)
	>::type type;
};

template <typename A, int... grades>
struct grades_to_list;

template <typename A>
struct grades_to_list<A>
{
	typedef hep::list<> type;
};

template <typename A, int grade, int... grades>
struct grades_to_list<A, grade, grades...>
{
	static_assert (grade <= A::dim, "grade bigger than algebra dimension");

	typedef typename hep::merge<
		typename grade_to_list<A, grade>::type,
		typename grades_to_list<A, grades...>::type
	>::type type;
};

}

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 *
 */
template <typename E, int... grades>
using grade_list = typename intersection<
	typename grades_to_list<typename E::algebra, grades...>::type,
	typename E::list>::type;

/**
 * Expression class for grade projections.
 */
template <typename E, int... grades>
class grade_projection : public unary_expression<E, grade_list<E, grades...>>
{
public:
	/**
	 * Type definition for the components contained in this expression.
	 */
	typedef grade_list<E, grades...> list;

	/**
	 * Constructor. This simply calls the contructor of the parent class.
	 */
	hep_inline grade_projection(E const& expr)
		: unary_expression<E, list>(expr)
	{
	}

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	hep_inline typename E::algebra::scalar_type at() const
	{
		static_assert (find<list>(index) != -1, "component does not exist");

		return this->expr.template at<index>();
	}
};

/**
 * Selects components from the \ref expression \c expr based on the grades
 * specified with \c grades. Note that some components may be omitted (although
 * they are requested with certain grades) if they are not present in the
 * expression \c E and therefore zero by * default.
 */
template <int... grades, typename E>
hep_inline grade_projection<E, grades...> grade(E const& expr)
{
	return grade_projection<E, grades...>(expr);
}

/**
 * @}
 */

}

#endif
