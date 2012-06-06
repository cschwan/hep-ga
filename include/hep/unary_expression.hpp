#ifndef HEP_UNARY_EXPRESSION_HPP
#define HEP_UNARY_EXPRESSION_HPP

#include <hep/expression.hpp>
#include <hep/inline.hpp>
#include <hep/multi_vector.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Parent class for unary expressions.
 */
template <typename E, typename A, typename L>
class unary_expression : public expression<A, L>
{
public:
	/**
	 * Constructor.
	 */
	hep_inline unary_expression(E const& expr)
		: expr(expr)
	{
	}

protected:
	/**
	 * The expression.
	 */
	typename std::conditional<
		std::is_same<E, multi_vector<A, L>>::value, E const&, E>::type expr;
};

/**
 * @}
 */

}

#endif
