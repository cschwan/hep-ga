#ifndef HEP_UNARY_EXPRESSION_HPP
#define HEP_UNARY_EXPRESSION_HPP

#include <hep/expression.hpp>
#include <hep/expression_ref.hpp>
#include <hep/inline.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * Parent class for all unary operations. The operand of type \c E must be an
 * \ref expression. The component list \c L of the resultant expression must be
 * a \ref list.
 */
template <typename E, typename L>
class unary_expression : public expression<typename E::algebra, L>
{
public:
	/**
	 * Constructor. This sets the operand \c expr.
	 */
	hep_inline unary_expression(E const& expr)
		: expr(expr)
	{
	}

protected:
	/**
	 * The operand of this expression.
	 */
	expression_ref<E> expr;
};

/**
 * @}
 */

}

#endif
