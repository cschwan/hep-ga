#ifndef HEP_GA_HPP
#define HEP_GA_HPP

/**
 * \mainpage An Efficient Numeric Template Library for Geometric Algebra
 *
 * \section introduction Introduction
 *
 * Hep-ga is a C++11 library for numeric treatment of Geometric Algebra. It
 * provides a template class for multi-vectors in \f$ \mathcal{G}_{p,q} \f$ and
 * the corresponding operations, such as the geometric product, dot product,
 * wedge product and much more.
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
 * \section geometric_algebra Geometric Algebra
 *
 * There are a lot of good introductions to Geometric Algebra available, e.g. in
 * \cite GAForPhysicists. If you do not have access to this book, I recommend
 * reading papers freely available online \cite PHDDoran, \cite GAPrimer,
 * \cite ImagNumAreNotReal, \cite PrimerOnGA. If you are interested in
 * implementation details, take a look at the software documentation of NKlein's
 * GA implementation \cite NKlein.
 *
 * \section usage_of_this_library Usage of This Library
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
 * initialized to one, the vector part is zero. Note that you have to specify
 * every component of a multi_vector or no component, as shown with the
 * definition of \c c. In this case all component are initialized to zero.
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
 * \example test_ga.cpp
 */

#endif
