#include <iostream>

/// [header]
#include <hep/ga.hpp>
/// [header]

int main()
{

	/// [algebra]
	typedef hep::algebra<double, 3, 0> space3;
	/// [algebra]

	/// [components]
	typedef hep::list<1,2,4> components;
	/// [components]

	/// [vector]
	typedef hep::multi_vector<space3, components> vector;
	/// [vector]

	/// [vector_sum]
	vector a = { 1.0, 2.0, 3.0 };
	vector b = { 4.0, 5.0, 6.0 };
	vector c = a + b;
	/// [vector_sum]

	std::cout << c[0] << ' ' << c[1] << ' ' << c[2] << std::endl;

	/// [quaternion]
	typedef hep::multi_vector<space3, hep::list<0,3,5,6>> quaternion;

	quaternion d = a * b;
	/// [quaternion]

	std::cout << d[0] << ' ' << d[1] << ' ' << d[2] << ' ' << d[3] << std::endl;

	/// [auto]
	auto e = hep::eval(a * b);
	/// [auto]

	std::cout << e[0] << ' ' << e[1] << ' ' << e[2] << ' ' << e[3] << std::endl;

	return 0;
}
