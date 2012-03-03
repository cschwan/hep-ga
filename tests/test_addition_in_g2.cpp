#include <tuple>

#include <hep/addition.hpp>

#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <std::size_t L>
using mv2 = hep::multi_vector<float, 2, 0, L>;

BOOST_AUTO_TEST_CASE(addition)
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

	mv2<1> mv00 = std::get<0>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00[0], 5.0f);

	mv2<3> mv01 = std::get<0>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01[0], 2.0f);
	BOOST_CHECK_EQUAL(mv01[1], 11.0f);
	BOOST_CHECK_EQUAL(mv01[2], 13.0f);

	mv2<5> mv02 = std::get<0>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02[0], 2.0f);
	BOOST_CHECK_EQUAL(mv02[1], 19.0f);

	mv2<3> mv03 = std::get<0>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03[0], 39.0f);
	BOOST_CHECK_EQUAL(mv03[1], 41.0f);
	BOOST_CHECK_EQUAL(mv03[2], 43.0f);

	mv2<5> mv04 = std::get<0>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04[0], 61.0f);
	BOOST_CHECK_EQUAL(mv04[1], 61.0f);

	mv2<7> mv05 = std::get<0>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05[0], 2.0f);
	BOOST_CHECK_EQUAL(mv05[1], 79.0f);
	BOOST_CHECK_EQUAL(mv05[2], 83.0f);
	BOOST_CHECK_EQUAL(mv05[3], 89.0f);

	mv2<7> mv06 = std::get<0>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv06[0], 111.0f);
	BOOST_CHECK_EQUAL(mv06[1], 113.0f);
	BOOST_CHECK_EQUAL(mv06[2], 127.0f);
	BOOST_CHECK_EQUAL(mv06[3], 131.0f);

	mv2<3> mv10 = std::get<1>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10[0], 3.0f);
	BOOST_CHECK_EQUAL(mv10[1], 5.0f);
	BOOST_CHECK_EQUAL(mv10[2], 7.0f);

	mv2<2> mv11 = std::get<1>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11[0], 16.0f);
	BOOST_CHECK_EQUAL(mv11[1], 20.0f);

	mv2<6> mv12 = std::get<1>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12[0], 5.0f);
	BOOST_CHECK_EQUAL(mv12[1], 7.0f);
	BOOST_CHECK_EQUAL(mv12[2], 19.0f);

	mv2<3> mv13 = std::get<1>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13[0], 37.0f);
	BOOST_CHECK_EQUAL(mv13[1], 46.0f);
	BOOST_CHECK_EQUAL(mv13[2], 50.0f);

	mv2<7> mv14 = std::get<1>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14[0], 59.0f);
	BOOST_CHECK_EQUAL(mv14[1], 5.0f);
	BOOST_CHECK_EQUAL(mv14[2], 7.0f);
	BOOST_CHECK_EQUAL(mv14[3], 61.0f);

	mv2<6> mv15 = std::get<1>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15[0], 84.0f);
	BOOST_CHECK_EQUAL(mv15[1], 90.0f);
	BOOST_CHECK_EQUAL(mv15[2], 89.0f);

	mv2<7> mv16 = std::get<1>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv16[0], 109.0f);
	BOOST_CHECK_EQUAL(mv16[1], 118.0f);
	BOOST_CHECK_EQUAL(mv16[2], 134.0f);
	BOOST_CHECK_EQUAL(mv16[3], 131.0f);

	mv2<5> mv20 = std::get<2>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20[0], 3.0f);
	BOOST_CHECK_EQUAL(mv20[1], 17.0f);

	mv2<6> mv21 = std::get<2>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21[0], 11.0f);
	BOOST_CHECK_EQUAL(mv21[1], 13.0f);
	BOOST_CHECK_EQUAL(mv21[2], 17.0f);

	mv2<4> mv22 = std::get<2>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22[0], 36.0f);

	mv2<7> mv23 = std::get<2>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23[0], 37.0f);
	BOOST_CHECK_EQUAL(mv23[1], 41.0f);
	BOOST_CHECK_EQUAL(mv23[2], 43.0f);
	BOOST_CHECK_EQUAL(mv23[3], 17.0f);

	mv2<5> mv24 = std::get<2>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24[0], 59.0f);
	BOOST_CHECK_EQUAL(mv24[1], 78.0f);

	mv2<6> mv25 = std::get<2>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25[0], 79.0f);
	BOOST_CHECK_EQUAL(mv25[1], 83.0f);
	BOOST_CHECK_EQUAL(mv25[2], 106.0f);

	mv2<7> mv26 = std::get<2>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv26[0], 109.0f);
	BOOST_CHECK_EQUAL(mv26[1], 113.0f);
	BOOST_CHECK_EQUAL(mv26[2], 127.0f);
	BOOST_CHECK_EQUAL(mv26[3], 148.0f);

	mv2<3> mv30 = std::get<3>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30[0], 26.0f);
	BOOST_CHECK_EQUAL(mv30[1], 29.0f);
	BOOST_CHECK_EQUAL(mv30[2], 31.0f);

	mv2<3> mv31 = std::get<3>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31[0], 23.0f);
	BOOST_CHECK_EQUAL(mv31[1], 40.0f);
	BOOST_CHECK_EQUAL(mv31[2], 44.0f);

	mv2<7> mv32 = std::get<3>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32[0], 23.0f);
	BOOST_CHECK_EQUAL(mv32[1], 29.0f);
	BOOST_CHECK_EQUAL(mv32[2], 31.0f);
	BOOST_CHECK_EQUAL(mv32[3], 19.0f);

	mv2<3> mv33 = std::get<3>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33[0], 60.0f);
	BOOST_CHECK_EQUAL(mv33[1], 70.0f);
	BOOST_CHECK_EQUAL(mv33[2], 74.0f);

	mv2<7> mv34 = std::get<3>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34[0], 82.0f);
	BOOST_CHECK_EQUAL(mv34[1], 29.0f);
	BOOST_CHECK_EQUAL(mv34[2], 31.0f);
	BOOST_CHECK_EQUAL(mv34[3], 61.0f);

	mv2<7> mv35 = std::get<3>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35[0], 23.0f);
	BOOST_CHECK_EQUAL(mv35[1], 108.0f);
	BOOST_CHECK_EQUAL(mv35[2], 114.0f);
	BOOST_CHECK_EQUAL(mv35[3], 89.0f);

	mv2<7> mv36 = std::get<3>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv36[0], 132.0f);
	BOOST_CHECK_EQUAL(mv36[1], 142.0f);
	BOOST_CHECK_EQUAL(mv36[2], 158.0f);
	BOOST_CHECK_EQUAL(mv36[3], 131.0f);

	mv2<5> mv40 = std::get<4>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40[0], 50.0f);
	BOOST_CHECK_EQUAL(mv40[1], 53.0f);

	mv2<7> mv41 = std::get<4>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41[0], 47.0f);
	BOOST_CHECK_EQUAL(mv41[1], 11.0f);
	BOOST_CHECK_EQUAL(mv41[2], 13.0f);
	BOOST_CHECK_EQUAL(mv41[3], 53.0f);

	mv2<5> mv42 = std::get<4>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42[0], 47.0f);
	BOOST_CHECK_EQUAL(mv42[1], 72.0f);

	mv2<7> mv43 = std::get<4>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43[0], 84.0f);
	BOOST_CHECK_EQUAL(mv43[1], 41.0f);
	BOOST_CHECK_EQUAL(mv43[2], 43.0f);
	BOOST_CHECK_EQUAL(mv43[3], 53.0f);

	mv2<5> mv44 = std::get<4>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44[0], 106.0f);
	BOOST_CHECK_EQUAL(mv44[1], 114.0f);

	mv2<7> mv45 = std::get<4>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45[0], 47.0f);
	BOOST_CHECK_EQUAL(mv45[1], 79.0f);
	BOOST_CHECK_EQUAL(mv45[2], 83.0f);
	BOOST_CHECK_EQUAL(mv45[3], 142.0f);

	mv2<7> mv46 = std::get<4>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv46[0], 156.0f);
	BOOST_CHECK_EQUAL(mv46[1], 113.0f);
	BOOST_CHECK_EQUAL(mv46[2], 127.0f);
	BOOST_CHECK_EQUAL(mv46[3], 184.0f);

	mv2<7> mv50 = std::get<5>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50[0], 3.0f);
	BOOST_CHECK_EQUAL(mv50[1], 67.0f);
	BOOST_CHECK_EQUAL(mv50[2], 71.0f);
	BOOST_CHECK_EQUAL(mv50[3], 73.0f);

	mv2<6> mv51 = std::get<5>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51[0], 78.0f);
	BOOST_CHECK_EQUAL(mv51[1], 84.0f);
	BOOST_CHECK_EQUAL(mv51[2], 73.0f);

	mv2<6> mv52 = std::get<5>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52[0], 67.0f);
	BOOST_CHECK_EQUAL(mv52[1], 71.0f);
	BOOST_CHECK_EQUAL(mv52[2], 92.0f);

	mv2<7> mv53 = std::get<5>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53[0], 37.0f);
	BOOST_CHECK_EQUAL(mv53[1], 108.0f);
	BOOST_CHECK_EQUAL(mv53[2], 114.0f);
	BOOST_CHECK_EQUAL(mv53[3], 73.0f);

	mv2<7> mv54 = std::get<5>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54[0], 59.0f);
	BOOST_CHECK_EQUAL(mv54[1], 67.0f);
	BOOST_CHECK_EQUAL(mv54[2], 71.0f);
	BOOST_CHECK_EQUAL(mv54[3], 134.0f);

	mv2<6> mv55 = std::get<5>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55[0], 146.0f);
	BOOST_CHECK_EQUAL(mv55[1], 154.0f);
	BOOST_CHECK_EQUAL(mv55[2], 162.0f);

	mv2<7> mv56 = std::get<5>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv56[0], 109.0f);
	BOOST_CHECK_EQUAL(mv56[1], 180.0f);
	BOOST_CHECK_EQUAL(mv56[2], 198.0f);
	BOOST_CHECK_EQUAL(mv56[3], 204.0f);

	mv2<7> mv60 = std::get<6>(lhs) + std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv60[0], 100.0f);
	BOOST_CHECK_EQUAL(mv60[1], 101.0f);
	BOOST_CHECK_EQUAL(mv60[2], 103.0f);
	BOOST_CHECK_EQUAL(mv60[3], 107.0f);

	mv2<7> mv61 = std::get<6>(lhs) + std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv61[0], 97.0f);
	BOOST_CHECK_EQUAL(mv61[1], 112.0f);
	BOOST_CHECK_EQUAL(mv61[2], 116.0f);
	BOOST_CHECK_EQUAL(mv61[3], 107.0f);

	mv2<7> mv62 = std::get<6>(lhs) + std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv62[0], 97.0f);
	BOOST_CHECK_EQUAL(mv62[1], 101.0f);
	BOOST_CHECK_EQUAL(mv62[2], 103.0f);
	BOOST_CHECK_EQUAL(mv62[3], 126.0f);

	mv2<7> mv63 = std::get<6>(lhs) + std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv63[0], 134.0f);
	BOOST_CHECK_EQUAL(mv63[1], 142.0f);
	BOOST_CHECK_EQUAL(mv63[2], 146.0f);
	BOOST_CHECK_EQUAL(mv63[3], 107.0f);

	mv2<7> mv64 = std::get<6>(lhs) + std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv64[0], 156.0f);
	BOOST_CHECK_EQUAL(mv64[1], 101.0f);
	BOOST_CHECK_EQUAL(mv64[2], 103.0f);
	BOOST_CHECK_EQUAL(mv64[3], 168.0f);

	mv2<7> mv65 = std::get<6>(lhs) + std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv65[0], 97.0f);
	BOOST_CHECK_EQUAL(mv65[1], 180.0f);
	BOOST_CHECK_EQUAL(mv65[2], 186.0f);
	BOOST_CHECK_EQUAL(mv65[3], 196.0f);

	mv2<7> mv66 = std::get<6>(lhs) + std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv66[0], 206.0f);
	BOOST_CHECK_EQUAL(mv66[1], 214.0f);
	BOOST_CHECK_EQUAL(mv66[2], 230.0f);
	BOOST_CHECK_EQUAL(mv66[3], 238.0f);
}
