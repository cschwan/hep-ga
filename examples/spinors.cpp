#include <cmath>
#include <iostream>
#include <hep/ga.hpp>

// define the scalar type and determine numerical precision of calculations
typedef double scalar_type;

// space-time algebra (signature is +---)
typedef hep::algebra<scalar_type, 1, 3> sta;

// a scalar
typedef hep::multi_vector<sta, hep::list<0>> scalar;

// a real fourvector
typedef hep::multi_vector<sta, hep::list<1,2,4,8>> fourvector;

// a spinor (even-grade element)
typedef hep::multi_vector<sta, hep::list<0,3,5,6,9,10,12,15>> spinor;

// define basis-blades
#define gamma_0  hep::blade<sta,  1>()
#define gamma_03 hep::blade<sta,  9>()
#define gamma_12 hep::blade<sta,  6>()
#define gamma_13 hep::blade<sta, 10>()
#define gamma_23 hep::blade<sta, 12>()

// returns a right-handed spinor solving the dirac equation for momentum p
spinor weyl_spinor_pos(fourvector const& p)
{
	scalar_type const factor = 1.0 / (2.0 * std::sqrt(2.0 * p[0]));

	scalar_type a0 = p[0] + p[3];
	scalar_type a1 = p[2];
	scalar_type a2 = -p[1];
	scalar_type a3 = 0.0;

	return (a0 - a1 * gamma_23 + a2 * gamma_13 + a3 * gamma_12) *
		(1.0 - gamma_03) * factor;
}

// returns a left-handed spinor solving the dirac equation for momentum p
spinor weyl_spinor_neg(fourvector const& p)
{
	scalar_type const factor = 1.0 / (2.0 * std::sqrt(2.0 * p[0]));

	scalar_type a0 = p[0] - p[3];
	scalar_type a1 = -p[2];
	scalar_type a2 = p[1];
	scalar_type a3 = 0.0;

	return -(a0 - a1 * gamma_23 + a2 * gamma_13 + a3 * gamma_12) *
		(1.0 + gamma_03) * factor;
}

// implements the application of a vector to a spinor
spinor vector_spinor(fourvector const& odd, spinor const& even)
{
	return odd * even * gamma_0;
}

int main()
{
	std::cout << "EXAMPLE PROGRAM DEMONSTRATING THE USE OF DIRAC SPINORS IN ";
	std::cout << std::endl << "GEOMETRIC ALGEBRA" << std::endl << std::endl;

	// components of a momentum p
	scalar_type p1(1.0);
	scalar_type p2(2.0);
	scalar_type p3(2.0);
	scalar_type p0(3.0 /* std::sqrt(p1*p1 + p2*p2 + p3*p3) */);

	// construct a light-like fourvector from given components
	fourvector p = { p0, p1, p2, p3 };

	std::cout << "momentum p is (";
	std::cout << p[0] << ", ";
	std::cout << p[1] << ", ";
	std::cout << p[2] << ", ";
	std::cout << p[3] << ")" << std::endl;

	// the scalar product of p, which should be 0 for every light-like momentum
	// (if this is not the case, this indicates a problem with numerical
	// precision
	scalar p_squared = hep::inner_prod(p, p);

	// print result
	std::cout << "invariant p^2 is " << p_squared << std::endl;

	// two solutions of the dirac equations for fixed momentum p
	spinor p_plus = weyl_spinor_pos(p);
	spinor p_minus = weyl_spinor_neg(p);

	// compute one side of the dirac equation for a particle with momentum p
	spinor dirac_rh = vector_spinor(p, p_plus);

	// since spinor solves the dirac equation, these components should be zero
	std::cout << "dirac equation for right-handed spinor is ";
	std::cout << std::endl << "\t(";
	std::cout << dirac_rh[0] << ", ";
	std::cout << dirac_rh[1] << ", ";
	std::cout << dirac_rh[2] << ", ";
	std::cout << dirac_rh[3] << ", ";
	std::cout << dirac_rh[4] << ", ";
	std::cout << dirac_rh[5] << ", ";
	std::cout << dirac_rh[6] << ", ";
	std::cout << dirac_rh[7] << ") " << std::endl;

	// select vector part of a vector bilinear
	fourvector vector = hep::grade<1>(
		p_plus * gamma_0 * ~p_plus +
		p_minus * gamma_0 * ~p_minus
	);

	// equal to the momentum p
	std::cout << "completeness relation yields vector (";
	std::cout << vector[0] << ", ";
	std::cout << vector[1] << ", ";
	std::cout << vector[2] << ", ";
	std::cout << vector[3] << ") " << std::endl;

	return 0;
}
