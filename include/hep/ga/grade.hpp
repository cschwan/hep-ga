#ifndef HEP_GA_GRADE_HPP
#define HEP_GA_GRADE_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2012-2013,2015  Christopher Schwan
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
#include <hep/ga/list/list.hpp>
#include <hep/ga/list/intersection.hpp>
#include <hep/ga/list/merge.hpp>
#include <hep/ga/utils/next_bit_permutation.hpp>
#include <hep/ga/inline.hpp>
#include <hep/ga/unary_expression.hpp>

namespace
{

#define hep_first_component ((1 << grade) - 1)
#define hep_last_component (hep_first_component << (A::dim - grade))
#define hep_next_component (hep::next_bit_permutation(component))

template <typename A, int grade, int component = hep_first_component,
	int last_component = hep_last_component>
struct grade_to_list
{
	static_assert (grade <= A::dim, "grade bigger than algebra dimension");

	using type = hep::push_front_t<component, typename grade_to_list<A, grade, hep_next_component>::type>;
};

#undef hep_next_component
#undef hep_last_component
#undef hep_first_component

template <typename A, int grade, int component>
struct grade_to_list<A, grade, component, component>
{
	using type = hep::list<component>;
};

template <typename A, int... grades>
struct grades_to_list;

template <typename A>
struct grades_to_list<A>
{
	using type = hep::list<>;
};

template <typename A, int grade, int... grades>
struct grades_to_list<A, grade, grades...>
{
	static_assert (grade <= A::dim, "grade bigger than algebra dimension");

	using type = typename hep::merge<
		typename grade_to_list<A, grade>::type,
		typename grades_to_list<A, grades...>::type
	>::type;
};

template <typename E, int... grades>
using grade_list = typename hep::intersection<
	typename grades_to_list<typename E::algebra, grades...>::type,
	typename E::list>::type;

}

namespace hep
{

/**
 * \ingroup expressions
 *
 * Expression class for grade projections.
 */
template <typename E, int... grades>
class grade_projection : public unary_expression<E, grade_list<E, grades...>>
{
public:
	/**
	 * Type definition for the components contained in this expression.
	 */
	using list = grade_list<E, grades...>;

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
 * \ingroup main
 *
 * Selects components from the \ref expression \c expr based on the grades
 * specified with \c grades. Note that some components may be omitted (although
 * they are requested with certain grades) if they are not present in the
 * expression \c E and therefore zero.
 */
template <int... grades, typename E>
hep_inline grade_projection<E, grades...> grade(E const& expr)
{
	return grade_projection<E, grades...>(expr);
}

}

#endif
