#include <boost/test/unit_test.hpp>
#include <hep/utils/sign_table.hpp>
#include <hep/algebra.hpp>

BOOST_AUTO_TEST_CASE(sign_table_for_g2)
{
	typedef hep::algebra<double, 2, 0> g2;

	BOOST_CHECK_EQUAL((hep::sign_table<g2, 0, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 0, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 0, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 0, 3>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g2, 1, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 1, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 1, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 1, 3>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g2, 2, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 2, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 2, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 2, 3>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g2, 3, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 3, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 3, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g2, 3, 3>()), -1);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g3)
{
	typedef hep::algebra<double, 3, 0> g3;

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 0, 7>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 1, 7>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 3>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 2, 7>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 3>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 3, 7>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 4, 7>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 5, 7>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 3>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 6, 7>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 3>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g3, 7, 7>()), -1);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g4)
{
	typedef hep::algebra<double, 1, 3> g4;

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 0, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 1, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 2, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 3, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 4, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 5, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 6, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 8>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 11>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 7, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 8, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 9, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 10, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 4>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 7>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 12>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 11, 15>()), +1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 12, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 1>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 2>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 5>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 6>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 9>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 10>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 13>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 14>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 13, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 14, 15>()), -1);

	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 0>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 1>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 2>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 3>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 4>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 5>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 6>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 7>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 8>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 9>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 10>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 11>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 12>()), -1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 13>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 14>()), +1);
	BOOST_CHECK_EQUAL((hep::sign_table<g4, 15, 15>()), -1);
}
