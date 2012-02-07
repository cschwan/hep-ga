#include <tuple>

#include <hep/operations.hpp>

#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <std::size_t L>
using mv2 = hep::multi_vector<float, 2, 0, L>;

BOOST_AUTO_TEST_CASE(geometric_product)
{
	auto lhs = std::make_tuple(
		mv2<1>{ 2.0f },
		mv2<2>{ 5.0f, 7.0f },
		mv2<4>{ 17.0f },
		mv2<3>{ 23.0f, 29.0f, 31.0f },
		mv2<5>{ 47.0f, 53.0f },
		mv2<6>{ 67.0f, 71.0f, 73.0f },
		mv2<7>{ 97.0f, 101.0f, 103.0f, 107.0f }
	);

	auto rhs = std::make_tuple(
		mv2<1>{ 3.0f },
		mv2<2>{ 11.0f, 13.0f },
		mv2<4>{ 19.0f },
		mv2<3>{ 37.0f, 41.0f, 43.0f },
		mv2<5>{ 59.0f, 61.0f },
		mv2<6>{ 79.0f, 83.0f, 89.0f },
		mv2<7>{ 109.0f, 113.0f, 127.0f, 131.0f }
	);

	mv2<1> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00[0], 6.0f);

	mv2<2> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01[0], 22.0f);
	BOOST_CHECK_EQUAL(mv01[1], 26.0f);

	mv2<4> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02[0], 38.0f);

	mv2<3> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03[0], 74.0f);
	BOOST_CHECK_EQUAL(mv03[1], 82.0f);
	BOOST_CHECK_EQUAL(mv03[2], 86.0f);

	mv2<5> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04[0], 118.0f);
	BOOST_CHECK_EQUAL(mv04[1], 122.0f);

	mv2<6> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05[0], 158.0f);
	BOOST_CHECK_EQUAL(mv05[1], 166.0f);
	BOOST_CHECK_EQUAL(mv05[2], 178.0f);

	mv2<7> mv06 = std::get<0>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv06[0], 218.0f);
	BOOST_CHECK_EQUAL(mv06[1], 226.0f);
	BOOST_CHECK_EQUAL(mv06[2], 254.0f);
	BOOST_CHECK_EQUAL(mv06[3], 262.0f);

	mv2<2> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10[0], 15.0f);
	BOOST_CHECK_EQUAL(mv10[1], 21.0f);

	mv2<5> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11[0], 146.0f);
	BOOST_CHECK_EQUAL(mv11[1], -12.0f);

	mv2<2> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12[0], -133.0f);
	BOOST_CHECK_EQUAL(mv12[1], 95.0f);

	mv2<7> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13[0], 506.0f);
	BOOST_CHECK_EQUAL(mv13[1], 185.0f);
	BOOST_CHECK_EQUAL(mv13[2], 259.0f);
	BOOST_CHECK_EQUAL(mv13[3], -72.0f);

	mv2<2> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14[0], -132.0f);
	BOOST_CHECK_EQUAL(mv14[1], 718.0f);

	mv2<7> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15[0], 976.0f);
	BOOST_CHECK_EQUAL(mv15[1], -623.0f);
	BOOST_CHECK_EQUAL(mv15[2], 445.0f);
	BOOST_CHECK_EQUAL(mv15[3], -138.0f);

	mv2<7> mv16 = std::get<1>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv16[0], 1454.0f);
	BOOST_CHECK_EQUAL(mv16[1], -372.0f);
	BOOST_CHECK_EQUAL(mv16[2], 1418.0f);
	BOOST_CHECK_EQUAL(mv16[3], -156.0f);

	mv2<4> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20[0], 51.0f);

	mv2<2> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21[0], 221.0f);
	BOOST_CHECK_EQUAL(mv21[1], -187.0f);

	mv2<1> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22[0], -323.0f);

	mv2<6> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23[0], 731.0f);
	BOOST_CHECK_EQUAL(mv23[1], -697.0f);
	BOOST_CHECK_EQUAL(mv23[2], 629.0f);

	mv2<5> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24[0], -1037.0f);
	BOOST_CHECK_EQUAL(mv24[1], 1003.0f);

	mv2<3> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25[0], -1513.0f);
	BOOST_CHECK_EQUAL(mv25[1], 1411.0f);
	BOOST_CHECK_EQUAL(mv25[2], -1343.0f);

	mv2<7> mv26 = std::get<2>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv26[0], -2227.0f);
	BOOST_CHECK_EQUAL(mv26[1], 2159.0f);
	BOOST_CHECK_EQUAL(mv26[2], -1921.0f);
	BOOST_CHECK_EQUAL(mv26[3], 1853.0f);

	mv2<3> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30[0], 69.0f);
	BOOST_CHECK_EQUAL(mv30[1], 87.0f);
	BOOST_CHECK_EQUAL(mv30[2], 93.0f);

	mv2<7> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31[0], 722.0f);
	BOOST_CHECK_EQUAL(mv31[1], 253.0f);
	BOOST_CHECK_EQUAL(mv31[2], 299.0f);
	BOOST_CHECK_EQUAL(mv31[3], 36.0f);

	mv2<6> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32[0], -589.0f);
	BOOST_CHECK_EQUAL(mv32[1], 551.0f);
	BOOST_CHECK_EQUAL(mv32[2], 437.0f);

	mv2<7> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33[0], 3373.0f);
	BOOST_CHECK_EQUAL(mv33[1], 2016.0f);
	BOOST_CHECK_EQUAL(mv33[2], 2136.0f);
	BOOST_CHECK_EQUAL(mv33[3], -24.0f);

	mv2<7> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34[0], 1357.0f);
	BOOST_CHECK_EQUAL(mv34[1], -180.0f);
	BOOST_CHECK_EQUAL(mv34[2], 3598.0f);
	BOOST_CHECK_EQUAL(mv34[3], 1403.0f);

	mv2<7> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35[0], 4864.0f);
	BOOST_CHECK_EQUAL(mv35[1], -942.0f);
	BOOST_CHECK_EQUAL(mv35[2], 4490.0f);
	BOOST_CHECK_EQUAL(mv35[3], 2005.0f);

	mv2<7> mv36 = std::get<3>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv36[0], 9721.0f);
	BOOST_CHECK_EQUAL(mv36[1], 1699.0f);
	BOOST_CHECK_EQUAL(mv36[2], 10099.0f);
	BOOST_CHECK_EQUAL(mv36[3], 3193.0f);

	mv2<5> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40[0], 141.0f);
	BOOST_CHECK_EQUAL(mv40[1], 159.0f);

	mv2<2> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41[0], 1206.0f);
	BOOST_CHECK_EQUAL(mv41[1], 28.0f);

	mv2<5> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42[0], -1007.0f);
	BOOST_CHECK_EQUAL(mv42[1], 893.0f);

	mv2<7> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43[0], 1739.0f);
	BOOST_CHECK_EQUAL(mv43[1], 4206.0f);
	BOOST_CHECK_EQUAL(mv43[2], -152.0f);
	BOOST_CHECK_EQUAL(mv43[3], 1961.0f);

	mv2<5> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44[0], -460.0f);
	BOOST_CHECK_EQUAL(mv44[1], 5994.0f);

	mv2<7> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45[0], -4717.0f);
	BOOST_CHECK_EQUAL(mv45[1], 8112.0f);
	BOOST_CHECK_EQUAL(mv45[2], -286.0f);
	BOOST_CHECK_EQUAL(mv45[3], 4183.0f);

	mv2<7> mv46 = std::get<4>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv46[0], -1820.0f);
	BOOST_CHECK_EQUAL(mv46[1], 12042.0f);
	BOOST_CHECK_EQUAL(mv46[2], -20.0f);
	BOOST_CHECK_EQUAL(mv46[3], 11934.0f);

	mv2<6> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50[0], 201.0f);
	BOOST_CHECK_EQUAL(mv50[1], 213.0f);
	BOOST_CHECK_EQUAL(mv50[2], 219.0f);

	mv2<7> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51[0], 1660.0f);
	BOOST_CHECK_EQUAL(mv51[1], 949.0f);
	BOOST_CHECK_EQUAL(mv51[2], -803.0f);
	BOOST_CHECK_EQUAL(mv51[3], 90.0f);

	mv2<3> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52[0], -1387.0f);
	BOOST_CHECK_EQUAL(mv52[1], -1349.0f);
	BOOST_CHECK_EQUAL(mv52[2], 1273.0f);

	mv2<7> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53[0], 5800.0f);
	BOOST_CHECK_EQUAL(mv53[1], 5618.0f);
	BOOST_CHECK_EQUAL(mv53[2], -366.0f);
	BOOST_CHECK_EQUAL(mv53[3], 2671.0f);

	mv2<7> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54[0], -4453.0f);
	BOOST_CHECK_EQUAL(mv54[1], -378.0f);
	BOOST_CHECK_EQUAL(mv54[2], 8276.0f);
	BOOST_CHECK_EQUAL(mv54[3], 4307.0f);

	mv2<7> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55[0], 4689.0f);
	BOOST_CHECK_EQUAL(mv55[1], -260.0f);
	BOOST_CHECK_EQUAL(mv55[2], 196.0f);
	BOOST_CHECK_EQUAL(mv55[3], -48.0f);

	mv2<7> mv56 = std::get<5>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv56[0], 7025.0f);
	BOOST_CHECK_EQUAL(mv56[1], 7273.0f);
	BOOST_CHECK_EQUAL(mv56[2], 8267.0f);
	BOOST_CHECK_EQUAL(mv56[3], 8443.0f);

	mv2<7> mv60 = std::get<6>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv60[0], 291.0f);
	BOOST_CHECK_EQUAL(mv60[1], 303.0f);
	BOOST_CHECK_EQUAL(mv60[2], 309.0f);
	BOOST_CHECK_EQUAL(mv60[3], 321.0f);

	mv2<7> mv61 = std::get<6>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv61[0], 2450.0f);
	BOOST_CHECK_EQUAL(mv61[1], 2458.0f);
	BOOST_CHECK_EQUAL(mv61[2], 84.0f);
	BOOST_CHECK_EQUAL(mv61[3], 180.0f);

	mv2<7> mv62 = std::get<6>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv62[0], -2033.0f);
	BOOST_CHECK_EQUAL(mv62[1], -1957.0f);
	BOOST_CHECK_EQUAL(mv62[2], 1919.0f);
	BOOST_CHECK_EQUAL(mv62[3], 1843.0f);

	mv2<7> mv63 = std::get<6>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv63[0], 12159.0f);
	BOOST_CHECK_EQUAL(mv63[1], 12315.0f);
	BOOST_CHECK_EQUAL(mv63[2], 3595.0f);
	BOOST_CHECK_EQUAL(mv63[3], 4079.0f);

	mv2<7> mv64 = std::get<6>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv64[0], -804.0f);
	BOOST_CHECK_EQUAL(mv64[1], -324.0f);
	BOOST_CHECK_EQUAL(mv64[2], 12238.0f);
	BOOST_CHECK_EQUAL(mv64[3], 12230.0f);

	mv2<7> mv65 = std::get<6>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv65[0], 7005.0f);
	BOOST_CHECK_EQUAL(mv65[1], 7377.0f);
	BOOST_CHECK_EQUAL(mv65[2], 8587.0f);
	BOOST_CHECK_EQUAL(mv65[3], 8879.0f);

	mv2<7> mv66 = std::get<6>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv66[0], 21050.0f);
	BOOST_CHECK_EQUAL(mv66[1], 22066.0f);
	BOOST_CHECK_EQUAL(mv66[2], 24686.0f);
	BOOST_CHECK_EQUAL(mv66[3], 25558.0f);
}
