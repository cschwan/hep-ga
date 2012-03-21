#include <hep/ga.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sign_table_for_g2)
{
	typedef hep::algebra<double, 2, 0> euclidean2d;

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 0, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 0, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 0, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 0, 3>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 1, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 1, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 1, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 1, 3>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 2, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 2, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 2, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 2, 3>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 3, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 3, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 3, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean2d, 3, 3>()), -1.0);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g3)
{
	typedef hep::algebra<double, 3, 0> euclidean3d;

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 0, 7>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 1, 7>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 3>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 2, 7>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 3>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 3, 7>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 4, 7>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 5, 7>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 3>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 6, 7>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 3>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<euclidean3d, 7, 7>()), -1.0);
}

BOOST_AUTO_TEST_CASE(sign_table_for_g4)
{
	typedef hep::algebra<double, 1, 3> minkowski4d;

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 0, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 1, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 2, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 3, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 4, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 5, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 6, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 8>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 11>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 7, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 8, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 9, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 10, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 4>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 7>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 12>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 11, 15>()), 1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 12, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 1>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 2>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 5>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 6>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 9>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 10>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 13>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 14>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 13, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 14, 15>()), -1.0);

	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 0>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 1>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 2>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 3>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 4>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 5>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 6>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 7>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 8>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 9>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 10>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 11>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 12>()), -1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 13>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 14>()), 1.0);
	BOOST_CHECK_EQUAL((hep::sign_table<minkowski4d, 15, 15>()), -1.0);
}
