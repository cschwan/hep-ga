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
 * \ref expression_ref is either a constant reference (<tt>E const&</tt>) or the
 * type itself (\c E), i.e. objects are copied.
 *
 * The current behavior is to use a reference if \c E is a \ref multi_vector and
 * to copy otherwise. In any case expressions of type \ref wrapper must be
 * copied because they are created as temporary objects.
 */
template <typename E>
using expression_ref = typename std::conditional<
	std::is_same<E, multi_vector<typename E::algebra, typename E::list>>::value,
	E const&,
	E
>::type;

}

#endif
