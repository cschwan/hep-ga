#include <tuple>
#include <boost/test/unit_test.hpp>

#include <hep/ga_types.hpp>
#include <hep/reversion.hpp>

BOOST_AUTO_TEST_CASE(negation)
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

	mv3<0> mv00 = hep::reverse(std::get<0>(mvs));

	BOOST_CHECK_EQUAL(mv00.at<0>(), 2.0);

	mv3<1,2,4> mv01 = hep::reverse(std::get<1>(mvs));

	BOOST_CHECK_EQUAL(mv01.at<1>(), 3.0);
	BOOST_CHECK_EQUAL(mv01.at<2>(), 5.0);
	BOOST_CHECK_EQUAL(mv01.at<4>(), 7.0);

	mv3<3,5,6> mv02 = hep::reverse(std::get<2>(mvs));

	BOOST_CHECK_EQUAL(mv02.at<3>(), -11.0);
	BOOST_CHECK_EQUAL(mv02.at<5>(), -13.0);
	BOOST_CHECK_EQUAL(mv02.at<6>(), -17.0);

	mv3<7> mv03 = hep::reverse(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv03.at<7>(), -19.0);

	mv3<0,1,2,4> mv04 = hep::reverse(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv04.at<0>(), 23.0);
	BOOST_CHECK_EQUAL(mv04.at<1>(), 29.0);
	BOOST_CHECK_EQUAL(mv04.at<2>(), 31.0);
	BOOST_CHECK_EQUAL(mv04.at<4>(), 37.0);

	mv3<0,3,5,6> mv05 = hep::reverse(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv05.at<0>(), 41.0);
	BOOST_CHECK_EQUAL(mv05.at<3>(), -43.0);
	BOOST_CHECK_EQUAL(mv05.at<5>(), -47.0);
	BOOST_CHECK_EQUAL(mv05.at<6>(), -53.0);

	mv3<0,7> mv06 = hep::reverse(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv06.at<0>(), 59.0);
	BOOST_CHECK_EQUAL(mv06.at<7>(), -61.0);

	mv3<1,2,3,4,5,6> mv07 = hep::reverse(std::get<7>(mvs));

	BOOST_CHECK_EQUAL(mv07.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv07.at<2>(), 71.0);
	BOOST_CHECK_EQUAL(mv07.at<3>(), -73.0);
	BOOST_CHECK_EQUAL(mv07.at<4>(), 79.0);
	BOOST_CHECK_EQUAL(mv07.at<5>(), -83.0);
	BOOST_CHECK_EQUAL(mv07.at<6>(), -89.0);

	mv3<1,2,4,7> mv08 = hep::reverse(std::get<8>(mvs));

	BOOST_CHECK_EQUAL(mv08.at<1>(), 97.0);
	BOOST_CHECK_EQUAL(mv08.at<2>(), 101.0);
	BOOST_CHECK_EQUAL(mv08.at<4>(), 103.0);
	BOOST_CHECK_EQUAL(mv08.at<7>(), -107.0);

	mv3<3,5,6,7> mv09 = hep::reverse(std::get<9>(mvs));

	BOOST_CHECK_EQUAL(mv09.at<3>(), -109.0);
	BOOST_CHECK_EQUAL(mv09.at<5>(), -113.0);
	BOOST_CHECK_EQUAL(mv09.at<6>(), -127.0);
	BOOST_CHECK_EQUAL(mv09.at<7>(), -131.0);

	mv3<0,1,2,3,4,5,6> mv10 = hep::reverse(std::get<10>(mvs));

	BOOST_CHECK_EQUAL(mv10.at<0>(), 137.0);
	BOOST_CHECK_EQUAL(mv10.at<1>(), 139.0);
	BOOST_CHECK_EQUAL(mv10.at<2>(), 149.0);
	BOOST_CHECK_EQUAL(mv10.at<3>(), -151.0);
	BOOST_CHECK_EQUAL(mv10.at<4>(), 157.0);
	BOOST_CHECK_EQUAL(mv10.at<5>(), -163.0);
	BOOST_CHECK_EQUAL(mv10.at<6>(), -167.0);

	mv3<0,1,2,4,7> mv11 = hep::reverse(std::get<11>(mvs));

	BOOST_CHECK_EQUAL(mv11.at<0>(), 173.0);
	BOOST_CHECK_EQUAL(mv11.at<1>(), 179.0);
	BOOST_CHECK_EQUAL(mv11.at<2>(), 181.0);
	BOOST_CHECK_EQUAL(mv11.at<4>(), 191.0);
	BOOST_CHECK_EQUAL(mv11.at<7>(), -193.0);

	mv3<0,3,5,6,7> mv12 = hep::reverse(std::get<12>(mvs));

	BOOST_CHECK_EQUAL(mv12.at<0>(), 197.0);
	BOOST_CHECK_EQUAL(mv12.at<3>(), -199.0);
	BOOST_CHECK_EQUAL(mv12.at<5>(), -211.0);
	BOOST_CHECK_EQUAL(mv12.at<6>(), -223.0);
	BOOST_CHECK_EQUAL(mv12.at<7>(), -227.0);

	mv3<1,2,3,4,5,6,7> mv13 = hep::reverse(std::get<13>(mvs));

	BOOST_CHECK_EQUAL(mv13.at<1>(), 229.0);
	BOOST_CHECK_EQUAL(mv13.at<2>(), 233.0);
	BOOST_CHECK_EQUAL(mv13.at<3>(), -239.0);
	BOOST_CHECK_EQUAL(mv13.at<4>(), 241.0);
	BOOST_CHECK_EQUAL(mv13.at<5>(), -251.0);
	BOOST_CHECK_EQUAL(mv13.at<6>(), -257.0);
	BOOST_CHECK_EQUAL(mv13.at<7>(), -263.0);

	mv3<0,1,2,3,4,5,6,7> mv14 = hep::reverse(std::get<14>(mvs));

	BOOST_CHECK_EQUAL(mv14.at<0>(), 269.0);
	BOOST_CHECK_EQUAL(mv14.at<1>(), 271.0);
	BOOST_CHECK_EQUAL(mv14.at<2>(), 277.0);
	BOOST_CHECK_EQUAL(mv14.at<3>(), -281.0);
	BOOST_CHECK_EQUAL(mv14.at<4>(), 283.0);
	BOOST_CHECK_EQUAL(mv14.at<5>(), -293.0);
	BOOST_CHECK_EQUAL(mv14.at<6>(), -307.0);
	BOOST_CHECK_EQUAL(mv14.at<7>(), -311.0);
}
