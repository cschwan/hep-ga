#ifndef HEP_BINARY_EXPRESSION_HPP
#define HEP_BINARY_EXPRESSION_HPP

#include <hep/expression.hpp>
#include <hep/inline.hpp>

#include <type_traits>

namespace hep
{

/**
 * \addtogroup expressions
 * @{
 */

/**
 * 
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
	 * 
	 */
	hep_inline binary_expression(L const& lhs, R const& rhs)
		: lhs(lhs)
		, rhs(rhs)
	{
	}

protected:
	/**
	 * 
	 */
	L const& lhs;

	/**
	 * 
	 */
	R const& rhs;
};

/**
 * @}
 */

}

#endif
