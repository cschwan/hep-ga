#include "gtest/gtest.h"

#include <hep/ga_types.hpp>
#include <hep/ga/grade.hpp>

#include <tuple>

TEST(GradeTest, CheckGradeInG2)
{
	auto mvs = std::make_tuple(
		mv2<0>      { 2.0 },
		mv2<1,2>    { 5.0, 7.0 },
		mv2<3>      { 17.0 },
		mv2<0,1,2>  { 23.0, 29.0, 31.0 },
		mv2<0,3>    { 47.0, 53.0 },
		mv2<1,2,3>  { 67.0, 71.0, 73.0 },
		mv2<0,1,2,3>{ 97.0, 101.0, 103.0, 107.0 }
	);

	mv2<0> mv00 = hep::grade<0>(std::get<0>(mvs));

	EXPECT_EQ(mv00.at<0>(), 2.0);

	mv2<1,2> mv10 = hep::grade<1>(std::get<1>(mvs));

	EXPECT_EQ(mv10.at<1>(), 5.0);
	EXPECT_EQ(mv10.at<2>(), 7.0);

	mv2<3> mv20 = hep::grade<2>(std::get<2>(mvs));

	EXPECT_EQ(mv20.at<3>(), 17.0);

	mv2<0> mv30 = hep::grade<0>(std::get<3>(mvs));

	EXPECT_EQ(mv30.at<0>(), 23.0);

	mv2<1,2> mv31 = hep::grade<1>(std::get<3>(mvs));

	EXPECT_EQ(mv31.at<1>(), 29.0);
	EXPECT_EQ(mv31.at<2>(), 31.0);

	mv2<0,1,2> mv32 = hep::grade<0,1>(std::get<3>(mvs));

	EXPECT_EQ(mv32.at<0>(), 23.0);
	EXPECT_EQ(mv32.at<1>(), 29.0);
	EXPECT_EQ(mv32.at<2>(), 31.0);

	mv2<0> mv40 = hep::grade<0>(std::get<4>(mvs));

	EXPECT_EQ(mv40.at<0>(), 47.0);

	mv2<3> mv41 = hep::grade<2>(std::get<4>(mvs));

	EXPECT_EQ(mv41.at<3>(), 53.0);

	mv2<0,3> mv42 = hep::grade<0,2>(std::get<4>(mvs));

	EXPECT_EQ(mv42.at<0>(), 47.0);
	EXPECT_EQ(mv42.at<3>(), 53.0);

	mv2<1,2> mv50 = hep::grade<1>(std::get<5>(mvs));

	EXPECT_EQ(mv50.at<1>(), 67.0);
	EXPECT_EQ(mv50.at<2>(), 71.0);

	mv2<3> mv51 = hep::grade<2>(std::get<5>(mvs));

	EXPECT_EQ(mv51.at<3>(), 73.0);

	mv2<1,2,3> mv52 = hep::grade<1,2>(std::get<5>(mvs));

	EXPECT_EQ(mv52.at<1>(), 67.0);
	EXPECT_EQ(mv52.at<2>(), 71.0);
	EXPECT_EQ(mv52.at<3>(), 73.0);

	mv2<0> mv60 = hep::grade<0>(std::get<6>(mvs));

	EXPECT_EQ(mv60.at<0>(), 97.0);

	mv2<1,2> mv61 = hep::grade<1>(std::get<6>(mvs));

	EXPECT_EQ(mv61.at<1>(), 101.0);
	EXPECT_EQ(mv61.at<2>(), 103.0);

	mv2<3> mv62 = hep::grade<2>(std::get<6>(mvs));

	EXPECT_EQ(mv62.at<3>(), 107.0);

	mv2<0,1,2,3> mv63 = hep::grade<0,1,2>(std::get<6>(mvs));

	EXPECT_EQ(mv63.at<0>(), 97.0);
	EXPECT_EQ(mv63.at<1>(), 101.0);
	EXPECT_EQ(mv63.at<2>(), 103.0);
	EXPECT_EQ(mv63.at<3>(), 107.0);
}
