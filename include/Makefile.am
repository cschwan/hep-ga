nobase_include_HEADERS = \
	hep/impl/common_product.hpp \
	hep/impl/common_sum.hpp \
	hep/impl/multi_vector.hpp \
	hep/impl/stream.hpp \
	hep/list/find.hpp \
	hep/list/grade_to_list.hpp \
	hep/list/grades_to_list.hpp \
	hep/list/intersection.hpp \
	hep/list/list.hpp \
	hep/list/merge.hpp \
	hep/list/multiply.hpp \
	hep/utils/next_bit_permutation.hpp \
	hep/utils/pop_count.hpp \
	hep/utils/sign_table.hpp \
	hep/algebra.hpp \
	hep/binary_expression.hpp \
	hep/blade.hpp \
	hep/eval.hpp \
	hep/expression.hpp \
	hep/common_product.hpp \
	hep/common_sum.hpp \
	hep/difference.hpp \
	hep/ga.hpp \
	hep/ga_types.hpp \
	hep/grade.hpp \
	hep/inline.hpp \
	hep/inner_product.hpp \
	hep/multi_vector.hpp \
	hep/negation.hpp \
	hep/outer_product.hpp \
	hep/product.hpp \
	hep/reversion.hpp \
	hep/selection.hpp \
	hep/stream.hpp \
	hep/sum.hpp

# create a timestamp file so we can depend on it instead of depending on every
# single header
stamp-headers: $(nobase_include_HEADERS)
	echo "timestamp for headers" > $@

# build this by default
all-local: stamp-headers

MOSTLYCLEANFILES = stamp-headers
