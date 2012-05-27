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
#include <hep/list/grades_to_list.hpp>
#include <hep/list/intersection.hpp>
#include <hep/expression.hpp>
#include <hep/inline.hpp>

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
using grade_list = typename intersection<typename grades_to_list<typename
	E::algebra, grades...>::type, typename E::list>::type;

/**
 * Expression class for grade projection expressions.
 */
template <typename E, int... grades>
class grade_projection : public expression<typename E::algebra,
	grade_list<E, grades...>>
{
public:
	/**
	 * Type definition for the components contained in this expression.
	 */
	typedef grade_list<E, grades...> list;

	/**
	 * Contructs a new grade projection expression for expression \c expr.
	 */
	hep_inline grade_projection(E const& expr)
		: expr(expr)
	{
	}

	/**
	 * Performs the computation of the component represented by \c index.
	 */
	template <int index>
	hep_inline typename E::algebra::scalar_type at() const
	{
		static_assert (find<list>(index) != -1, "component does not exist");

		return expr.template at<index>();
	}

private:
	/**
	 * The expression which should be projected.
	 */
	E const& expr;
};

/**
 * Selects components from \c expr based on the grades specified with \c grades.
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
