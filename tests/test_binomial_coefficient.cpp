#include <hep/utils/binomial_coefficient.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(binomial_coefficient)
{
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(0, 0), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(1, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(1, 1), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(2, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(2, 1), 2);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(2, 2), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(3, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(3, 1), 3);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(3, 2), 3);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(3, 3), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(4, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(4, 1), 4);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(4, 2), 6);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(4, 3), 4);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(4, 4), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 1), 5);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 2), 10);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 3), 10);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 4), 5);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(5, 5), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 1), 6);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 2), 15);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 3), 20);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 4), 15);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 5), 6);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(6, 6), 1);

	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 0), 1);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 1), 7);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 2), 21);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 3), 35);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 4), 35);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 5), 21);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 6), 7);
	BOOST_CHECK_EQUAL(hep::binomial_coefficient(7, 7), 1);
}
