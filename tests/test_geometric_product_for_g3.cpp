#include <tuple>

#include <hep/operations.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(geometric_product_for_g3)
{
	auto lhs = std::make_tuple(
		hep::multi_vector<float, 3, 0>{ 2.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 5.0f, 7.0f, 0.0f,
		                                11.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 0.0f, 0.0f, 23.0f,
		                                0.0f, 29.0f, 31.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 0.0f, 0.0f, 0.0f,
		                                0.0f, 0.0f, 0.0f, 47.0f },
		hep::multi_vector<float, 3, 0>{ 59.0f, 0.0f, 0.0f, 61.0f,
		                                0.0f, 67.0f, 71.0f },
		hep::multi_vector<float, 3, 0>{ 97.0f, 101.0f, 103.0f, 107.0f,
		                                109.0f, 113.0f, 127.0f, 131.0f }
	);
	auto rhs = std::make_tuple(
		hep::multi_vector<float, 3, 0>{ 3.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 13.0f, 17.0f, 0.0f,
		                                19.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 0.0f, 0.0f, 37.0f,
		                                0.0f, 41.0f, 43.0f },
		hep::multi_vector<float, 3, 0>{ 0.0f, 0.0f, 0.0f, 0.0f,
		                                0.0f, 0.0f, 0.0f, 53.0f },
		hep::multi_vector<float, 3, 0>{ 73.0f, 0.0f, 0.0f, 79.0f,
		                                0.0f, 83.0f, 89.0f },
		hep::multi_vector<float, 3, 0>{ 137.0f, 139.0f, 149.0f, 151.0f,
		                                157.0f, 163.0f, 167.0f, 173.0f }
	);

	hep::multi_vector<float, 3, 0> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00[0], 6.0f);
	BOOST_CHECK_EQUAL(mv00[1], 0.0f);
	BOOST_CHECK_EQUAL(mv00[2], 0.0f);
	BOOST_CHECK_EQUAL(mv00[3], 0.0f);
	BOOST_CHECK_EQUAL(mv00[4], 0.0f);
	BOOST_CHECK_EQUAL(mv00[5], 0.0f);
	BOOST_CHECK_EQUAL(mv00[6], 0.0f);
	BOOST_CHECK_EQUAL(mv00[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01[0], 0.0f);
	BOOST_CHECK_EQUAL(mv01[1], 26.0f);
	BOOST_CHECK_EQUAL(mv01[2], 34.0f);
	BOOST_CHECK_EQUAL(mv01[3], 0.0f);
	BOOST_CHECK_EQUAL(mv01[4], 38.0f);
	BOOST_CHECK_EQUAL(mv01[5], 0.0f);
	BOOST_CHECK_EQUAL(mv01[6], 0.0f);
	BOOST_CHECK_EQUAL(mv01[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02[0], 0.0f);
	BOOST_CHECK_EQUAL(mv02[1], 0.0f);
	BOOST_CHECK_EQUAL(mv02[2], 0.0f);
	BOOST_CHECK_EQUAL(mv02[3], 74.0f);
	BOOST_CHECK_EQUAL(mv02[4], 0.0f);
	BOOST_CHECK_EQUAL(mv02[5], 82.0f);
	BOOST_CHECK_EQUAL(mv02[6], 86.0f);
	BOOST_CHECK_EQUAL(mv02[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03[0], 0.0f);
	BOOST_CHECK_EQUAL(mv03[1], 0.0f);
	BOOST_CHECK_EQUAL(mv03[2], 0.0f);
	BOOST_CHECK_EQUAL(mv03[3], 0.0f);
	BOOST_CHECK_EQUAL(mv03[4], 0.0f);
	BOOST_CHECK_EQUAL(mv03[5], 0.0f);
	BOOST_CHECK_EQUAL(mv03[6], 0.0f);
	BOOST_CHECK_EQUAL(mv03[7], 106.0f);

	hep::multi_vector<float, 3, 0> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04[0], 146.0f);
	BOOST_CHECK_EQUAL(mv04[1], 0.0f);
	BOOST_CHECK_EQUAL(mv04[2], 0.0f);
	BOOST_CHECK_EQUAL(mv04[3], 158.0f);
	BOOST_CHECK_EQUAL(mv04[4], 0.0f);
	BOOST_CHECK_EQUAL(mv04[5], 166.0f);
	BOOST_CHECK_EQUAL(mv04[6], 178.0f);
	BOOST_CHECK_EQUAL(mv04[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05[0], 274.0f);
	BOOST_CHECK_EQUAL(mv05[1], 278.0f);
	BOOST_CHECK_EQUAL(mv05[2], 298.0f);
	BOOST_CHECK_EQUAL(mv05[3], 302.0f);
	BOOST_CHECK_EQUAL(mv05[4], 314.0f);
	BOOST_CHECK_EQUAL(mv05[5], 326.0f);
	BOOST_CHECK_EQUAL(mv05[6], 334.0f);
	BOOST_CHECK_EQUAL(mv05[7], 346.0f);

	hep::multi_vector<float, 3, 0> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10[0], 0.0f);
	BOOST_CHECK_EQUAL(mv10[1], 15.0f);
	BOOST_CHECK_EQUAL(mv10[2], 21.0f);
	BOOST_CHECK_EQUAL(mv10[3], 0.0f);
	BOOST_CHECK_EQUAL(mv10[4], 33.0f);
	BOOST_CHECK_EQUAL(mv10[5], 0.0f);
	BOOST_CHECK_EQUAL(mv10[6], 0.0f);
	BOOST_CHECK_EQUAL(mv10[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11[0], 393.0f);
	BOOST_CHECK_EQUAL(mv11[1], 0.0f);
	BOOST_CHECK_EQUAL(mv11[2], 0.0f);
	BOOST_CHECK_EQUAL(mv11[3], -6.0f);
	BOOST_CHECK_EQUAL(mv11[4], .0f);
	BOOST_CHECK_EQUAL(mv11[5], -48.0f);
	BOOST_CHECK_EQUAL(mv11[6], -54.0f);
	BOOST_CHECK_EQUAL(mv11[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12[0], 0.0f);
	BOOST_CHECK_EQUAL(mv12[1], -710.0f);
	BOOST_CHECK_EQUAL(mv12[2], -288.0f);
	BOOST_CHECK_EQUAL(mv12[3], 0.0f);
	BOOST_CHECK_EQUAL(mv12[4], 506.0f);
	BOOST_CHECK_EQUAL(mv12[5], 0.0f);
	BOOST_CHECK_EQUAL(mv12[6], 0.0f);
	BOOST_CHECK_EQUAL(mv12[7], 335.0f);

	hep::multi_vector<float, 3, 0> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13[0], 0.0f);
	BOOST_CHECK_EQUAL(mv13[1], 0.0f);
	BOOST_CHECK_EQUAL(mv13[2], 0.0f);
	BOOST_CHECK_EQUAL(mv13[3], 583.0f);
	BOOST_CHECK_EQUAL(mv13[4], 0.0f);
	BOOST_CHECK_EQUAL(mv13[5], -371.0f);
	BOOST_CHECK_EQUAL(mv13[6], 265.0f);
	BOOST_CHECK_EQUAL(mv13[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14[0], 0.0f);
	BOOST_CHECK_EQUAL(mv14[1], -1101.0f);
	BOOST_CHECK_EQUAL(mv14[2], -73.0f);
	BOOST_CHECK_EQUAL(mv14[3], 0.0f);
	BOOST_CHECK_EQUAL(mv14[4], 1841.0f);
	BOOST_CHECK_EQUAL(mv14[5], 0.0f);
	BOOST_CHECK_EQUAL(mv14[6], 0.0f);
	BOOST_CHECK_EQUAL(mv14[7], 733.0f);

	hep::multi_vector<float, 3, 0> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15[0], 3465.0f);
	BOOST_CHECK_EQUAL(mv15[1], -2165.0f);
	BOOST_CHECK_EQUAL(mv15[2], -123.0f);
	BOOST_CHECK_EQUAL(mv15[3], 1675.0f);
	BOOST_CHECK_EQUAL(mv15[4], 3491.0f);
	BOOST_CHECK_EQUAL(mv15[5], -1955.0f);
	BOOST_CHECK_EQUAL(mv15[6], 325.0f);
	BOOST_CHECK_EQUAL(mv15[7], 1355.0f);

	hep::multi_vector<float, 3, 0> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20[0], 0.0f);
	BOOST_CHECK_EQUAL(mv20[1], 0.0f);
	BOOST_CHECK_EQUAL(mv20[2], 0.0f);
	BOOST_CHECK_EQUAL(mv20[3], 69.0f);
	BOOST_CHECK_EQUAL(mv20[4], 0.0f);
	BOOST_CHECK_EQUAL(mv20[5], 87.0f);
	BOOST_CHECK_EQUAL(mv20[6], 93.0f);
	BOOST_CHECK_EQUAL(mv20[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21[0], 0.0f);
	BOOST_CHECK_EQUAL(mv21[1], 942.0f);
	BOOST_CHECK_EQUAL(mv21[2], 290.0f);
	BOOST_CHECK_EQUAL(mv21[3], 0.0f);
	BOOST_CHECK_EQUAL(mv21[4], -904.0f);
	BOOST_CHECK_EQUAL(mv21[5], 0.0f);
	BOOST_CHECK_EQUAL(mv21[6], 0.0f);
	BOOST_CHECK_EQUAL(mv21[7], 347.0f);

	hep::multi_vector<float, 3, 0> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22[0], -3373.0f);
	BOOST_CHECK_EQUAL(mv22[1], 0.0f);
	BOOST_CHECK_EQUAL(mv22[2], 0.0f);
	BOOST_CHECK_EQUAL(mv22[3], 24.0f);
	BOOST_CHECK_EQUAL(mv22[4], 0.0f);
	BOOST_CHECK_EQUAL(mv22[5], -158.0f);
	BOOST_CHECK_EQUAL(mv22[6], 130.0f);
	BOOST_CHECK_EQUAL(mv22[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23[0], 0.0f);
	BOOST_CHECK_EQUAL(mv23[1], -1643.0f);
	BOOST_CHECK_EQUAL(mv23[2], 1537.0f);
	BOOST_CHECK_EQUAL(mv23[3], 0.0f);
	BOOST_CHECK_EQUAL(mv23[4], -1219.0f);
	BOOST_CHECK_EQUAL(mv23[5], 0.0f);
	BOOST_CHECK_EQUAL(mv23[6], 0.0f);
	BOOST_CHECK_EQUAL(mv23[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24[0], -6983.0f);
	BOOST_CHECK_EQUAL(mv24[1], 0.0f);
	BOOST_CHECK_EQUAL(mv24[2], 0.0f);
	BOOST_CHECK_EQUAL(mv24[3], 1671.0f);
	BOOST_CHECK_EQUAL(mv24[4], 0.0f);
	BOOST_CHECK_EQUAL(mv24[5], 1715.0f);
	BOOST_CHECK_EQUAL(mv24[6], 2645.0f);
	BOOST_CHECK_EQUAL(mv24[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25[0], -13377.0f);
	BOOST_CHECK_EQUAL(mv25[1], 2617.0f);
	BOOST_CHECK_EQUAL(mv25[2], 6687.0f);
	BOOST_CHECK_EQUAL(mv25[3], 3361.0f);
	BOOST_CHECK_EQUAL(mv25[4], -12629.0f);
	BOOST_CHECK_EQUAL(mv25[5], 3133.0f);
	BOOST_CHECK_EQUAL(mv25[6], 4877.0f);
	BOOST_CHECK_EQUAL(mv25[7], 3599.0f);

	hep::multi_vector<float, 3, 0> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30[0], 0.0f);
	BOOST_CHECK_EQUAL(mv30[1], 0.0f);
	BOOST_CHECK_EQUAL(mv30[2], 0.0f);
	BOOST_CHECK_EQUAL(mv30[3], 0.0f);
	BOOST_CHECK_EQUAL(mv30[4], 0.0f);
	BOOST_CHECK_EQUAL(mv30[5], 0.0f);
	BOOST_CHECK_EQUAL(mv30[6], 0.0f);
	BOOST_CHECK_EQUAL(mv30[7], 141.0f);

	hep::multi_vector<float, 3, 0> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31[0], 0.0f);
	BOOST_CHECK_EQUAL(mv31[1], 0.0f);
	BOOST_CHECK_EQUAL(mv31[2], 0.0f);
	BOOST_CHECK_EQUAL(mv31[3], 893.0f);
	BOOST_CHECK_EQUAL(mv31[4], 0.0f);
	BOOST_CHECK_EQUAL(mv31[5], -799.0f);
	BOOST_CHECK_EQUAL(mv31[6], 611.0f);
	BOOST_CHECK_EQUAL(mv31[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32[0], 0.0f);
	BOOST_CHECK_EQUAL(mv32[1], -2021.0f);
	BOOST_CHECK_EQUAL(mv32[2], 1927.0f);
	BOOST_CHECK_EQUAL(mv32[3], 0.0f);
	BOOST_CHECK_EQUAL(mv32[4], -1739.0f);
	BOOST_CHECK_EQUAL(mv32[5], 0.0f);
	BOOST_CHECK_EQUAL(mv32[6], 0.0f);
	BOOST_CHECK_EQUAL(mv32[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33[0], -2491.0f);
	BOOST_CHECK_EQUAL(mv33[1], 0.0f);
	BOOST_CHECK_EQUAL(mv33[2], 0.0f);
	BOOST_CHECK_EQUAL(mv33[3], 0.0f);
	BOOST_CHECK_EQUAL(mv33[4], 0.0f);
	BOOST_CHECK_EQUAL(mv33[5], 0.0f);
	BOOST_CHECK_EQUAL(mv33[6], 0.0f);
	BOOST_CHECK_EQUAL(mv33[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34[0], 0.0f);
	BOOST_CHECK_EQUAL(mv34[1], -4183.0f);
	BOOST_CHECK_EQUAL(mv34[2], 3901.0f);
	BOOST_CHECK_EQUAL(mv34[3], 0.0f);
	BOOST_CHECK_EQUAL(mv34[4], -3713.0f);
	BOOST_CHECK_EQUAL(mv34[5], 0.0f);
	BOOST_CHECK_EQUAL(mv34[6], 0.0f);
	BOOST_CHECK_EQUAL(mv34[7], 3431.0f);

	hep::multi_vector<float, 3, 0> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35[0], -8131.0f);
	BOOST_CHECK_EQUAL(mv35[1], -7849.0f);
	BOOST_CHECK_EQUAL(mv35[2], 7661.0f);
	BOOST_CHECK_EQUAL(mv35[3], 7379.0f);
	BOOST_CHECK_EQUAL(mv35[4], -7097.0f);
	BOOST_CHECK_EQUAL(mv35[5], -7003.0f);
	BOOST_CHECK_EQUAL(mv35[6], 6533.0f);
	BOOST_CHECK_EQUAL(mv35[7], 6439.0f);

	hep::multi_vector<float, 3, 0> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40[0], 177.0f);
	BOOST_CHECK_EQUAL(mv40[1], 0.0f);
	BOOST_CHECK_EQUAL(mv40[2], 0.0f);
	BOOST_CHECK_EQUAL(mv40[3], 183.0f);
	BOOST_CHECK_EQUAL(mv40[4], 0.0f);
	BOOST_CHECK_EQUAL(mv40[5], 201.0f);
	BOOST_CHECK_EQUAL(mv40[6], 213.0f);
	BOOST_CHECK_EQUAL(mv40[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41[0], 0.0f);
	BOOST_CHECK_EQUAL(mv41[1], 3077.0f);
	BOOST_CHECK_EQUAL(mv41[2], 1559.0f);
	BOOST_CHECK_EQUAL(mv41[3], 0.0f);
	BOOST_CHECK_EQUAL(mv41[4], -957.0f);
	BOOST_CHECK_EQUAL(mv41[5], 0.0f);
	BOOST_CHECK_EQUAL(mv41[6], 0.0f);
	BOOST_CHECK_EQUAL(mv41[7], 943.0f);

	hep::multi_vector<float, 3, 0> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42[0], -8057.0f);
	BOOST_CHECK_EQUAL(mv42[1], 0.0f);
	BOOST_CHECK_EQUAL(mv42[2], 0.0f);
	BOOST_CHECK_EQUAL(mv42[3], 2213.0f);
	BOOST_CHECK_EQUAL(mv42[4], 0.0f);
	BOOST_CHECK_EQUAL(mv42[5], 2415.0f);
	BOOST_CHECK_EQUAL(mv42[6], 2515.0f);
	BOOST_CHECK_EQUAL(mv42[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43[0], 0.0f);
	BOOST_CHECK_EQUAL(mv43[1], -3763.0f);
	BOOST_CHECK_EQUAL(mv43[2], 3551.0f);
	BOOST_CHECK_EQUAL(mv43[3], 0.0f);
	BOOST_CHECK_EQUAL(mv43[4], -3233.0f);
	BOOST_CHECK_EQUAL(mv43[5], 0.0f);
	BOOST_CHECK_EQUAL(mv43[6], 0.0f);
	BOOST_CHECK_EQUAL(mv43[7], 3127.0f);

	hep::multi_vector<float, 3, 0> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44[0], -12392.0f);
	BOOST_CHECK_EQUAL(mv44[1], 0.0f);
	BOOST_CHECK_EQUAL(mv44[2], 0.0f);
	BOOST_CHECK_EQUAL(mv44[3], 9044.0f);
	BOOST_CHECK_EQUAL(mv44[4], 0.0f);
	BOOST_CHECK_EQUAL(mv44[5], 9608.0f);
	BOOST_CHECK_EQUAL(mv44[6], 10664.0f);
	BOOST_CHECK_EQUAL(mv44[7], 0.0f);

	hep::multi_vector<float, 3, 0> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45[0], -23906.0f);
	BOOST_CHECK_EQUAL(mv45[1], 15526.0f);
	BOOST_CHECK_EQUAL(mv45[2], 23050.0f);
	BOOST_CHECK_EQUAL(mv45[3], 17650.0f);
	BOOST_CHECK_EQUAL(mv45[4], -21182.0f);
	BOOST_CHECK_EQUAL(mv45[5], 18262.0f);
	BOOST_CHECK_EQUAL(mv45[6], 19754.0f);
	BOOST_CHECK_EQUAL(mv45[7], 19670.0f);

	hep::multi_vector<float, 3, 0> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50[0], 291.0f);
	BOOST_CHECK_EQUAL(mv50[1], 303.0f);
	BOOST_CHECK_EQUAL(mv50[2], 309.0f);
	BOOST_CHECK_EQUAL(mv50[3], 321.0f);
	BOOST_CHECK_EQUAL(mv50[4], 327.0f);
	BOOST_CHECK_EQUAL(mv50[5], 339.0f);
	BOOST_CHECK_EQUAL(mv50[6], 381.0f);
	BOOST_CHECK_EQUAL(mv50[7], 393.0f);

	hep::multi_vector<float, 3, 0> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51[0], 5135.0f);
	BOOST_CHECK_EQUAL(mv51[1], 5227.0f);
	BOOST_CHECK_EQUAL(mv51[2], 2671.0f);
	BOOST_CHECK_EQUAL(mv51[3], 2867.0f);
	BOOST_CHECK_EQUAL(mv51[4], -1785.0f);
	BOOST_CHECK_EQUAL(mv51[5], -1725.0f);
	BOOST_CHECK_EQUAL(mv51[6], 1807.0f);
	BOOST_CHECK_EQUAL(mv51[7], 1763.0f);

	hep::multi_vector<float, 3, 0> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52[0], -14053.0f);
	BOOST_CHECK_EQUAL(mv52[1], -13913.0f);
	BOOST_CHECK_EQUAL(mv52[2], 4421.0f);
	BOOST_CHECK_EQUAL(mv52[3], 3937.0f);
	BOOST_CHECK_EQUAL(mv52[4], 3723.0f);
	BOOST_CHECK_EQUAL(mv52[5], 3879.0f);
	BOOST_CHECK_EQUAL(mv52[6], 3965.0f);
	BOOST_CHECK_EQUAL(mv52[7], 4153.0f);

	hep::multi_vector<float, 3, 0> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53[0], -6943.0f);
	BOOST_CHECK_EQUAL(mv53[1], -6731.0f);
	BOOST_CHECK_EQUAL(mv53[2], 5989.0f);
	BOOST_CHECK_EQUAL(mv53[3], 5777.0f);
	BOOST_CHECK_EQUAL(mv53[4], -5671.0f);
	BOOST_CHECK_EQUAL(mv53[5], -5459.0f);
	BOOST_CHECK_EQUAL(mv53[6], 5353.0f);
	BOOST_CHECK_EQUAL(mv53[7], 5141.0f);

	hep::multi_vector<float, 3, 0> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54[0], -22054.0f);
	BOOST_CHECK_EQUAL(mv54[1], -21470.0f);
	BOOST_CHECK_EQUAL(mv54[2], 16670.0f);
	BOOST_CHECK_EQUAL(mv54[3], 15958.0f);
	BOOST_CHECK_EQUAL(mv54[4], 15158.0f);
	BOOST_CHECK_EQUAL(mv54[5], 15790.0f);
	BOOST_CHECK_EQUAL(mv54[6], 17950.0f);
	BOOST_CHECK_EQUAL(mv54[7], 18614.0f);

	hep::multi_vector<float, 3, 0> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55[0], -18660.0f);
	BOOST_CHECK_EQUAL(mv55[1], -16164.0f);
	BOOST_CHECK_EQUAL(mv55[2], 71580.0f);
	BOOST_CHECK_EQUAL(mv55[3], 71292.0f);
	BOOST_CHECK_EQUAL(mv55[4], -9096.0f);
	BOOST_CHECK_EQUAL(mv55[5], -6648.0f);
	BOOST_CHECK_EQUAL(mv55[6], 68832.0f);
	BOOST_CHECK_EQUAL(mv55[7], 68880.0f);
}
