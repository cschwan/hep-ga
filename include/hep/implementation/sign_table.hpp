#ifndef HEP_IMPLEMENTATION_SIGN_TABLE_HPP
#define HEP_IMPLEMENTATION_SIGN_TABLE_HPP

#include <hep/sign_table.hpp>

namespace hep
{

/// \cond HEP_DOCUMENT_INTERNAL

/**
 * Computes the number of bits set to '1' in \c bits.
 */
constexpr std::size_t pop_count(std::size_t bits)
{
	return (bits == 0) ? 0 : 1 + pop_count(bits & (bits - 1));
}

/**
 * Recursive constexpr implementation for sign_table.
 */
template <std::size_t P, std::size_t Q>
constexpr int sign_table_loop(
	std::size_t i,
	std::size_t j,
	std::size_t k,
	std::size_t grade
) {
	// constexpr functions do not support variables, so we have to use the
	// preprocessor instead to write readable code
#define is_bit_set(x)   (((x) & (1 << k)) != 0)
#define i_pop_count     (grade + (is_bit_set(i) ? -1 : 0))
#define condition_1     (is_bit_set(j))
#define condition_2     (is_bit_set(i) && (k >= P))
#define condition_3     (i_pop_count & 1)

	// k is the loop variable; we start with 0 and end the recursion if k is P+Q
	return (k == P + Q) ? 1 : (
		((condition_1 && (condition_2 != condition_3)) ? -1 : 1) *
		sign_table_loop<P, Q>(i, j, k + 1, i_pop_count)
	);

#undef condition_3
#undef condition_2
#undef condition_1
#undef i_pop_count
#undef is_bit_set
}

/// \endcond

template <typename T, std::size_t P, std::size_t Q>
constexpr T sign_table(std::size_t i, std::size_t j)
{
	return T(sign_table_loop<P, Q>(i, j, 0, pop_count(i)));
}

}

#endif
