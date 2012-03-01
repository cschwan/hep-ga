#include <tuple>

#include <hep/product.hpp>

#include <boost/test/unit_test.hpp>

// multi vector with metric (3,0) and general grade list
template <std::size_t L>
using mv3 = hep::multi_vector<float, 3, 0, L>;

BOOST_AUTO_TEST_CASE(geometric_product)
{
	auto lhs = std::make_tuple(
		mv3< 1>{ 2.0f },
		mv3< 2>{ 5.0f, 7.0f, 11.0f },
		mv3< 4>{ 23.0f, 29.0f, 31.0f },
		mv3< 8>{ 47.0f },
		mv3< 5>{ 59.0f, 61.0f, 67.0f, 71.0f },
		mv3<15>{ 97.0f, 101.0f, 103.0f, 109.0f,
		         107.0f, 113.0f, 127.0f, 131.0f }
	);
	auto rhs = std::make_tuple(
		mv3< 1>{ 3.0f },
		mv3< 2>{ 13.0f, 17.0f, 19.0f },
		mv3< 4>{ 37.0f, 41.0f, 43.0f },
		mv3< 8>{ 53.0f },
		mv3< 5>{ 73.0f, 79.0f, 83.0f, 89.0f },
		mv3<15>{ 137.0f, 139.0f, 149.0f, 157.0f,
		         151.0f, 163.0f, 167.0f, 173.0f }
	);

	mv3<1> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00[0], 6.0f);

	mv3<2> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01[0], 26.0f);
	BOOST_CHECK_EQUAL(mv01[1], 34.0f);
	BOOST_CHECK_EQUAL(mv01[2], 38.0f);

	mv3<4> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02[0], 74.0f);
	BOOST_CHECK_EQUAL(mv02[1], 82.0f);
	BOOST_CHECK_EQUAL(mv02[2], 86.0f);

	mv3<8> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03[0], 106.0f);

	mv3<5> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04[0], 146.0f);
	BOOST_CHECK_EQUAL(mv04[1], 158.0f);
	BOOST_CHECK_EQUAL(mv04[2], 166.0f);
	BOOST_CHECK_EQUAL(mv04[3], 178.0f);

	mv3<15> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05[0], 274.0f);
	BOOST_CHECK_EQUAL(mv05[1], 278.0f);
	BOOST_CHECK_EQUAL(mv05[2], 298.0f);
	BOOST_CHECK_EQUAL(mv05[3], 314.0f);
	BOOST_CHECK_EQUAL(mv05[4], 302.0f);
	BOOST_CHECK_EQUAL(mv05[5], 326.0f);
	BOOST_CHECK_EQUAL(mv05[6], 334.0f);
	BOOST_CHECK_EQUAL(mv05[7], 346.0f);

	mv3<2> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10[0], 15.0f);
	BOOST_CHECK_EQUAL(mv10[1], 21.0f);
	BOOST_CHECK_EQUAL(mv10[2], 33.0f);

	mv3<5> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11[0], 393.0f);
	BOOST_CHECK_EQUAL(mv11[1], -6.0f);
	BOOST_CHECK_EQUAL(mv11[2], -48.0f);
	BOOST_CHECK_EQUAL(mv11[3], -54.0f);

	mv3<10> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12[0], -710.0f);
	BOOST_CHECK_EQUAL(mv12[1], -288.0f);
	BOOST_CHECK_EQUAL(mv12[2], 506.0f);
	BOOST_CHECK_EQUAL(mv12[3], 335.0f);

	mv3<4> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13[0], 583.0f);
	BOOST_CHECK_EQUAL(mv13[1], -371.0f);
	BOOST_CHECK_EQUAL(mv13[2], 265.0f);

	mv3<10> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14[0], -1101.0f);
	BOOST_CHECK_EQUAL(mv14[1], -73.0f);
	BOOST_CHECK_EQUAL(mv14[2], 1841.0f);
	BOOST_CHECK_EQUAL(mv14[3], 733.0f);

	mv3<15> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15[0], 3465.0f);
	BOOST_CHECK_EQUAL(mv15[1], -2165.0f);
	BOOST_CHECK_EQUAL(mv15[2], -123.0f);
	BOOST_CHECK_EQUAL(mv15[3], 3491.0f);
	BOOST_CHECK_EQUAL(mv15[4], 1675.0f);
	BOOST_CHECK_EQUAL(mv15[5], -1955.0f);
	BOOST_CHECK_EQUAL(mv15[6], 325.0f);
	BOOST_CHECK_EQUAL(mv15[7], 1355.0f);

	mv3<4> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20[0], 69.0f);
	BOOST_CHECK_EQUAL(mv20[1], 87.0f);
	BOOST_CHECK_EQUAL(mv20[2], 93.0f);

	mv3<10> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21[0], 942.0f);
	BOOST_CHECK_EQUAL(mv21[1], 290.0f);
	BOOST_CHECK_EQUAL(mv21[2], -904.0f);
	BOOST_CHECK_EQUAL(mv21[3], 347.0f);

	mv3<5> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22[0], -3373.0f);
	BOOST_CHECK_EQUAL(mv22[1], 24.0f);
	BOOST_CHECK_EQUAL(mv22[2], -158.0f);
	BOOST_CHECK_EQUAL(mv22[3], 130.0f);

	mv3<2> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23[0], -1643.0f);
	BOOST_CHECK_EQUAL(mv23[1], 1537.0f);
	BOOST_CHECK_EQUAL(mv23[2], -1219.0f);

	mv3<5> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24[0], -6983.0f);
	BOOST_CHECK_EQUAL(mv24[1], 1671.0f);
	BOOST_CHECK_EQUAL(mv24[2], 1715.0f);
	BOOST_CHECK_EQUAL(mv24[3], 2645.0f);

	mv3<15> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25[0], -13377.0f);
	BOOST_CHECK_EQUAL(mv25[1], 2617.0f);
	BOOST_CHECK_EQUAL(mv25[2], 6687.0f);
	BOOST_CHECK_EQUAL(mv25[3], -12629.0f);
	BOOST_CHECK_EQUAL(mv25[4], 3361.0f);
	BOOST_CHECK_EQUAL(mv25[5], 3133.0f);
	BOOST_CHECK_EQUAL(mv25[6], 4877.0f);
	BOOST_CHECK_EQUAL(mv25[7], 3599.0f);

	mv3<8> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30[0], 141.0f);

	mv3<4> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31[0], 893.0f);
	BOOST_CHECK_EQUAL(mv31[1], -799.0f);
	BOOST_CHECK_EQUAL(mv31[2], 611.0f);

	mv3<2> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32[0], -2021.0f);
	BOOST_CHECK_EQUAL(mv32[1], 1927.0f);
	BOOST_CHECK_EQUAL(mv32[2], -1739.0f);

	mv3<1> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33[0], -2491.0f);

	mv3<10> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34[0], -4183.0f);
	BOOST_CHECK_EQUAL(mv34[1], 3901.0f);
	BOOST_CHECK_EQUAL(mv34[2], -3713.0f);
	BOOST_CHECK_EQUAL(mv34[3], 3431.0f);

	mv3<15> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35[0], -8131.0f);
	BOOST_CHECK_EQUAL(mv35[1], -7849.0f);
	BOOST_CHECK_EQUAL(mv35[2], 7661.0f);
	BOOST_CHECK_EQUAL(mv35[3], -7097.0f);
	BOOST_CHECK_EQUAL(mv35[4], 7379.0f);
	BOOST_CHECK_EQUAL(mv35[5], -7003.0f);
	BOOST_CHECK_EQUAL(mv35[6], 6533.0f);
	BOOST_CHECK_EQUAL(mv35[7], 6439.0f);

	mv3<5> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40[0], 177.0f);
	BOOST_CHECK_EQUAL(mv40[1], 183.0f);
	BOOST_CHECK_EQUAL(mv40[2], 201.0f);
	BOOST_CHECK_EQUAL(mv40[3], 213.0f);

	mv3<10> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41[0], 3077.0f);
	BOOST_CHECK_EQUAL(mv41[1], 1559.0f);
	BOOST_CHECK_EQUAL(mv41[2], -957.0f);
	BOOST_CHECK_EQUAL(mv41[3], 943.0f);

	mv3<5> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42[0], -8057.0f);
	BOOST_CHECK_EQUAL(mv42[1], 2213.0f);
	BOOST_CHECK_EQUAL(mv42[2], 2415.0f);
	BOOST_CHECK_EQUAL(mv42[3], 2515.0f);

	mv3<10> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43[0], -3763.0f);
	BOOST_CHECK_EQUAL(mv43[1], 3551.0f);
	BOOST_CHECK_EQUAL(mv43[2], -3233.0f);
	BOOST_CHECK_EQUAL(mv43[3], 3127.0f);

	mv3<5> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44[0], -12392.0f);
	BOOST_CHECK_EQUAL(mv44[1], 9044.0f);
	BOOST_CHECK_EQUAL(mv44[2], 9608.0f);
	BOOST_CHECK_EQUAL(mv44[3], 10664.0f);

	mv3<15> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45[0], -23906.0f);
	BOOST_CHECK_EQUAL(mv45[1], 15526.0f);
	BOOST_CHECK_EQUAL(mv45[2], 23050.0f);
	BOOST_CHECK_EQUAL(mv45[3], -21182.0f);
	BOOST_CHECK_EQUAL(mv45[4], 17650.0f);
	BOOST_CHECK_EQUAL(mv45[5], 18262.0f);
	BOOST_CHECK_EQUAL(mv45[6], 19754.0f);
	BOOST_CHECK_EQUAL(mv45[7], 19670.0f);

	mv3<15> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50[0], 291.0f);
	BOOST_CHECK_EQUAL(mv50[1], 303.0f);
	BOOST_CHECK_EQUAL(mv50[2], 309.0f);
	BOOST_CHECK_EQUAL(mv50[3], 327.0f);
	BOOST_CHECK_EQUAL(mv50[4], 321.0f);
	BOOST_CHECK_EQUAL(mv50[5], 339.0f);
	BOOST_CHECK_EQUAL(mv50[6], 381.0f);
	BOOST_CHECK_EQUAL(mv50[7], 393.0f);

	mv3<15> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51[0], 5135.0f);
	BOOST_CHECK_EQUAL(mv51[1], 5227.0f);
	BOOST_CHECK_EQUAL(mv51[2], 2671.0f);
	BOOST_CHECK_EQUAL(mv51[3], -1785.0f);
	BOOST_CHECK_EQUAL(mv51[4], 2867.0f);
	BOOST_CHECK_EQUAL(mv51[5], -1725.0f);
	BOOST_CHECK_EQUAL(mv51[6], 1807.0f);
	BOOST_CHECK_EQUAL(mv51[7], 1763.0f);

	mv3<15> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52[0], -14053.0f);
	BOOST_CHECK_EQUAL(mv52[1], -13913.0f);
	BOOST_CHECK_EQUAL(mv52[2], 4421.0f);
	BOOST_CHECK_EQUAL(mv52[3], 3723.0f);
	BOOST_CHECK_EQUAL(mv52[4], 3937.0f);
	BOOST_CHECK_EQUAL(mv52[5], 3879.0f);
	BOOST_CHECK_EQUAL(mv52[6], 3965.0f);
	BOOST_CHECK_EQUAL(mv52[7], 4153.0f);

	mv3<15> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53[0], -6943.0f);
	BOOST_CHECK_EQUAL(mv53[1], -6731.0f);
	BOOST_CHECK_EQUAL(mv53[2], 5989.0f);
	BOOST_CHECK_EQUAL(mv53[3], -5671.0f);
	BOOST_CHECK_EQUAL(mv53[4], 5777.0f);
	BOOST_CHECK_EQUAL(mv53[5], -5459.0f);
	BOOST_CHECK_EQUAL(mv53[6], 5353.0f);
	BOOST_CHECK_EQUAL(mv53[7], 5141.0f);

	mv3<15> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54[0], -22054.0f);
	BOOST_CHECK_EQUAL(mv54[1], -21470.0f);
	BOOST_CHECK_EQUAL(mv54[2], 16670.0f);
	BOOST_CHECK_EQUAL(mv54[3], 15158.0f);
	BOOST_CHECK_EQUAL(mv54[4], 15958.0f);
	BOOST_CHECK_EQUAL(mv54[5], 15790.0f);
	BOOST_CHECK_EQUAL(mv54[6], 17950.0f);
	BOOST_CHECK_EQUAL(mv54[7], 18614.0f);

	mv3<15> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55[0], -18660.0f);
	BOOST_CHECK_EQUAL(mv55[1], -16164.0f);
	BOOST_CHECK_EQUAL(mv55[2], 71580.0f);
	BOOST_CHECK_EQUAL(mv55[3], -9096.0f);
	BOOST_CHECK_EQUAL(mv55[4], 71292.0f);
	BOOST_CHECK_EQUAL(mv55[5], -6648.0f);
	BOOST_CHECK_EQUAL(mv55[6], 68832.0f);
	BOOST_CHECK_EQUAL(mv55[7], 68880.0f);
}
