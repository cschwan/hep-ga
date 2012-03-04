#include <cstddef>
#include <tuple>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <std::size_t L>
using mv2 = hep::multi_vector<hep::algebra<float, 2, 0>, L>;

auto mvs = std::make_tuple(
	mv2<1>{ 2.0f },
	mv2<2>{ 3.0f, 5.0f },
	mv2<4>{ 7.0f },
	mv2<3>{ 11.0f, 13.0f, 17.0f },
	mv2<5>{ 19.0f, 23.0f },
	mv2<6>{ 29.0f, 31.0f, 37.0f },
	mv2<7>{ 41.0f, 43.0f, 47.0f, 53.0f }
);

BOOST_AUTO_TEST_CASE(component_access)
{
	// scalar
	BOOST_CHECK_EQUAL(std::get<0>(mvs)[0], 2.0f);

	// vector
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[0], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[1], 5.0f);

	// bivector
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[0], 7.0f);

	// scalar + vector
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[1], 13.0f);
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[2], 17.0f);

	// scalar + bivector
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[0], 19.0f);
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[1], 23.0f);

	// vector + bivector
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[0], 29.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[1], 31.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[2], 37.0f);

	// scalar + vector + bivector
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[0], 41.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[1], 43.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[2], 47.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[3], 53.0f);
}
