#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/sum.hpp>

#include <tuple>

TEST(Sum, CheckSumInG2)
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

	mv2<0> mv00 = std::get<0>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv00.at<0>(), 5.0);

	mv2<0,1,2> mv01 = std::get<0>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv01.at<0>(), 2.0);
	EXPECT_EQ(mv01.at<1>(), 11.0);
	EXPECT_EQ(mv01.at<2>(), 13.0);

	mv2<0,3> mv02 = std::get<0>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv02.at<0>(), 2.0);
	EXPECT_EQ(mv02.at<3>(), 19.0);

	mv2<0,1,2> mv03 = std::get<0>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv03.at<0>(), 39.0);
	EXPECT_EQ(mv03.at<1>(), 41.0);
	EXPECT_EQ(mv03.at<2>(), 43.0);

	mv2<0,3> mv04 = std::get<0>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv04.at<0>(), 61.0);
	EXPECT_EQ(mv04.at<3>(), 61.0);

	mv2<0,1,2,3> mv05 = std::get<0>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv05.at<0>(), 2.0);
	EXPECT_EQ(mv05.at<1>(), 79.0);
	EXPECT_EQ(mv05.at<2>(), 83.0);
	EXPECT_EQ(mv05.at<3>(), 89.0);

	mv2<0,1,2,3> mv06 = std::get<0>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv06.at<0>(), 111.0);
	EXPECT_EQ(mv06.at<1>(), 113.0);
	EXPECT_EQ(mv06.at<2>(), 127.0);
	EXPECT_EQ(mv06.at<3>(), 131.0);

	mv2<0,1,2> mv10 = std::get<1>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv10.at<0>(), 3.0);
	EXPECT_EQ(mv10.at<1>(), 5.0);
	EXPECT_EQ(mv10.at<2>(), 7.0);

	mv2<1,2> mv11 = std::get<1>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv11.at<1>(), 16.0);
	EXPECT_EQ(mv11.at<2>(), 20.0);

	mv2<1,2,3> mv12 = std::get<1>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv12.at<1>(), 5.0);
	EXPECT_EQ(mv12.at<2>(), 7.0);
	EXPECT_EQ(mv12.at<3>(), 19.0);

	mv2<0,1,2> mv13 = std::get<1>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv13.at<0>(), 37.0);
	EXPECT_EQ(mv13.at<1>(), 46.0);
	EXPECT_EQ(mv13.at<2>(), 50.0);

	mv2<0,1,2,3> mv14 = std::get<1>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv14.at<0>(), 59.0);
	EXPECT_EQ(mv14.at<1>(), 5.0);
	EXPECT_EQ(mv14.at<2>(), 7.0);
	EXPECT_EQ(mv14.at<3>(), 61.0);

	mv2<1,2,3> mv15 = std::get<1>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv15.at<1>(), 84.0);
	EXPECT_EQ(mv15.at<2>(), 90.0);
	EXPECT_EQ(mv15.at<3>(), 89.0);

	mv2<0,1,2,3> mv16 = std::get<1>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv16.at<0>(), 109.0);
	EXPECT_EQ(mv16.at<1>(), 118.0);
	EXPECT_EQ(mv16.at<2>(), 134.0);
	EXPECT_EQ(mv16.at<3>(), 131.0);

	mv2<0,3> mv20 = std::get<2>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv20.at<0>(), 3.0);
	EXPECT_EQ(mv20.at<3>(), 17.0);

	mv2<1,2,3> mv21 = std::get<2>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv21.at<1>(), 11.0);
	EXPECT_EQ(mv21.at<2>(), 13.0);
	EXPECT_EQ(mv21.at<3>(), 17.0);

	mv2<3> mv22 = std::get<2>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv22.at<3>(), 36.0);

	mv2<0,1,2,3> mv23 = std::get<2>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv23.at<0>(), 37.0);
	EXPECT_EQ(mv23.at<1>(), 41.0);
	EXPECT_EQ(mv23.at<2>(), 43.0);
	EXPECT_EQ(mv23.at<3>(), 17.0);

	mv2<0,3> mv24 = std::get<2>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv24.at<0>(), 59.0);
	EXPECT_EQ(mv24.at<3>(), 78.0);

	mv2<1,2,3> mv25 = std::get<2>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv25.at<1>(), 79.0);
	EXPECT_EQ(mv25.at<2>(), 83.0);
	EXPECT_EQ(mv25.at<3>(), 106.0);

	mv2<0,1,2,3> mv26 = std::get<2>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv26.at<0>(), 109.0);
	EXPECT_EQ(mv26.at<1>(), 113.0);
	EXPECT_EQ(mv26.at<2>(), 127.0);
	EXPECT_EQ(mv26.at<3>(), 148.0);

	mv2<0,1,2> mv30 = std::get<3>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv30.at<0>(), 26.0);
	EXPECT_EQ(mv30.at<1>(), 29.0);
	EXPECT_EQ(mv30.at<2>(), 31.0);

	mv2<0,1,2> mv31 = std::get<3>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv31.at<0>(), 23.0);
	EXPECT_EQ(mv31.at<1>(), 40.0);
	EXPECT_EQ(mv31.at<2>(), 44.0);

	mv2<0,1,2,3> mv32 = std::get<3>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv32.at<0>(), 23.0);
	EXPECT_EQ(mv32.at<1>(), 29.0);
	EXPECT_EQ(mv32.at<2>(), 31.0);
	EXPECT_EQ(mv32.at<3>(), 19.0);

	mv2<0,1,2> mv33 = std::get<3>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv33.at<0>(), 60.0);
	EXPECT_EQ(mv33.at<1>(), 70.0);
	EXPECT_EQ(mv33.at<2>(), 74.0);

	mv2<0,1,2,3> mv34 = std::get<3>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv34.at<0>(), 82.0);
	EXPECT_EQ(mv34.at<1>(), 29.0);
	EXPECT_EQ(mv34.at<2>(), 31.0);
	EXPECT_EQ(mv34.at<3>(), 61.0);

	mv2<0,1,2,3> mv35 = std::get<3>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv35.at<0>(), 23.0);
	EXPECT_EQ(mv35.at<1>(), 108.0);
	EXPECT_EQ(mv35.at<2>(), 114.0);
	EXPECT_EQ(mv35.at<3>(), 89.0);

	mv2<0,1,2,3> mv36 = std::get<3>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv36.at<0>(), 132.0);
	EXPECT_EQ(mv36.at<1>(), 142.0);
	EXPECT_EQ(mv36.at<2>(), 158.0);
	EXPECT_EQ(mv36.at<3>(), 131.0);

	mv2<0,3> mv40 = std::get<4>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv40.at<0>(), 50.0);
	EXPECT_EQ(mv40.at<3>(), 53.0);

	mv2<0,1,2,3> mv41 = std::get<4>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv41.at<0>(), 47.0);
	EXPECT_EQ(mv41.at<1>(), 11.0);
	EXPECT_EQ(mv41.at<2>(), 13.0);
	EXPECT_EQ(mv41.at<3>(), 53.0);

	mv2<0,3> mv42 = std::get<4>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv42.at<0>(), 47.0);
	EXPECT_EQ(mv42.at<3>(), 72.0);

	mv2<0,1,2,3> mv43 = std::get<4>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv43.at<0>(), 84.0);
	EXPECT_EQ(mv43.at<1>(), 41.0);
	EXPECT_EQ(mv43.at<2>(), 43.0);
	EXPECT_EQ(mv43.at<3>(), 53.0);

	mv2<0,3> mv44 = std::get<4>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv44.at<0>(), 106.0);
	EXPECT_EQ(mv44.at<3>(), 114.0);

	mv2<0,1,2,3> mv45 = std::get<4>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv45.at<0>(), 47.0);
	EXPECT_EQ(mv45.at<1>(), 79.0);
	EXPECT_EQ(mv45.at<2>(), 83.0);
	EXPECT_EQ(mv45.at<3>(), 142.0);

	mv2<0,1,2,3> mv46 = std::get<4>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv46.at<0>(), 156.0);
	EXPECT_EQ(mv46.at<1>(), 113.0);
	EXPECT_EQ(mv46.at<2>(), 127.0);
	EXPECT_EQ(mv46.at<3>(), 184.0);

	mv2<0,1,2,3> mv50 = std::get<5>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv50.at<0>(), 3.0);
	EXPECT_EQ(mv50.at<1>(), 67.0);
	EXPECT_EQ(mv50.at<2>(), 71.0);
	EXPECT_EQ(mv50.at<3>(), 73.0);

	mv2<1,2,3> mv51 = std::get<5>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv51.at<1>(), 78.0);
	EXPECT_EQ(mv51.at<2>(), 84.0);
	EXPECT_EQ(mv51.at<3>(), 73.0);

	mv2<1,2,3> mv52 = std::get<5>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv52.at<1>(), 67.0);
	EXPECT_EQ(mv52.at<2>(), 71.0);
	EXPECT_EQ(mv52.at<3>(), 92.0);

	mv2<0,1,2,3> mv53 = std::get<5>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv53.at<0>(), 37.0);
	EXPECT_EQ(mv53.at<1>(), 108.0);
	EXPECT_EQ(mv53.at<2>(), 114.0);
	EXPECT_EQ(mv53.at<3>(), 73.0);

	mv2<0,1,2,3> mv54 = std::get<5>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv54.at<0>(), 59.0);
	EXPECT_EQ(mv54.at<1>(), 67.0);
	EXPECT_EQ(mv54.at<2>(), 71.0);
	EXPECT_EQ(mv54.at<3>(), 134.0);

	mv2<1,2,3> mv55 = std::get<5>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv55.at<1>(), 146.0);
	EXPECT_EQ(mv55.at<2>(), 154.0);
	EXPECT_EQ(mv55.at<3>(), 162.0);

	mv2<0,1,2,3> mv56 = std::get<5>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv56.at<0>(), 109.0);
	EXPECT_EQ(mv56.at<1>(), 180.0);
	EXPECT_EQ(mv56.at<2>(), 198.0);
	EXPECT_EQ(mv56.at<3>(), 204.0);

	mv2<0,1,2,3> mv60 = std::get<6>(lhs) + std::get<0>(rhs);

	EXPECT_EQ(mv60.at<0>(), 100.0);
	EXPECT_EQ(mv60.at<1>(), 101.0);
	EXPECT_EQ(mv60.at<2>(), 103.0);
	EXPECT_EQ(mv60.at<3>(), 107.0);

	mv2<0,1,2,3> mv61 = std::get<6>(lhs) + std::get<1>(rhs);

	EXPECT_EQ(mv61.at<0>(), 97.0);
	EXPECT_EQ(mv61.at<1>(), 112.0);
	EXPECT_EQ(mv61.at<2>(), 116.0);
	EXPECT_EQ(mv61.at<3>(), 107.0);

	mv2<0,1,2,3> mv62 = std::get<6>(lhs) + std::get<2>(rhs);

	EXPECT_EQ(mv62.at<0>(), 97.0);
	EXPECT_EQ(mv62.at<1>(), 101.0);
	EXPECT_EQ(mv62.at<2>(), 103.0);
	EXPECT_EQ(mv62.at<3>(), 126.0);

	mv2<0,1,2,3> mv63 = std::get<6>(lhs) + std::get<3>(rhs);

	EXPECT_EQ(mv63.at<0>(), 134.0);
	EXPECT_EQ(mv63.at<1>(), 142.0);
	EXPECT_EQ(mv63.at<2>(), 146.0);
	EXPECT_EQ(mv63.at<3>(), 107.0);

	mv2<0,1,2,3> mv64 = std::get<6>(lhs) + std::get<4>(rhs);

	EXPECT_EQ(mv64.at<0>(), 156.0);
	EXPECT_EQ(mv64.at<1>(), 101.0);
	EXPECT_EQ(mv64.at<2>(), 103.0);
	EXPECT_EQ(mv64.at<3>(), 168.0);

	mv2<0,1,2,3> mv65 = std::get<6>(lhs) + std::get<5>(rhs);

	EXPECT_EQ(mv65.at<0>(), 97.0);
	EXPECT_EQ(mv65.at<1>(), 180.0);
	EXPECT_EQ(mv65.at<2>(), 186.0);
	EXPECT_EQ(mv65.at<3>(), 196.0);

	mv2<0,1,2,3> mv66 = std::get<6>(lhs) + std::get<6>(rhs);

	EXPECT_EQ(mv66.at<0>(), 206.0);
	EXPECT_EQ(mv66.at<1>(), 214.0);
	EXPECT_EQ(mv66.at<2>(), 230.0);
	EXPECT_EQ(mv66.at<3>(), 238.0);
}
