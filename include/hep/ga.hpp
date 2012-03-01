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
 * hep-ga is a C++ library for numeric calculations with Geometric Algebra. It
 * provides a template class for multi-vectors in \f$ \mathcal{G}_{p,q} \f$ and
 * template-expression based functions for the corresponding operations, such as
 * the geometric product, dot product and wedge product.
 *
 * \section technical_details Technical Details
 *
 * This library is largely based on Jaap Suter's implementation and his ideas
 * \cite JaapSuterVital. Opposed to existing implementations, hep-ga makes use
 * of C++11 features and thus requires the user to have a compiler supporting
 * certain features of this new C++ standard. In particular, the following
 * features are required:
 *   - Variadic Templates,
 *   - Constant Expression Eunctions and
 *   - Static Assertions.
 *
 * \section installation Installation
 *
 * hep-ga is a header-only library, so you do not need to install
 * any binaries or shared libraries. To install it, use the usual series of
 * commands for autotools-based projects, for example:
 * \code
 * ./configure --prefix=/usr/local --disable-doxygen
 * make
 * make install
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
 * // - 1+4 means scalar + bivector (log 1 = 0, log 4 = 2)
 * typedef hep::multi_vector<float, 2, 0, 1+4> complex;
 *
 * complex a = { 2.0f, 3.0f };
 * complex b = { 5.0f, 7.0f };
 * \endcode
 * To simplify matters, you should use type definitions for your different
 * multi-vectors (shown above) or use those defined in TODO which are useful for
 * physics-related computations.
 *
 * In order to speed up calculations, it was decided that the type of
 * basis-blades which can be handled with a \c multi_vector must be explitly
 * stated in its definition. In the example above, you can see that a complex
 * number consists of a scalar and a bivector. Since the grade of of a scalar is
 * zero and two of the bivector, the zeroeth and second bit in the grade list
 * must be set. This results in the number \c 1+4. Note that every operation
 * automatically computes the resulting grades, e.g. the geometric product of
 * \c a and \c b is also a \c complex
 * \code
 * complex c = a * b;
 * \endcode
 * This automatic type-deduction does not take into account algebraic relations,
 * i.e. if certain grades vanish, those will nevertheless be present. In that
 * case you may use the TODO function to select the desired grades:
 * \code
 * // select scalar part of c
 * complex d = hep::grade<1>(c);
 * \endcode
 *
 * For further examples have a look at the examples section.
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

namespace hep {}

#include <hep/grade.hpp>
#include <hep/multi_vector.hpp>
#include <hep/product.hpp>

/**
 * \example test_geometric_product_in_g2.cpp
 * \example test_geometric_product_in_g3.cpp
 * \example test_geometric_product_in_g4.cpp
 * \example test_grade_projection.cpp
 * \example test_multi_vector_in_g2.cpp
 * \example test_multi_vector_in_g3.cpp
 * \example test_multi_vector_in_g4.cpp
 */

#endif
