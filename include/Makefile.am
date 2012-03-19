nobase_include_HEADERS = \
	hep/expr/assignment.hpp \
	hep/impl/algebra.hpp \
	hep/impl/grade.hpp \
	hep/impl/multi_vector.hpp \
	hep/impl/negation.hpp \
	hep/impl/product.hpp \
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
	hep/expression.hpp \
	hep/ga.hpp \
	hep/grade.hpp \
	hep/multi_vector.hpp \
	hep/negation.hpp \
	hep/product.hpp \
	hep/sum.hpp

# create a timestamp file so we can depend on it instead of depending on every
# single header
stamp-headers: $(nobase_include_HEADERS)
	echo "timestamp for headers" > $@

# build this by default
all-local: stamp-headers

MOSTLYCLEANFILES = stamp-headers
