nobase_include_HEADERS = \
	hep/ga/impl/common_product.hpp \
	hep/ga/impl/common_sum.hpp \
	hep/ga/impl/multi_vector.hpp \
	hep/ga/list/find.hpp \
	hep/ga/list/intersection.hpp \
	hep/ga/list/list.hpp \
	hep/ga/list/merge.hpp \
	hep/ga/utils/next_bit_permutation.hpp \
	hep/ga/utils/pop_count.hpp \
	hep/ga/utils/sign_table.hpp \
	hep/ga/algebra.hpp \
	hep/ga/binary_expression.hpp \
	hep/ga/blade.hpp \
	hep/ga/eval.hpp \
	hep/ga/expression.hpp \
	hep/ga/expression_ref.hpp \
	hep/ga/common_product.hpp \
	hep/ga/common_sum.hpp \
	hep/ga/difference.hpp \
	hep/ga/grade.hpp \
	hep/ga/inline.hpp \
	hep/ga/inner_product.hpp \
	hep/ga/multi_vector.hpp \
	hep/ga/negation.hpp \
	hep/ga/ostream.hpp \
	hep/ga/outer_product.hpp \
	hep/ga/product.hpp \
	hep/ga/reversion.hpp \
	hep/ga/selection.hpp \
	hep/ga/sum.hpp \
	hep/ga/unary_expression.hpp \
	hep/ga/wrapper.hpp \
	hep/ga.hpp \
	hep/ga_types.hpp

# create a timestamp file so we can depend on it instead of depending on every
# single header
stamp-headers: $(nobase_include_HEADERS)
	echo "timestamp for headers" > $@

# build this by default
all-local: stamp-headers

MOSTLYCLEANFILES = stamp-headers
