#ifndef HEP_BINARY_EXPRESSION_HPP
#define HEP_BINARY_EXPRESSION_HPP

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
 * Parent class for all expressions involving two subexpressions. The
 * left-hand subexpression is of type \c L and the right-hand expression of type
 * \c R. The combined expression contains components specified with \c List.
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
	 * Constructor. This sets the left- and right-hand subexpressions \c lhs and
	 * \c rhs.
	 */
	hep_inline binary_expression(L const& lhs, R const& rhs)
		: lhs(lhs)
		, rhs(rhs)
	{
	}

protected:
	/**
	 * Left-hand expression.
	 */
	typename std::conditional<
		std::is_same<L, multi_vector<typename L::algebra,
			typename L::list>>::value,
		L const&,
		L
	>::type lhs;

	/**
	 * Right-hand expression.
	 */
	typename std::conditional<
		std::is_same<R, multi_vector<typename R::algebra,
			typename R::list>>::value,
		R const&,
		R
	>::type rhs;
};

/**
 * @}
 */

}

#endif
