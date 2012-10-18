#ifndef HEP_GA_EVAL_HPP
#define HEP_GA_EVAL_HPP

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

#include <hep/ga/multi_vector.hpp>
#include <hep/ga/inline.hpp>

namespace hep
{

/**
 * \ingroup main
 *
 * Explicitly evaluates the given expression \c expr to the corresponding
 * \ref multi_vector. This is typically used in conjunction with the \c auto
 * keyword, for example in situations like the following one:
 * \snippet eval.cpp example
 */
template <typename E>
hep_inline multi_vector<typename E::algebra, typename E::list> eval(
	E const& expr
) {
	return expr;
}

}

#endif
