#include <tuple>
#include <boost/test/unit_test.hpp>

#include <hep/ga_types.hpp>

BOOST_AUTO_TEST_CASE(index_access)
{
	auto mvs = std::make_tuple(
		mv2<0>      { 2.0 },
		mv2<1,2>    { 3.0, 5.0 },
		mv2<3>      { 7.0 },
		mv2<0,1,2>  { 11.0, 13.0, 17.0 },
		mv2<0,3>    { 19.0, 23.0 },
		mv2<1,2,3>  { 29.0, 31.0, 37.0 },
		mv2<0,1,2,3>{ 41.0, 43.0, 47.0, 53.0 }
	);

	// scalar
	BOOST_CHECK_EQUAL(std::get<0>(mvs).at<0>(), 2.0);

	// vector
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<1>(), 3.0);
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<2>(), 5.0);

	// bivector
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<3>(), 7.0);

	// scalar + vector
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<0>(), 11.0);
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<1>(), 13.0);
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<2>(), 17.0);

	// scalar + bivector
	BOOST_CHECK_EQUAL(std::get<4>(mvs).at<0>(), 19.0);
	BOOST_CHECK_EQUAL(std::get<4>(mvs).at<3>(), 23.0);

	// vector + bivector
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<1>(), 29.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<2>(), 31.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<3>(), 37.0);

	// scalar + vector + bivector
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<0>(), 41.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<1>(), 43.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<2>(), 47.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<3>(), 53.0);
}
