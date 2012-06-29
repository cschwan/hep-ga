#ifndef HEP_BINARY_EXPRESSION_HPP
#define HEP_BINARY_EXPRESSION_HPP

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
 * Parent class for all binary operations. Both the left-hand operand of type
 * \c L and the right-hand operand of type \c R must be an \ref expression. The
 * component list \c List of the resultant expression must be a \ref list.
 */
template <typename L, typename R, typename List>
class binary_expression : public expression<typename L::algebra, List>
{
	static_assert (
		std::is_same<typename L::algebra, typename R::algebra>::value,
		"expression for different algebras is undefined"
	);

public:
	/**
	 * Constructor. This sets the left- and right-hand operands \c lhs and
	 * \c rhs.
	 */
	hep_inline binary_expression(L const& lhs, R const& rhs)
		: lhs(lhs)
		, rhs(rhs)
	{
	}

protected:
	/**
	 * Left-hand operand of this expression.
	 */
	expression_ref<L> lhs;

	/**
	 * Right-hand operand of this expression.
	 */
	expression_ref<R> rhs;
};

/**
 * @}
 */

}

#endif
