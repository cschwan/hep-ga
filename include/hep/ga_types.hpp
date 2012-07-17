#ifndef HEP_GA_TYPES_HPP
#define HEP_GA_TYPES_HPP

#include <hep/ga/list/list.hpp>
#include <hep/ga/algebra.hpp>
#include <hep/ga/multi_vector.hpp>

#ifndef HEP_ALGEBRA_SCALAR_TYPE
#define HEP_ALGEBRA_SCALAR_TYPE double
#endif

#ifndef HEP_ALGEBRA_P
#define HEP_ALGEBRA_P 1
#endif

#ifndef HEP_ALGEBRA_Q
#define HEP_ALGEBRA_Q 3
#endif

#define HEP_ALGEBRA_DEFAULT \
	hep::algebra< \
		HEP_ALGEBRA_SCALAR_TYPE, \
		HEP_ALGEBRA_P, \
		HEP_ALGEBRA_Q \
	>

/**
 * 
 */
template <int... components>
using mv2 = hep::multi_vector<
	hep::algebra<HEP_ALGEBRA_SCALAR_TYPE, 2, 0>,
	hep::list<components...>
>;

/**
 * 
 */
template <int... components>
using mv3 = hep::multi_vector<
	hep::algebra<HEP_ALGEBRA_SCALAR_TYPE, 3, 0>,
	hep::list<components...>
>;

/**
 * 
 */
template <int... components>
using mv4 = hep::multi_vector<
	hep::algebra<HEP_ALGEBRA_SCALAR_TYPE, 1, 3>,
	hep::list<components...>
>;

#endif
