#include "gtest/gtest.h"

#include <hep/ga_types.hpp>

#include <tuple>

TEST(IndexAccess, CheckAtInG3)
{
	auto mvs = std::make_tuple(
		mv3<0>              { 2.0 },
		mv3<1,2,4>          { 3.0, 5.0, 7.0 },
		mv3<3,5,6>          { 11.0, 13.0, 17.0 },
		mv3<7>              { 19.0 },
		mv3<0,1,2,4>        { 23.0, 29.0, 31.0, 37.0 },
		mv3<0,3,5,6>        { 41.0, 43.0, 47.0, 53.0 },
		mv3<0,7>            { 59.0, 61.0 },
		mv3<1,2,3,4,5,6>    { 67.0, 71.0, 73.0, 79.0,
		                      83.0, 89.0 },
		mv3<1,2,4,7>        { 97.0, 101.0, 103.0, 107.0 },
		mv3<3,5,6,7>        { 109.0, 113.0, 127.0, 131.0 },
		mv3<0,1,2,3,4,5,6>  { 137.0, 139.0, 149.0, 151.0,
		                      157.0, 163.0, 167.0 },
		mv3<0,1,2,4,7>      { 173.0, 179.0, 181.0, 191.0,
		                      193.0 },
		mv3<0,3,5,6,7>      { 197.0, 199.0, 211.0, 223.0,
		                      227.0 },
		mv3<1,2,3,4,5,6,7>  { 229.0, 233.0, 239.0, 241.0,
		                      251.0, 257.0, 263.0 },
		mv3<0,1,2,3,4,5,6,7>{ 269.0, 271.0, 277.0, 281.0,
		                      283.0, 293.0, 307.0, 311.0 }
	);

	// scalar
	EXPECT_EQ(std::get<0>(mvs).at<0>(), 2.0);

	// vector
	EXPECT_EQ(std::get<1>(mvs).at<1>(), 3.0);
	EXPECT_EQ(std::get<1>(mvs).at<2>(), 5.0);
	EXPECT_EQ(std::get<1>(mvs).at<4>(), 7.0);

	// bivector
	EXPECT_EQ(std::get<2>(mvs).at<3>(), 11.0);
	EXPECT_EQ(std::get<2>(mvs).at<5>(), 13.0);
	EXPECT_EQ(std::get<2>(mvs).at<6>(), 17.0);

	// trivector
	EXPECT_EQ(std::get<3>(mvs).at<7>(), 19.0);

	// scalar + vector
	EXPECT_EQ(std::get<4>(mvs).at<0>(), 23.0);
	EXPECT_EQ(std::get<4>(mvs).at<1>(), 29.0);
	EXPECT_EQ(std::get<4>(mvs).at<2>(), 31.0);
	EXPECT_EQ(std::get<4>(mvs).at<4>(), 37.0);

	// scalar + bivector
	EXPECT_EQ(std::get<5>(mvs).at<0>(), 41.0);
	EXPECT_EQ(std::get<5>(mvs).at<3>(), 43.0);
	EXPECT_EQ(std::get<5>(mvs).at<5>(), 47.0);
	EXPECT_EQ(std::get<5>(mvs).at<6>(), 53.0);

	// scalar + trivector
	EXPECT_EQ(std::get<6>(mvs).at<0>(), 59.0);
	EXPECT_EQ(std::get<6>(mvs).at<7>(), 61.0);

	// vector + bivector
	EXPECT_EQ(std::get<7>(mvs).at<1>(), 67.0);
	EXPECT_EQ(std::get<7>(mvs).at<2>(), 71.0);
	EXPECT_EQ(std::get<7>(mvs).at<3>(), 73.0);
	EXPECT_EQ(std::get<7>(mvs).at<4>(), 79.0);
	EXPECT_EQ(std::get<7>(mvs).at<5>(), 83.0);
	EXPECT_EQ(std::get<7>(mvs).at<6>(), 89.0);

	// vector + trivector
	EXPECT_EQ(std::get<8>(mvs).at<1>(), 97.0);
	EXPECT_EQ(std::get<8>(mvs).at<2>(), 101.0);
	EXPECT_EQ(std::get<8>(mvs).at<4>(), 103.0);
	EXPECT_EQ(std::get<8>(mvs).at<7>(), 107.0);

	// bivector + trivector
	EXPECT_EQ(std::get<9>(mvs).at<3>(), 109.0);
	EXPECT_EQ(std::get<9>(mvs).at<5>(), 113.0);
	EXPECT_EQ(std::get<9>(mvs).at<6>(), 127.0);
	EXPECT_EQ(std::get<9>(mvs).at<7>(), 131.0);

	// scalar + vector + bivector
	EXPECT_EQ(std::get<10>(mvs).at<0>(), 137.0);
	EXPECT_EQ(std::get<10>(mvs).at<1>(), 139.0);
	EXPECT_EQ(std::get<10>(mvs).at<2>(), 149.0);
	EXPECT_EQ(std::get<10>(mvs).at<3>(), 151.0);
	EXPECT_EQ(std::get<10>(mvs).at<4>(), 157.0);
	EXPECT_EQ(std::get<10>(mvs).at<5>(), 163.0);
	EXPECT_EQ(std::get<10>(mvs).at<6>(), 167.0);

	// scalar + vector + trivector
	EXPECT_EQ(std::get<11>(mvs).at<0>(), 173.0);
	EXPECT_EQ(std::get<11>(mvs).at<1>(), 179.0);
	EXPECT_EQ(std::get<11>(mvs).at<2>(), 181.0);
	EXPECT_EQ(std::get<11>(mvs).at<4>(), 191.0);
	EXPECT_EQ(std::get<11>(mvs).at<7>(), 193.0);

	// scalar + bivector + trivector
	EXPECT_EQ(std::get<12>(mvs).at<0>(), 197.0);
	EXPECT_EQ(std::get<12>(mvs).at<3>(), 199.0);
	EXPECT_EQ(std::get<12>(mvs).at<5>(), 211.0);
	EXPECT_EQ(std::get<12>(mvs).at<6>(), 223.0);
	EXPECT_EQ(std::get<12>(mvs).at<7>(), 227.0);

	// vector + bivector + trivector
	EXPECT_EQ(std::get<13>(mvs).at<1>(), 229.0);
	EXPECT_EQ(std::get<13>(mvs).at<2>(), 233.0);
	EXPECT_EQ(std::get<13>(mvs).at<3>(), 239.0);
	EXPECT_EQ(std::get<13>(mvs).at<4>(), 241.0);
	EXPECT_EQ(std::get<13>(mvs).at<5>(), 251.0);
	EXPECT_EQ(std::get<13>(mvs).at<6>(), 257.0);
	EXPECT_EQ(std::get<13>(mvs).at<7>(), 263.0);

	// scalar + vector + bivector + trivector
	EXPECT_EQ(std::get<14>(mvs).at<0>(), 269.0);
	EXPECT_EQ(std::get<14>(mvs).at<1>(), 271.0);
	EXPECT_EQ(std::get<14>(mvs).at<2>(), 277.0);
	EXPECT_EQ(std::get<14>(mvs).at<3>(), 281.0);
	EXPECT_EQ(std::get<14>(mvs).at<4>(), 283.0);
	EXPECT_EQ(std::get<14>(mvs).at<5>(), 293.0);
	EXPECT_EQ(std::get<14>(mvs).at<6>(), 307.0);
	EXPECT_EQ(std::get<14>(mvs).at<7>(), 311.0);
}
