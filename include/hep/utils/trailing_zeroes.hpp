#ifndef HEP_UTILS_TRAILING_ZEROES_HPP
#define HEP_UTILS_TRAILING_ZEROES_HPP

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

#include <cstddef>

namespace hep
{

/// \cond DOXYGEN_IGNORE
constexpr std::size_t recursive_trailing_zeroes(std::size_t number)
{
	return (number & 1) ? 0 : recursive_trailing_zeroes(number >> 1) + 1;
}
/// \endcond

/**
 * Returns the number of trailing zeroes for \c number.
 */
constexpr std::size_t trailing_zeroes(std::size_t number)
{
	return (number == 0) ? (8 * sizeof (std::size_t)) :
		recursive_trailing_zeroes(number);
}

}

#endif
