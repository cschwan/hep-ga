#ifndef HEP_GA_HPP
#define HEP_GA_HPP

/*
 * hep-ga - An Efficient Numeric Template Library for Geometric Algebra
 * Copyright (C) 2011  Christopher Schwan
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
 * Hep-ga is a C++11 library for numeric treatment of Geometric Algebra. It
 * provides a template class for multi-vectors in \f$ \mathcal{G}_{p,q} \f$ and
 * the corresponding operations, such as the geometric product, dot product and
 * wedge product.
 *
 * The implementation is based on Jaap Suter's ideas described in his
 * implementation \cite JaapSuterVital and making use of the new features of
 * C++11 which allow for much simpler coding. Therefore, in order to use this
 * library, you will need a recent C++ compiler supporting at least the
 * following features:
 *
 *   - Variadic templates
 *   - Generalized const expressions (constexpr)
 *
 * GCC users will need at least version 4.5 in order use hep-ga.
 *
 * \section geometric_algebra Geometric Algebra
 *
 * There are a lot of good introductions to Geometric Algebra available, e.g. in
 * \cite GAForPhysicists. If you do not have access to this book, I recommend
 * reading papers freely available online \cite PHDDoran, \cite GAPrimer,
 * \cite ImagNumAreNotReal, \cite PrimerOnGA. If you are interested in
 * implementation details, take a look at the software documentation of NKlein's
 * GA implementation \cite NKlein.
 *
 * \section how_to_use_hep_ga How to use hep-ga
 *
 * To use this library, you first have to include its header:
 * \code
 * #include <hep/ga.hpp>
 * \endcode
 * Multi-vectors are defined by using the multi_vector class. For example, a
 * multi_vector in \f$ \mathcal{G}_{2,0} \f$ is defined as
 * \code
 * typedef hep::multi_vector<float, 2, 0> mv2;
 *
 * mv2 a = { 1.0f, 0.0f, 0.0f,  1.0f };
 * mv2 b = { 1.0f, 0.0f, 0.0f, -1.0f };
 * mv2 c;
 * \endcode
 * The first multi-vector \c a is a scalar plus a bivector with components
 * initialized to \c 1.0, the vector part is zero. Note that you do not
 * need to specify every component; unspecified components are initialized with
 * zero.
 *
 * The geometric product is evaluated by simply using the multiplication
 * operator:
 * \code
 * c = a * b;
 * \endcode
 *
 * For further examples have a look at the examples section.
 */

namespace hep {}

#include <hep/multi_vector.hpp>
#include <hep/operations.hpp>

/**
 * \example test_multi_vector.cpp
 * \example test_geometric_product_for_g2.cpp
 * \example test_geometric_product_for_g3.cpp
 * \example test_geometric_product_for_g4.cpp
 */

#endif
