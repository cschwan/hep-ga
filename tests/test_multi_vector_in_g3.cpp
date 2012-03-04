#include <cstddef>
#include <tuple>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (3,0) and general grade list
template <std::size_t L>
using mv3 = hep::multi_vector<hep::algebra<float, 3, 0>, L>;

BOOST_AUTO_TEST_CASE(component_access)
{
	auto mvs = std::make_tuple(
		mv3< 1>{ 2.0f },
		mv3< 2>{ 3.0f, 5.0f, 7.0f },
		mv3< 4>{ 11.0f, 13.0f, 17.0f },
		mv3< 8>{ 19.0f },
		mv3< 3>{ 23.0f, 29.0f, 31.0f, 37.0f },
		mv3< 5>{ 41.0f, 43.0f, 47.0f, 53.0f },
		mv3< 9>{ 59.0f, 61.0f },
		mv3< 6>{ 67.0f, 71.0f, 79.0f, 73.0f,
		         83.0f, 89.0f },
		mv3<10>{ 97.0f, 101.0f, 103.0f, 107.0f },
		mv3<12>{ 109.0f, 113.0f, 127.0f, 131.0f },
		mv3< 7>{ 137.0f, 139.0f, 149.0f, 157.0f,
		         151.0f, 163.0f, 167.0f },
		mv3<11>{ 173.0f, 179.0f, 181.0f, 191.0f,
		         193.0f },
		mv3<13>{ 197.0f, 199.0f, 211.0f, 223.0f,
		         227.0f },
		mv3<14>{ 229.0f, 233.0f, 241.0f, 239.0f,
		         251.0f, 257.0f, 263.0f },
		mv3<15>{ 269.0f, 271.0f, 277.0f, 283.0f,
		         281.0f, 293.0f, 307.0f, 311.0f }
	);

	// scalar
	BOOST_CHECK_EQUAL(std::get<0>(mvs)[0], 2.0f);

	// vector
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[0], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[1], 5.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[2], 7.0f);

	// bivector
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[1], 13.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[2], 17.0f);

	// trivector
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[0], 19.0f);

	// scalar + vector
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[0], 23.0f);
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[1], 29.0f);
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[2], 31.0f);
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[3], 37.0f);

	// scalar + bivector
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[0], 41.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[1], 43.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[2], 47.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[3], 53.0f);

	// scalar + trivector
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[0], 59.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[1], 61.0f);

	// vector + bivector
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[0], 67.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[1], 71.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[2], 79.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[3], 73.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[4], 83.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[5], 89.0f);

	// vector + trivector
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[0], 97.0f);
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[1], 101.0f);
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[2], 103.0f);
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[3], 107.0f);

	// bivector + trivector
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[0], 109.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[1], 113.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[2], 127.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[3], 131.0f);

	// scalar + vector + bivector
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[0], 137.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[1], 139.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[2], 149.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[3], 157.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[4], 151.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[5], 163.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[6], 167.0f);

	// scalar + vector + trivector
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[0], 173.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[1], 179.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[2], 181.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[3], 191.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[4], 193.0f);

	// scalar + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[0], 197.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[1], 199.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[2], 211.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[3], 223.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[4], 227.0f);

	// vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[0], 229.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[1], 233.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[2], 241.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[3], 239.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[4], 251.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[5], 257.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[6], 263.0f);

	// scalar + vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[0], 269.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[1], 271.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[2], 277.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[3], 283.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[4], 281.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[5], 293.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[6], 307.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[7], 311.0f);
}
