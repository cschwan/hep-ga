#include <cstddef>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <std::size_t L>
using mv2 = hep::multi_vector<hep::algebra<float, 2, 0>, L>;

BOOST_AUTO_TEST_CASE(grade_selection)
{
	auto mvs = std::make_tuple(
		mv2<1>{ 2.0f },
		mv2<2>{ 3.0f, 5.0f },
		mv2<4>{ 7.0f },
		mv2<3>{ 11.0f, 13.0f, 17.0f },
		mv2<5>{ 19.0f, 23.0f },
		mv2<6>{ 29.0f, 31.0f, 37.0f },
		mv2<7>{ 41.0f, 43.0f, 47.0f, 53.0f }
	);

	// scalars
	auto grade_0 = std::make_tuple(
		hep::grade<1>(std::get<0>(mvs)),
		hep::grade<1>(std::get<1>(mvs)),
		hep::grade<1>(std::get<2>(mvs)),
		hep::grade<1>(std::get<3>(mvs)),
		hep::grade<1>(std::get<4>(mvs)),
		hep::grade<1>(std::get<5>(mvs)),
		hep::grade<1>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_0)[0], 2.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_0)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_0)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_0)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_0)[0], 19.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_0)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_0)[0], 41.0f);

	// vectors
	auto grade_1 = std::make_tuple(
		hep::grade<2>(std::get<0>(mvs)),
		hep::grade<2>(std::get<1>(mvs)),
		hep::grade<2>(std::get<2>(mvs)),
		hep::grade<2>(std::get<3>(mvs)),
		hep::grade<2>(std::get<4>(mvs)),
		hep::grade<2>(std::get<5>(mvs)),
		hep::grade<2>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_1)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_1)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_1)[0], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_1)[1], 5.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_1)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_1)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_1)[0], 13.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_1)[1], 17.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_1)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_1)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_1)[0], 29.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_1)[1], 31.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_1)[0], 43.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_1)[1], 47.0f);

	// bivectors
	auto grade_2 = std::make_tuple(
		hep::grade<4>(std::get<0>(mvs)),
		hep::grade<4>(std::get<1>(mvs)),
		hep::grade<4>(std::get<2>(mvs)),
		hep::grade<4>(std::get<3>(mvs)),
		hep::grade<4>(std::get<4>(mvs)),
		hep::grade<4>(std::get<5>(mvs)),
		hep::grade<4>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_2)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_2)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_2)[0], 7.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_2)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_2)[0], 23.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_2)[0], 37.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_2)[0], 53.0f);

	// scalars + vectors
	auto grade_01 = std::make_tuple(
		hep::grade<3>(std::get<0>(mvs)),
		hep::grade<3>(std::get<1>(mvs)),
		hep::grade<3>(std::get<2>(mvs)),
		hep::grade<3>(std::get<3>(mvs)),
		hep::grade<3>(std::get<4>(mvs)),
		hep::grade<3>(std::get<5>(mvs)),
		hep::grade<3>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_01)[0], 2.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_01)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_01)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_01)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_01)[1], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_01)[2], 5.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_01)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_01)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_01)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_01)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_01)[1], 13.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_01)[2], 17.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_01)[0], 19.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_01)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_01)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_01)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_01)[1], 29.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_01)[2], 31.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_01)[0], 41.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_01)[1], 43.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_01)[2], 47.0f);

	// scalars + bivectors
	auto grade_02 = std::make_tuple(
		hep::grade<5>(std::get<0>(mvs)),
		hep::grade<5>(std::get<1>(mvs)),
		hep::grade<5>(std::get<2>(mvs)),
		hep::grade<5>(std::get<3>(mvs)),
		hep::grade<5>(std::get<4>(mvs)),
		hep::grade<5>(std::get<5>(mvs)),
		hep::grade<5>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_02)[0], 2.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_02)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_02)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_02)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_02)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_02)[1], 7.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_02)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_02)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_02)[0], 19.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_02)[1], 23.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_02)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_02)[1], 37.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_02)[0], 41.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_02)[1], 53.0f);

	// vectors + bivectors
	auto grade_12 = std::make_tuple(
		hep::grade<6>(std::get<0>(mvs)),
		hep::grade<6>(std::get<1>(mvs)),
		hep::grade<6>(std::get<2>(mvs)),
		hep::grade<6>(std::get<3>(mvs)),
		hep::grade<6>(std::get<4>(mvs)),
		hep::grade<6>(std::get<5>(mvs)),
		hep::grade<6>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_12)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_12)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_12)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_12)[0], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_12)[1], 5.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_12)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_12)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_12)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_12)[2], 7.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_12)[0], 13.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_12)[1], 17.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_12)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_12)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_12)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_12)[2], 23.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_12)[0], 29.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_12)[1], 31.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_12)[2], 37.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_12)[0], 43.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_12)[1], 47.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_12)[2], 53.0f);

	// scalars + vectors + bivectors
	auto grade_012 = std::make_tuple(
		hep::grade<7>(std::get<0>(mvs)),
		hep::grade<7>(std::get<1>(mvs)),
		hep::grade<7>(std::get<2>(mvs)),
		hep::grade<7>(std::get<3>(mvs)),
		hep::grade<7>(std::get<4>(mvs)),
		hep::grade<7>(std::get<5>(mvs)),
		hep::grade<7>(std::get<6>(mvs))
	);

	BOOST_CHECK_EQUAL(std::get<0>(grade_012)[0], 2.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_012)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_012)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<0>(grade_012)[3], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_012)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_012)[1], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_012)[2], 5.0f);
	BOOST_CHECK_EQUAL(std::get<1>(grade_012)[3], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_012)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_012)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_012)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<2>(grade_012)[3], 7.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_012)[0], 11.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_012)[1], 13.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_012)[2], 17.0f);
	BOOST_CHECK_EQUAL(std::get<3>(grade_012)[3], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_012)[0], 19.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_012)[1], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_012)[2], 0.0f);
	BOOST_CHECK_EQUAL(std::get<4>(grade_012)[3], 23.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_012)[0], 0.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_012)[1], 29.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_012)[2], 31.0f);
	BOOST_CHECK_EQUAL(std::get<5>(grade_012)[3], 37.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_012)[0], 41.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_012)[1], 43.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_012)[2], 47.0f);
	BOOST_CHECK_EQUAL(std::get<6>(grade_012)[3], 53.0f);
}
