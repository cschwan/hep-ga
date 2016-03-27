#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/negation.hpp>

#include <tuple>

TEST(Negation, CheckMinusInG2)
{
	auto rhs = std::make_tuple(
		mv2<0>      { 3.0 },
		mv2<1,2>    { 11.0, 13.0 },
		mv2<3>      { 19.0 },
		mv2<0,1,2>  { 37.0, 41.0, 43.0 },
		mv2<0,3>    { 59.0, 61.0 },
		mv2<1,2,3>  { 79.0, 83.0, 89.0 },
		mv2<0,1,2,3>{ 109.0, 113.0, 127.0, 131.0 }
	);

	mv2<0> mv00 = -std::get<0>(rhs);

	EXPECT_EQ(mv00.at<0>(), -3.0);

	mv2<1,2> mv01 = -std::get<1>(rhs);

	EXPECT_EQ(mv01.at<1>(), -11.0);
	EXPECT_EQ(mv01.at<2>(), -13.0);

	mv2<3> mv02 = -std::get<2>(rhs);

	EXPECT_EQ(mv02.at<3>(), -19.0);

	mv2<0,1,2> mv03 = -std::get<3>(rhs);

	EXPECT_EQ(mv03.at<0>(), -37.0);
	EXPECT_EQ(mv03.at<1>(), -41.0);
	EXPECT_EQ(mv03.at<2>(), -43.0);

	mv2<0,3> mv04 = -std::get<4>(rhs);

	EXPECT_EQ(mv04.at<0>(), -59.0);
	EXPECT_EQ(mv04.at<3>(), -61.0);

	mv2<1,2,3> mv05 = -std::get<5>(rhs);

	EXPECT_EQ(mv05.at<1>(), -79.0);
	EXPECT_EQ(mv05.at<2>(), -83.0);
	EXPECT_EQ(mv05.at<3>(), -89.0);

	mv2<0,1,2,3> mv06 = -std::get<6>(rhs);

	EXPECT_EQ(mv06.at<0>(), -109.0);
	EXPECT_EQ(mv06.at<1>(), -113.0);
	EXPECT_EQ(mv06.at<2>(), -127.0);
	EXPECT_EQ(mv06.at<3>(), -131.0);
}
