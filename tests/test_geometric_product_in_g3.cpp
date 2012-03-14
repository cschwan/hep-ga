#include <tuple>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (3,0) and general grade list
template <int... C>
using mv3 = hep::multi_vector<hep::algebra<double, 3, 0>, hep::list<C...>>;

BOOST_AUTO_TEST_CASE(geometric_product)
{
	auto lhs = std::make_tuple(
		mv3<0>              { 2.0 },
		mv3<1,2,4>          { 5.0, 7.0, 11.0 },
		mv3<3,5,6>          { 23.0, 29.0, 31.0 },
		mv3<7>              { 47.0 },
		mv3<0,3,5,6>        { 59.0, 61.0, 67.0, 71.0 },
		mv3<0,1,2,3,4,5,6,7>{ 97.0, 101.0, 103.0, 107.0, 109.0, 113.0,
		                      127.0, 131.0 }
	);
	auto rhs = std::make_tuple(
		mv3<0>              { 3.0 },
		mv3<1,2,4>          { 13.0, 17.0, 19.0 },
		mv3<3,5,6>          { 37.0, 41.0, 43.0 },
		mv3<7>              { 53.0 },
		mv3<0,3,5,6>        { 73.0, 79.0, 83.0, 89.0 },
		mv3<0,1,2,3,4,5,6,7>{ 137.0, 139.0, 149.0, 151.0, 157.0, 163.0,
		                      167.0, 173.0 }
	);

	mv3<0> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00.at<0>(), 6.0);

	mv3<1,2,4> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01.at<1>(), 26.0);
	BOOST_CHECK_EQUAL(mv01.at<2>(), 34.0);
	BOOST_CHECK_EQUAL(mv01.at<4>(), 38.0);

	mv3<3,5,6> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02.at<3>(), 74.0);
	BOOST_CHECK_EQUAL(mv02.at<5>(), 82.0);
	BOOST_CHECK_EQUAL(mv02.at<6>(), 86.0);

	mv3<7> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03.at<7>(), 106.0);

	mv3<0,3,5,6> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04.at<0>(), 146.0);
	BOOST_CHECK_EQUAL(mv04.at<3>(), 158.0);
	BOOST_CHECK_EQUAL(mv04.at<5>(), 166.0);
	BOOST_CHECK_EQUAL(mv04.at<6>(), 178.0);

	mv3<0,1,2,3,4,5,6,7> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05.at<0>(), 274.0);
	BOOST_CHECK_EQUAL(mv05.at<1>(), 278.0);
	BOOST_CHECK_EQUAL(mv05.at<2>(), 298.0);
	BOOST_CHECK_EQUAL(mv05.at<3>(), 302.0);
	BOOST_CHECK_EQUAL(mv05.at<4>(), 314.0);
	BOOST_CHECK_EQUAL(mv05.at<5>(), 326.0);
	BOOST_CHECK_EQUAL(mv05.at<6>(), 334.0);
	BOOST_CHECK_EQUAL(mv05.at<7>(), 346.0);

	mv3<1,2,4> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10.at<1>(), 15.0);
	BOOST_CHECK_EQUAL(mv10.at<2>(), 21.0);
	BOOST_CHECK_EQUAL(mv10.at<4>(), 33.0);

	mv3<0,3,5,6> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11.at<0>(), 393.0);
	BOOST_CHECK_EQUAL(mv11.at<3>(), -6.0);
	BOOST_CHECK_EQUAL(mv11.at<5>(), -48.0);
	BOOST_CHECK_EQUAL(mv11.at<6>(), -54.0);

	mv3<1,2,4,7> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12.at<1>(), -710.0);
	BOOST_CHECK_EQUAL(mv12.at<2>(), -288.0);
	BOOST_CHECK_EQUAL(mv12.at<4>(), 506.0);
	BOOST_CHECK_EQUAL(mv12.at<7>(), 335.0);

	mv3<3,5,6> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13.at<3>(), 583.0);
	BOOST_CHECK_EQUAL(mv13.at<5>(), -371.0);
	BOOST_CHECK_EQUAL(mv13.at<6>(), 265.0);

	mv3<1,2,4,7> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14.at<1>(), -1101.0);
	BOOST_CHECK_EQUAL(mv14.at<2>(), -73.0);
	BOOST_CHECK_EQUAL(mv14.at<4>(), 1841.0);
	BOOST_CHECK_EQUAL(mv14.at<7>(), 733.0);

	mv3<0,1,2,3,4,5,6,7> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15.at<0>(), 3465.0);
	BOOST_CHECK_EQUAL(mv15.at<1>(), -2165.0);
	BOOST_CHECK_EQUAL(mv15.at<2>(), -123.0);
	BOOST_CHECK_EQUAL(mv15.at<3>(), 1675.0);
	BOOST_CHECK_EQUAL(mv15.at<4>(), 3491.0);
	BOOST_CHECK_EQUAL(mv15.at<5>(), -1955.0);
	BOOST_CHECK_EQUAL(mv15.at<6>(), 325.0);
	BOOST_CHECK_EQUAL(mv15.at<7>(), 1355.0);

	mv3<3,5,6> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20.at<3>(), 69.0);
	BOOST_CHECK_EQUAL(mv20.at<5>(), 87.0);
	BOOST_CHECK_EQUAL(mv20.at<6>(), 93.0);

	mv3<1,2,4,7> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21.at<1>(), 942.0);
	BOOST_CHECK_EQUAL(mv21.at<2>(), 290.0);
	BOOST_CHECK_EQUAL(mv21.at<4>(), -904.0);
	BOOST_CHECK_EQUAL(mv21.at<7>(), 347.0);

	mv3<0,3,5,6> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22.at<0>(), -3373.0);
	BOOST_CHECK_EQUAL(mv22.at<3>(), 24.0);
	BOOST_CHECK_EQUAL(mv22.at<5>(), -158.0);
	BOOST_CHECK_EQUAL(mv22.at<6>(), 130.0);

	mv3<1,2,4> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23.at<1>(), -1643.0);
	BOOST_CHECK_EQUAL(mv23.at<2>(), 1537.0);
	BOOST_CHECK_EQUAL(mv23.at<4>(), -1219.0);

	mv3<0,3,5,6> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24.at<0>(), -6983.0);
	BOOST_CHECK_EQUAL(mv24.at<3>(), 1671.0);
	BOOST_CHECK_EQUAL(mv24.at<5>(), 1715.0);
	BOOST_CHECK_EQUAL(mv24.at<6>(), 2645.0);

	mv3<0,1,2,3,4,5,6,7> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25.at<0>(), -13377.0);
	BOOST_CHECK_EQUAL(mv25.at<1>(), 2617.0);
	BOOST_CHECK_EQUAL(mv25.at<2>(), 6687.0);
	BOOST_CHECK_EQUAL(mv25.at<3>(), 3361.0);
	BOOST_CHECK_EQUAL(mv25.at<4>(), -12629.0);
	BOOST_CHECK_EQUAL(mv25.at<5>(), 3133.0);
	BOOST_CHECK_EQUAL(mv25.at<6>(), 4877.0);
	BOOST_CHECK_EQUAL(mv25.at<7>(), 3599.0);

	mv3<7> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30.at<7>(), 141.0);

	mv3<3,5,6> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31.at<3>(), 893.0);
	BOOST_CHECK_EQUAL(mv31.at<5>(), -799.0);
	BOOST_CHECK_EQUAL(mv31.at<6>(), 611.0);

	mv3<1,2,4> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32.at<1>(), -2021.0);
	BOOST_CHECK_EQUAL(mv32.at<2>(), 1927.0);
	BOOST_CHECK_EQUAL(mv32.at<4>(), -1739.0);

	mv3<0> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33.at<0>(), -2491.0);

	mv3<1,2,4,7> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34.at<1>(), -4183.0);
	BOOST_CHECK_EQUAL(mv34.at<2>(), 3901.0);
	BOOST_CHECK_EQUAL(mv34.at<4>(), -3713.0);
	BOOST_CHECK_EQUAL(mv34.at<7>(), 3431.0);

	mv3<0,1,2,3,4,5,6,7> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35.at<0>(), -8131.0);
	BOOST_CHECK_EQUAL(mv35.at<1>(), -7849.0);
	BOOST_CHECK_EQUAL(mv35.at<2>(), 7661.0);
	BOOST_CHECK_EQUAL(mv35.at<3>(), 7379.0);
	BOOST_CHECK_EQUAL(mv35.at<4>(), -7097.0);
	BOOST_CHECK_EQUAL(mv35.at<5>(), -7003.0);
	BOOST_CHECK_EQUAL(mv35.at<6>(), 6533.0);
	BOOST_CHECK_EQUAL(mv35.at<7>(), 6439.0);

	mv3<0,3,5,6> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40.at<0>(), 177.0);
	BOOST_CHECK_EQUAL(mv40.at<3>(), 183.0);
	BOOST_CHECK_EQUAL(mv40.at<5>(), 201.0);
	BOOST_CHECK_EQUAL(mv40.at<6>(), 213.0);

	mv3<1,2,4,7> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41.at<1>(), 3077.0);
	BOOST_CHECK_EQUAL(mv41.at<2>(), 1559.0);
	BOOST_CHECK_EQUAL(mv41.at<4>(), -957.0);
	BOOST_CHECK_EQUAL(mv41.at<7>(), 943.0);

	mv3<0,3,5,6> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42.at<0>(), -8057.0);
	BOOST_CHECK_EQUAL(mv42.at<3>(), 2213.0);
	BOOST_CHECK_EQUAL(mv42.at<5>(), 2415.0);
	BOOST_CHECK_EQUAL(mv42.at<6>(), 2515.0);

	mv3<1,2,4,7> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43.at<1>(), -3763.0);
	BOOST_CHECK_EQUAL(mv43.at<2>(), 3551.0);
	BOOST_CHECK_EQUAL(mv43.at<4>(), -3233.0);
	BOOST_CHECK_EQUAL(mv43.at<7>(), 3127.0);

	mv3<0,3,5,6> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44.at<0>(), -12392.0);
	BOOST_CHECK_EQUAL(mv44.at<3>(), 9044.0);
	BOOST_CHECK_EQUAL(mv44.at<5>(), 9608.0);
	BOOST_CHECK_EQUAL(mv44.at<6>(), 10664.0);

	mv3<0,1,2,3,4,5,6,7> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45.at<0>(), -23906.0);
	BOOST_CHECK_EQUAL(mv45.at<1>(), 15526.0);
	BOOST_CHECK_EQUAL(mv45.at<2>(), 23050.0);
	BOOST_CHECK_EQUAL(mv45.at<3>(), 17650.0);
	BOOST_CHECK_EQUAL(mv45.at<4>(), -21182.0);
	BOOST_CHECK_EQUAL(mv45.at<5>(), 18262.0);
	BOOST_CHECK_EQUAL(mv45.at<6>(), 19754.0);
	BOOST_CHECK_EQUAL(mv45.at<7>(), 19670.0);

	mv3<0,1,2,3,4,5,6,7> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50.at<0>(), 291.0);
	BOOST_CHECK_EQUAL(mv50.at<1>(), 303.0);
	BOOST_CHECK_EQUAL(mv50.at<2>(), 309.0);
	BOOST_CHECK_EQUAL(mv50.at<3>(), 321.0);
	BOOST_CHECK_EQUAL(mv50.at<4>(), 327.0);
	BOOST_CHECK_EQUAL(mv50.at<5>(), 339.0);
	BOOST_CHECK_EQUAL(mv50.at<6>(), 381.0);
	BOOST_CHECK_EQUAL(mv50.at<7>(), 393.0);

	mv3<0,1,2,3,4,5,6,7> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51.at<0>(), 5135.0);
	BOOST_CHECK_EQUAL(mv51.at<1>(), 5227.0);
	BOOST_CHECK_EQUAL(mv51.at<2>(), 2671.0);
	BOOST_CHECK_EQUAL(mv51.at<3>(), 2867.0);
	BOOST_CHECK_EQUAL(mv51.at<4>(), -1785.0);
	BOOST_CHECK_EQUAL(mv51.at<5>(), -1725.0);
	BOOST_CHECK_EQUAL(mv51.at<6>(), 1807.0);
	BOOST_CHECK_EQUAL(mv51.at<7>(), 1763.0);

	mv3<0,1,2,3,4,5,6,7> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52.at<0>(), -14053.0);
	BOOST_CHECK_EQUAL(mv52.at<1>(), -13913.0);
	BOOST_CHECK_EQUAL(mv52.at<2>(), 4421.0);
	BOOST_CHECK_EQUAL(mv52.at<3>(), 3937.0);
	BOOST_CHECK_EQUAL(mv52.at<4>(), 3723.0);
	BOOST_CHECK_EQUAL(mv52.at<5>(), 3879.0);
	BOOST_CHECK_EQUAL(mv52.at<6>(), 3965.0);
	BOOST_CHECK_EQUAL(mv52.at<7>(), 4153.0);

	mv3<0,1,2,3,4,5,6,7> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53.at<0>(), -6943.0);
	BOOST_CHECK_EQUAL(mv53.at<1>(), -6731.0);
	BOOST_CHECK_EQUAL(mv53.at<2>(), 5989.0);
	BOOST_CHECK_EQUAL(mv53.at<3>(), 5777.0);
	BOOST_CHECK_EQUAL(mv53.at<4>(), -5671.0);
	BOOST_CHECK_EQUAL(mv53.at<5>(), -5459.0);
	BOOST_CHECK_EQUAL(mv53.at<6>(), 5353.0);
	BOOST_CHECK_EQUAL(mv53.at<7>(), 5141.0);

	mv3<0,1,2,3,4,5,6,7> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54.at<0>(), -22054.0);
	BOOST_CHECK_EQUAL(mv54.at<1>(), -21470.0);
	BOOST_CHECK_EQUAL(mv54.at<2>(), 16670.0);
	BOOST_CHECK_EQUAL(mv54.at<3>(), 15958.0);
	BOOST_CHECK_EQUAL(mv54.at<4>(), 15158.0);
	BOOST_CHECK_EQUAL(mv54.at<5>(), 15790.0);
	BOOST_CHECK_EQUAL(mv54.at<6>(), 17950.0);
	BOOST_CHECK_EQUAL(mv54.at<7>(), 18614.0);

	mv3<0,1,2,3,4,5,6,7> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55.at<0>(), -18660.0);
	BOOST_CHECK_EQUAL(mv55.at<1>(), -16164.0);
	BOOST_CHECK_EQUAL(mv55.at<2>(), 71580.0);
	BOOST_CHECK_EQUAL(mv55.at<3>(), 71292.0);
	BOOST_CHECK_EQUAL(mv55.at<4>(), -9096.0);
	BOOST_CHECK_EQUAL(mv55.at<5>(), -6648.0);
	BOOST_CHECK_EQUAL(mv55.at<6>(), 68832.0);
	BOOST_CHECK_EQUAL(mv55.at<7>(), 68880.0);
}
