#include <hep/ga.hpp>

#include <iostream>

int main()
{
	/// [product_with_scalar]
	typedef hep::multi_vector<hep::algebra<double, 2,0>, hep::list<1,2>> vector;

	vector v = { 3.0, 4.0 };

	auto vector_times_scalar = v * 2.0;
	auto scalar_times_vector = 2.0 * v;
	/// [product_with_scalar]

	std::cout << vector_times_scalar.at<1>() << ' '
		<< vector_times_scalar.at<2>() << std::endl;

	std::cout << scalar_times_vector.at<1>() << ' '
		<< scalar_times_vector.at<2>() << std::endl;

	return 0;
}
