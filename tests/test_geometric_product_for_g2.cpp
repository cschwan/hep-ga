#include <tuple>

#include <hep/operations.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(geometric_product_for_g2)
{
	auto lhs = std::make_tuple(
		hep::multi_vector<float, 2, 0>{ 2.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 5.0f, 7.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 0.0f, 0.0f, 17.0f },
		hep::multi_vector<float, 2, 0>{ 23.0f, 29.0f, 31.0f },
		hep::multi_vector<float, 2, 0>{ 47.0f, 0.0f, 0.0f, 53.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 67.0f, 71.0f, 73.0f },
		hep::multi_vector<float, 2, 0>{ 97.0f, 101.0f, 103.0f, 107.0f }
	);

	auto rhs = std::make_tuple(
		hep::multi_vector<float, 2, 0>{ 3.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 11.0f, 13.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 0.0f, 0.0f, 19.0f },
		hep::multi_vector<float, 2, 0>{ 37.0f, 41.0f, 43.0f },
		hep::multi_vector<float, 2, 0>{ 59.0f, 0.0f, 0.0f, 61.0f },
		hep::multi_vector<float, 2, 0>{ 0.0f, 79.0f, 83.0f, 89.0f },
		hep::multi_vector<float, 2, 0>{ 109.0f, 113.0f, 127.0f, 131.0f }
	);

	hep::multi_vector<float, 2, 0> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00[0], 6.0f);
	BOOST_CHECK_EQUAL(mv00[1], 0.0f);
	BOOST_CHECK_EQUAL(mv00[2], 0.0f);
	BOOST_CHECK_EQUAL(mv00[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01[0], 0.0f);
	BOOST_CHECK_EQUAL(mv01[1], 22.0f);
	BOOST_CHECK_EQUAL(mv01[2], 26.0f);
	BOOST_CHECK_EQUAL(mv01[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02[0], 0.0f);
	BOOST_CHECK_EQUAL(mv02[1], 0.0f);
	BOOST_CHECK_EQUAL(mv02[2], 0.0f);
	BOOST_CHECK_EQUAL(mv02[3], 38.0f);

	hep::multi_vector<float, 2, 0> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03[0], 74.0f);
	BOOST_CHECK_EQUAL(mv03[1], 82.0f);
	BOOST_CHECK_EQUAL(mv03[2], 86.0f);
	BOOST_CHECK_EQUAL(mv03[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04[0], 118.0f);
	BOOST_CHECK_EQUAL(mv04[1], 0.0f);
	BOOST_CHECK_EQUAL(mv04[2], 0.0f);
	BOOST_CHECK_EQUAL(mv04[3], 122.0f);

	hep::multi_vector<float, 2, 0> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05[0], 0.0f);
	BOOST_CHECK_EQUAL(mv05[1], 158.0f);
	BOOST_CHECK_EQUAL(mv05[2], 166.0f);
	BOOST_CHECK_EQUAL(mv05[3], 178.0f);

	hep::multi_vector<float, 2, 0> mv06 = std::get<0>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv06[0], 218.0f);
	BOOST_CHECK_EQUAL(mv06[1], 226.0f);
	BOOST_CHECK_EQUAL(mv06[2], 254.0f);
	BOOST_CHECK_EQUAL(mv06[3], 262.0f);

	hep::multi_vector<float, 2, 0> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10[0], 0.0f);
	BOOST_CHECK_EQUAL(mv10[1], 15.0f);
	BOOST_CHECK_EQUAL(mv10[2], 21.0f);
	BOOST_CHECK_EQUAL(mv10[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11[0], 146.0f);
	BOOST_CHECK_EQUAL(mv11[1], 0.0f);
	BOOST_CHECK_EQUAL(mv11[2], 0.0f);
	BOOST_CHECK_EQUAL(mv11[3], -12.0f);

	hep::multi_vector<float, 2, 0> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12[0], 0.0f);
	BOOST_CHECK_EQUAL(mv12[1], -133.0f);
	BOOST_CHECK_EQUAL(mv12[2], 95.0f);
	BOOST_CHECK_EQUAL(mv12[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13[0], 506.0f);
	BOOST_CHECK_EQUAL(mv13[1], 185.0f);
	BOOST_CHECK_EQUAL(mv13[2], 259.0f);
	BOOST_CHECK_EQUAL(mv13[3], -72.0f);

	hep::multi_vector<float, 2, 0> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14[0], 0.0f);
	BOOST_CHECK_EQUAL(mv14[1], -132.0f);
	BOOST_CHECK_EQUAL(mv14[2], 718.0f);
	BOOST_CHECK_EQUAL(mv14[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15[0], 976.0f);
	BOOST_CHECK_EQUAL(mv15[1], -623.0f);
	BOOST_CHECK_EQUAL(mv15[2], 445.0f);
	BOOST_CHECK_EQUAL(mv15[3], -138.0f);

	hep::multi_vector<float, 2, 0> mv16 = std::get<1>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv16[0], 1454.0f);
	BOOST_CHECK_EQUAL(mv16[1], -372.0f);
	BOOST_CHECK_EQUAL(mv16[2], 1418.0f);
	BOOST_CHECK_EQUAL(mv16[3], -156.0f);

	hep::multi_vector<float, 2, 0> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20[0], 0.0f);
	BOOST_CHECK_EQUAL(mv20[1], 0.0f);
	BOOST_CHECK_EQUAL(mv20[2], 0.0f);
	BOOST_CHECK_EQUAL(mv20[3], 51.0f);

	hep::multi_vector<float, 2, 0> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21[0], 0.0f);
	BOOST_CHECK_EQUAL(mv21[1], 221.0f);
	BOOST_CHECK_EQUAL(mv21[2], -187.0f);
	BOOST_CHECK_EQUAL(mv21[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22[0], -323.0f);
	BOOST_CHECK_EQUAL(mv22[1], 0.0f);
	BOOST_CHECK_EQUAL(mv22[2], 0.0f);
	BOOST_CHECK_EQUAL(mv22[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23[0], 0.0f);
	BOOST_CHECK_EQUAL(mv23[1], 731.0f);
	BOOST_CHECK_EQUAL(mv23[2], -697.0f);
	BOOST_CHECK_EQUAL(mv23[3], 629.0f);

	hep::multi_vector<float, 2, 0> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24[0], -1037.0f);
	BOOST_CHECK_EQUAL(mv24[1], 0.0f);
	BOOST_CHECK_EQUAL(mv24[2], 0.0f);
	BOOST_CHECK_EQUAL(mv24[3], 1003.0f);

	hep::multi_vector<float, 2, 0> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25[0], -1513.0f);
	BOOST_CHECK_EQUAL(mv25[1], 1411.0f);
	BOOST_CHECK_EQUAL(mv25[2], -1343.0f);
	BOOST_CHECK_EQUAL(mv25[3], .0f);

	hep::multi_vector<float, 2, 0> mv26 = std::get<2>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv26[0], -2227.0f);
	BOOST_CHECK_EQUAL(mv26[1], 2159.0f);
	BOOST_CHECK_EQUAL(mv26[2], -1921.0f);
	BOOST_CHECK_EQUAL(mv26[3], 1853.0f);

	hep::multi_vector<float, 2, 0> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30[0], 69.0f);
	BOOST_CHECK_EQUAL(mv30[1], 87.0f);
	BOOST_CHECK_EQUAL(mv30[2], 93.0f);
	BOOST_CHECK_EQUAL(mv30[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31[0], 722.0f);
	BOOST_CHECK_EQUAL(mv31[1], 253.0f);
	BOOST_CHECK_EQUAL(mv31[2], 299.0f);
	BOOST_CHECK_EQUAL(mv31[3], 36.0f);

	hep::multi_vector<float, 2, 0> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32[0], 0.0f);
	BOOST_CHECK_EQUAL(mv32[1], -589.0f);
	BOOST_CHECK_EQUAL(mv32[2], 551.0f);
	BOOST_CHECK_EQUAL(mv32[3], 437.0f);

	hep::multi_vector<float, 2, 0> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33[0], 3373.0f);
	BOOST_CHECK_EQUAL(mv33[1], 2016.0f);
	BOOST_CHECK_EQUAL(mv33[2], 2136.0f);
	BOOST_CHECK_EQUAL(mv33[3], -24.0f);

	hep::multi_vector<float, 2, 0> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34[0], 1357.0f);
	BOOST_CHECK_EQUAL(mv34[1], -180.0f);
	BOOST_CHECK_EQUAL(mv34[2], 3598.0f);
	BOOST_CHECK_EQUAL(mv34[3], 1403.0f);

	hep::multi_vector<float, 2, 0> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35[0], 4864.0f);
	BOOST_CHECK_EQUAL(mv35[1], -942.0f);
	BOOST_CHECK_EQUAL(mv35[2], 4490.0f);
	BOOST_CHECK_EQUAL(mv35[3], 2005.0f);

	hep::multi_vector<float, 2, 0> mv36 = std::get<3>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv36[0], 9721.0f);
	BOOST_CHECK_EQUAL(mv36[1], 1699.0f);
	BOOST_CHECK_EQUAL(mv36[2], 10099.0f);
	BOOST_CHECK_EQUAL(mv36[3], 3193.0f);

	hep::multi_vector<float, 2, 0> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40[0], 141.0f);
	BOOST_CHECK_EQUAL(mv40[1], 0.0f);
	BOOST_CHECK_EQUAL(mv40[2], 0.0f);
	BOOST_CHECK_EQUAL(mv40[3], 159.0f);

	hep::multi_vector<float, 2, 0> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41[0], 0.0f);
	BOOST_CHECK_EQUAL(mv41[1], 1206.0f);
	BOOST_CHECK_EQUAL(mv41[2], 28.0f);
	BOOST_CHECK_EQUAL(mv41[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42[0], -1007.0f);
	BOOST_CHECK_EQUAL(mv42[1], 0.0f);
	BOOST_CHECK_EQUAL(mv42[2], 0.0f);
	BOOST_CHECK_EQUAL(mv42[3], 893.0f);

	hep::multi_vector<float, 2, 0> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43[0], 1739.0f);
	BOOST_CHECK_EQUAL(mv43[1], 4206.0f);
	BOOST_CHECK_EQUAL(mv43[2], -152.0f);
	BOOST_CHECK_EQUAL(mv43[3], 1961.0f);

	hep::multi_vector<float, 2, 0> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44[0], -460.0f);
	BOOST_CHECK_EQUAL(mv44[1], 0.0f);
	BOOST_CHECK_EQUAL(mv44[2], 0.0f);
	BOOST_CHECK_EQUAL(mv44[3], 5994.0f);

	hep::multi_vector<float, 2, 0> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45[0], -4717.0f);
	BOOST_CHECK_EQUAL(mv45[1], 8112.0f);
	BOOST_CHECK_EQUAL(mv45[2], -286.0f);
	BOOST_CHECK_EQUAL(mv45[3], 4183.0f);

	hep::multi_vector<float, 2, 0> mv46 = std::get<4>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv46[0], -1820.0f);
	BOOST_CHECK_EQUAL(mv46[1], 12042.0f);
	BOOST_CHECK_EQUAL(mv46[2], -20.0f);
	BOOST_CHECK_EQUAL(mv46[3], 11934.0f);

	hep::multi_vector<float, 2, 0> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50[0], 0.0f);
	BOOST_CHECK_EQUAL(mv50[1], 201.0f);
	BOOST_CHECK_EQUAL(mv50[2], 213.0f);
	BOOST_CHECK_EQUAL(mv50[3], 219.0f);

	hep::multi_vector<float, 2, 0> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51[0], 1660.0f);
	BOOST_CHECK_EQUAL(mv51[1], 949.0f);
	BOOST_CHECK_EQUAL(mv51[2], -803.0f);
	BOOST_CHECK_EQUAL(mv51[3], 90.0f);

	hep::multi_vector<float, 2, 0> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52[0], -1387.0f);
	BOOST_CHECK_EQUAL(mv52[1], -1349.0f);
	BOOST_CHECK_EQUAL(mv52[2], 1273.0f);
	BOOST_CHECK_EQUAL(mv52[3], 0.0f);

	hep::multi_vector<float, 2, 0> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53[0], 5800.0f);
	BOOST_CHECK_EQUAL(mv53[1], 5618.0f);
	BOOST_CHECK_EQUAL(mv53[2], -366.0f);
	BOOST_CHECK_EQUAL(mv53[3], 2671.0f);

	hep::multi_vector<float, 2, 0> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54[0], -4453.0f);
	BOOST_CHECK_EQUAL(mv54[1], -378.0f);
	BOOST_CHECK_EQUAL(mv54[2], 8276.0f);
	BOOST_CHECK_EQUAL(mv54[3], 4307.0f);

	hep::multi_vector<float, 2, 0> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55[0], 4689.0f);
	BOOST_CHECK_EQUAL(mv55[1], -260.0f);
	BOOST_CHECK_EQUAL(mv55[2], 196.0f);
	BOOST_CHECK_EQUAL(mv55[3], -48.0f);

	hep::multi_vector<float, 2, 0> mv56 = std::get<5>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv56[0], 7025.0f);
	BOOST_CHECK_EQUAL(mv56[1], 7273.0f);
	BOOST_CHECK_EQUAL(mv56[2], 8267.0f);
	BOOST_CHECK_EQUAL(mv56[3], 8443.0f);

	hep::multi_vector<float, 2, 0> mv60 = std::get<6>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv60[0], 291.0f);
	BOOST_CHECK_EQUAL(mv60[1], 303.0f);
	BOOST_CHECK_EQUAL(mv60[2], 309.0f);
	BOOST_CHECK_EQUAL(mv60[3], 321.0f);

	hep::multi_vector<float, 2, 0> mv61 = std::get<6>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv61[0], 2450.0f);
	BOOST_CHECK_EQUAL(mv61[1], 2458.0f);
	BOOST_CHECK_EQUAL(mv61[2], 84.0f);
	BOOST_CHECK_EQUAL(mv61[3], 180.0f);

	hep::multi_vector<float, 2, 0> mv62 = std::get<6>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv62[0], -2033.0f);
	BOOST_CHECK_EQUAL(mv62[1], -1957.0f);
	BOOST_CHECK_EQUAL(mv62[2], 1919.0f);
	BOOST_CHECK_EQUAL(mv62[3], 1843.0f);

	hep::multi_vector<float, 2, 0> mv63 = std::get<6>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv63[0], 12159.0f);
	BOOST_CHECK_EQUAL(mv63[1], 12315.0f);
	BOOST_CHECK_EQUAL(mv63[2], 3595.0f);
	BOOST_CHECK_EQUAL(mv63[3], 4079.0f);

	hep::multi_vector<float, 2, 0> mv64 = std::get<6>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv64[0], -804.0f);
	BOOST_CHECK_EQUAL(mv64[1], -324.0f);
	BOOST_CHECK_EQUAL(mv64[2], 12238.0f);
	BOOST_CHECK_EQUAL(mv64[3], 12230.0f);

	hep::multi_vector<float, 2, 0> mv65 = std::get<6>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv65[0], 7005.0f);
	BOOST_CHECK_EQUAL(mv65[1], 7377.0f);
	BOOST_CHECK_EQUAL(mv65[2], 8587.0f);
	BOOST_CHECK_EQUAL(mv65[3], 8879.0f);

	hep::multi_vector<float, 2, 0> mv66 = std::get<6>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv66[0], 21050.0f);
	BOOST_CHECK_EQUAL(mv66[1], 22066.0f);
	BOOST_CHECK_EQUAL(mv66[2], 24686.0f);
	BOOST_CHECK_EQUAL(mv66[3], 25558.0f);
}
