nobase_include_HEADERS = \
	hep/expression/assignment.hpp \
	hep/impl/algebra.hpp \
	hep/impl/multi_vector.hpp \
	hep/impl/negation.hpp \
	hep/impl/product.hpp \
	hep/impl/sum.hpp \
	hep/utils/find.hpp \
	hep/utils/list.hpp \
	hep/utils/merge.hpp \
	hep/utils/multiply.hpp \
	hep/utils/pop_count.hpp \
	hep/utils/sign_table.hpp \
	hep/algebra.hpp \
	hep/expression.hpp \
	hep/ga.hpp \
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
