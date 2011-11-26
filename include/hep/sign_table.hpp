#ifndef HEP_SIGN_TABLE_HPP
#define HEP_SIGN_TABLE_HPP

#include <cstddef>

namespace hep
{

/**
 * Returns the sign for multiplication of components \c i and \c j of two
 * multi-vectors.
 *
 * \tparam T Type used for components of the multi vector
 * \tparam P Number of basis vectors which square to \f$ +1 \f$
 * \tparam Q Number of basis vectors which square to \f$ -1 \f$
 */
template <typename T, std::size_t P, std::size_t Q>
constexpr T sign_table(std::size_t i, std::size_t j);

}

#include <hep/implementation/sign_table.hpp>

#endif
