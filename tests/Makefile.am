AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-DBOOST_TEST_NO_LIB \
	-DBOOST_TEST_DYN_LINK \
	-DBOOST_TEST_MAIN

AM_CXXFLAGS = -std=c++0x

check_PROGRAMS = \
	test_binomial_coefficient \
	test_geometric_product_for_g2 \
	test_geometric_product_for_g3 \
	test_geometric_product_for_g4 \
	test_index_representation \
	test_multi_vector \
	test_next_bit_permutation \
	test_num_of_components \
	test_pop_count \
	test_sign_table \
	test_nth_bit_permutation_inverse

test_binomial_coefficient_SOURCES = test_binomial_coefficient.cpp
test_binomial_coefficient_LDADD = -lboost_unit_test_framework

test_geometric_product_for_g2_SOURCES = test_geometric_product_for_g2.cpp
test_geometric_product_for_g2_LDADD = -lboost_unit_test_framework

test_geometric_product_for_g3_SOURCES = test_geometric_product_for_g3.cpp
test_geometric_product_for_g3_LDADD = -lboost_unit_test_framework

test_geometric_product_for_g4_SOURCES = test_geometric_product_for_g4.cpp
test_geometric_product_for_g4_LDADD = -lboost_unit_test_framework

test_index_representation_SOURCES = test_index_representation.cpp
test_index_representation_LDADD = -lboost_unit_test_framework

test_multi_vector_SOURCES = test_multi_vector.cpp
test_multi_vector_LDADD = -lboost_unit_test_framework

test_next_bit_permutation_SOURCES = test_next_bit_permutation.cpp
test_next_bit_permutation_LDADD = -lboost_unit_test_framework

test_num_of_components_SOURCES = test_num_of_components.cpp
test_num_of_components_LDADD = -lboost_unit_test_framework

test_pop_count_SOURCES = test_pop_count.cpp
test_pop_count_LDADD = -lboost_unit_test_framework

test_sign_table_SOURCES = test_sign_table.cpp
test_sign_table_LDADD = -lboost_unit_test_framework

test_nth_bit_permutation_inverse_SOURCES = test_nth_bit_permutation_inverse.cpp
test_nth_bit_permutation_inverse_LDADD = -lboost_unit_test_framework

TESTS_ENVIRONMENT = BOOST_TEST_LOG_LEVEL=warning
TESTS = $(check_PROGRAMS)
