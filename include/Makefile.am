nobase_include_HEADERS = \
	hep/impl/grade.hpp \
	hep/impl/multi_vector.hpp \
	hep/impl/product.hpp \
	hep/utils/binomial_coefficient.hpp \
	hep/utils/grade_list_product.hpp \
	hep/utils/index_representation.hpp \
	hep/utils/next_bit_permutation.hpp \
	hep/utils/nth_bit_permutation_inverse.hpp \
	hep/utils/num_of_components.hpp \
	hep/utils/pop_count.hpp \
	hep/utils/sign_table.hpp \
	hep/utils/trailing_zeroes.hpp \
	hep/ga.hpp \
	hep/grade.hpp \
	hep/multi_vector.hpp \
	hep/product.hpp

# create a timestamp file so we can depend on it instead of depending on every
# single header
stamp-headers: $(nobase_include_HEADERS)
	echo "timestamp for headers" > $@

# build this by default
all-local: stamp-headers

MOSTLYCLEANFILES = stamp-headers
