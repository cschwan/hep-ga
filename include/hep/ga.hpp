#ifndef HEP_GA_HPP
#define HEP_GA_HPP

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

/**
 * \mainpage An Efficient Numeric Template Library for Geometric Algebra
 *
 * \section introduction Introduction
 *
 * <tt>hep-ga</tt> is a C++ library for numeric calculations with Geometric
 * Algebra. It provides a template class for multi-vectors in
 * \f$ \mathcal{G}_{p,q} \f$ and a template-expression mechanism for many
 * operations, such as addition, geometric product, inner and outer product.
 *
 * \section technical_details Technical Details
 *
 * The main concepts are based on Jaap Suter's implementation and his ideas
 * described in \cite JaapSuterVital. <tt>hep-ga</tt> uses some of the new C++11
 * features and thus requires your compiler to support these. In particular,
 * the following features must be supported:
 *   - Variadic templates
 *   - Right angle brackets
 *   - Generalized constant expressions
 *   - Static assertions
 *   - <tt>auto</tt>-typed variables
 *
 * \section installation Installation
 *
 * <tt>hep-ga</tt> is a header-only library which makes installation very easy.
 * To install it, use the usual series of commands for autotools-based projects,
 * for example:
 * \code
 * ./configure --prefix=/usr/local --disable-doxygen
 * make
 * make install
 * \endcode
 * This will install the headers into <tt>/usr/local/include</tt> and will not
 * generate doxygen documentation. The following command lists additional
 * options available for the configure step:
 * \code
 * ./configure --help
 * \endcode
 *
 * \section how_to_use_hep_ga How to use hep-ga
 *
 * To use this library, you first have to include its header:
 * \code
 * #include <hep/ga.hpp>
 * \endcode
 * Multi-vectors are defined by using the \c multi_vector class. For example,
 * two multi-vectors representing complex numbers are defined as:
 * \code
 * // - float -> type used for numerical comutations
 * // - 2,0 -> Euclidean plane (3,0 -> Euclidean space; 1,3 -> Minkowski space)
 * typedef hep::algebra<float, 2, 0> plane;
 * // - 0,3 means scalar + bivector (log 1 = 0, log 4 = 2)
 * typedef hep::multi_vector<plane, hep::list<0,3>> complex;
 *
 * complex a = { 2.0f, 3.0f };
 * complex b = { 5.0f, 7.0f };
 * \endcode
 * To simplify matters, you should use type definitions for your different
 * multi-vectors (shown above).
 *
 * In order to speed up calculations, the type of basis-blades which can be
 * handled with a \c multi_vector must be explitly stated in its definition.
 * In the example above, you can see that a complex number consists of a
 * scalar (index \c 0) and a bivector (index \c 3).
 *
 * Note that every operation automatically computes the resulting grades, e.g.
 * the geometric product of \c a and \c b is also a \c complex
 * \code
 * auto c = a * b;
 * \endcode
 * This automatic type-deduction does not take algebraic relations into account,
 * i.e. if certain grades vanish, those will nevertheless be present. In that
 * case you may use the grade function to select the desired grades:
 * \code
 * // select scalar part (=0) of c
 * complex d = hep::grade<0>(c);
 * \endcode
 *
 * \section recommended_reading Recommended Reading
 *
 * If you want to learn Geometric Algebra and you are interested in its
 * applications in physics, we recommend you to read \cite GAForPhysicists. We
 * also recommend to read papers which are freely available online:
 * \cite PHDDoran, \cite GAPrimer, \cite ImagNumAreNotReal, \cite PrimerOnGA.
 * If you are interested in implementation-related concepts, have a look at the
 * software documentation of NKlein's GA implementation \cite NKlein.
 *
 */

// To make expression templates efficient, it is of _uttermost importance_ to
// inline functions REGARDLESS OF WHAT THE COMPILER THINKS. For these functions
// HEP_INLINE is defined.
#if defined(__GNUG__) && !defined(__NO_INLINE__)
#define HEP_INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER) || defined(__INTEL_COMPILER)
// TODO: not tested
#define HEP_INLINE __forceinline
#else
#define HEP_INLINE inline
#endif

namespace hep {}

#include <hep/algebra.hpp>
#include <hep/difference.hpp>
#include <hep/grade.hpp>
#include <hep/inner_product.hpp>
#include <hep/multi_vector.hpp>
#include <hep/negation.hpp>
#include <hep/product.hpp>
#include <hep/sum.hpp>

#endif
