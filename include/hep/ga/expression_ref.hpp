#ifndef HEP_GA_EXPRESSION_REF_HPP
#define HEP_GA_EXPRESSION_REF_HPP

#include <hep/ga/multi_vector.hpp>

#include <type_traits>

namespace hep
{

/**
 * \ingroup expressions
 *
 * A reference to an \ref expression used in \ref unary_expression and 
 * \ref binary_expression. Depending on the type of the expression \c E,
 * \c expr_ref is either a constant reference (<tt>E const&</tt>) or the type
 * itself (\c E), i.e. objects are copied. This is useful for testing how the
 * choice above influences performance.
 *
 * The current implementation is to use a constant reference if \c E is a
 * \ref multi_vector and to use \c E in other cases. The idea behind this is
 * that references introduce indirections lowering performance, so they are best
 * avoided (assuming that the compiler can not resolve these indirections).
 * However, objects of the type \ref multi_vector are usually too big so that
 * copying inflicts more performance penalties than the indirection.
 */
template <typename E>
using expression_ref = typename std::conditional<
	std::is_same<E, multi_vector<typename E::algebra, typename E::list>>::value,
	E const&,
	E
>::type;

}

#endif
