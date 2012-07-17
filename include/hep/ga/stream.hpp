#ifndef HEP_GA_STREAM_HPP
#define HEP_GA_STREAM_HPP

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

#include <ostream>

namespace std
{

/**
 * Outstream operator for scalars. This simply prints the first (and only)
 * component of \c scalar.
 */
template <typename C, typename T, typename A>
basic_ostream<C, T>& operator<<(
	basic_ostream<C, T>& out,
	hep::multi_vector<A, hep::list<0>> const& scalar
);

}

#include <hep/ga/impl/stream.hpp>

#endif
