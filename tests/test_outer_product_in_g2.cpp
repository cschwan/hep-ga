#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/outer_product.hpp>

#include <tuple>

TEST(OuterProduct, CheckOuterProductInG2)
{
	auto lhs = std::make_tuple(
		mv2<0>      { 2.0 },
		mv2<1,2>    { 5.0, 7.0 },
		mv2<3>      { 17.0 },
		mv2<0,1,2>  { 23.0, 29.0, 31.0 },
		mv2<0,3>    { 47.0, 53.0 },
		mv2<1,2,3>  { 67.0, 71.0, 73.0 },
		mv2<0,1,2,3>{ 97.0, 101.0, 103.0, 107.0 }
	);

	auto rhs = std::make_tuple(
		mv2<0>      { 3.0 },
		mv2<1,2>    { 11.0, 13.0 },
		mv2<3>      { 19.0 },
		mv2<0,1,2>  { 37.0, 41.0, 43.0 },
		mv2<0,3>    { 59.0, 61.0 },
		mv2<1,2,3>  { 79.0, 83.0, 89.0 },
		mv2<0,1,2,3>{ 109.0, 113.0, 127.0, 131.0 }
	);

	mv2<0> mv00 = std::get<0>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv00.at<0>(), 6.0);

	mv2<1,2> mv01 = std::get<0>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv01.at<1>(), 22.0);
	EXPECT_EQ(mv01.at<2>(), 26.0);

	mv2<3> mv02 = std::get<0>(lhs) ^ std::get<2>(rhs);

	EXPECT_EQ(mv02.at<3>(), 38.0);

	mv2<0,1,2> mv03 = std::get<0>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv03.at<0>(), 74.0);
	EXPECT_EQ(mv03.at<1>(), 82.0);
	EXPECT_EQ(mv03.at<2>(), 86.0);

	mv2<0,3> mv04 = std::get<0>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv04.at<0>(), 118.0);
	EXPECT_EQ(mv04.at<3>(), 122.0);

	mv2<1,2,3> mv05 = std::get<0>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv05.at<1>(), 158.0);
	EXPECT_EQ(mv05.at<2>(), 166.0);
	EXPECT_EQ(mv05.at<3>(), 178.0);

	mv2<0,1,2,3> mv06 = std::get<0>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv06.at<0>(), 218.0);
	EXPECT_EQ(mv06.at<1>(), 226.0);
	EXPECT_EQ(mv06.at<2>(), 254.0);
	EXPECT_EQ(mv06.at<3>(), 262.0);

	mv2<1,2> mv10 = std::get<1>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv10.at<1>(), 15.0);
	EXPECT_EQ(mv10.at<2>(), 21.0);

	mv2<3> mv11 = std::get<1>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv11.at<3>(), -12.0);

// 	std::get<1>(lhs) ^ std::get<2>(rhs);

	mv2<1,2,3> mv13 = std::get<1>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv13.at<1>(), 185.0);
	EXPECT_EQ(mv13.at<2>(), 259.0);
	EXPECT_EQ(mv13.at<3>(), -72.0);

	mv2<1,2> mv14 = std::get<1>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv14.at<1>(), 295.0);
	EXPECT_EQ(mv14.at<2>(), 413.0);

	mv2<3> mv15 = std::get<1>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv15.at<3>(), -138.0);

	mv2<1,2,3> mv16 = std::get<1>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv16.at<1>(), 545.0);
	EXPECT_EQ(mv16.at<2>(), 763.0);
	EXPECT_EQ(mv16.at<3>(), -156.0);

	mv2<3> mv20 = std::get<2>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv20.at<3>(), 51.0);

// 	std::get<2>(lhs) ^ std::get<1>(rhs);
// 	std::get<2>(lhs) ^ std::get<2>(rhs);

	mv2<3> mv23 = std::get<2>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv23.at<3>(), 629.0);

	mv2<3> mv24 = std::get<2>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv24.at<3>(), 1003.0);

// 	std::get<2>(lhs) ^ std::get<5>(rhs);

	mv2<3> mv26 = std::get<2>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv26.at<3>(), 1853.0);

	mv2<0,1,2> mv30 = std::get<3>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv30.at<0>(), 69.0);
	EXPECT_EQ(mv30.at<1>(), 87.0);
	EXPECT_EQ(mv30.at<2>(), 93.0);

	mv2<1,2,3> mv31 = std::get<3>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv31.at<1>(), 253.0);
	EXPECT_EQ(mv31.at<2>(), 299.0);
	EXPECT_EQ(mv31.at<3>(), 36.0);

	mv2<3> mv32 = std::get<3>(lhs) ^ std::get<2>(rhs);

	EXPECT_EQ(mv32.at<3>(), 437.0);

	mv2<0,1,2,3> mv33 = std::get<3>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv33.at<1>(), 2016.0);
	EXPECT_EQ(mv33.at<2>(), 2136.0);
	EXPECT_EQ(mv33.at<3>(), -24.0);

	mv2<0,1,2,3> mv34 = std::get<3>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv34.at<0>(), 1357.0);
	EXPECT_EQ(mv34.at<1>(), 1711.0);
	EXPECT_EQ(mv34.at<2>(), 1829.0);
	EXPECT_EQ(mv34.at<3>(), 1403.0);

	mv2<1,2,3> mv35 = std::get<3>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv35.at<1>(), 1817.0);
	EXPECT_EQ(mv35.at<2>(), 1909.0);
	EXPECT_EQ(mv35.at<3>(), 2005.0);

	mv2<0,1,2,3> mv36 = std::get<3>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv36.at<0>(), 2507.0);
	EXPECT_EQ(mv36.at<1>(), 5760.0);
	EXPECT_EQ(mv36.at<2>(), 6300.0);
	EXPECT_EQ(mv36.at<3>(), 3193.0);

	mv2<0,3> mv40 = std::get<4>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv40.at<0>(), 141.0);
	EXPECT_EQ(mv40.at<3>(), 159.0);

	mv2<1,2> mv41 = std::get<4>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv41.at<1>(), 517.0);
	EXPECT_EQ(mv41.at<2>(), 611.0);

	mv2<3> mv42 = std::get<4>(lhs) ^ std::get<2>(rhs);

	EXPECT_EQ(mv42.at<3>(), 893.0);

	mv2<0,1,2,3> mv43 = std::get<4>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv43.at<0>(), 1739.0);
	EXPECT_EQ(mv43.at<1>(), 1927.0);
	EXPECT_EQ(mv43.at<2>(), 2021.0);
	EXPECT_EQ(mv43.at<3>(), 1961.0);

	mv2<0,3> mv44 = std::get<4>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv44.at<0>(), 2773.0);
	EXPECT_EQ(mv44.at<3>(), 5994.0);

	mv2<1,2,3> mv45 = std::get<4>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv45.at<1>(), 3713.0);
	EXPECT_EQ(mv45.at<2>(), 3901.0);
	EXPECT_EQ(mv45.at<3>(), 4183.0);

	mv2<0,1,2,3> mv46 = std::get<4>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv46.at<0>(), 5123.0);
	EXPECT_EQ(mv46.at<1>(), 5311.0);
	EXPECT_EQ(mv46.at<2>(), 5969.0);
	EXPECT_EQ(mv46.at<3>(), 11934.0);

	mv2<1,2,3> mv50 = std::get<5>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv50.at<1>(), 201.0);
	EXPECT_EQ(mv50.at<2>(), 213.0);
	EXPECT_EQ(mv50.at<3>(), 219.0);

	mv2<3> mv51 = std::get<5>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv51.at<3>(), 90.0);

// 	std::get<5>(lhs) ^ std::get<2>(rhs);

	mv2<1,2,3> mv53 = std::get<5>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv53.at<1>(), 2479.0);
	EXPECT_EQ(mv53.at<2>(), 2627.0);
	EXPECT_EQ(mv53.at<3>(), 2671.0);

	mv2<1,2,3> mv54 = std::get<5>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv54.at<1>(), 3953.0);
	EXPECT_EQ(mv54.at<2>(), 4189.0);
	EXPECT_EQ(mv54.at<3>(), 4307.0);

	mv2<3> mv55 = std::get<5>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv55.at<3>(), -48.0);

	mv2<1,2,3> mv56 = std::get<5>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv56.at<1>(), 7303.0);
	EXPECT_EQ(mv56.at<2>(), 7739.0);
	EXPECT_EQ(mv56.at<3>(), 8443.0);

	mv2<0,1,2,3> mv60 = std::get<6>(lhs) ^ std::get<0>(rhs);

	EXPECT_EQ(mv60.at<0>(), 291.0);
	EXPECT_EQ(mv60.at<1>(), 303.0);
	EXPECT_EQ(mv60.at<2>(), 309.0);
	EXPECT_EQ(mv60.at<3>(), 321.0);

	mv2<1,2,3> mv61 = std::get<6>(lhs) ^ std::get<1>(rhs);

	EXPECT_EQ(mv61.at<1>(), 1067.0);
	EXPECT_EQ(mv61.at<2>(), 1261.0);
	EXPECT_EQ(mv61.at<3>(), 180.0);

	mv2<3> mv62 = std::get<6>(lhs) ^ std::get<2>(rhs);

	EXPECT_EQ(mv62.at<3>(), 1843.0);

	mv2<0,1,2,3> mv63 = std::get<6>(lhs) ^ std::get<3>(rhs);

	EXPECT_EQ(mv63.at<0>(), 3589.0);
	EXPECT_EQ(mv63.at<1>(), 7714.0);
	EXPECT_EQ(mv63.at<2>(), 7982.0);
	EXPECT_EQ(mv63.at<3>(), 4079.0);

	mv2<0,1,2,3> mv64 = std::get<6>(lhs) ^ std::get<4>(rhs);

	EXPECT_EQ(mv64.at<0>(), 5723.0);
	EXPECT_EQ(mv64.at<1>(), 5959.0);
	EXPECT_EQ(mv64.at<2>(), 6077.0);
	EXPECT_EQ(mv64.at<3>(), 12230.0);

	mv2<1,2,3> mv65 = std::get<6>(lhs) ^ std::get<5>(rhs);

	EXPECT_EQ(mv65.at<1>(), 7663.0);
	EXPECT_EQ(mv65.at<2>(), 8051.0);
	EXPECT_EQ(mv65.at<3>(), 8879.0);

	mv2<0,1,2,3> mv66 = std::get<6>(lhs) ^ std::get<6>(rhs);

	EXPECT_EQ(mv66.at<0>(), 10573.0);
	EXPECT_EQ(mv66.at<1>(), 21970.0);
	EXPECT_EQ(mv66.at<2>(), 23546.0);
	EXPECT_EQ(mv66.at<3>(), 25558.0);
}
