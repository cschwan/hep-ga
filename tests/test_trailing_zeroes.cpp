#include <hep/utils/trailing_zeroes.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(trailing_zeroes)
{
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(1), 0);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(2), 1);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(4), 2);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(8), 3);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(16), 4);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(32), 5);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(64), 6);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(128), 7);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(256), 8);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(512), 9);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(1024), 10);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(2048), 11);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(4096), 12);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(8192), 13);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(16384), 14);
	BOOST_CHECK_EQUAL(hep::trailing_zeroes(32768), 15);
}
