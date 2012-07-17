#ifndef HEP_GA_IMPL_STREAM_HPP
#define HEP_GA_IMPL_STREAM_HPP

#include <hep/ga/stream.hpp>

namespace std
{

template <typename C, typename T, typename A>
inline basic_ostream<C, T>& operator<<(
	basic_ostream<C, T>& out,
	hep::multi_vector<A, hep::list<0>> const& scalar)
{
	return out << scalar.template at<0>();
}

}

#endif
