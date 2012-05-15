nobase_include_HEADERS = \
	hep/expr/cond_difference.hpp \
	hep/expr/cond_sum.hpp \
	hep/expr/predicates.hpp \
	hep/expr/prod_elem_cond_sum.hpp \
	hep/expr/prod_elem_sum.hpp \
	hep/expr/prod_elem_sum_list.hpp \
	hep/impl/algebra.hpp \
	hep/impl/blade.hpp \
	hep/impl/difference.hpp \
	hep/impl/eval.hpp \
	hep/impl/grade.hpp \
	hep/impl/inner_product.hpp \
	hep/impl/multi_vector.hpp \
	hep/impl/negation.hpp \
	hep/impl/product.hpp \
	hep/impl/reversion.hpp \
	hep/impl/selection.hpp \
	hep/impl/stream.hpp \
	hep/impl/sum.hpp \
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
	hep/blade.hpp \
	hep/eval.hpp \
	hep/expression.hpp \
	hep/difference.hpp \
	hep/ga.hpp \
	hep/grade.hpp \
	hep/inline.hpp \
	hep/inner_product.hpp \
	hep/multi_vector.hpp \
	hep/negation.hpp \
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
