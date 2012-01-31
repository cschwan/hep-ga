#ifndef HEP_UTILS_BINOMIAL_COEFFICIENT_HPP
#define HEP_UTILS_BINOMIAL_COEFFICIENT_HPP

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

#include <cstddef>

namespace hep
{

/**
 * Computes the binomial coefficient n over k using the recurring formula:
 * \f[
 *     {n \choose k} = \frac{(n - k - 1) {n \choose k - 1}}{k}
 * \f]
 */
constexpr std::size_t binomial_coefficient(std::size_t n, std::size_t k)
{
	return (k > (n - k)) ? binomial_coefficient(n, n - k) : (
		(k == 0) ? 1 : (((n - k + 1) * binomial_coefficient(n, k - 1)) / k)
	);
}

}

#endif
