#include <hep/ga.hpp>

#include <boost/test/unit_test.hpp>

typedef hep::multi_vector<float, 2, 0> mv2;
typedef hep::multi_vector<float, 3, 0> mv3;
typedef hep::multi_vector<float, 1, 3> mv4;

BOOST_AUTO_TEST_CASE(component_access_for_mv2)
{
	mv2 a = { 10.0f,  3.0f,  7.0f, 49.0f };

	BOOST_CHECK_EQUAL(a[0], 10.0f);
	BOOST_CHECK_EQUAL(a[1],  3.0f);
	BOOST_CHECK_EQUAL(a[2],  7.0f);
	BOOST_CHECK_EQUAL(a[3], 49.0f);
}

BOOST_AUTO_TEST_CASE(component_access_for_mv3)
{
	mv3 b = { 18.0f, 21.0f, 99.0f, 56.0f, 15.0f, 33.0f, 12.0f, 77.0f };

	BOOST_CHECK_EQUAL(b[0], 18.0f);
	BOOST_CHECK_EQUAL(b[1], 21.0f);
	BOOST_CHECK_EQUAL(b[2], 99.0f);
	BOOST_CHECK_EQUAL(b[3], 56.0f);
	BOOST_CHECK_EQUAL(b[4], 15.0f);
	BOOST_CHECK_EQUAL(b[5], 33.0f);
	BOOST_CHECK_EQUAL(b[6], 12.0f);
	BOOST_CHECK_EQUAL(b[7], 77.0f);
}

BOOST_AUTO_TEST_CASE(component_access_mv4)
{
	mv4 c = { 16.0f, 23.0f, 69.0f, 98.0f,  6.0f, 34.0f, 47.0f, 51.0f,
	          78.0f, 86.0f, 81.0f, 75.0f,  4.0f, 65.0f, 53.0f, 13.0f };

	BOOST_CHECK_EQUAL(c[0],  16.0f);
	BOOST_CHECK_EQUAL(c[1],  23.0f);
	BOOST_CHECK_EQUAL(c[2],  69.0f);
	BOOST_CHECK_EQUAL(c[3],  98.0f);
	BOOST_CHECK_EQUAL(c[4],   6.0f);
	BOOST_CHECK_EQUAL(c[5],  34.0f);
	BOOST_CHECK_EQUAL(c[6],  47.0f);
	BOOST_CHECK_EQUAL(c[7],  51.0f);
	BOOST_CHECK_EQUAL(c[8],  78.0f);
	BOOST_CHECK_EQUAL(c[9],  86.0f);
	BOOST_CHECK_EQUAL(c[10], 81.0f);
	BOOST_CHECK_EQUAL(c[11], 75.0f);
	BOOST_CHECK_EQUAL(c[12],  4.0f);
	BOOST_CHECK_EQUAL(c[13], 65.0f);
	BOOST_CHECK_EQUAL(c[14], 53.0f);
	BOOST_CHECK_EQUAL(c[15], 13.0f);

}

BOOST_AUTO_TEST_CASE(geometric_product_of_g2_even_grade_elements)
{
	mv2 a = { 1.0f, 0.0f, 0.0f,  4.0f };
	mv2 b = { 1.0f, 0.0f, 0.0f, -4.0f };

	mv2 d = a * b;
	mv2 e = b * a;

	BOOST_CHECK_EQUAL(d[0], 17.0f);
	BOOST_CHECK_EQUAL(d[1],  0.0f);
	BOOST_CHECK_EQUAL(d[2],  0.0f);
	BOOST_CHECK_EQUAL(d[3],  0.0f);

	BOOST_CHECK_EQUAL(e[0], 17.0f);
	BOOST_CHECK_EQUAL(e[1],  0.0f);
	BOOST_CHECK_EQUAL(e[2],  0.0f);
	BOOST_CHECK_EQUAL(e[3],  0.0f);
}

BOOST_AUTO_TEST_CASE(geometric_product_of_g2_odd_grade_elements)
{
	mv2 c = { 0.0f, 2.0f, 3.0f,  0.0f };
	mv2 f = c * c;

	BOOST_CHECK_EQUAL(f[0], 13.0f);
	BOOST_CHECK_EQUAL(f[1],  0.0f);
	BOOST_CHECK_EQUAL(f[2],  0.0f);
	BOOST_CHECK_EQUAL(f[3],  0.0f);
}

BOOST_AUTO_TEST_CASE(geometric_product_of_g3_even_grade_elements)
{
	mv3 g = { 2.0f, 0.0f, 0.0f,  3.0f, 0.0f,  5.0f,  7.0f, 0.0f };
	mv3 h = { 2.0f, 0.0f, 0.0f, -3.0f, 0.0f, -5.0f, -7.0f, 0.0f };

	mv3 i = g * h;

	BOOST_CHECK_EQUAL(i[0], 87.0f);
	BOOST_CHECK_EQUAL(i[1],  0.0f);
	BOOST_CHECK_EQUAL(i[2],  0.0f);
	BOOST_CHECK_EQUAL(i[3],  0.0f);
	BOOST_CHECK_EQUAL(i[4],  0.0f);
	BOOST_CHECK_EQUAL(i[5],  0.0f);
	BOOST_CHECK_EQUAL(i[6],  0.0f);
	BOOST_CHECK_EQUAL(i[7],  0.0f);
}
