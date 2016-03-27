#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/product.hpp>

#include <tuple>

TEST(Product, CheckProductWithScalarInG2)
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

	mv2<0> mv00 = std::get<0>(lhs) * 10.0;

	EXPECT_EQ(mv00.at<0>(), 20.0);

	mv2<1,2> mv01 = std::get<1>(lhs) * 10.0;

	EXPECT_EQ(mv01.at<1>(), 50.0);
	EXPECT_EQ(mv01.at<2>(), 70.0);

	mv2<3> mv02 = std::get<2>(lhs) * 10.0;

	EXPECT_EQ(mv02.at<3>(), 170.0);

	mv2<0,1,2> mv03 = std::get<3>(lhs) * 10.0;

	EXPECT_EQ(mv03.at<0>(), 230.0);
	EXPECT_EQ(mv03.at<1>(), 290.0);
	EXPECT_EQ(mv03.at<2>(), 310.0);

	mv2<0,3> mv04 = std::get<4>(lhs) * 10.0;

	EXPECT_EQ(mv04.at<0>(), 470.0);
	EXPECT_EQ(mv04.at<3>(), 530.0);

	mv2<1,2,3> mv05 = std::get<5>(lhs) * 10.0;

	EXPECT_EQ(mv05.at<1>(), 670.0);
	EXPECT_EQ(mv05.at<2>(), 710.0);
	EXPECT_EQ(mv05.at<3>(), 730.0);

	mv2<0,1,2,3> mv06 = std::get<6>(lhs) * 10.0;

	EXPECT_EQ(mv06.at<0>(), 970.0);
	EXPECT_EQ(mv06.at<1>(), 1010.0);
	EXPECT_EQ(mv06.at<2>(), 1030.0);
	EXPECT_EQ(mv06.at<3>(), 1070.0);

	mv2<0> mv10 = 10.0 * std::get<0>(rhs);

	EXPECT_EQ(mv10.at<0>(), 30.0);

	mv2<1,2> mv11 = 10.0 * std::get<1>(rhs);

	EXPECT_EQ(mv11.at<1>(), 110.0);
	EXPECT_EQ(mv11.at<2>(), 130.0);

	mv2<3> mv12 = 10.0 * std::get<2>(rhs);

	EXPECT_EQ(mv12.at<3>(), 190.0);

	mv2<0,1,2> mv13 = 10.0 * std::get<3>(rhs);

	EXPECT_EQ(mv13.at<0>(), 370.0);
	EXPECT_EQ(mv13.at<1>(), 410.0);
	EXPECT_EQ(mv13.at<2>(), 430.0);

	mv2<0,3> mv14 = 10.0 * std::get<4>(rhs);

	EXPECT_EQ(mv14.at<0>(), 590.0);
	EXPECT_EQ(mv14.at<3>(), 610.0);

	mv2<1,2,3> mv15 = 10.0 * std::get<5>(rhs);

	EXPECT_EQ(mv15.at<1>(), 790.0);
	EXPECT_EQ(mv15.at<2>(), 830.0);
	EXPECT_EQ(mv15.at<3>(), 890.0);

	mv2<0,1,2,3> mv16 = 10.0 * std::get<6>(rhs);

	EXPECT_EQ(mv16.at<0>(), 1090.0);
	EXPECT_EQ(mv16.at<1>(), 1130.0);
	EXPECT_EQ(mv16.at<2>(), 1270.0);
	EXPECT_EQ(mv16.at<3>(), 1310.0);
}
