#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/sum.hpp>

#include <tuple>

TEST(Sum, CheckSumWithScalarInG2)
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

	mv2<0> mv00 = 1000.0 + std::get<0>(rhs);

	EXPECT_EQ(mv00.at<0>(), 1003.0);

	mv2<0,1,2> mv01 = 1000.0 + std::get<1>(rhs);

	EXPECT_EQ(mv01.at<0>(), 1000.0);
	EXPECT_EQ(mv01.at<1>(), 11.0);
	EXPECT_EQ(mv01.at<2>(), 13.0);

	mv2<0,3> mv02 = 1000.0 + std::get<2>(rhs);

	EXPECT_EQ(mv02.at<0>(), 1000.0);
	EXPECT_EQ(mv02.at<3>(), 19.0);

	mv2<0,1,2> mv03 = 1000.0 + std::get<3>(rhs);

	EXPECT_EQ(mv03.at<0>(), 1037.0);
	EXPECT_EQ(mv03.at<1>(), 41.0);
	EXPECT_EQ(mv03.at<2>(), 43.0);

	mv2<0,3> mv04 = 1000.0 + std::get<4>(rhs);

	EXPECT_EQ(mv04.at<0>(), 1059.0);
	EXPECT_EQ(mv04.at<3>(), 61.0);

	mv2<0,1,2,3> mv05 = 1000.0 + std::get<5>(rhs);

	EXPECT_EQ(mv05.at<0>(), 1000.0);
	EXPECT_EQ(mv05.at<1>(), 79.0);
	EXPECT_EQ(mv05.at<2>(), 83.0);
	EXPECT_EQ(mv05.at<3>(), 89.0);

	mv2<0,1,2,3> mv06 = 1000.0 + std::get<6>(rhs);

	EXPECT_EQ(mv06.at<0>(), 1109.0);
	EXPECT_EQ(mv06.at<1>(), 113.0);
	EXPECT_EQ(mv06.at<2>(), 127.0);
	EXPECT_EQ(mv06.at<3>(), 131.0);

	mv2<0> mv10 = std::get<0>(lhs) + 1000.0;

	EXPECT_EQ(mv10.at<0>(), 1002.0);

	mv2<0,1,2> mv11 = std::get<1>(lhs) + 1000.0;

	EXPECT_EQ(mv11.at<0>(), 1000.0);
	EXPECT_EQ(mv11.at<1>(), 5.0);
	EXPECT_EQ(mv11.at<2>(), 7.0);

	mv2<0,3> mv12 = std::get<2>(lhs) + 1000.0;

	EXPECT_EQ(mv12.at<0>(), 1000.0);
	EXPECT_EQ(mv12.at<3>(), 17.0);

	mv2<0,1,2> mv13 = std::get<3>(lhs) + 1000.0;

	EXPECT_EQ(mv13.at<0>(), 1023.0);
	EXPECT_EQ(mv13.at<1>(), 29.0);
	EXPECT_EQ(mv13.at<2>(), 31.0);

	mv2<0,3> mv14 = std::get<4>(lhs) + 1000.0;

	EXPECT_EQ(mv14.at<0>(), 1047.0);
	EXPECT_EQ(mv14.at<3>(), 53.0);

	mv2<0,1,2,3> mv15 = std::get<5>(lhs) + 1000.0;

	EXPECT_EQ(mv15.at<0>(), 1000.0);
	EXPECT_EQ(mv15.at<1>(), 67.0);
	EXPECT_EQ(mv15.at<2>(), 71.0);
	EXPECT_EQ(mv15.at<3>(), 73.0);

	mv2<0,1,2,3> mv16 = std::get<6>(lhs) + 1000.0;

	EXPECT_EQ(mv16.at<0>(), 1097.0);
	EXPECT_EQ(mv16.at<1>(), 101.0);
	EXPECT_EQ(mv16.at<2>(), 103.0);
	EXPECT_EQ(mv16.at<3>(), 107.0);
}
