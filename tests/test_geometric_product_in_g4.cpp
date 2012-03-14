#include <tuple>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (1,3) and general grade list
template <int... C>
using mv4 = hep::multi_vector<hep::algebra<double, 1, 3>, hep::list<C...>>;

BOOST_AUTO_TEST_CASE(geometric_product)
{
	auto lhs = std::make_tuple(
		mv4<0>{ 2.0 },
		mv4<1,2,4,8>{ 5.0, 7.0, 11.0, 13.0 },
		mv4<3,5,6,9,10,12>{ 31.0, 37.0, 41.0, 43.0, 47.0, 53.0 },
		mv4<7,11,13,14>{ 83.0, 89.0, 97.0, 101.0 },
		mv4<15>{ 127.0 },
		mv4<0,3,5,6,9,10,12,15>{
			137.0, 139.0, 149.0, 151.0, 157.0, 163.0, 167.0, 173.0
		},
		mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15>{
			227.0, 229.0, 233.0, 239.0, 241.0, 251.0, 257.0, 263.0, 269.0,
			271.0, 277.0, 281.0, 283.0, 293.0, 307.0, 311.0
		}
	);

	auto rhs = std::make_tuple(
		mv4<0>{ 3.0 },
		mv4<1,2,4,8>{ 17.0, 19.0, 23.0, 29.0 },
		mv4<3,5,6,9,10,12>{ 59.0, 61.0, 67.0, 71.0, 73.0, 79.0 },
		mv4<7,11,13,14>{ 103.0, 107.0, 109.0, 113.0 },
		mv4<15>{ 131.0 },
		mv4<0,3,5,6,9,10,12,15>{
			179.0, 181.0, 191.0, 193.0, 197.0, 199.0, 211.0, 223.0
		},
		mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15>{
			313.0, 317.0, 331.0, 337.0, 347.0, 349.0, 353.0, 359.0, 367.0,
			373.0, 379.0, 383.0, 389.0, 397.0, 401.0, 409.0
		}
	);

	mv4<0> mv00 = std::get<0>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv00.at<0>(), 6.0);

	mv4<1,2,4,8> mv01 = std::get<0>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv01.at<1>(), 34.0);
	BOOST_CHECK_EQUAL(mv01.at<2>(), 38.0);
	BOOST_CHECK_EQUAL(mv01.at<4>(), 46.0);
	BOOST_CHECK_EQUAL(mv01.at<8>(), 58.0);

	mv4<3,5,6,9,10,12> mv02 = std::get<0>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv02.at<3>(), 118.0);
	BOOST_CHECK_EQUAL(mv02.at<5>(), 122.0);
	BOOST_CHECK_EQUAL(mv02.at<6>(), 134.0);
	BOOST_CHECK_EQUAL(mv02.at<9>(), 142.0);
	BOOST_CHECK_EQUAL(mv02.at<10>(), 146.0);
	BOOST_CHECK_EQUAL(mv02.at<12>(), 158.0);

	mv4<7,11,13,14> mv03 = std::get<0>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv03.at<7>(), 206.0);
	BOOST_CHECK_EQUAL(mv03.at<11>(), 214.0);
	BOOST_CHECK_EQUAL(mv03.at<13>(), 218.0);
	BOOST_CHECK_EQUAL(mv03.at<14>(), 226.0);

	mv4<15> mv04 = std::get<0>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv04.at<15>(), 262.0);

	mv4<0,3,5,6,9,10,12,15> mv05 = std::get<0>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv05.at<0>(), 358.0);
	BOOST_CHECK_EQUAL(mv05.at<3>(), 362.0);
	BOOST_CHECK_EQUAL(mv05.at<5>(), 382.0);
	BOOST_CHECK_EQUAL(mv05.at<6>(), 386.0);
	BOOST_CHECK_EQUAL(mv05.at<9>(), 394.0);
	BOOST_CHECK_EQUAL(mv05.at<10>(), 398.0);
	BOOST_CHECK_EQUAL(mv05.at<12>(), 422.0);
	BOOST_CHECK_EQUAL(mv05.at<15>(), 446.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv06
		= std::get<0>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv06.at<0>(), 626.0);
	BOOST_CHECK_EQUAL(mv06.at<1>(), 634.0);
	BOOST_CHECK_EQUAL(mv06.at<2>(), 662.0);
	BOOST_CHECK_EQUAL(mv06.at<3>(), 674.0);
	BOOST_CHECK_EQUAL(mv06.at<4>(), 694.0);
	BOOST_CHECK_EQUAL(mv06.at<5>(), 698.0);
	BOOST_CHECK_EQUAL(mv06.at<6>(), 706.0);
	BOOST_CHECK_EQUAL(mv06.at<7>(), 718.0);
	BOOST_CHECK_EQUAL(mv06.at<8>(), 734.0);
	BOOST_CHECK_EQUAL(mv06.at<9>(), 746.0);
	BOOST_CHECK_EQUAL(mv06.at<10>(), 758.0);
	BOOST_CHECK_EQUAL(mv06.at<11>(), 766.0);
	BOOST_CHECK_EQUAL(mv06.at<12>(), 778.0);
	BOOST_CHECK_EQUAL(mv06.at<13>(), 794.0);
	BOOST_CHECK_EQUAL(mv06.at<14>(), 802.0);
	BOOST_CHECK_EQUAL(mv06.at<15>(), 818.0);

	mv4<1,2,4,8> mv10 = std::get<1>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv10.at<1>(), 15.0);
	BOOST_CHECK_EQUAL(mv10.at<2>(), 21.0);
	BOOST_CHECK_EQUAL(mv10.at<4>(), 33.0);
	BOOST_CHECK_EQUAL(mv10.at<8>(), 39.0);

	mv4<0,3,5,6,9,10,12> mv11 = std::get<1>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv11.at<0>(), -678.0);
	BOOST_CHECK_EQUAL(mv11.at<3>(), -24.0);
	BOOST_CHECK_EQUAL(mv11.at<5>(), -72.0);
	BOOST_CHECK_EQUAL(mv11.at<6>(), -48.0);
	BOOST_CHECK_EQUAL(mv11.at<9>(), -76.0);
	BOOST_CHECK_EQUAL(mv11.at<10>(), -44.0);
	BOOST_CHECK_EQUAL(mv11.at<12>(), 20.0);

	mv4<1,2,4,7,8,11,13,14> mv12 = std::get<1>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv12.at<1>(), 2007.0);
	BOOST_CHECK_EQUAL(mv12.at<2>(), 1981.0);
	BOOST_CHECK_EQUAL(mv12.at<4>(), 863.0);
	BOOST_CHECK_EQUAL(mv12.at<7>(), 557.0);
	BOOST_CHECK_EQUAL(mv12.at<8>(), -1025.0);
	BOOST_CHECK_EQUAL(mv12.at<11>(), 635.0);
	BOOST_CHECK_EQUAL(mv12.at<13>(), 407.0);
	BOOST_CHECK_EQUAL(mv12.at<14>(), 621.0);

	mv4<3,5,6,9,10,12,15> mv13 = std::get<1>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv13.at<3>(), -2524.0);
	BOOST_CHECK_EQUAL(mv13.at<5>(), -696.0);
	BOOST_CHECK_EQUAL(mv13.at<6>(), -954.0);
	BOOST_CHECK_EQUAL(mv13.at<9>(), 1948.0);
	BOOST_CHECK_EQUAL(mv13.at<10>(), 1778.0);
	BOOST_CHECK_EQUAL(mv13.at<12>(), -246.0);
	BOOST_CHECK_EQUAL(mv13.at<15>(), -360.0);

	mv4<7,11,13,14> mv14 = std::get<1>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv14.at<7>(), 1703.0);
	BOOST_CHECK_EQUAL(mv14.at<11>(), -1441.0);
	BOOST_CHECK_EQUAL(mv14.at<13>(), 917.0);
	BOOST_CHECK_EQUAL(mv14.at<14>(), 655.0);

	mv4<1,2,4,7,8,11,13,14> mv15 = std::get<1>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv15.at<1>(), 6824.0);
	BOOST_CHECK_EQUAL(mv15.at<2>(), 6868.0);
	BOOST_CHECK_EQUAL(mv15.at<4>(), 4316.0);
	BOOST_CHECK_EQUAL(mv15.at<7>(), 4518.0);
	BOOST_CHECK_EQUAL(mv15.at<8>(), -402.0);
	BOOST_CHECK_EQUAL(mv15.at<11>(), -484.0);
	BOOST_CHECK_EQUAL(mv15.at<13>(), 2932.0);
	BOOST_CHECK_EQUAL(mv15.at<14>(), 2912.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv16
		= std::get<1>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv16.at<0>(), -9320.0);
	BOOST_CHECK_EQUAL(mv16.at<1>(), 12612.0);
	BOOST_CHECK_EQUAL(mv16.at<2>(), 12686.0);
	BOOST_CHECK_EQUAL(mv16.at<3>(), -9492.0);
	BOOST_CHECK_EQUAL(mv16.at<4>(), 7774.0);
	BOOST_CHECK_EQUAL(mv16.at<5>(), -4400.0);
	BOOST_CHECK_EQUAL(mv16.at<6>(), -4630.0);
	BOOST_CHECK_EQUAL(mv16.at<7>(), 8346.0);
	BOOST_CHECK_EQUAL(mv16.at<8>(), -998.0);
	BOOST_CHECK_EQUAL(mv16.at<9>(), 4762.0);
	BOOST_CHECK_EQUAL(mv16.at<10>(), 4592.0);
	BOOST_CHECK_EQUAL(mv16.at<11>(), -834.0);
	BOOST_CHECK_EQUAL(mv16.at<12>(), -1296.0);
	BOOST_CHECK_EQUAL(mv16.at<13>(), 5242.0);
	BOOST_CHECK_EQUAL(mv16.at<14>(), 5188.0);
	BOOST_CHECK_EQUAL(mv16.at<15>(), -1228.0);

	mv4<3,5,6,9,10,12> mv20 = std::get<2>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv20.at<3>(), 93.0);
	BOOST_CHECK_EQUAL(mv20.at<5>(), 111.0);
	BOOST_CHECK_EQUAL(mv20.at<6>(), 123.0);
	BOOST_CHECK_EQUAL(mv20.at<9>(), 129.0);
	BOOST_CHECK_EQUAL(mv20.at<10>(), 141.0);
	BOOST_CHECK_EQUAL(mv20.at<12>(), 159.0);

	mv4<1,2,4,7,8,11,13,14> mv21 = std::get<2>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv21.at<1>(), -2687.0);
	BOOST_CHECK_EQUAL(mv21.at<2>(), -2833.0);
	BOOST_CHECK_EQUAL(mv21.at<4>(), -1387.0);
	BOOST_CHECK_EQUAL(mv21.at<7>(), 707.0);
	BOOST_CHECK_EQUAL(mv21.at<8>(), 1381.0);
	BOOST_CHECK_EQUAL(mv21.at<11>(), 881.0);
	BOOST_CHECK_EQUAL(mv21.at<13>(), 985.0);
	BOOST_CHECK_EQUAL(mv21.at<14>(), 1115.0);

	mv4<0,3,5,6,9,10,12,15> mv22 = std::get<2>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv22.at<0>(), -3226.0);
	BOOST_CHECK_EQUAL(mv22.at<3>(), -220.0);
	BOOST_CHECK_EQUAL(mv22.at<5>(), -24.0);
	BOOST_CHECK_EQUAL(mv22.at<6>(), 136.0);
	BOOST_CHECK_EQUAL(mv22.at<9>(), 820.0);
	BOOST_CHECK_EQUAL(mv22.at<10>(), 648.0);
	BOOST_CHECK_EQUAL(mv22.at<12>(), -160.0);
	BOOST_CHECK_EQUAL(mv22.at<15>(), 5800.0);

	mv4<1,2,4,7,8,11,13,14> mv23 = std::get<2>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv23.at<1>(), -15029.0);
	BOOST_CHECK_EQUAL(mv23.at<2>(), -14401.0);
	BOOST_CHECK_EQUAL(mv23.at<4>(), 3817.0);
	BOOST_CHECK_EQUAL(mv23.at<7>(), -5407.0);
	BOOST_CHECK_EQUAL(mv23.at<8>(), 2717.0);
	BOOST_CHECK_EQUAL(mv23.at<11>(), 5171.0);
	BOOST_CHECK_EQUAL(mv23.at<13>(), -3957.0);
	BOOST_CHECK_EQUAL(mv23.at<14>(), -3849.0);

	mv4<3,5,6,9,10,12> mv24 = std::get<2>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv24.at<3>(), -6943.0);
	BOOST_CHECK_EQUAL(mv24.at<5>(), 6157.0);
	BOOST_CHECK_EQUAL(mv24.at<6>(), 5633.0);
	BOOST_CHECK_EQUAL(mv24.at<9>(), -5371.0);
	BOOST_CHECK_EQUAL(mv24.at<10>(), -4847.0);
	BOOST_CHECK_EQUAL(mv24.at<12>(), 4061.0);

	mv4<0,3,5,6,9,10,12,15> mv25 = std::get<2>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv25.at<0>(), -7300.0);
	BOOST_CHECK_EQUAL(mv25.at<3>(), -7662.0);
	BOOST_CHECK_EQUAL(mv25.at<5>(), 17174.0);
	BOOST_CHECK_EQUAL(mv25.at<6>(), 17074.0);
	BOOST_CHECK_EQUAL(mv25.at<9>(), 3208.0);
	BOOST_CHECK_EQUAL(mv25.at<10>(), 3416.0);
	BOOST_CHECK_EQUAL(mv25.at<12>(), 16412.0);
	BOOST_CHECK_EQUAL(mv25.at<15>(), 16170.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv26
		= std::get<2>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv26.at<0>(), -13504.0);
	BOOST_CHECK_EQUAL(mv26.at<1>(), -92642.0);
	BOOST_CHECK_EQUAL(mv26.at<2>(), -92308.0);
	BOOST_CHECK_EQUAL(mv26.at<3>(), -14456.0);
	BOOST_CHECK_EQUAL(mv26.at<4>(), -4704.0);
	BOOST_CHECK_EQUAL(mv26.at<5>(), 30636.0);
	BOOST_CHECK_EQUAL(mv26.at<6>(), 30266.0);
	BOOST_CHECK_EQUAL(mv26.at<7>(), -7376.0);
	BOOST_CHECK_EQUAL(mv26.at<8>(), 30438.0);
	BOOST_CHECK_EQUAL(mv26.at<9>(), 4884.0);
	BOOST_CHECK_EQUAL(mv26.at<10>(), 5266.0);
	BOOST_CHECK_EQUAL(mv26.at<11>(), 29630.0);
	BOOST_CHECK_EQUAL(mv26.at<12>(), 29422.0);
	BOOST_CHECK_EQUAL(mv26.at<13>(), 1858.0);
	BOOST_CHECK_EQUAL(mv26.at<14>(), 2708.0);
	BOOST_CHECK_EQUAL(mv26.at<15>(), 29966.0);

	mv4<7,11,13,14> mv30 = std::get<3>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv30.at<7>(), 249.0);
	BOOST_CHECK_EQUAL(mv30.at<11>(), 267.0);
	BOOST_CHECK_EQUAL(mv30.at<13>(), 291.0);
	BOOST_CHECK_EQUAL(mv30.at<14>(), 303.0);

	mv4<3,5,6,9,10,12,15> mv31 = std::get<3>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv31.at<3>(), -4490.0);
	BOOST_CHECK_EQUAL(mv31.at<5>(), -1236.0);
	BOOST_CHECK_EQUAL(mv31.at<6>(), -1518.0);
	BOOST_CHECK_EQUAL(mv31.at<9>(), 3922.0);
	BOOST_CHECK_EQUAL(mv31.at<10>(), 3836.0);
	BOOST_CHECK_EQUAL(mv31.at<12>(), -270.0);
	BOOST_CHECK_EQUAL(mv31.at<15>(), 486.0);

	mv4<1,2,4,7,8,11,13,14> mv32 = std::get<3>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv32.at<1>(), -19721.0);
	BOOST_CHECK_EQUAL(mv32.at<2>(), -19361.0);
	BOOST_CHECK_EQUAL(mv32.at<4>(), 5383.0);
	BOOST_CHECK_EQUAL(mv32.at<7>(), 7121.0);
	BOOST_CHECK_EQUAL(mv32.at<8>(), 4401.0);
	BOOST_CHECK_EQUAL(mv32.at<11>(), -6219.0);
	BOOST_CHECK_EQUAL(mv32.at<13>(), 6055.0);
	BOOST_CHECK_EQUAL(mv32.at<14>(), 6187.0);

	mv4<0,3,5,6,9,10,12> mv33 = std::get<3>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv33.at<0>(), -17232.0);
	BOOST_CHECK_EQUAL(mv33.at<3>(), 48.0);
	BOOST_CHECK_EQUAL(mv33.at<5>(), -750.0);
	BOOST_CHECK_EQUAL(mv33.at<6>(), -678.0);
	BOOST_CHECK_EQUAL(mv33.at<9>(), 1024.0);
	BOOST_CHECK_EQUAL(mv33.at<10>(), 944.0);
	BOOST_CHECK_EQUAL(mv33.at<12>(), -286.0);

	mv4<1,2,4,8> mv34 = std::get<3>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv34.at<1>(), -13231.0);
	BOOST_CHECK_EQUAL(mv34.at<2>(), -12707.0);
	BOOST_CHECK_EQUAL(mv34.at<4>(), 11659.0);
	BOOST_CHECK_EQUAL(mv34.at<8>(), -10873.0);

	mv4<1,2,4,7,8,11,13,14> mv35 = std::get<3>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv35.at<1>(), -76720.0);
	BOOST_CHECK_EQUAL(mv35.at<2>(), -76328.0);
	BOOST_CHECK_EQUAL(mv35.at<4>(), 35860.0);
	BOOST_CHECK_EQUAL(mv35.at<7>(), 34230.0);
	BOOST_CHECK_EQUAL(mv35.at<8>(), -3366.0);
	BOOST_CHECK_EQUAL(mv35.at<11>(), -2152.0);
	BOOST_CHECK_EQUAL(mv35.at<13>(), 34984.0);
	BOOST_CHECK_EQUAL(mv35.at<14>(), 34988.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv36
		= std::get<3>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv36.at<0>(), -61892.0);
	BOOST_CHECK_EQUAL(mv36.at<1>(), -142072.0);
	BOOST_CHECK_EQUAL(mv36.at<2>(), -141126.0);
	BOOST_CHECK_EQUAL(mv36.at<3>(), -60264.0);
	BOOST_CHECK_EQUAL(mv36.at<4>(), 66470.0);
	BOOST_CHECK_EQUAL(mv36.at<5>(), -11120.0);
	BOOST_CHECK_EQUAL(mv36.at<6>(), -12574.0);
	BOOST_CHECK_EQUAL(mv36.at<7>(), 61510.0);
	BOOST_CHECK_EQUAL(mv36.at<8>(), -5754.0);
	BOOST_CHECK_EQUAL(mv36.at<9>(), 66094.0);
	BOOST_CHECK_EQUAL(mv36.at<10>(), 65132.0);
	BOOST_CHECK_EQUAL(mv36.at<11>(), -5438.0);
	BOOST_CHECK_EQUAL(mv36.at<12>(), -2844.0);
	BOOST_CHECK_EQUAL(mv36.at<13>(), 64438.0);
	BOOST_CHECK_EQUAL(mv36.at<14>(), 64200.0);
	BOOST_CHECK_EQUAL(mv36.at<15>(), -332.0);

	mv4<15> mv40 = std::get<4>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv40.at<15>(), 381.0);

	mv4<7,11,13,14> mv41 = std::get<4>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv41.at<7>(), -3683.0);
	BOOST_CHECK_EQUAL(mv41.at<11>(), 2921.0);
	BOOST_CHECK_EQUAL(mv41.at<13>(), -2413.0);
	BOOST_CHECK_EQUAL(mv41.at<14>(), -2159.0);

	mv4<3,5,6,9,10,12> mv42 = std::get<4>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv42.at<3>(), -10033.0);
	BOOST_CHECK_EQUAL(mv42.at<5>(), 9271.0);
	BOOST_CHECK_EQUAL(mv42.at<6>(), 9017.0);
	BOOST_CHECK_EQUAL(mv42.at<9>(), -8509.0);
	BOOST_CHECK_EQUAL(mv42.at<10>(), -7747.0);
	BOOST_CHECK_EQUAL(mv42.at<12>(), 7493.0);

	mv4<1,2,4,8> mv43 = std::get<4>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv43.at<1>(), 14351.0);
	BOOST_CHECK_EQUAL(mv43.at<2>(), 13843.0);
	BOOST_CHECK_EQUAL(mv43.at<4>(), -13589.0);
	BOOST_CHECK_EQUAL(mv43.at<8>(), 13081.0);

	mv4<0> mv44 = std::get<4>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv44.at<0>(), -16637.0);

	mv4<0,3,5,6,9,10,12,15> mv45 = std::get<4>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv45.at<0>(), -28321.0);
	BOOST_CHECK_EQUAL(mv45.at<3>(), -26797.0);
	BOOST_CHECK_EQUAL(mv45.at<5>(), 25273.0);
	BOOST_CHECK_EQUAL(mv45.at<6>(), 25019.0);
	BOOST_CHECK_EQUAL(mv45.at<9>(), -24511.0);
	BOOST_CHECK_EQUAL(mv45.at<10>(), -24257.0);
	BOOST_CHECK_EQUAL(mv45.at<12>(), 22987.0);
	BOOST_CHECK_EQUAL(mv45.at<15>(), 22733.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv46
		= std::get<4>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv46.at<0>(), -51943.0);
	BOOST_CHECK_EQUAL(mv46.at<1>(), 50927.0);
	BOOST_CHECK_EQUAL(mv46.at<2>(), 50419.0);
	BOOST_CHECK_EQUAL(mv46.at<3>(), -49403.0);
	BOOST_CHECK_EQUAL(mv46.at<4>(), -48641.0);
	BOOST_CHECK_EQUAL(mv46.at<5>(), 48133.0);
	BOOST_CHECK_EQUAL(mv46.at<6>(), 47371.0);
	BOOST_CHECK_EQUAL(mv46.at<7>(), -46609.0);
	BOOST_CHECK_EQUAL(mv46.at<8>(), 45593.0);
	BOOST_CHECK_EQUAL(mv46.at<9>(), -44831.0);
	BOOST_CHECK_EQUAL(mv46.at<10>(), -44323.0);
	BOOST_CHECK_EQUAL(mv46.at<11>(), 44069.0);
	BOOST_CHECK_EQUAL(mv46.at<12>(), 42799.0);
	BOOST_CHECK_EQUAL(mv46.at<13>(), -42037.0);
	BOOST_CHECK_EQUAL(mv46.at<14>(), -40259.0);
	BOOST_CHECK_EQUAL(mv46.at<15>(), 39751.0);

	mv4<0,3,5,6,9,10,12,15> mv50 = std::get<5>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv50.at<0>(), 411.0);
	BOOST_CHECK_EQUAL(mv50.at<3>(), 417.0);
	BOOST_CHECK_EQUAL(mv50.at<5>(), 447.0);
	BOOST_CHECK_EQUAL(mv50.at<6>(), 453.0);
	BOOST_CHECK_EQUAL(mv50.at<9>(), 471.0);
	BOOST_CHECK_EQUAL(mv50.at<10>(), 489.0);
	BOOST_CHECK_EQUAL(mv50.at<12>(), 501.0);
	BOOST_CHECK_EQUAL(mv50.at<15>(), 519.0);

	mv4<1,2,4,7,8,11,13,14> mv51 = std::get<5>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv51.at<1>(), -8292.0);
	BOOST_CHECK_EQUAL(mv51.at<2>(), -7960.0);
	BOOST_CHECK_EQUAL(mv51.at<4>(), -1356.0);
	BOOST_CHECK_EQUAL(mv51.at<7>(), -2084.0);
	BOOST_CHECK_EQUAL(mv51.at<8>(), 8242.0);
	BOOST_CHECK_EQUAL(mv51.at<11>(), 7798.0);
	BOOST_CHECK_EQUAL(mv51.at<13>(), 262.0);
	BOOST_CHECK_EQUAL(mv51.at<14>(), 862.0);

	mv4<0,3,5,6,9,10,12,15> mv52 = std::get<5>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv52.at<0>(), -6772.0);
	BOOST_CHECK_EQUAL(mv52.at<3>(), -4924.0);
	BOOST_CHECK_EQUAL(mv52.at<5>(), 21128.0);
	BOOST_CHECK_EQUAL(mv52.at<6>(), 22460.0);
	BOOST_CHECK_EQUAL(mv52.at<9>(), -3978.0);
	BOOST_CHECK_EQUAL(mv52.at<10>(), -1898.0);
	BOOST_CHECK_EQUAL(mv52.at<12>(), 20130.0);
	BOOST_CHECK_EQUAL(mv52.at<15>(), 21254.0);

	mv4<1,2,4,7,8,11,13,14> mv53 = std::get<5>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv53.at<1>(), -31648.0);
	BOOST_CHECK_EQUAL(mv53.at<2>(), -32160.0);
	BOOST_CHECK_EQUAL(mv53.at<4>(), -2888.0);
	BOOST_CHECK_EQUAL(mv53.at<7>(), -3732.0);
	BOOST_CHECK_EQUAL(mv53.at<8>(), 31870.0);
	BOOST_CHECK_EQUAL(mv53.at<11>(), 32238.0);
	BOOST_CHECK_EQUAL(mv53.at<13>(), -1406.0);
	BOOST_CHECK_EQUAL(mv53.at<14>(), 102.0);

	mv4<0,3,5,6,9,10,12,15> mv54 = std::get<5>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv54.at<0>(), -22663.0);
	BOOST_CHECK_EQUAL(mv54.at<3>(), -21877.0);
	BOOST_CHECK_EQUAL(mv54.at<5>(), 21353.0);
	BOOST_CHECK_EQUAL(mv54.at<6>(), 20567.0);
	BOOST_CHECK_EQUAL(mv54.at<9>(), -19781.0);
	BOOST_CHECK_EQUAL(mv54.at<10>(), -19519.0);
	BOOST_CHECK_EQUAL(mv54.at<12>(), 18209.0);
	BOOST_CHECK_EQUAL(mv54.at<15>(), 17947.0);

	mv4<0,3,5,6,9,10,12,15> mv55 = std::get<5>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv55.at<0>(), -26326.0);
	BOOST_CHECK_EQUAL(mv55.at<3>(), -25018.0);
	BOOST_CHECK_EQUAL(mv55.at<5>(), 124346.0);
	BOOST_CHECK_EQUAL(mv55.at<6>(), 124142.0);
	BOOST_CHECK_EQUAL(mv55.at<9>(), -9670.0);
	BOOST_CHECK_EQUAL(mv55.at<10>(), -8426.0);
	BOOST_CHECK_EQUAL(mv55.at<12>(), 120334.0);
	BOOST_CHECK_EQUAL(mv55.at<15>(), 120338.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv56
		= std::get<5>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv56.at<0>(), -50514.0);
	BOOST_CHECK_EQUAL(mv56.at<1>(), -225466.0);
	BOOST_CHECK_EQUAL(mv56.at<2>(), -222842.0);
	BOOST_CHECK_EQUAL(mv56.at<3>(), -47322.0);
	BOOST_CHECK_EQUAL(mv56.at<4>(), -24326.0);
	BOOST_CHECK_EQUAL(mv56.at<5>(), 227286.0);
	BOOST_CHECK_EQUAL(mv56.at<6>(), 226182.0);
	BOOST_CHECK_EQUAL(mv56.at<7>(), -29734.0);
	BOOST_CHECK_EQUAL(mv56.at<8>(), 226358.0);
	BOOST_CHECK_EQUAL(mv56.at<9>(), -20014.0);
	BOOST_CHECK_EQUAL(mv56.at<10>(), -17102.0);
	BOOST_CHECK_EQUAL(mv56.at<11>(), 222974.0);
	BOOST_CHECK_EQUAL(mv56.at<12>(), 219622.0);
	BOOST_CHECK_EQUAL(mv56.at<13>(), -6154.0);
	BOOST_CHECK_EQUAL(mv56.at<14>(), -250.0);
	BOOST_CHECK_EQUAL(mv56.at<15>(), 218918.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv60
		= std::get<6>(lhs) * std::get<0>(rhs);

	BOOST_CHECK_EQUAL(mv60.at<0>(), 681.0);
	BOOST_CHECK_EQUAL(mv60.at<1>(), 687.0);
	BOOST_CHECK_EQUAL(mv60.at<2>(), 699.0);
	BOOST_CHECK_EQUAL(mv60.at<3>(), 717.0);
	BOOST_CHECK_EQUAL(mv60.at<4>(), 723.0);
	BOOST_CHECK_EQUAL(mv60.at<5>(), 753.0);
	BOOST_CHECK_EQUAL(mv60.at<6>(), 771.0);
	BOOST_CHECK_EQUAL(mv60.at<7>(), 789.0);
	BOOST_CHECK_EQUAL(mv60.at<8>(), 807.0);
	BOOST_CHECK_EQUAL(mv60.at<9>(), 813.0);
	BOOST_CHECK_EQUAL(mv60.at<10>(), 831.0);
	BOOST_CHECK_EQUAL(mv60.at<11>(), 843.0);
	BOOST_CHECK_EQUAL(mv60.at<12>(), 849.0);
	BOOST_CHECK_EQUAL(mv60.at<13>(), 879.0);
	BOOST_CHECK_EQUAL(mv60.at<14>(), 921.0);
	BOOST_CHECK_EQUAL(mv60.at<15>(), 933.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv61
		= std::get<6>(lhs) * std::get<1>(rhs);

	BOOST_CHECK_EQUAL(mv61.at<0>(), -13878.0);
	BOOST_CHECK_EQUAL(mv61.at<1>(), -14314.0);
	BOOST_CHECK_EQUAL(mv61.at<2>(), -13694.0);
	BOOST_CHECK_EQUAL(mv61.at<3>(), -13808.0);
	BOOST_CHECK_EQUAL(mv61.at<4>(), -2370.0);
	BOOST_CHECK_EQUAL(mv61.at<5>(), -2330.0);
	BOOST_CHECK_EQUAL(mv61.at<6>(), -3652.0);
	BOOST_CHECK_EQUAL(mv61.at<7>(), -3922.0);
	BOOST_CHECK_EQUAL(mv61.at<8>(), 13748.0);
	BOOST_CHECK_EQUAL(mv61.at<9>(), 14146.0);
	BOOST_CHECK_EQUAL(mv61.at<10>(), 13484.0);
	BOOST_CHECK_EQUAL(mv61.at<11>(), 13644.0);
	BOOST_CHECK_EQUAL(mv61.at<12>(), -50.0);
	BOOST_CHECK_EQUAL(mv61.at<13>(), -52.0);
	BOOST_CHECK_EQUAL(mv61.at<14>(), 1172.0);
	BOOST_CHECK_EQUAL(mv61.at<15>(), 1512.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv62
		= std::get<6>(lhs) * std::get<2>(rhs);

	BOOST_CHECK_EQUAL(mv62.at<0>(), -11144.0);
	BOOST_CHECK_EQUAL(mv62.at<1>(), -13734.0);
	BOOST_CHECK_EQUAL(mv62.at<2>(), -10952.0);
	BOOST_CHECK_EQUAL(mv62.at<3>(), -9920.0);
	BOOST_CHECK_EQUAL(mv62.at<4>(), 36734.0);
	BOOST_CHECK_EQUAL(mv62.at<5>(), 37016.0);
	BOOST_CHECK_EQUAL(mv62.at<6>(), 38744.0);
	BOOST_CHECK_EQUAL(mv62.at<7>(),37956.0);
	BOOST_CHECK_EQUAL(mv62.at<8>(), -5906.0);
	BOOST_CHECK_EQUAL(mv62.at<9>(), -8390.0);
	BOOST_CHECK_EQUAL(mv62.at<10>(),  -4722.0);
	BOOST_CHECK_EQUAL(mv62.at<11>(), -3828.0);
	BOOST_CHECK_EQUAL(mv62.at<12>(), 35194.0);
	BOOST_CHECK_EQUAL(mv62.at<13>(), 35874.0);
	BOOST_CHECK_EQUAL(mv62.at<14>(), 37656.0);
	BOOST_CHECK_EQUAL(mv62.at<15>(), 36762.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv63
		= std::get<6>(lhs) * std::get<3>(rhs);

	BOOST_CHECK_EQUAL(mv63.at<0>(), -54402.0);
	BOOST_CHECK_EQUAL(mv63.at<1>(), -51814.0);
	BOOST_CHECK_EQUAL(mv63.at<2>(), -52930.0);
	BOOST_CHECK_EQUAL(mv63.at<3>(), -53252.0);
	BOOST_CHECK_EQUAL(mv63.at<4>(), -6898.0);
	BOOST_CHECK_EQUAL(mv63.at<5>(), -6418.0);
	BOOST_CHECK_EQUAL(mv63.at<6>(), -7532.0);
	BOOST_CHECK_EQUAL(mv63.at<7>(), -7330.0);
	BOOST_CHECK_EQUAL(mv63.at<8>(), 55924.0);
	BOOST_CHECK_EQUAL(mv63.at<9>(), 53102.0);
	BOOST_CHECK_EQUAL(mv63.at<10>(), 53248.0);
	BOOST_CHECK_EQUAL(mv63.at<11>(), 53788.0);
	BOOST_CHECK_EQUAL(mv63.at<12>(), -2170.0);
	BOOST_CHECK_EQUAL(mv63.at<13>(), -3296.0);
	BOOST_CHECK_EQUAL(mv63.at<14>(), -1456.0);
	BOOST_CHECK_EQUAL(mv63.at<15>(), -1440.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv64
		= std::get<6>(lhs) * std::get<4>(rhs);

	BOOST_CHECK_EQUAL(mv64.at<0>(), -40741.0);
	BOOST_CHECK_EQUAL(mv64.at<1>(), -40217.0);
	BOOST_CHECK_EQUAL(mv64.at<2>(), -38383.0);
	BOOST_CHECK_EQUAL(mv64.at<3>(), -37073.0);
	BOOST_CHECK_EQUAL(mv64.at<4>(), 36811.0);
	BOOST_CHECK_EQUAL(mv64.at<5>(), 36287.0);
	BOOST_CHECK_EQUAL(mv64.at<6>(), 35501.0);
	BOOST_CHECK_EQUAL(mv64.at<7>(),35239.0);
	BOOST_CHECK_EQUAL(mv64.at<8>(), -34453.0);
	BOOST_CHECK_EQUAL(mv64.at<9>(), -33667.0);
	BOOST_CHECK_EQUAL(mv64.at<10>(),  -32881.0);
	BOOST_CHECK_EQUAL(mv64.at<11>(), -31571.0);
	BOOST_CHECK_EQUAL(mv64.at<12>(), 31309.0);
	BOOST_CHECK_EQUAL(mv64.at<13>(), 30523.0);
	BOOST_CHECK_EQUAL(mv64.at<14>(), 29999.0);
	BOOST_CHECK_EQUAL(mv64.at<15>(), 29737.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv65
		= std::get<6>(lhs) * std::get<5>(rhs);

	BOOST_CHECK_EQUAL(mv65.at<0>(), -48570.0);
	BOOST_CHECK_EQUAL(mv65.at<1>(), -54774.0);
	BOOST_CHECK_EQUAL(mv65.at<2>(), -52506.0);
	BOOST_CHECK_EQUAL(mv65.at<3>(), -46146.0);
	BOOST_CHECK_EQUAL(mv65.at<4>(), 212306.0);
	BOOST_CHECK_EQUAL(mv65.at<5>(), 213766.0);
	BOOST_CHECK_EQUAL(mv65.at<6>(), 213426.0);
	BOOST_CHECK_EQUAL(mv65.at<7>(), 211842.0);
	BOOST_CHECK_EQUAL(mv65.at<8>(), -15030.0);
	BOOST_CHECK_EQUAL(mv65.at<9>(), -20438.0);
	BOOST_CHECK_EQUAL(mv65.at<10>(),  -18258.0);
	BOOST_CHECK_EQUAL(mv65.at<11>(), -12666.0);
	BOOST_CHECK_EQUAL(mv65.at<12>(), 208138.0);
	BOOST_CHECK_EQUAL(mv65.at<13>(), 210298.0);
	BOOST_CHECK_EQUAL(mv65.at<14>(), 210314.0);
	BOOST_CHECK_EQUAL(mv65.at<15>(), 208018.0);

	mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15> mv66
		= std::get<6>(lhs) * std::get<6>(rhs);

	BOOST_CHECK_EQUAL(mv66.at<0>(), -474848.0);
	BOOST_CHECK_EQUAL(mv66.at<1>(), -483932.0);
	BOOST_CHECK_EQUAL(mv66.at<2>(), -474116.0);
	BOOST_CHECK_EQUAL(mv66.at<3>(), -464732.0);
	BOOST_CHECK_EQUAL(mv66.at<4>(), 338956.0);
	BOOST_CHECK_EQUAL(mv66.at<5>(), 345592.0);
	BOOST_CHECK_EQUAL(mv66.at<6>(), 334548.0);
	BOOST_CHECK_EQUAL(mv66.at<7>(), 327436.0);
	BOOST_CHECK_EQUAL(mv66.at<8>(), 355640.0);
	BOOST_CHECK_EQUAL(mv66.at<9>(), 341612.0);
	BOOST_CHECK_EQUAL(mv66.at<10>(), 340844.0);
	BOOST_CHECK_EQUAL(mv66.at<11>(), 354796.0);
	BOOST_CHECK_EQUAL(mv66.at<12>(), 363716.0);
	BOOST_CHECK_EQUAL(mv66.at<13>(), 362136.0);
	BOOST_CHECK_EQUAL(mv66.at<14>(), 371052.0);
	BOOST_CHECK_EQUAL(mv66.at<15>(), 371988.0);
}
