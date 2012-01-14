#include <hep/utils/sign_table.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sign_table_for_g2)
{
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(0, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(0, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(0, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(0, 3)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(1, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(1, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(1, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(1, 3)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(2, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(2, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(2, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(2, 3)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(3, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(3, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(3, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 2, 0>(3, 3)), -1.0);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g3)
{
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(0, 7)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(1, 7)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 3)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(2, 7)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 3)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(3, 7)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(4, 7)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(5, 7)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 3)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(6, 7)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 3)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 3, 0>(7, 7)), -1.0);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g13)
{
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(0, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(1, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(2, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(3, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(4, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(5, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(6, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 8)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 11)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(7, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(8, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(9, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(10, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 4)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 7)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 12)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(11, 15)), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(12, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 1)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 2)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 5)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 6)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 9)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 10)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 13)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 14)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(13, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(14, 15)), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 0)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 1)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 2)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 3)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 4)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 5)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 6)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 7)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 8)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 9)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 10)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 11)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 12)), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 13)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 14)), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<double, 1, 3>(15, 15)), -1.0);
}
