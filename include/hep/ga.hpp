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
 * \f$ \mathcal{G}_{p,q} \f$ and template-expressions for many operations such
 * as addition, geometric product, inner and outer product. To improve the
 * efficiency of this library, SSE-optimized template specializations are
 * provided for typical expressions in high-energy physics applications.
 * However, <tt>hep-ga</tt> is not restricted to these and can be used everywere
 * Geometric Algebra is applied.
 *
 * \section origin_and_motivation Origin and Motivation
 *
 * The library is heavily based on the ideas of Jaap Suter's implementation
 * \cite JaapSuterVitalImpl which are partially described in
 * \cite JaapSuterVital. In contrast to this existing implementation
 * <tt>hep-ga</tt> makes use of some of the new features of C++11. This allows,
 * for an automatic type deduction of arbitrary expressions. Another major
 * difference is that <tt>hep-ga</tt> allows the user to selectively in- or
 * exclude the components of every basis-blade instead of the grades of blades.
 *
 * \section installation_and_testing Installation and Testing
 *
 * <tt>hep-ga</tt> is a header-only library which requires no compilation. To
 * install it, use the usual series of commands for autotools-based projects,
 * for example:
 * \code
 * ./configure --prefix=/usr/local --enable-doxygen
 * make
 * make install
 * \endcode
 * This will generate the Doxygen documentation for this library first and
 * installs it in the second step to <tt>/usr/local/doc/hep-ga</tt>. The headers
 * are installed to <tt>/usr/local/include</tt>. You may change these
 * directories by specifying additional options to <tt>./configure</tt>. The
 * following command gives you a complete list of available configuration
 * options:
 * \code
 * ./configure --help
 * \endcode
 * If you want to run the test-suite, type
 * \code
 * make check
 * \endcode
 * In every case you will need a C++ compiler supporting parts of C++11. At the
 * time of writing, only GCC 4.7 is capable of compiling this library.
 *
 * \section how_to_use_hep_ga How to use hep-ga
 *
 * To use this library, you have to include its header first:
 * \code
 * #include <hep/ga.hpp>
 * \endcode
 * Multi-vectors are defined by using the \c multi_vector class. For example,
 * two multi-vectors representing complex numbers are defined as:
 * \code
 * // - float -> type used for numerical comutations
 * // - 2,0 -> Euclidean plane (3,0 -> Euclidean space; 1,3 -> Minkowski space)
 * typedef hep::algebra<float, 2, 0> plane;
 * // - 0,3 means scalar + bivector
 * typedef hep::multi_vector<plane, hep::list<0,3>> complex;
 *
 * complex a = { 2.0f, 3.0f };
 * complex b = { 5.0f, 7.0f };
 * \endcode
 * To simplify matters, you should use type definitions for your different
 * multi-vectors (as shown above).
 *
 * In order to speed up calculations, the type of basis-blades which can be
 * handled with a \c multi_vector must be explitly stated in its definition.
 * In the example above, you can see that a complex number consists of a
 * scalar (index \c 0) and a bivector (index \c 3).
 *
 * Note that every operation automatically computes the resulting grades, e.g.
 * the geometric product of \c a and \c b is also a \c complex
 * \code
 * auto c = hep::eval(a * b);
 * \endcode
 * This automatic type-deduction does not take algebraic relations into account,
 * i.e. if certain grades vanish, those will nevertheless be present. In that
 * case you may use the grade function to select the desired grades:
 * \code
 * // select scalar part (=0) of c
 * complex d = hep::grade<0>(c);
 * \endcode
 */

namespace hep {}

#include <hep/algebra.hpp>
#include <hep/blade.hpp>
#include <hep/difference.hpp>
#include <hep/eval.hpp>
#include <hep/grade.hpp>
#include <hep/inner_product.hpp>
#include <hep/multi_vector.hpp>
#include <hep/negation.hpp>
#include <hep/product.hpp>
#include <hep/selection.hpp>
#include <hep/sum.hpp>

#endif
