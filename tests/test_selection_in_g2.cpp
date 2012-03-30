#include <tuple>
#include <boost/test/unit_test.hpp>

#include <hep/ga_types.hpp>
#include <hep/selection.hpp>

BOOST_AUTO_TEST_CASE(selection)
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

	mv2<0> mv01 = hep::select<0>(std::get<0>(mvs));

	BOOST_CHECK_EQUAL(mv01.at<0>(), 2.0);

	mv2<1> mv02 = hep::select<1>(std::get<1>(mvs));

	BOOST_CHECK_EQUAL(mv02.at<1>(), 5.0);

	mv2<2> mv03 = hep::select<2>(std::get<1>(mvs));

	BOOST_CHECK_EQUAL(mv03.at<2>(), 7.0);

	mv2<1,2> mv04 = hep::select<1,2>(std::get<1>(mvs));

	BOOST_CHECK_EQUAL(mv04.at<1>(), 5.0);
	BOOST_CHECK_EQUAL(mv04.at<2>(), 7.0);

	mv2<3> mv05 = hep::select<3>(std::get<2>(mvs));

	BOOST_CHECK_EQUAL(mv05.at<3>(), 17.0);

	mv2<0> mv06 = hep::select<0>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv06.at<0>(), 23.0);

	mv2<1> mv07 = hep::select<1>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv07.at<1>(), 29.0);

	mv2<2> mv08 = hep::select<2>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv08.at<2>(), 31.0);

	mv2<0,1> mv09 = hep::select<0,1>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv09.at<0>(), 23.0);
	BOOST_CHECK_EQUAL(mv09.at<1>(), 29.0);

	mv2<0,2> mv10 = hep::select<0,2>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv10.at<0>(), 23.0);
	BOOST_CHECK_EQUAL(mv10.at<2>(), 31.0);

	mv2<1,2> mv11 = hep::select<1,2>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv11.at<1>(), 29.0);
	BOOST_CHECK_EQUAL(mv11.at<2>(), 31.0);

	mv2<0,1,2> mv12 = hep::select<0,1,2>(std::get<3>(mvs));

	BOOST_CHECK_EQUAL(mv12.at<0>(), 23.0);
	BOOST_CHECK_EQUAL(mv12.at<1>(), 29.0);
	BOOST_CHECK_EQUAL(mv12.at<2>(), 31.0);

	mv2<0> mv13 = hep::select<0>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv13.at<0>(), 47.0);

	mv2<3> mv14 = hep::select<3>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv14.at<3>(), 53.0);

	mv2<0,3> mv15 = hep::select<0,3>(std::get<4>(mvs));

	BOOST_CHECK_EQUAL(mv15.at<0>(), 47.0);
	BOOST_CHECK_EQUAL(mv15.at<3>(), 53.0);

	mv2<1> mv16 = hep::select<1>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv16.at<1>(), 67.0);

	mv2<2> mv17 = hep::select<2>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv17.at<2>(), 71.0);

	mv2<3> mv18 = hep::select<3>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv18.at<3>(), 73.0);

	mv2<1,2> mv19 = hep::select<1,2>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv19.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv19.at<2>(), 71.0);

	mv2<1,3> mv20 = hep::select<1,3>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv20.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv20.at<3>(), 73.0);

	mv2<2,3> mv21 = hep::select<2,3>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv21.at<2>(), 71.0);
	BOOST_CHECK_EQUAL(mv21.at<3>(), 73.0);

	mv2<1,2,3> mv22 = hep::select<1,2,3>(std::get<5>(mvs));

	BOOST_CHECK_EQUAL(mv22.at<1>(), 67.0);
	BOOST_CHECK_EQUAL(mv22.at<2>(), 71.0);
	BOOST_CHECK_EQUAL(mv22.at<3>(), 73.0);

	mv2<0> mv23 = hep::select<0>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv23.at<0>(), 97.0);

	mv2<1> mv24 = hep::select<1>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv24.at<1>(), 101.0);

	mv2<2> mv25 = hep::select<2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv25.at<2>(), 103.0);

	mv2<3> mv26 = hep::select<3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv26.at<3>(), 107.0);

	mv2<0,1> mv27 = hep::select<0,1>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv27.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv27.at<1>(), 101.0);

	mv2<0,2> mv28 = hep::select<0,2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv28.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv28.at<2>(), 103.0);

	mv2<0,3> mv29 = hep::select<0,3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv29.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv29.at<3>(), 107.0);

	mv2<1,2> mv30 = hep::select<1,2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv30.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv30.at<2>(), 103.0);

	mv2<1,3> mv31 = hep::select<1,3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv31.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv31.at<3>(), 107.0);

	mv2<2,3> mv32 = hep::select<2,3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv32.at<2>(), 103.0);
	BOOST_CHECK_EQUAL(mv32.at<3>(), 107.0);

	mv2<0,1,2> mv33 = hep::select<0,1,2>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv33.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv33.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv33.at<2>(), 103.0);

	mv2<1,2,3> mv34 = hep::select<1,2,3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv34.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv34.at<2>(), 103.0);
	BOOST_CHECK_EQUAL(mv34.at<3>(), 107.0);

	mv2<0,1,2,3> mv35 = hep::select<0,1,2,3>(std::get<6>(mvs));

	BOOST_CHECK_EQUAL(mv35.at<0>(), 97.0);
	BOOST_CHECK_EQUAL(mv35.at<1>(), 101.0);
	BOOST_CHECK_EQUAL(mv35.at<2>(), 103.0);
	BOOST_CHECK_EQUAL(mv35.at<3>(), 107.0);
}
