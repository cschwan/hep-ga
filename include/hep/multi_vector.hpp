#ifndef HEP_MULTI_VECTOR_HPP
#define HEP_MULTI_VECTOR_HPP

#include <cstddef>

namespace hep
{

/**
 * \section introduction Introduction
 *
 * An implementation for multi-vectors of geometric algebra \f$ \mathcal{G}_{p,
 * q} \f$. The basis vectors \f$ e_0, e_1, \ldots, e_{p+q-1} \f$ satisfy the
 * following properties:
 * \f[
 *     e_i^2 = \begin{cases} +1 & \forall \, 0 \le i < p \\
 *                           -1 & \forall \, p \le i < p+q \end{cases}
 * \f]
 * For example, \f$ \mathcal{G}_{2,0} \f$ is the geometric algebra of the
 * (euclidian) plane, \f$ \mathcal{G}_{3,0} \f$ is the GA of euclidian space and
 * \f$ \mathcal{G}_{1,3} \f$ denotes the GA of Minkowski space with basis
 * vectors satisfying \f$ e_0^2 = +1 \f$, \f$ e_1^2 = -1 \f$, \f$ e_2^2 = -1 \f$
 * and \f$ e_3^2 = -1 \f$.
 *
 * \section component_storage_layout Component Storage Layout
 *
 * The multi_vector class stores its components in a form which follows the
 * bit-representation of a multi-vector:
 *
 *   - Index \f$ 0 = 000_2 \mapsto 1 \f$
 *   - Index \f$ 1 = 001_2 \mapsto e_0 \f$
 *   - Index \f$ 2 = 010_2 \mapsto e_1 \f$
 *   - Index \f$ 3 = 011_2 \mapsto e_0 e_1 \f$
 *   - Index \f$ 4 = 100_2 \mapsto e_2 \f$
 *   - Index \f$ 5 = 101_2 \mapsto e_0 e_2 \f$
 *   - Index \f$ 6 = 110_2 \mapsto e_1 e_2 \f$
 *   - Index \f$ 7 = 111_2 \mapsto e_0 e_1 e_2 \f$
 *   - \f$ \ldots \f$
 *
 * For example, the first component (index \f$ 0 \f$) denotes the scalar part of
 * every multi-vector and index \f$ 6 \f$ points to the component with basis
 * blade \f$ e_1 e_2 \f$.
 *
 * Note that the basis blade of a single grade in general will not have
 * consecutive indices, e.g. the vectors always have indices which are powers
 * of \f$ 2 \f$.The reason for choosing such a scheme is that multiplication
 * (geometric product) becomes very easy and also efficient to implement.
 *
 * \tparam T Type used for components of the multi vector
 * \tparam P Number of basis vectors which square to \f$ +1 \f$
 * \tparam Q Number of basis vectors which square to \f$ -1 \f$
 */
template <typename T, std::size_t P, std::size_t Q>
class multi_vector
{
public:
	/**
	 * Constructor. Initializes all components to zero.
	 */
	multi_vector();

	/**
	 * Constructor. This constructor is used to initialize all of the
	 * multi-vector's components. Note that you have to specify all \f$ 2^{p+q}
	 * \f$ components, otherwise compilation will fail. Furthmore note that you
	 * have to specify the components in the order described in the class
	 * description of multi_vector.
	 * 
	 * \param components Components of the multi-vector
	 */
	template <typename ... Args>
	multi_vector(Args ... components);

	/**
	 * Component write-access operator. Note the order of components described
	 * in multi_vector.
	 */
	T& operator[](std::size_t index);

	/**
	 * Component read-access operator. Note the order of components described in
	 * multi_vector.
	 */
	T const& operator[](std::size_t index) const;

private:
	/**
	 * Number of components of this multi-vector.
	 */
	constexpr static std::size_t no_of_components = 1 << (P + Q);

	/**
	 * Array storing the components of this multi-vector.
	 */
	T m_components[no_of_components];
};

}

#include <hep/implementation/multi_vector.hpp>

#endif
