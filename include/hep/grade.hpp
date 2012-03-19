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

#include <hep/expression.hpp>
#include <hep/utils/grades_to_list.hpp>
#include <hep/utils/intersection.hpp>

namespace hep
{

/**
 * 
 */
template <typename E, int... grades>
class grade_projection : public expression<typename E::algebra,
	typename intersection<typename grades_to_list<typename E::algebra,
	grades...>::type, typename E::list>::type>
{
public:
	/**
	 * 
	 */
	typedef typename intersection<typename grades_to_list<typename
		E::algebra, grades...>::type, typename E::list>::type list;

	/**
	 * 
	 */
	grade_projection(E const& expr);

	/**
	 * 
	 */
	template <int index>
	typename E::algebra::scalar_type at() const;

private:
	/**
	 * 
	 */
	E const& expr;
};

/**
 * 
 */
template <int... grades, typename E>
grade_projection<E, grades...> grade(E const& expr);

}

#include <hep/impl/grade.hpp>

#endif
