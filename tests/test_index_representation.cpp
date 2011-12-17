#include <hep/utils/index_representation.hpp>

#include <boost/test/unit_test.hpp>

#include <cstddef>

BOOST_AUTO_TEST_CASE(index_representation_for_g2_subalgebras)
{
	constexpr std::size_t n = 2;

	// 1 = scalar
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1, n), 0);

	// 2 = vector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2, n), 1);

	// 4 = bivector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4, n), 0);

	// 1 + 2 = scalar, vector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2, n), 2);

	// 1 + 4 = scalar, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4, n), 1);

	// 2 + 4 = vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4, n), 2);

	// 1 + 2 + 4 = scalar, vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 2 + 4, n), 3);
}

BOOST_AUTO_TEST_CASE(index_representation_for_g3_subalgebras)
{
	constexpr std::size_t n = 3;

	// 1 = scalar
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1, n), 0);

	// 2 = vector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2, n), 2);

	// 4 = bivector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4, n), 2);

	// 8 = trivector
	BOOST_CHECK_EQUAL(hep::index_representation(7, 8, n), 0);

	// 1 + 2 = scalar, vector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2, n), 3);

	// 1 + 4 = scalar, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 4, n), 3);

	// 1 + 8 = scalar, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 8, n), 1);

	// 2 + 4 = vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 2 + 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 2 + 4, n), 5);

	// 2 + 8 = vector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 2 + 8, n), 3);

	// 4 + 8 = bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 4 + 8, n), 3);

	// 1 + 2 + 4 = scalar, vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 2 + 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 2 + 4, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 2 + 4, n), 6);

	// 1 + 2 + 8 = scalar, vector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 2 + 8, n), 4);

	// 1 + 4 + 8 = scalar, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 4 + 8, n), 4);

	// 2 + 4 + 8 = vector, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 2 + 4 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 2 + 4 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 2 + 4 + 8, n), 6);

	// 1 + 2 + 4 + 8 = scalar, vector, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 2 + 4 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 2 + 4 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 2 + 4 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 2 + 4 + 8, n), 7);
}

BOOST_AUTO_TEST_CASE(index_representation_for_g4_subalgebras)
{
	constexpr std::size_t n = 4;

	// 1 = scalar
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1, n), 0);

	// 2 = vector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2, n), 3);

	// 4 = bivector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 4, n), 5);

	// 8 = trivector
	BOOST_CHECK_EQUAL(hep::index_representation(7, 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 8, n), 3);

	// 16 = quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(15, 16, n), 0);

	// 1 + 2 = scalar, vector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 1 + 2, n), 4);

	// 1 + 4 = scalar, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 1 + 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 1 + 4, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 1 + 4, n), 6);

	// 1 + 8 = scalar, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 1 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 1 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 1 + 8, n), 4);

	// 1 + 16 = scalar, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 1 + 16, n), 1);

	// 2 + 4 = vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 2 + 4, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 2 + 4, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 2 + 4, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 2 + 4, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 2 + 4, n), 9);

	// 2 + 8 = vector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 2 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 2 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 2 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 2 + 8, n), 7);

	// 2 + 16 = vector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 2 + 16, n), 4);

	// 4 + 8 = bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 4 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 4 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 4 + 8, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 4 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 4 + 8, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 4 + 8, n), 9);

	// 4 + 16 = bivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 4 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 4 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 4 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 4 + 16, n), 6);

	// 8 + 16 = trivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(7, 8 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 8 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 8 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 8 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 8 + 16, n), 4);

	// 1 + 2 + 4 = scalar, vector, bivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 4, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 4, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 4, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 2 + 4, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 4, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 2 + 4, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 2 + 4, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 1 + 2 + 4, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 1 + 2 + 4, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 1 + 2 + 4, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 1 + 2 + 4, n), 10);

	// 1 + 2 + 8 = scalar, vector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 2 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 1 + 2 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 1 + 2 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 1 + 2 + 8, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 1 + 2 + 8, n), 8);

	// 1 + 2 + 16 = scalar, vector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 1 + 2 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 1 + 2 + 16, n), 5);

	// 1 + 4 + 8 = scalar, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 4 + 8, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 1 + 4 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 1 + 4 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 1 + 4 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 1 + 4 + 8, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 1 + 4 + 8, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 1 + 4 + 8, n), 10);

	// 1 + 4 + 16 = scalar, bivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 4 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 4 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 4 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 4 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 1 + 4 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 1 + 4 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 1 + 4 + 16, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 1 + 4 + 16, n), 7);

	// 1 + 8 + 16 = scalar, trivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 8 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 8 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 1 + 8 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 1 + 8 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 1 + 8 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 1 + 8 + 16, n), 5);

	// 2 + 4 + 8 = vector, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4 + 8, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4 + 8, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 4 + 8, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4 + 8, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 2 + 4 + 8, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 2 + 4 + 8, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 2 + 4 + 8, n), 10);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 4 + 8, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 2 + 4 + 8, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 2 + 4 + 8, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 2 + 4 + 8, n), 11);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 2 + 4 + 8, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 2 + 4 + 8, n), 12);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 2 + 4 + 8, n), 13);

	// 2 + 4 + 16 = vector, bivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 4 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 4 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 2 + 4 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 4 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 2 + 4 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 2 + 4 + 16, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 4 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 2 + 4 + 16, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 2 + 4 + 16, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 2 + 4 + 16, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 2 + 4 + 16, n), 10);

	// 2 + 8 + 16 = vector, trivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(1, 2 + 8 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 2 + 8 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 2 + 8 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 2 + 8 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 2 + 8 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 2 + 8 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 2 + 8 + 16, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 2 + 8 + 16, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 2 + 8 + 16, n), 8);

	// 4 + 8 + 16 = bivector, trivector, quadvector
	BOOST_CHECK_EQUAL(hep::index_representation(3, 4 + 8 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 4 + 8 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 4 + 8 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 4 + 8 + 16, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 4 + 8 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 4 + 8 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 4 + 8 + 16, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 4 + 8 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 4 + 8 + 16, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 4 + 8 + 16, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 4 + 8 + 16, n), 10);

	// 1 + 2 + 4 + 8 = scalar, vector, bivector, trivector
	BOOST_CHECK_EQUAL(hep::index_representation(0, 1 + 2 + 4 + 8 + 16, n), 0);
	BOOST_CHECK_EQUAL(hep::index_representation(1, 1 + 2 + 4 + 8 + 16, n), 1);
	BOOST_CHECK_EQUAL(hep::index_representation(2, 1 + 2 + 4 + 8 + 16, n), 2);
	BOOST_CHECK_EQUAL(hep::index_representation(3, 1 + 2 + 4 + 8 + 16, n), 5);
	BOOST_CHECK_EQUAL(hep::index_representation(4, 1 + 2 + 4 + 8 + 16, n), 3);
	BOOST_CHECK_EQUAL(hep::index_representation(5, 1 + 2 + 4 + 8 + 16, n), 6);
	BOOST_CHECK_EQUAL(hep::index_representation(6, 1 + 2 + 4 + 8 + 16, n), 7);
	BOOST_CHECK_EQUAL(hep::index_representation(7, 1 + 2 + 4 + 8 + 16, n), 11);
	BOOST_CHECK_EQUAL(hep::index_representation(8, 1 + 2 + 4 + 8 + 16, n), 4);
	BOOST_CHECK_EQUAL(hep::index_representation(9, 1 + 2 + 4 + 8 + 16, n), 8);
	BOOST_CHECK_EQUAL(hep::index_representation(10, 1 + 2 + 4 + 8 + 16, n), 9);
	BOOST_CHECK_EQUAL(hep::index_representation(11, 1 + 2 + 4 + 8 + 16, n), 12);
	BOOST_CHECK_EQUAL(hep::index_representation(12, 1 + 2 + 4 + 8 + 16, n), 10);
	BOOST_CHECK_EQUAL(hep::index_representation(13, 1 + 2 + 4 + 8 + 16, n), 13);
	BOOST_CHECK_EQUAL(hep::index_representation(14, 1 + 2 + 4 + 8 + 16, n), 14);
	BOOST_CHECK_EQUAL(hep::index_representation(15, 1 + 2 + 4 + 8 + 16, n), 15);
}
