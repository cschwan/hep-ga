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

#include <hep/list/list.hpp>

#include <hep/algebra.hpp>
#include <hep/blade.hpp>
#include <hep/difference.hpp>
#include <hep/eval.hpp>
#include <hep/grade.hpp>
#include <hep/inner_product.hpp>
#include <hep/multi_vector.hpp>
#include <hep/negation.hpp>
#include <hep/outer_product.hpp>
#include <hep/product.hpp>
#include <hep/reversion.hpp>
#include <hep/selection.hpp>
#include <hep/stream.hpp>
#include <hep/sum.hpp>

namespace hep
{

/**
 * \mainpage Expression Template Library for Geometric Algebra
 *
 * \section description Description of the Project
 *
 * <tt>hep-ga</tt> is a C++ library for efficient numeric calculations with
 * geometric algebra. It provides a template class for multi-vectors of
 * \f$ \mathcal{G}(p,q) \f$ and template-expressions for many operations such as
 * addition, geometric product, inner and outer product. Although intended to be
 * used in the context of high energy physics, <tt>hep-ga</tt> is not restricted
 * to it and can be used everywere geometric algebra is applied.
 *
 * \section introduction Short Introduction
 *
 * To use this library, you have to include its header first:
 * \snippet mainpage.cpp header
 * The primary type you will be working with is the \ref multi_vector class.
 * Depending on how you specify its template parameters, this type represents
 * scalars, vectors, spinors, pseudoscalars, etc. Because of that you need to
 * know two additional types.
 *
 * The first one is the \ref algebra class, by which you define the geometric
 * algebra you want to use. For example, if you want to work in
 * three-dimensional (euclidean) space, you will need to define the following
 * type:
 * \snippet mainpage.cpp algebra
 * In this case we also stated that we want to work with \c double as the
 * underlying numerical type. In general, you can use any type supporting the
 * basic arithmetic operators (<tt>+</tt>, <tt>-</tt>, <tt>*</tt> and
 * <tt>/</tt>). You can find more about this in the documentation of the
 * \ref algebra class.
 *
 * Next, you need to specify the components you want to include in your type.
 * For example, if you want to get a type representing vectors, you would write
 * \snippet mainpage.cpp components
 * Note that the indices reprent basis-blades as specified e.g. in
 * \cite Gaigen2. For vectors these indices are powers of 2. A more detailed
 * introduction and description of this representation is found on the page
 * \subpage bitmap_representation.
 *
 * Finally, a vector is defined with
 * \snippet mainpage.cpp vector
 * If your project uses only a single algebra, you may include the file
 * hep/ga_types.hpp into your namespace and use the predefined types defined
 * there.
 *
 * Let us now come to an example for some operations on multi vectors. A
 * complete list of possible operations is found on the page for
 * \ref expressions. Adding vectors is done by simply using the addition
 * operator:
 * \snippet mainpage.cpp vector_sum
 * Multiplication of two vectors will yield a quaternion, for which we define
 * a new type:
 * \snippet mainpage.cpp quaternion
 * Note that every operation generates an <i>expression object</i>, which is
 * coverted to a \c multi_vector in assignments. If you do not specify the
 * resulting type, you therefore might have to explicitly evaluate this
 * expression object. This means that in the previous example we could also
 * have written:
 * \snippet mainpage.cpp auto
 * For that you do not need to define the \c quaternion type.
 */

/**
 * \page bitmap_representation Bitmap Resentation of Basis Blades
 *
 * \section problem Problem
 *
 * The possible components of a multi-vector are determined by the algebra
 * containing it. For example, a general multi-vector \f$ A \in \mathcal{G}(2,0)
 * \f$ can be written as
 * \f[
 *     A = c^0 \cdot 1 + c^1 e_1 + c^2 e_2 + c^3 e_1 e_2
 * \f]
 * where \f$ c^0, c^1, c^2, c^3 \f$ are called the components of the
 * multi-vector. In general, a multi-vector from an algebra \f$ \mathcal{G}(p,q)
 * \f$ will have \f$ 2^{p+q} \f$ possible components. However, in practise one
 * does not use all components of a multi-vector. If one in the example above
 * one would like to work with the vector-part only, there is no point in
 * carrying the components \f$ c^0 = c^3 = 0 \f$ within a multi-vector. For this
 * reason the \ref multi_vector class is templatized and allows one to
 * selectively include the components. For this one has to find a way to map the
 * components to a number.
 *
 * \section mapping The Mapping in Detail
 *
 * For \f$ \mathcal{G}(2,0) \f$ this library uses the following mapping:
 * <center>
 * <table>
 * <tr><th>Bitmap</th><th>Blade</th></tr>
 * <tr><td>\f$ 00_2 = 0 \f$</td><td>\f$ 1 \f$</td></tr>
 * <tr><td>\f$ 01_2 = 1 \f$</td><td>\f$ e_1 \f$</td></tr>
 * <tr><td>\f$ 10_2 = 2 \f$</td><td>\f$ e_2 \f$</td></tr>
 * <tr><td>\f$ 11_2 = 3 \f$</td><td>\f$ e_1 e_2 \f$</td></tr>
 * </table>
 * </center>
 * In general, we make use of the fact that there a \f$ 2^n \f$ elements to map
 * and that the algebra can be constructed by vectors. If we assign each vector
 * a power of two we can map the remaining elements by <tt>OR</tt>ing the
 * corresponding mappings of the vectors. The mapping of the vectors is so that
 * the position of the bit set to '1' (there is only one bit set in powers of
 * two) identifies the vector. To better understand this scheme, look at the
 * mapping of blades of \f$ \mathcal{G}(3,0) \f$ (for this algebra one usually
 * denotes the vectors with \f$ \sigma \f$ instead of \f$ e \f$):
 * <center>
 * <table>
 * <tr><th>Bitmap</th><th>Blade</th></tr>
 * <tr><td>\f$ 000_2 = 0 \f$</td><td>\f$ 1 \f$</td></tr>
 * <tr><td>\f$ 001_2 = 1 \f$</td><td>\f$ \sigma_1 \f$</td></tr>
 * <tr><td>\f$ 010_2 = 2 \f$</td><td>\f$ \sigma_2 \f$</td></tr>
 * <tr><td>\f$ 011_2 = 3 \f$</td><td>\f$ \sigma_1 \sigma_2 \f$</td></tr>
 * <tr><td>\f$ 100_2 = 4 \f$</td><td>\f$ \sigma_3 \f$</td></tr>
 * <tr><td>\f$ 101_2 = 5 \f$</td><td>\f$ \sigma_1 \sigma_3 \f$</td></tr>
 * <tr><td>\f$ 110_2 = 6 \f$</td><td>\f$ \sigma_2 \sigma_3 \f$</td></tr>
 * <tr>
 *     <td>\f$ 111_2 = 7 \f$</td>
 *     <td>\f$ \sigma_1 \sigma_2 \sigma_3 \f$</td>
 * </tr>
 * </table>
 * </center>
 * Note that the vectors are denoted by bitmaps which are powers of two. The bit
 * position represents the number of the bit. Further note that e.g. the bitmap
 * of blade \f$ \sigma_1 \sigma_3 \f$ is determined by the bitmaps of the
 * underlying vectors as the following calculation shows:
 * \f[
 *     \underbrace{001_2}_{\sigma_1} \, \mathtt{OR} \,
 *     \underbrace{100_2}_{\sigma_3} = \underbrace{101_2}_{\sigma_1 \sigma_3}
 * \f]
 * As a last example, the following table shows the components of \f$
 * \mathcal{G}(1,3) \f$:
 * <center>
 * <table>
 * <tr><th>Bitmap</th><th>Blade</th></tr>
 * <tr><td>\f$ 0000_2 = 0 \f$</td><td>\f$ 1 \f$</td></tr>
 * <tr><td>\f$ 0001_2 = 1 \f$</td><td>\f$ \gamma_0 \f$</td></tr>
 * <tr><td>\f$ 0010_2 = 2 \f$</td><td>\f$ \gamma_1 \f$</td></tr>
 * <tr><td>\f$ 0011_2 = 3 \f$</td><td>\f$ \gamma_0 \gamma_1 \f$</td></tr>
 * <tr><td>\f$ 0100_2 = 4 \f$</td><td>\f$ \gamma_2 \f$</td></tr>
 * <tr><td>\f$ 0101_2 = 5 \f$</td><td>\f$ \gamma_0 \gamma_2 \f$</td></tr>
 * <tr><td>\f$ 0110_2 = 6 \f$</td><td>\f$ \gamma_1 \gamma_2 \f$</td></tr>
 * <tr>
 *     <td>\f$ 0111_2 = 7 \f$</td>
 *     <td>\f$ \gamma_0 \gamma_1 \gamma_2 \f$</td>
 * </tr>
 * <tr><td>\f$ 1000_2 = 8 \f$</td><td>\f$ \gamma_3 \f$</td></tr>
 * <tr><td>\f$ 1001_2 = 9 \f$</td><td>\f$ \gamma_0 \gamma_3 \f$</td></tr>
 * <tr><td>\f$ 1010_2 = 10 \f$</td><td>\f$ \gamma_1 \gamma_3 \f$</td></tr>
 * <tr>
 *     <td>\f$ 1011_2 = 11 \f$</td>
 *     <td>\f$ \gamma_0 \gamma_1 \gamma_3 \f$</td>
 * </tr>
 * <tr><td>\f$ 1100_2 = 12 \f$</td><td>\f$ \gamma_2 \gamma_3 \f$</td></tr>
 * <tr>
 *     <td>\f$ 1101_2 = 13 \f$</td>
 *     <td>\f$ \gamma_0 \gamma_2 \gamma_3 \f$</td>
 * </tr>
 * <tr>
 *     <td>\f$ 1110_2 = 14 \f$</td>
 *     <td>\f$ \gamma_1 \gamma_2 \gamma_3 \f$</td>
 * </tr>
 * <tr>
 *     <td>\f$ 1111_2 = 15 \f$</td>
 *     <td>\f$ \gamma_0 \gamma_1 \gamma_2 \gamma_3 \f$</td>
 * </tr>
 * </table>
 * </center>
 */

}

/**
 * \example eval.cpp
 * \example mainpage.cpp
 * \example spinors.cpp
 */

#endif
