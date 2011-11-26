#ifndef HEP_IMPLEMENTATION_MULTI_VECTOR_HPP
#define HEP_IMPLEMENTATION_MULTI_VECTOR_HPP

#include <hep/multi_vector.hpp>

#include <algorithm>

namespace hep
{

template <typename T, std::size_t P, std::size_t Q>
multi_vector<T, P, Q>::multi_vector()
{
	std::fill(m_components, m_components + no_of_components, T(0.0));
}

template <typename T, std::size_t P, std::size_t Q>
template <typename ... Args>
multi_vector<T, P, Q>::multi_vector(Args ... components)
	: m_components{components ...}
{
	static_assert(
		sizeof... (Args) == no_of_components,
		"not every component was specified"
	);
}

template <typename T, std::size_t P, std::size_t Q>
T& multi_vector<T, P, Q>::operator[](std::size_t index)
{
	return m_components[index];
}

template <typename T, std::size_t P, std::size_t Q>
T const& multi_vector<T, P, Q>::operator[](std::size_t index) const
{
	return m_components[index];
}

}

#endif
