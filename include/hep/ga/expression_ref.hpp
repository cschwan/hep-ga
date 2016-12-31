#ifndef HEP_GA_EXPRESSION_REF_HPP
#define HEP_GA_EXPRESSION_REF_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2012,2016  Christopher Schwan
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

#include <hep/ga/multi_vector.hpp>

#include <type_traits>

namespace hep
{

/**
 * \ingroup expressions
 *
 * A reference to an \ref expression used in \ref unary_expression and
 * \ref binary_expression. Depending on the type of the expression \c E,
 * \ref expression_ref is either a constant reference (<tt>E const&</tt>) or the
 * type itself (\c E), i.e. objects are copied.
 *
 * The current behavior is to use a reference if \c E is a \ref multi_vector and
 * to copy otherwise. In any case expressions of type \ref wrapper must be
 * copied because they are created as temporary objects.
 */
template <typename E>
using expression_ref = std::conditional_t<
	std::is_same<E, multi_vector<typename E::algebra, typename E::list>>::value,
	E const&,
	E
>;

}

#endif
