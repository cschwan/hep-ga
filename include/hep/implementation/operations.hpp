#ifndef HEP_IMPLEMENTATION_OPERATIONS_HPP
#define HEP_IMPLEMENTATION_OPERATIONS_HPP

#include <hep/operations.hpp>
#include <hep/sign_table.hpp>

namespace hep
{

template <typename T, std::size_t P, std::size_t Q>
multi_vector<T, P, Q> operator*(
	multi_vector<T, P, Q> const& lhs,
	multi_vector<T, P, Q> const& rhs
) {
	multi_vector<T, P, Q> result;
	constexpr std::size_t no_of_components = (1 << (P + Q));

	for (std::size_t i = 0; i != no_of_components; ++i)
	{
		for (std::size_t j = 0; j != no_of_components; ++j)
		{
			result[i ^ j] += sign_table<T, P, Q>(i, j) * lhs[i] * rhs[j];
		}
	}

	return result;
}

}

#endif
