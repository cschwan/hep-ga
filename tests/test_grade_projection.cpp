#include <hep/grade.hpp>

#include <boost/test/unit_test.hpp>

// multi vector with metric (2,0) and general grade list
template <std::size_t L>
using mv2 = hep::multi_vector<float, 2, 0, L>;

BOOST_AUTO_TEST_CASE(grade_projection)
{
	mv2<7> scalar_vector_bivector{ 2.0f, 3.0f, 5.0f, 7.0f };

	mv2<1> scalar = hep::grade<1>(scalar_vector_bivector);
	mv2<2> vector = hep::grade<2>(scalar_vector_bivector);
	mv2<4> bivector = hep::grade<4>(scalar_vector_bivector);

	BOOST_CHECK_EQUAL(scalar[0], 2.0f);
	BOOST_CHECK_EQUAL(vector[0], 3.0f);
	BOOST_CHECK_EQUAL(vector[1], 5.0f);
	BOOST_CHECK_EQUAL(bivector[0], 7.0f);
}
