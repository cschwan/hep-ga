#include <tuple>
#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <int... C>
using mv2 = hep::multi_vector<hep::algebra<double, 2, 0>, hep::list<C...>>;

BOOST_AUTO_TEST_CASE(addition)
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

	BOOST_CHECK_EQUAL(mv00.at<0>(), 2.0);

	mv2<1,2> mv10 = hep::grade<1>(std::get<1>(mvs));

	BOOST_CHECK_EQUAL(mv10.at<1>(), 5.0);
	BOOST_CHECK_EQUAL(mv10.at<2>(), 7.0);

	mv2<3> mv20 = hep::grade<2>(std::get<2>(mvs));

	BOOST_CHECK_EQUAL(mv20.at<3>(), 17.0);

	mv2<0> mv30 = hep::grade<0>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv30.at<0>(), 23.0);

	mv2<1,2> mv31 = hep::grade<1>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv31.at<1>(), 29.0);
	BOOST_CHECK_EQUAL(mv31.at<2>(), 31.0);

	mv2<0,1,2> mv32 = hep::grade<0,1>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv32.at<0>(), 23.0);
	BOOST_CHECK_EQUAL(mv32.at<1>(), 29.0);
	BOOST_CHECK_EQUAL(mv32.at<2>(), 31.0);

	mv2<0> mv40 = hep::grade<0>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv40.at<0>(), 47.0);

	mv2<3> mv41 = hep::grade<2>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv41.at<3>(), 53.0);

	mv2<0,3> mv42 = hep::grade<0,2>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv42.at<0>(), 47.0);
	BOOST_CHECK_EQUAL(mv42.at<3>(), 53.0);

	mv2<1,2> mv50 = hep::grade<1>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv50.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv50.at<2>(), 71.0);

	mv2<3> mv51 = hep::grade<2>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv51.at<3>(), 73.0);

	mv2<1,2,3> mv52 = hep::grade<1,2>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv52.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv52.at<2>(), 71.0);
	BOOST_CHECK_EQUAL(mv52.at<3>(), 73.0);

	mv2<0> mv60 = hep::grade<0>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv60.at<0>(), 97.0);

	mv2<1,2> mv61 = hep::grade<1>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv61.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv61.at<2>(), 103.0);

	mv2<3> mv62 = hep::grade<2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv62.at<3>(), 107.0);

	mv2<0,1,2,3> mv63 = hep::grade<0,1,2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv63.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv63.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv63.at<2>(), 103.0);
	BOOST_CHECK_EQUAL(mv63.at<3>(), 107.0);
}
