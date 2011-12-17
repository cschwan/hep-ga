#include <hep/utils/num_of_components.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(num_of_components_for_g2_subalgebras)
{
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 1), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 2), 2);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 4), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 1 + 2), 3);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 1 + 4), 2);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 2 + 4), 3);
	BOOST_CHECK_EQUAL(hep::num_of_components(2, 1 + 2 + 4), 4);
}

BOOST_AUTO_TEST_CASE(num_of_components_for_g3_subalgebras)
{
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 2), 3);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 4), 3);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 8), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 2), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 4), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 8), 2);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 2 + 4), 6);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 2 + 8), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 4 + 8), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 2 + 4), 7);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 2 + 8), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 4 + 8), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 2 + 4 + 8), 7);
	BOOST_CHECK_EQUAL(hep::num_of_components(3, 1 + 2 + 4 + 8), 8);
}

BOOST_AUTO_TEST_CASE(num_of_components_for_g4_subalgebras)
{
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 4), 6);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 8), 4);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 16), 1);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 4), 7);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 8), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 16), 2);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 4), 10);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 8), 8);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 16), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 4 + 8), 10);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 4 + 16), 7);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 8 + 16), 5);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 4), 11);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 8), 9);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 16), 6);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 4 + 8), 11);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 4 + 16), 8);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 8 + 16), 6);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 4 + 8), 14);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 4 + 16), 11);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 8 + 16), 9);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 4 + 8 + 16), 11);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 4 + 8), 15);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 4 + 16), 12);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 8 + 16), 10);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 4 + 8 + 16), 12);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 2 + 4 + 8 + 16), 15);
	BOOST_CHECK_EQUAL(hep::num_of_components(4, 1 + 2 + 4 + 8 + 16), 16);
}
