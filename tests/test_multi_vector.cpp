#include <hep/multi_vector.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(component_access_for_g2)
{
	// scalar
	hep::multi_vector<float, 2, 0> a = { 2.0f };

	BOOST_CHECK_EQUAL(a[0], 2.0f);
	BOOST_CHECK_EQUAL(a[1], 0.0f);
	BOOST_CHECK_EQUAL(a[2], 0.0f);
	BOOST_CHECK_EQUAL(a[3], 0.0f);

	// vector
	hep::multi_vector<float, 2, 0> b = { 0.0f, 3.0f, 5.0f };

	BOOST_CHECK_EQUAL(b[0], 0.0f);
	BOOST_CHECK_EQUAL(b[1], 3.0f);
	BOOST_CHECK_EQUAL(b[2], 5.0f);
	BOOST_CHECK_EQUAL(b[3], 0.0f);

	// bivector
	hep::multi_vector<float, 2, 0> c = { 0.0f, 0.0f, 0.0f, 7.0f };

	BOOST_CHECK_EQUAL(c[0], 0.0f);
	BOOST_CHECK_EQUAL(c[1], 0.0f);
	BOOST_CHECK_EQUAL(c[2], 0.0f);
	BOOST_CHECK_EQUAL(c[3], 7.0f);

	// scalar + vector
	hep::multi_vector<float, 2, 0> d = { 11.0f, 13.0f, 17.0f };

	BOOST_CHECK_EQUAL(d[0], 11.0f);
	BOOST_CHECK_EQUAL(d[1], 13.0f);
	BOOST_CHECK_EQUAL(d[2], 17.0f);
	BOOST_CHECK_EQUAL(d[3], 0.0f);
	
	// scalar + bivector
	hep::multi_vector<float, 2, 0> e = { 19.0f, 0.0f, 0.0f, 23.0f };

	BOOST_CHECK_EQUAL(e[0], 19.0f);
	BOOST_CHECK_EQUAL(e[1], 0.0f);
	BOOST_CHECK_EQUAL(e[2], 0.0f);
	BOOST_CHECK_EQUAL(e[3], 23.0f);

	// vector + bivector
	hep::multi_vector<float, 2, 0> f = { 0.0f, 29.0f, 31.0f, 37.0f };

	BOOST_CHECK_EQUAL(f[0], 0.0f);
	BOOST_CHECK_EQUAL(f[1], 29.0f);
	BOOST_CHECK_EQUAL(f[2], 31.0f);
	BOOST_CHECK_EQUAL(f[3], 37.0f);

	// scalar + vector + bivector
	hep::multi_vector<float, 2, 0> g = { 41.0f, 43.0f, 47.0f, 53.0f };

	BOOST_CHECK_EQUAL(g[0], 41.0f);
	BOOST_CHECK_EQUAL(g[1], 43.0f);
	BOOST_CHECK_EQUAL(g[2], 47.0f);
	BOOST_CHECK_EQUAL(g[3], 53.0f);
}

BOOST_AUTO_TEST_CASE(component_access_for_g3)
{
	// scalar
	hep::multi_vector<float, 3, 0> a = { 2.0f };

	BOOST_CHECK_EQUAL(a[0], 2.0f);
	BOOST_CHECK_EQUAL(a[1], 0.0f);
	BOOST_CHECK_EQUAL(a[2], 0.0f);
	BOOST_CHECK_EQUAL(a[3], 0.0f);
	BOOST_CHECK_EQUAL(a[4], 0.0f);
	BOOST_CHECK_EQUAL(a[5], 0.0f);
	BOOST_CHECK_EQUAL(a[6], 0.0f);
	BOOST_CHECK_EQUAL(a[7], 0.0f);

	// vector
	hep::multi_vector<float, 3, 0> b = { 0.0f, 3.0f, 5.0f, 0.0f,
	                                     7.0f };

	BOOST_CHECK_EQUAL(b[0], 0.0f);
	BOOST_CHECK_EQUAL(b[1], 3.0f);
	BOOST_CHECK_EQUAL(b[2], 5.0f);
	BOOST_CHECK_EQUAL(b[3], 0.0f);
	BOOST_CHECK_EQUAL(b[4], 7.0f);
	BOOST_CHECK_EQUAL(b[5], 0.0f);
	BOOST_CHECK_EQUAL(b[6], 0.0f);
	BOOST_CHECK_EQUAL(b[7], 0.0f);

	// bivector
	hep::multi_vector<float, 3, 0> c = { 0.0f, 0.0f, 0.0f, 11.0f,
	                                     0.0f, 13.0f, 17.0f };

	BOOST_CHECK_EQUAL(c[0], 0.0f);
	BOOST_CHECK_EQUAL(c[1], 0.0f);
	BOOST_CHECK_EQUAL(c[2], 0.0f);
	BOOST_CHECK_EQUAL(c[3], 11.0f);
	BOOST_CHECK_EQUAL(c[4], 0.0f);
	BOOST_CHECK_EQUAL(c[5], 13.0f);
	BOOST_CHECK_EQUAL(c[6], 17.0f);
	BOOST_CHECK_EQUAL(c[7], 0.0f);

	// trivector
	hep::multi_vector<float, 3, 0> d = { 0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 19.0f };

	BOOST_CHECK_EQUAL(d[0], 0.0f);
	BOOST_CHECK_EQUAL(d[1], 0.0f);
	BOOST_CHECK_EQUAL(d[2], 0.0f);
	BOOST_CHECK_EQUAL(d[3], 0.0f);
	BOOST_CHECK_EQUAL(d[4], 0.0f);
	BOOST_CHECK_EQUAL(d[5], 0.0f);
	BOOST_CHECK_EQUAL(d[6], 0.0f);
	BOOST_CHECK_EQUAL(d[7], 19.0f);

	// scalar + vector
	hep::multi_vector<float, 3, 0> e = { 23.0f, 29.0f, 31.0f, 0.0f,
	                                     37.0f };

	BOOST_CHECK_EQUAL(e[0], 23.0f);
	BOOST_CHECK_EQUAL(e[1], 29.0f);
	BOOST_CHECK_EQUAL(e[2], 31.0f);
	BOOST_CHECK_EQUAL(e[3], 0.0f);
	BOOST_CHECK_EQUAL(e[4], 37.0f);
	BOOST_CHECK_EQUAL(e[5], 0.0f);
	BOOST_CHECK_EQUAL(e[6], 0.0f);
	BOOST_CHECK_EQUAL(e[7], 0.0f);

	// scalar + bivector
	hep::multi_vector<float, 3, 0> f = { 41.0f, 0.0f, 0.0f, 43.0f,
	                                     0.0f, 47.0f, 53.0f, 0.0f };

	BOOST_CHECK_EQUAL(f[0], 41.0f);
	BOOST_CHECK_EQUAL(f[1], 0.0f);
	BOOST_CHECK_EQUAL(f[2], 0.0f);
	BOOST_CHECK_EQUAL(f[3], 43.0f);
	BOOST_CHECK_EQUAL(f[4], 0.0f);
	BOOST_CHECK_EQUAL(f[5], 47.0f);
	BOOST_CHECK_EQUAL(f[6], 53.0f);
	BOOST_CHECK_EQUAL(f[7], 0.0f);

	// scalar + trivector
	hep::multi_vector<float, 3, 0> g = { 59.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 61.0f };

	BOOST_CHECK_EQUAL(g[0], 59.0f);
	BOOST_CHECK_EQUAL(g[1], 0.0f);
	BOOST_CHECK_EQUAL(g[2], 0.0f);
	BOOST_CHECK_EQUAL(g[3], 0.0f);
	BOOST_CHECK_EQUAL(g[4], 0.0f);
	BOOST_CHECK_EQUAL(g[5], 0.0f);
	BOOST_CHECK_EQUAL(g[6], 0.0f);
	BOOST_CHECK_EQUAL(g[7], 61.0f);

	// vector + bivector
	hep::multi_vector<float, 3, 0> h = { 0.0f, 67.0f, 71.0f, 73.0f,
	                                     79.0f, 83.0f, 89.0f, 0.0f };

	BOOST_CHECK_EQUAL(h[0], 0.0f);
	BOOST_CHECK_EQUAL(h[1], 67.0f);
	BOOST_CHECK_EQUAL(h[2], 71.0f);
	BOOST_CHECK_EQUAL(h[3], 73.0f);
	BOOST_CHECK_EQUAL(h[4], 79.0f);
	BOOST_CHECK_EQUAL(h[5], 83.0f);
	BOOST_CHECK_EQUAL(h[6], 89.0f);
	BOOST_CHECK_EQUAL(h[7], 0.0f);

	// vector + trivector
	hep::multi_vector<float, 3, 0> i = { 0.0f, 97.0f, 101.0f, 0.0f,
	                                     103.0f, 0.0f, 0.0f, 107.0f };

	BOOST_CHECK_EQUAL(i[0], 0.0f);
	BOOST_CHECK_EQUAL(i[1], 97.0f);
	BOOST_CHECK_EQUAL(i[2], 101.0f);
	BOOST_CHECK_EQUAL(i[3], 0.0f);
	BOOST_CHECK_EQUAL(i[4], 103.0f);
	BOOST_CHECK_EQUAL(i[5], 0.0f);
	BOOST_CHECK_EQUAL(i[6], 0.0f);
	BOOST_CHECK_EQUAL(i[7], 107.0f);

	// bivector + trivector
	hep::multi_vector<float, 3, 0> j = { 0.0f, 0.0f, 0.0f, 109.0f,
	                                     0.0f, 113.0f, 127.0f, 131.0f };

	BOOST_CHECK_EQUAL(j[0], 0.0f);
	BOOST_CHECK_EQUAL(j[1], 0.0f);
	BOOST_CHECK_EQUAL(j[2], 0.0f);
	BOOST_CHECK_EQUAL(j[3], 109.0f);
	BOOST_CHECK_EQUAL(j[4], 0.0f);
	BOOST_CHECK_EQUAL(j[5], 113.0f);
	BOOST_CHECK_EQUAL(j[6], 127.0f);
	BOOST_CHECK_EQUAL(j[7], 131.0f);

	// scalar + vector + bivector
	hep::multi_vector<float, 3, 0> k = { 137.0f, 139.0f, 149.0f, 151.0f,
	                                     157.0f, 163.0f, 167.0f, 0.0f };

	BOOST_CHECK_EQUAL(k[0], 137.0f);
	BOOST_CHECK_EQUAL(k[1], 139.0f);
	BOOST_CHECK_EQUAL(k[2], 149.0f);
	BOOST_CHECK_EQUAL(k[3], 151.0f);
	BOOST_CHECK_EQUAL(k[4], 157.0f);
	BOOST_CHECK_EQUAL(k[5], 163.0f);
	BOOST_CHECK_EQUAL(k[6], 167.0f);
	BOOST_CHECK_EQUAL(k[7], 0.0f);

	// scalar + vector + trivector
	hep::multi_vector<float, 3, 0> l = { 173.0f, 179.0f, 181.0f, 0.0f,
	                                     191.0f, 0.0f, 0.0f, 193.0f };

	BOOST_CHECK_EQUAL(l[0], 173.0f);
	BOOST_CHECK_EQUAL(l[1], 179.0f);
	BOOST_CHECK_EQUAL(l[2], 181.0f);
	BOOST_CHECK_EQUAL(l[3], 0.0f);
	BOOST_CHECK_EQUAL(l[4], 191.0f);
	BOOST_CHECK_EQUAL(l[5], 0.0f);
	BOOST_CHECK_EQUAL(l[6], 0.0f);
	BOOST_CHECK_EQUAL(l[7], 193.0f);

	// scalar + bivector + trivector
	hep::multi_vector<float, 3, 0> m = { 197.0f, 0.0f, 0.0f, 199.0f,
	                                     0.0f, 211.0f, 223.0f, 227.0f };

	BOOST_CHECK_EQUAL(m[0], 197.0f);
	BOOST_CHECK_EQUAL(m[1], 0.0f);
	BOOST_CHECK_EQUAL(m[2], 0.0f);
	BOOST_CHECK_EQUAL(m[3], 199.0f);
	BOOST_CHECK_EQUAL(m[4], 0.0f);
	BOOST_CHECK_EQUAL(m[5], 211.0f);
	BOOST_CHECK_EQUAL(m[6], 223.0f);
	BOOST_CHECK_EQUAL(m[7], 227.0f);

	// vector + bivector + trivector
	hep::multi_vector<float, 3, 0> n = { 0.0f, 229.0f, 233.0f, 239.0f,
	                                     241.0f, 251.0f, 257.0f, 263.0f };

	BOOST_CHECK_EQUAL(n[0], 0.0f);
	BOOST_CHECK_EQUAL(n[1], 229.0f);
	BOOST_CHECK_EQUAL(n[2], 233.0f);
	BOOST_CHECK_EQUAL(n[3], 239.0f);
	BOOST_CHECK_EQUAL(n[4], 241.0f);
	BOOST_CHECK_EQUAL(n[5], 251.0f);
	BOOST_CHECK_EQUAL(n[6], 257.0f);
	BOOST_CHECK_EQUAL(n[7], 263.0f);

	// scalar + vector + bivector + trivector
	hep::multi_vector<float, 3, 0> o = { 269.0f, 271.0f, 277.0f, 281.0f,
	                                     283.0f, 293.0f, 307.0f, 311.0f };

	BOOST_CHECK_EQUAL(o[0], 269.0f);
	BOOST_CHECK_EQUAL(o[1], 271.0f);
	BOOST_CHECK_EQUAL(o[2], 277.0f);
	BOOST_CHECK_EQUAL(o[3], 281.0f);
	BOOST_CHECK_EQUAL(o[4], 283.0f);
	BOOST_CHECK_EQUAL(o[5], 293.0f);
	BOOST_CHECK_EQUAL(o[6], 307.0f);
	BOOST_CHECK_EQUAL(o[7], 311.0f);
}

BOOST_AUTO_TEST_CASE(component_access_g4)
{
	// scalar
	hep::multi_vector<float, 1, 3> a = { 2.0f };

	BOOST_CHECK_EQUAL(a[0], 2.0f);
	BOOST_CHECK_EQUAL(a[1], 0.0f);
	BOOST_CHECK_EQUAL(a[2], 0.0f);
	BOOST_CHECK_EQUAL(a[3], 0.0f);
	BOOST_CHECK_EQUAL(a[4], 0.0f);
	BOOST_CHECK_EQUAL(a[5], 0.0f);
	BOOST_CHECK_EQUAL(a[6], 0.0f);
	BOOST_CHECK_EQUAL(a[7], 0.0f);
	BOOST_CHECK_EQUAL(a[8], 0.0f);
	BOOST_CHECK_EQUAL(a[9], 0.0f);
	BOOST_CHECK_EQUAL(a[10], 0.0f);
	BOOST_CHECK_EQUAL(a[11], 0.0f);
	BOOST_CHECK_EQUAL(a[12], 0.0f);
	BOOST_CHECK_EQUAL(a[13], 0.0f);
	BOOST_CHECK_EQUAL(a[14], 0.0f);
	BOOST_CHECK_EQUAL(a[15], 0.0f);

	// vector
	hep::multi_vector<float, 1, 3> b = { 0.0f, 3.0f, 5.0f, 0.0f,
		                                 7.0f, 0.0f, 0.0f, 0.0f,
		                                 11.0f };

	BOOST_CHECK_EQUAL(b[0], 0.0f);
	BOOST_CHECK_EQUAL(b[1], 3.0f);
	BOOST_CHECK_EQUAL(b[2], 5.0f);
	BOOST_CHECK_EQUAL(b[3], 0.0f);
	BOOST_CHECK_EQUAL(b[4], 7.0f);
	BOOST_CHECK_EQUAL(b[5], 0.0f);
	BOOST_CHECK_EQUAL(b[6], 0.0f);
	BOOST_CHECK_EQUAL(b[7], 0.0f);
	BOOST_CHECK_EQUAL(b[8], 11.0f);
	BOOST_CHECK_EQUAL(b[9], 0.0f);
	BOOST_CHECK_EQUAL(b[10], 0.0f);
	BOOST_CHECK_EQUAL(b[11], 0.0f);
	BOOST_CHECK_EQUAL(b[12], 0.0f);
	BOOST_CHECK_EQUAL(b[13], 0.0f);
	BOOST_CHECK_EQUAL(b[14], 0.0f);
	BOOST_CHECK_EQUAL(b[15], 0.0f);

	// bivector
	hep::multi_vector<float, 1, 3> c = { 0.0f, 0.0f, 0.0f, 13.0f,
	                                     0.0f, 17.0f, 19.0f, 0.0f,
	                                     0.0f, 23.0f, 29.0f, 0.0f,
	                                     31.0f };

	BOOST_CHECK_EQUAL(c[0], 0.0f);
	BOOST_CHECK_EQUAL(c[1], 0.0f);
	BOOST_CHECK_EQUAL(c[2], 0.0f);
	BOOST_CHECK_EQUAL(c[3], 13.0f);
	BOOST_CHECK_EQUAL(c[4], 0.0f);
	BOOST_CHECK_EQUAL(c[5], 17.0f);
	BOOST_CHECK_EQUAL(c[6], 19.0f);
	BOOST_CHECK_EQUAL(c[7], 0.0f);
	BOOST_CHECK_EQUAL(c[8], 0.0f);
	BOOST_CHECK_EQUAL(c[9], 23.0f);
	BOOST_CHECK_EQUAL(c[10], 29.0f);
	BOOST_CHECK_EQUAL(c[11], 0.0f);
	BOOST_CHECK_EQUAL(c[12], 31.0f);
	BOOST_CHECK_EQUAL(c[13], 0.0f);
	BOOST_CHECK_EQUAL(c[14], 0.0f);
	BOOST_CHECK_EQUAL(c[15], 0.0f);

	// trivector
	hep::multi_vector<float, 1, 3> d = { 0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 37.0f,
	                                     0.0f, 0.0f, 0.0f, 41.0f,
	                                     0.0f, 43.0f, 47.0f };

	BOOST_CHECK_EQUAL(d[0], 0.0f);
	BOOST_CHECK_EQUAL(d[1], 0.0f);
	BOOST_CHECK_EQUAL(d[2], 0.0f);
	BOOST_CHECK_EQUAL(d[3], 0.0f);
	BOOST_CHECK_EQUAL(d[4], 0.0f);
	BOOST_CHECK_EQUAL(d[5], 0.0f);
	BOOST_CHECK_EQUAL(d[6], 0.0f);
	BOOST_CHECK_EQUAL(d[7], 37.0f);
	BOOST_CHECK_EQUAL(d[8], 0.0f);
	BOOST_CHECK_EQUAL(d[9], 0.0f);
	BOOST_CHECK_EQUAL(d[10], 0.0f);
	BOOST_CHECK_EQUAL(d[11], 41.0f);
	BOOST_CHECK_EQUAL(d[12], 0.0f);
	BOOST_CHECK_EQUAL(d[13], 43.0f);
	BOOST_CHECK_EQUAL(d[14], 47.0f);
	BOOST_CHECK_EQUAL(d[15], 0.0f);

	// quadvector
	hep::multi_vector<float, 1, 3> e = { 0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 53.0f };

	BOOST_CHECK_EQUAL(e[0], 0.0f);
	BOOST_CHECK_EQUAL(e[1], 0.0f);
	BOOST_CHECK_EQUAL(e[2], 0.0f);
	BOOST_CHECK_EQUAL(e[3], 0.0f);
	BOOST_CHECK_EQUAL(e[4], 0.0f);
	BOOST_CHECK_EQUAL(e[5], 0.0f);
	BOOST_CHECK_EQUAL(e[6], 0.0f);
	BOOST_CHECK_EQUAL(e[7], 0.0f);
	BOOST_CHECK_EQUAL(e[8], 0.0f);
	BOOST_CHECK_EQUAL(e[9], 0.0f);
	BOOST_CHECK_EQUAL(e[10], 0.0f);
	BOOST_CHECK_EQUAL(e[11], 0.0f);
	BOOST_CHECK_EQUAL(e[12], 0.0f);
	BOOST_CHECK_EQUAL(e[13], 0.0f);
	BOOST_CHECK_EQUAL(e[14], 0.0f);
	BOOST_CHECK_EQUAL(e[15], 53.0f);

	// scalar + vector
	hep::multi_vector<float, 1, 3> f = { 59.0f, 61.0f, 67.0f, 0.0f,
	                                     71.0f, 0.0f, 0.0f, 0.0f,
	                                     73.0f };

	BOOST_CHECK_EQUAL(f[0], 59.0f);
	BOOST_CHECK_EQUAL(f[1], 61.0f);
	BOOST_CHECK_EQUAL(f[2], 67.0f);
	BOOST_CHECK_EQUAL(f[3], 0.0f);
	BOOST_CHECK_EQUAL(f[4], 71.0f);
	BOOST_CHECK_EQUAL(f[5], 0.0f);
	BOOST_CHECK_EQUAL(f[6], 0.0f);
	BOOST_CHECK_EQUAL(f[7], 0.0f);
	BOOST_CHECK_EQUAL(f[8], 73.0f);
	BOOST_CHECK_EQUAL(f[9], 0.0f);
	BOOST_CHECK_EQUAL(f[10], 0.0f);
	BOOST_CHECK_EQUAL(f[11], 0.0f);
	BOOST_CHECK_EQUAL(f[12], 0.0f);
	BOOST_CHECK_EQUAL(f[13], 0.0f);
	BOOST_CHECK_EQUAL(f[14], 0.0f);
	BOOST_CHECK_EQUAL(f[15], 0.0f);

	// scalar + bivector
	hep::multi_vector<float, 1, 3> g = { 79.0f, 0.0f, 0.0f, 83.0f,
	                                     0.0f, 89.0f, 97.0f, 0.0f,
	                                     0.0f, 101.0f, 103.0f, 0.0f,
	                                     107.0f };

	BOOST_CHECK_EQUAL(g[0], 79.0f);
	BOOST_CHECK_EQUAL(g[1], 0.0f);
	BOOST_CHECK_EQUAL(g[2], 0.0f);
	BOOST_CHECK_EQUAL(g[3], 83.0f);
	BOOST_CHECK_EQUAL(g[4], 0.0f);
	BOOST_CHECK_EQUAL(g[5], 89.0f);
	BOOST_CHECK_EQUAL(g[6], 97.0f);
	BOOST_CHECK_EQUAL(g[7], 0.0f);
	BOOST_CHECK_EQUAL(g[8], 0.0f);
	BOOST_CHECK_EQUAL(g[9], 101.0f);
	BOOST_CHECK_EQUAL(g[10], 103.0f);
	BOOST_CHECK_EQUAL(g[11], 0.0f);
	BOOST_CHECK_EQUAL(g[12], 107.0f);
	BOOST_CHECK_EQUAL(g[13], 0.0f);
	BOOST_CHECK_EQUAL(g[14], 0.0f);
	BOOST_CHECK_EQUAL(g[15], 0.0f);

	// scalar + trivector
	hep::multi_vector<float, 1, 3> h = { 109.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 113.0f,
	                                     0.0f, 0.0f, 0.0f, 127.0f,
	                                     0.0f, 131.0f, 137.0f, 0.0f };

	BOOST_CHECK_EQUAL(h[0], 109.0f);
	BOOST_CHECK_EQUAL(h[1], 0.0f);
	BOOST_CHECK_EQUAL(h[2], 0.0f);
	BOOST_CHECK_EQUAL(h[3], 0.0f);
	BOOST_CHECK_EQUAL(h[4], 0.0f);
	BOOST_CHECK_EQUAL(h[5], 0.0f);
	BOOST_CHECK_EQUAL(h[6], 0.0f);
	BOOST_CHECK_EQUAL(h[7], 113.0f);
	BOOST_CHECK_EQUAL(h[8], 0.0f);
	BOOST_CHECK_EQUAL(h[9], 0.0f);
	BOOST_CHECK_EQUAL(h[10], 0.0f);
	BOOST_CHECK_EQUAL(h[11], 127.0f);
	BOOST_CHECK_EQUAL(h[12], 0.0f);
	BOOST_CHECK_EQUAL(h[13], 131.0f);
	BOOST_CHECK_EQUAL(h[14], 137.0f);
	BOOST_CHECK_EQUAL(h[15], 0.0f);

	// scalar + quadvector
	hep::multi_vector<float, 1, 3> i = { 139.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 149.0f };

	BOOST_CHECK_EQUAL(i[0], 139.0f);
	BOOST_CHECK_EQUAL(i[1], 0.0f);
	BOOST_CHECK_EQUAL(i[2], 0.0f);
	BOOST_CHECK_EQUAL(i[3], 0.0f);
	BOOST_CHECK_EQUAL(i[4], 0.0f);
	BOOST_CHECK_EQUAL(i[5], 0.0f);
	BOOST_CHECK_EQUAL(i[6], 0.0f);
	BOOST_CHECK_EQUAL(i[7], 0.0f);
	BOOST_CHECK_EQUAL(i[8], 0.0f);
	BOOST_CHECK_EQUAL(i[9], 0.0f);
	BOOST_CHECK_EQUAL(i[10], 0.0f);
	BOOST_CHECK_EQUAL(i[11], 0.0f);
	BOOST_CHECK_EQUAL(i[12], 0.0f);
	BOOST_CHECK_EQUAL(i[13], 0.0f);
	BOOST_CHECK_EQUAL(i[14], 0.0f);
	BOOST_CHECK_EQUAL(i[15], 149.0f);

	// vector + bivector
	hep::multi_vector<float, 1, 3> j = { 0.0f, 151.0f, 157.0f, 163.0f,
	                                     167.0f, 173.0f, 179.0f, 0.0f,
	                                     181.0f, 191.0f, 193.0f, 0.0f,
	                                     197.0f };

	BOOST_CHECK_EQUAL(j[0], 0.0f);
	BOOST_CHECK_EQUAL(j[1], 151.0f);
	BOOST_CHECK_EQUAL(j[2], 157.0f);
	BOOST_CHECK_EQUAL(j[3], 163.0f);
	BOOST_CHECK_EQUAL(j[4], 167.0f);
	BOOST_CHECK_EQUAL(j[5], 173.0f);
	BOOST_CHECK_EQUAL(j[6], 179.0f);
	BOOST_CHECK_EQUAL(j[7], 0.0f);
	BOOST_CHECK_EQUAL(j[8], 181.0f);
	BOOST_CHECK_EQUAL(j[9], 191.0f);
	BOOST_CHECK_EQUAL(j[10], 193.0f);
	BOOST_CHECK_EQUAL(j[11], 0.0f);
	BOOST_CHECK_EQUAL(j[12], 197.0f);
	BOOST_CHECK_EQUAL(j[13], 0.0f);
	BOOST_CHECK_EQUAL(j[14], 0.0f);
	BOOST_CHECK_EQUAL(j[15], 0.0f);

	// vector + trivector
	hep::multi_vector<float, 1, 3> k = { 0.0f, 199.0f, 211.0f, 0.0f,
	                                     223.0f, 0.0f, 0.0f, 227.0f,
	                                     229.0f, 0.0f, 0.0f, 233.0f,
	                                     0.0f, 239.0f, 241.0f, 0.0f };

	BOOST_CHECK_EQUAL(k[0], 0.0f);
	BOOST_CHECK_EQUAL(k[1], 199.0f);
	BOOST_CHECK_EQUAL(k[2], 211.0f);
	BOOST_CHECK_EQUAL(k[3], 0.0f);
	BOOST_CHECK_EQUAL(k[4], 223.0f);
	BOOST_CHECK_EQUAL(k[5], 0.0f);
	BOOST_CHECK_EQUAL(k[6], 0.0f);
	BOOST_CHECK_EQUAL(k[7], 227.0f);
	BOOST_CHECK_EQUAL(k[8], 229.0f);
	BOOST_CHECK_EQUAL(k[9], 0.0f);
	BOOST_CHECK_EQUAL(k[10], 0.0f);
	BOOST_CHECK_EQUAL(k[11], 233.0f);
	BOOST_CHECK_EQUAL(k[12], 0.0f);
	BOOST_CHECK_EQUAL(k[13], 239.0f);
	BOOST_CHECK_EQUAL(k[14], 241.0f);
	BOOST_CHECK_EQUAL(k[15], 0.0f);

	// vector + quadvector
	hep::multi_vector<float, 1, 3> l = { 0.0f, 251.0f, 257.0f, 0.0f,
	                                     263.0f, 0.0f, 0.0f, 0.0f,
	                                     269.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 271.0f };

	BOOST_CHECK_EQUAL(l[0], 0.0f);
	BOOST_CHECK_EQUAL(l[1], 251.0f);
	BOOST_CHECK_EQUAL(l[2], 257.0f);
	BOOST_CHECK_EQUAL(l[3], 0.0f);
	BOOST_CHECK_EQUAL(l[4], 263.0f);
	BOOST_CHECK_EQUAL(l[5], 0.0f);
	BOOST_CHECK_EQUAL(l[6], 0.0f);
	BOOST_CHECK_EQUAL(l[7], 0.0f);
	BOOST_CHECK_EQUAL(l[8], 269.0f);
	BOOST_CHECK_EQUAL(l[9], 0.0f);
	BOOST_CHECK_EQUAL(l[10], 0.0f);
	BOOST_CHECK_EQUAL(l[11], 0.0f);
	BOOST_CHECK_EQUAL(l[12], 0.0f);
	BOOST_CHECK_EQUAL(l[13], 0.0f);
	BOOST_CHECK_EQUAL(l[14], 0.0f);
	BOOST_CHECK_EQUAL(l[15], 271.0f);

	// bivector + trivector
	hep::multi_vector<float, 1, 3> m = { 0.0f, 0.0f, 0.0f, 277.0f,
	                                     0.0f, 281.0f, 283.0f, 293.0f,
	                                     0.0f, 307.0f, 311.0f, 313.0f,
	                                     317.0f, 331.0f, 337.0f };

	BOOST_CHECK_EQUAL(m[0], 0.0f);
	BOOST_CHECK_EQUAL(m[1], 0.0f);
	BOOST_CHECK_EQUAL(m[2], 0.0f);
	BOOST_CHECK_EQUAL(m[3], 277.0f);
	BOOST_CHECK_EQUAL(m[4], 0.0f);
	BOOST_CHECK_EQUAL(m[5], 281.0f);
	BOOST_CHECK_EQUAL(m[6], 283.0f);
	BOOST_CHECK_EQUAL(m[7], 293.0f);
	BOOST_CHECK_EQUAL(m[8], 0.0f);
	BOOST_CHECK_EQUAL(m[9], 307.0f);
	BOOST_CHECK_EQUAL(m[10], 311.0f);
	BOOST_CHECK_EQUAL(m[11], 313.0f);
	BOOST_CHECK_EQUAL(m[12], 317.0f);
	BOOST_CHECK_EQUAL(m[13], 331.0f);
	BOOST_CHECK_EQUAL(m[14], 337.0f);
	BOOST_CHECK_EQUAL(m[15], 0.0f);

	// bivector + quadvector
	hep::multi_vector<float, 1, 3> n = { 0.0f, 0.0f, 0.0f, 347.0f,
	                                     0.0f, 349.0f, 353.0f, 0.0f,
	                                     0.0f, 359.0f, 367.0f, 0.0f,
	                                     373.0f, 0.0f, 0.0f, 379.0f };

	BOOST_CHECK_EQUAL(n[0], 0.0f);
	BOOST_CHECK_EQUAL(n[1], 0.0f);
	BOOST_CHECK_EQUAL(n[2], 0.0f);
	BOOST_CHECK_EQUAL(n[3], 347.0f);
	BOOST_CHECK_EQUAL(n[4], 0.0f);
	BOOST_CHECK_EQUAL(n[5], 349.0f);
	BOOST_CHECK_EQUAL(n[6], 353.0f);
	BOOST_CHECK_EQUAL(n[7], 0.0f);
	BOOST_CHECK_EQUAL(n[8], 0.0f);
	BOOST_CHECK_EQUAL(n[9], 359.0f);
	BOOST_CHECK_EQUAL(n[10], 367.0f);
	BOOST_CHECK_EQUAL(n[11], 0.0f);
	BOOST_CHECK_EQUAL(n[12], 373.0f);
	BOOST_CHECK_EQUAL(n[13], 0.0f);
	BOOST_CHECK_EQUAL(n[14], 0.0f);
	BOOST_CHECK_EQUAL(n[15], 379.0f);

	// trivector + quadvector
	hep::multi_vector<float, 1, 3> o = { 0.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 383.0f,
	                                     0.0f, 0.0f, 0.0f, 389.0f,
	                                     0.0f, 397.0f, 401.0f, 409.0f };

	BOOST_CHECK_EQUAL(o[0], 0.0f);
	BOOST_CHECK_EQUAL(o[1], 0.0f);
	BOOST_CHECK_EQUAL(o[2], 0.0f);
	BOOST_CHECK_EQUAL(o[3], 0.0f);
	BOOST_CHECK_EQUAL(o[4], 0.0f);
	BOOST_CHECK_EQUAL(o[5], 0.0f);
	BOOST_CHECK_EQUAL(o[6], 0.0f);
	BOOST_CHECK_EQUAL(o[7], 383.0f);
	BOOST_CHECK_EQUAL(o[8], 0.0f);
	BOOST_CHECK_EQUAL(o[9], 0.0f);
	BOOST_CHECK_EQUAL(o[10], 0.0f);
	BOOST_CHECK_EQUAL(o[11], 389.0f);
	BOOST_CHECK_EQUAL(o[12], 0.0f);
	BOOST_CHECK_EQUAL(o[13], 397.0f);
	BOOST_CHECK_EQUAL(o[14], 401.0f);
	BOOST_CHECK_EQUAL(o[15], 409.0f);

	// scalar + vector + bivector
	hep::multi_vector<float, 1, 3> p = { 419.0f, 421.0f, 431.0f, 433.0f,
	                                     439.0f, 443.0f, 449.0f, 0.0f,
	                                     457.0f, 461.0f, 463.0f, 0.0f,
	                                     467.0f };

	BOOST_CHECK_EQUAL(p[0], 419.0f);
	BOOST_CHECK_EQUAL(p[1], 421.0f);
	BOOST_CHECK_EQUAL(p[2], 431.0f);
	BOOST_CHECK_EQUAL(p[3], 433.0f);
	BOOST_CHECK_EQUAL(p[4], 439.0f);
	BOOST_CHECK_EQUAL(p[5], 443.0f);
	BOOST_CHECK_EQUAL(p[6], 449.0f);
	BOOST_CHECK_EQUAL(p[7], 0.0f);
	BOOST_CHECK_EQUAL(p[8], 457.0f);
	BOOST_CHECK_EQUAL(p[9], 461.0f);
	BOOST_CHECK_EQUAL(p[10], 463.0f);
	BOOST_CHECK_EQUAL(p[11], 0.0f);
	BOOST_CHECK_EQUAL(p[12], 467.0f);
	BOOST_CHECK_EQUAL(p[13], 0.0f);
	BOOST_CHECK_EQUAL(p[14], 0.0f);
	BOOST_CHECK_EQUAL(p[15], 0.0f);

	// scalar + vector + trivector
	hep::multi_vector<float, 1, 3> q = { 479.0f, 487.0f, 491.0f, 0.0f,
	                                     499.0f, 0.0f, 0.0f, 503.0f,
	                                     509.0f, 0.0f, 521.0f, 0.0f,
	                                     0.0f, 523.0f, 541.0f };

	BOOST_CHECK_EQUAL(q[0], 479.0f);
	BOOST_CHECK_EQUAL(q[1], 487.0f);
	BOOST_CHECK_EQUAL(q[2], 491.0f);
	BOOST_CHECK_EQUAL(q[3], 0.0f);
	BOOST_CHECK_EQUAL(q[4], 499.0f);
	BOOST_CHECK_EQUAL(q[5], 0.0f);
	BOOST_CHECK_EQUAL(q[6], 0.0f);
	BOOST_CHECK_EQUAL(q[7], 503.0f);
	BOOST_CHECK_EQUAL(q[8], 509.0f);
	BOOST_CHECK_EQUAL(q[9], 0.0f);
	BOOST_CHECK_EQUAL(q[10], 521.0f);
	BOOST_CHECK_EQUAL(q[11], 0.0f);
	BOOST_CHECK_EQUAL(q[12], 0.0f);
	BOOST_CHECK_EQUAL(q[13], 523.0f);
	BOOST_CHECK_EQUAL(q[14], 541.0f);
	BOOST_CHECK_EQUAL(q[15], 0.0f);

	// scalar + vector + quadvector
	hep::multi_vector<float, 1, 3> r = { 547.0f, 557.0f, 563.0f, 0.0f,
	                                     569.0f, 0.0f, 0.0f, 0.0f,
	                                     571.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 577.0f };

	BOOST_CHECK_EQUAL(r[0], 547.0f);
	BOOST_CHECK_EQUAL(r[1], 557.0f);
	BOOST_CHECK_EQUAL(r[2], 563.0f);
	BOOST_CHECK_EQUAL(r[3], 0.0f);
	BOOST_CHECK_EQUAL(r[4], 569.0f);
	BOOST_CHECK_EQUAL(r[5], 0.0f);
	BOOST_CHECK_EQUAL(r[6], 0.0f);
	BOOST_CHECK_EQUAL(r[7], 0.0f);
	BOOST_CHECK_EQUAL(r[8], 571.0f);
	BOOST_CHECK_EQUAL(r[9], 0.0f);
	BOOST_CHECK_EQUAL(r[10], 0.0f);
	BOOST_CHECK_EQUAL(r[11], 0.0f);
	BOOST_CHECK_EQUAL(r[12], 0.0f);
	BOOST_CHECK_EQUAL(r[13], 0.0f);
	BOOST_CHECK_EQUAL(r[14], 0.0f);
	BOOST_CHECK_EQUAL(r[15], 577.0f);

	// scalar + bivector + trivector
	hep::multi_vector<float, 1, 3> s = { 577.0f, 0.0f, 0.0f, 587.0f,
	                                     0.0f, 593.0f, 599.0f, 601.0f,
	                                     0.0f, 607.0f, 613.0f, 617.0f,
	                                     619.0f, 631.0f, 641.0f };

	BOOST_CHECK_EQUAL(s[0], 577.0f);
	BOOST_CHECK_EQUAL(s[1], 0.0f);
	BOOST_CHECK_EQUAL(s[2], 0.0f);
	BOOST_CHECK_EQUAL(s[3], 587.0f);
	BOOST_CHECK_EQUAL(s[4], 0.0f);
	BOOST_CHECK_EQUAL(s[5], 593.0f);
	BOOST_CHECK_EQUAL(s[6], 599.0f);
	BOOST_CHECK_EQUAL(s[7], 601.0f);
	BOOST_CHECK_EQUAL(s[8], 0.0f);
	BOOST_CHECK_EQUAL(s[9], 607.0f);
	BOOST_CHECK_EQUAL(s[10], 613.0f);
	BOOST_CHECK_EQUAL(s[11], 617.0f);
	BOOST_CHECK_EQUAL(s[12], 619.0f);
	BOOST_CHECK_EQUAL(s[13], 631.0f);
	BOOST_CHECK_EQUAL(s[14], 641.0f);
	BOOST_CHECK_EQUAL(s[15], 0.0f);

	// scalar + bivector + quadvector
	hep::multi_vector<float, 1, 3> t = { 643.0f, 0.0f, 0.0f, 647.0f,
	                                     0.0f, 653.0f, 659.0f, 0.0f,
	                                     0.0f, 661.0f, 673.0f, 0.0f,
	                                     677.0f, 0.0f, 0.0f, 683.0f };

	BOOST_CHECK_EQUAL(t[0], 643.0f);
	BOOST_CHECK_EQUAL(t[1], 0.0f);
	BOOST_CHECK_EQUAL(t[2], 0.0f);
	BOOST_CHECK_EQUAL(t[3], 647.0f);
	BOOST_CHECK_EQUAL(t[4], 0.0f);
	BOOST_CHECK_EQUAL(t[5], 653.0f);
	BOOST_CHECK_EQUAL(t[6], 659.0f);
	BOOST_CHECK_EQUAL(t[7], 0.0f);
	BOOST_CHECK_EQUAL(t[8], 0.0f);
	BOOST_CHECK_EQUAL(t[9], 661.0f);
	BOOST_CHECK_EQUAL(t[10], 673.0f);
	BOOST_CHECK_EQUAL(t[11], 0.0f);
	BOOST_CHECK_EQUAL(t[12], 677.0f);
	BOOST_CHECK_EQUAL(t[13], 0.0f);
	BOOST_CHECK_EQUAL(t[14], 0.0f);
	BOOST_CHECK_EQUAL(t[15], 683.0f);

	// scalar + trivector + quadvector
	hep::multi_vector<float, 1, 3> u = { 691.0f, 0.0f, 0.0f, 0.0f,
	                                     0.0f, 0.0f, 0.0f, 701.0f,
	                                     0.0f, 0.0f, 0.0f, 709.0f,
	                                     0.0f, 719.0f, 727.0f, 733.0f };

	BOOST_CHECK_EQUAL(u[0], 691.0f);
	BOOST_CHECK_EQUAL(u[1], 0.0f);
	BOOST_CHECK_EQUAL(u[2], 0.0f);
	BOOST_CHECK_EQUAL(u[3], 0.0f);
	BOOST_CHECK_EQUAL(u[4], 0.0f);
	BOOST_CHECK_EQUAL(u[5], 0.0f);
	BOOST_CHECK_EQUAL(u[6], 0.0f);
	BOOST_CHECK_EQUAL(u[7], 701.0f);
	BOOST_CHECK_EQUAL(u[8], 0.0f);
	BOOST_CHECK_EQUAL(u[9], 0.0f);
	BOOST_CHECK_EQUAL(u[10], 0.0f);
	BOOST_CHECK_EQUAL(u[11], 709.0f);
	BOOST_CHECK_EQUAL(u[12], 0.0f);
	BOOST_CHECK_EQUAL(u[13], 719.0f);
	BOOST_CHECK_EQUAL(u[14], 727.0f);
	BOOST_CHECK_EQUAL(u[15], 733.0f);

	// vector + bivector + trivector
	hep::multi_vector<float, 1, 3> v = { 0.0f, 739.0f, 743.0f, 751.0f,
	                                     757.0f, 761.0f, 769.0f, 773.0f,
	                                     787.0f, 797.0f, 809.0f, 811.0f,
	                                     821.0f, 823.0f, 827.0f };

	BOOST_CHECK_EQUAL(v[0], 0.0f);
	BOOST_CHECK_EQUAL(v[1], 739.0f);
	BOOST_CHECK_EQUAL(v[2], 743.0f);
	BOOST_CHECK_EQUAL(v[3], 751.0f);
	BOOST_CHECK_EQUAL(v[4], 757.0f);
	BOOST_CHECK_EQUAL(v[5], 761.0f);
	BOOST_CHECK_EQUAL(v[6], 769.0f);
	BOOST_CHECK_EQUAL(v[7], 773.0f);
	BOOST_CHECK_EQUAL(v[8], 787.0f);
	BOOST_CHECK_EQUAL(v[9], 797.0f);
	BOOST_CHECK_EQUAL(v[10], 809.0f);
	BOOST_CHECK_EQUAL(v[11], 811.0f);
	BOOST_CHECK_EQUAL(v[12], 821.0f);
	BOOST_CHECK_EQUAL(v[13], 823.0f);
	BOOST_CHECK_EQUAL(v[14], 827.0f);
	BOOST_CHECK_EQUAL(v[15], 0.0f);

	// vector + bivector + quadvector
	hep::multi_vector<float, 1, 3> w = { 0.0f, 829.0f, 839.0f, 853.0f,
	                                     857.0f, 859.0f, 863.0f, 0.0f,
	                                     877.0f, 881.0f, 883.0f, 0.0f,
	                                     887.0f, 0.0f, 0.0f, 907.0f };

	BOOST_CHECK_EQUAL(w[0], 0.0f);
	BOOST_CHECK_EQUAL(w[1], 829.0f);
	BOOST_CHECK_EQUAL(w[2], 839.0f);
	BOOST_CHECK_EQUAL(w[3], 853.0f);
	BOOST_CHECK_EQUAL(w[4], 857.0f);
	BOOST_CHECK_EQUAL(w[5], 859.0f);
	BOOST_CHECK_EQUAL(w[6], 863.0f);
	BOOST_CHECK_EQUAL(w[7], 0.0f);
	BOOST_CHECK_EQUAL(w[8], 877.0f);
	BOOST_CHECK_EQUAL(w[9], 881.0f);
	BOOST_CHECK_EQUAL(w[10], 883.0f);
	BOOST_CHECK_EQUAL(w[11], 0.0f);
	BOOST_CHECK_EQUAL(w[12], 887.0f);
	BOOST_CHECK_EQUAL(w[13], 0.0f);
	BOOST_CHECK_EQUAL(w[14], 0.0f);
	BOOST_CHECK_EQUAL(w[15], 907.0f);

	// vector + trivector + quadvector
	hep::multi_vector<float, 1, 3> x = { 0.0f, 911.0f, 919.0f, 0.0f,
	                                     929.0f, 0.0f, 0.0f, 937.0f,
	                                     941.0f, 0.0f, 0.0f, 947.0f,
	                                     0.0f, 953.0f, 967.0f, 971.0f };

	BOOST_CHECK_EQUAL(x[0], 0.0f);
	BOOST_CHECK_EQUAL(x[1], 911.0f);
	BOOST_CHECK_EQUAL(x[2], 919.0f);
	BOOST_CHECK_EQUAL(x[3], 0.0f);
	BOOST_CHECK_EQUAL(x[4], 929.0f);
	BOOST_CHECK_EQUAL(x[5], 0.0f);
	BOOST_CHECK_EQUAL(x[6], 0.0f);
	BOOST_CHECK_EQUAL(x[7], 937.0f);
	BOOST_CHECK_EQUAL(x[8], 941.0f);
	BOOST_CHECK_EQUAL(x[9], 0.0f);
	BOOST_CHECK_EQUAL(x[10], 0.0f);
	BOOST_CHECK_EQUAL(x[11], 947.0f);
	BOOST_CHECK_EQUAL(x[12], 0.0f);
	BOOST_CHECK_EQUAL(x[13], 953.0f);
	BOOST_CHECK_EQUAL(x[14], 967.0f);
	BOOST_CHECK_EQUAL(x[15], 971.0f);

	// bivector + trivector + quadvector
	hep::multi_vector<float, 1, 3> y = { 0.0f, 0.0f, 0.0f, 977.0f,
	                                     0.0f, 983.0f, 991.0f, 997.0f,
	                                     0.0f, 1009.0f, 1013.0f, 1019.0f,
	                                     1021.0f, 1031.0f, 1033.0f, 1039.0f };

	BOOST_CHECK_EQUAL(y[0], 0.0f);
	BOOST_CHECK_EQUAL(y[1], 0.0f);
	BOOST_CHECK_EQUAL(y[2], 0.0f);
	BOOST_CHECK_EQUAL(y[3], 977.0f);
	BOOST_CHECK_EQUAL(y[4], 0.0f);
	BOOST_CHECK_EQUAL(y[5], 983.0f);
	BOOST_CHECK_EQUAL(y[6], 991.0f);
	BOOST_CHECK_EQUAL(y[7], 997.0f);
	BOOST_CHECK_EQUAL(y[8], 0.0f);
	BOOST_CHECK_EQUAL(y[9], 1009.0f);
	BOOST_CHECK_EQUAL(y[10], 1013.0f);
	BOOST_CHECK_EQUAL(y[11], 1019.0f);
	BOOST_CHECK_EQUAL(y[12], 1021.0f);
	BOOST_CHECK_EQUAL(y[13], 1031.0f);
	BOOST_CHECK_EQUAL(y[14], 1033.0f);
	BOOST_CHECK_EQUAL(y[15], 1039.0f);

	// scalar + vector + bivector + trivector
	hep::multi_vector<float, 1, 3> z = { 1049.0f, 1051.0f, 1061.0f, 1063.0f,
	                                     1069.0f, 1087.0f, 1091.0f, 1093.0f,
	                                     1097.0f, 1103.0f, 1109.0f, 1117.0f,
	                                     1123.0f, 1129.0f, 1151.0f, 0.0f };

	BOOST_CHECK_EQUAL(z[0], 1049.0f);
	BOOST_CHECK_EQUAL(z[1], 1051.0f);
	BOOST_CHECK_EQUAL(z[2], 1061.0f);
	BOOST_CHECK_EQUAL(z[3], 1063.0f);
	BOOST_CHECK_EQUAL(z[4], 1069.0f);
	BOOST_CHECK_EQUAL(z[5], 1087.0f);
	BOOST_CHECK_EQUAL(z[6], 1091.0f);
	BOOST_CHECK_EQUAL(z[7], 1093.0f);
	BOOST_CHECK_EQUAL(z[8], 1097.0f);
	BOOST_CHECK_EQUAL(z[9], 1103.0f);
	BOOST_CHECK_EQUAL(z[10], 1109.0f);
	BOOST_CHECK_EQUAL(z[11], 1117.0f);
	BOOST_CHECK_EQUAL(z[12], 1123.0f);
	BOOST_CHECK_EQUAL(z[13], 1129.0f);
	BOOST_CHECK_EQUAL(z[14], 1151.0f);
	BOOST_CHECK_EQUAL(z[15], 0.0f);

	// scalar + vector + bivector + quadvector
	hep::multi_vector<float, 1, 3> z1 = { 1163.0f, 1171.0f, 1181.0f, 1187.0f,
	                                      1193.0f, 1201.0f, 1213.0f, 0.0f,
	                                      1217.0f, 1223.0f, 1229.0f, 0.0f,
	                                      1231.0f, 0.0f, 0.0f, 1237.0f };

	BOOST_CHECK_EQUAL(z1[0], 1163.0f);
	BOOST_CHECK_EQUAL(z1[1], 1171.0f);
	BOOST_CHECK_EQUAL(z1[2], 1181.0f);
	BOOST_CHECK_EQUAL(z1[3], 1187.0f);
	BOOST_CHECK_EQUAL(z1[4], 1193.0f);
	BOOST_CHECK_EQUAL(z1[5], 1201.0f);
	BOOST_CHECK_EQUAL(z1[6], 1213.0f);
	BOOST_CHECK_EQUAL(z1[7], 0.0f);
	BOOST_CHECK_EQUAL(z1[8], 1217.0f);
	BOOST_CHECK_EQUAL(z1[9], 1223.0f);
	BOOST_CHECK_EQUAL(z1[10], 1229.0f);
	BOOST_CHECK_EQUAL(z1[11], 0.0f);
	BOOST_CHECK_EQUAL(z1[12], 1231.0f);
	BOOST_CHECK_EQUAL(z1[13], 0.0f);
	BOOST_CHECK_EQUAL(z1[14], 0.0f);
	BOOST_CHECK_EQUAL(z1[15], 1237.0f);

	// scalar + vector + trivector + quadvector
	hep::multi_vector<float, 1, 3> z2 = { 1249.0f, 1259.0f, 1277.0f, 0.0f,
	                                      1279.0f, 0.0f, 0.0f, 1283.0f,
	                                      1289.0f, 0.0f, 0.0f, 1291.0f,
	                                      0.0f, 1297.0f, 1301.0f, 1303.0f };

	BOOST_CHECK_EQUAL(z2[0], 1249.0f);
	BOOST_CHECK_EQUAL(z2[1], 1259.0f);
	BOOST_CHECK_EQUAL(z2[2], 1277.0f);
	BOOST_CHECK_EQUAL(z2[3], 0.0f);
	BOOST_CHECK_EQUAL(z2[4], 1279.0f);
	BOOST_CHECK_EQUAL(z2[5], 0.0f);
	BOOST_CHECK_EQUAL(z2[6], 0.0f);
	BOOST_CHECK_EQUAL(z2[7], 1283.0f);
	BOOST_CHECK_EQUAL(z2[8], 1289.0f);
	BOOST_CHECK_EQUAL(z2[9], 0.0f);
	BOOST_CHECK_EQUAL(z2[10], 0.0f);
	BOOST_CHECK_EQUAL(z2[11], 1291.0f);
	BOOST_CHECK_EQUAL(z2[12], 0.0f);
	BOOST_CHECK_EQUAL(z2[13], 1297.0f);
	BOOST_CHECK_EQUAL(z2[14], 1301.0f);
	BOOST_CHECK_EQUAL(z2[15], 1303.0f);

	// scalar + bivector + trivector + quadvector
	hep::multi_vector<float, 1, 3> z3 = { 1307.0f, 0.0f, 0.0f, 1319.0f,
	                                      0.0f, 1321.0f, 1327.0f, 1361.0f,
	                                      0.0f, 1367.0f, 1373.0f, 1381.0f,
	                                      1399.0f, 1409.0f, 1423.0f, 1427.0f };

	BOOST_CHECK_EQUAL(z3[0], 1307.0f);
	BOOST_CHECK_EQUAL(z3[1], 0.0f);
	BOOST_CHECK_EQUAL(z3[2], 0.0f);
	BOOST_CHECK_EQUAL(z3[3], 1319.0f);
	BOOST_CHECK_EQUAL(z3[4], 0.0f);
	BOOST_CHECK_EQUAL(z3[5], 1321.0f);
	BOOST_CHECK_EQUAL(z3[6], 1327.0f);
	BOOST_CHECK_EQUAL(z3[7], 1361.0f);
	BOOST_CHECK_EQUAL(z3[8], 0.0f);
	BOOST_CHECK_EQUAL(z3[9], 1367.0f);
	BOOST_CHECK_EQUAL(z3[10], 1373.0f);
	BOOST_CHECK_EQUAL(z3[11], 1381.0f);
	BOOST_CHECK_EQUAL(z3[12], 1399.0f);
	BOOST_CHECK_EQUAL(z3[13], 1409.0f);
	BOOST_CHECK_EQUAL(z3[14], 1423.0f);
	BOOST_CHECK_EQUAL(z3[15], 1427.0f);

	// vector + bivector + trivector + quadvector
	hep::multi_vector<float, 1, 3> z4 = { 0.0f, 1429.0f, 1433.0f, 1439.0f,
	                                      1447.0f, 1451.0f, 1453.0f, 1459.0f,
	                                      1471.0f, 1481.0f, 1483.0f, 1487.0f,
	                                      1489.0f, 1493.0f, 1499.0f, 1511.0f };

	BOOST_CHECK_EQUAL(z4[0], 0.0f);
	BOOST_CHECK_EQUAL(z4[1], 1429.0f);
	BOOST_CHECK_EQUAL(z4[2], 1433.0f);
	BOOST_CHECK_EQUAL(z4[3], 1439.0f);
	BOOST_CHECK_EQUAL(z4[4], 1447.0f);
	BOOST_CHECK_EQUAL(z4[5], 1451.0f);
	BOOST_CHECK_EQUAL(z4[6], 1453.0f);
	BOOST_CHECK_EQUAL(z4[7], 1459.0f);
	BOOST_CHECK_EQUAL(z4[8], 1471.0f);
	BOOST_CHECK_EQUAL(z4[9], 1481.0f);
	BOOST_CHECK_EQUAL(z4[10], 1483.0f);
	BOOST_CHECK_EQUAL(z4[11], 1487.0f);
	BOOST_CHECK_EQUAL(z4[12], 1489.0f);
	BOOST_CHECK_EQUAL(z4[13], 1493.0f);
	BOOST_CHECK_EQUAL(z4[14], 1499.0f);
	BOOST_CHECK_EQUAL(z4[15], 1511.0f);

	// scalar + vector + bivector + trivector + quadvector
	hep::multi_vector<float, 1, 3> z5 = { 1523.0f, 1531.0f, 1543.0f, 1549.0f,
	                                      1553.0f, 1559.0f, 1567.0f, 1571.0f,
	                                      1579.0f, 1583.0f, 1597.0f, 1601.0f,
	                                      1607.0f, 1609.0f, 1613.0f, 1619.0f };

	BOOST_CHECK_EQUAL(z5[0], 1523.0f);
	BOOST_CHECK_EQUAL(z5[1], 1531.0f);
	BOOST_CHECK_EQUAL(z5[2], 1543.0f);
	BOOST_CHECK_EQUAL(z5[3], 1549.0f);
	BOOST_CHECK_EQUAL(z5[4], 1553.0f);
	BOOST_CHECK_EQUAL(z5[5], 1559.0f);
	BOOST_CHECK_EQUAL(z5[6], 1567.0f);
	BOOST_CHECK_EQUAL(z5[7], 1571.0f);
	BOOST_CHECK_EQUAL(z5[8], 1579.0f);
	BOOST_CHECK_EQUAL(z5[9], 1583.0f);
	BOOST_CHECK_EQUAL(z5[10], 1597.0f);
	BOOST_CHECK_EQUAL(z5[11], 1601.0f);
	BOOST_CHECK_EQUAL(z5[12], 1607.0f);
	BOOST_CHECK_EQUAL(z5[13], 1609.0f);
	BOOST_CHECK_EQUAL(z5[14], 1613.0f);
	BOOST_CHECK_EQUAL(z5[15], 1619.0f);
}
