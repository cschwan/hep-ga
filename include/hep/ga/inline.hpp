#ifndef HEP_GA_INLINE_HPP
#define HEP_GA_INLINE_HPP

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

#ifdef __GNUG__

// this is the GNU C++ compiler. Force inlining if optimization is enabled
#ifndef __NO_INLINE__
#define hep_inline inline __attribute__((always_inline))
#else
#define hep_inline inline
#endif

#elif defined(_MSC_VER) || defined(__INTEL_COMPILER)

// this is the Microsoft or Intel C++ compiler -- NOT TESTED!
#define hep_inline __forceinline

#else

#warning compiler not supported - inlining will most likely not work

/**
 * Keyword forcing the compiler to inline.
 */
#define hep_inline inline

#endif

#endif
