#ifndef HEP_OPERATIONS_HPP
#define HEP_OPERATIONS_HPP

#include <hep/multi_vector.hpp>

#include <cstddef>

namespace hep
{

/**
 * Implements the Geometric Product of two multi-vectors \c lhs and \c rhs.
 *
 * \tparam T Type used for components of the multi vector
 * \tparam P Number of basis vectors which square to \f$ +1 \f$
 * \tparam Q Number of basis vectors which square to \f$ -1 \f$
 */
template <typename T, std::size_t P, std::size_t Q>
multi_vector<T, P, Q> operator*(
	multi_vector<T, P, Q> const& lhs,
	multi_vector<T, P, Q> const& rhs
);

}

#include <hep/implementation/operations.hpp>

#endif
