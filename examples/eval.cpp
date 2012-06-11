#include <iostream>

#include <hep/ga.hpp>

int main()
{
	/// [example]
	typedef hep::algebra<double, 3, 0> space3;
	typedef hep::list<1,2,4> components;
	typedef hep::multi_vector<space3, components> vector;

	vector v1 = { 1.0, 2.0, 3.0 };
	vector v2 = { 4.0, 5.0, 6.0 };
	vector v3 = { 7.0, 8.0, 9.0 };

	// expr is of type sum<sum<vector, vector>, vector>, components are
	// *not* computed at this point
	auto expr = v1 + v2 + v3;

	// sum is of type 'vector', the computations are done right here
	auto sum = hep::eval(v1 + v2 + v3);
	/// [example]

	// at this point expr is implicitly evaluated in 'at'
	std::cout << expr.at<1>() << ' ';
	std::cout << expr.at<2>() << ' ';
	std::cout << expr.at<4>() << std::endl;

	// here we just print the saved values of the sum vector
	std::cout << sum.at<1>() << ' ';
	std::cout << sum.at<2>() << ' ';
	std::cout << sum.at<4>() << std::endl;

	return 0;
}
