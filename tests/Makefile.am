AUTOMAKE_OPTIONS = parallel-tests

AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-DBOOST_TEST_NO_LIB \
	-DBOOST_TEST_DYN_LINK \
	-DBOOST_TEST_MAIN

AM_DEFAULT_SOURCE_EXT = .cpp

check_PROGRAMS = \
	test_addition_in_g2 \
	test_binomial_coefficient \
	test_geometric_product_in_g2 \
	test_geometric_product_in_g3 \
	test_geometric_product_in_g4 \
	test_grade_list_product \
	test_grade_projection \
	test_index_representation \
	test_multi_vector_in_g2 \
	test_multi_vector_in_g3 \
	test_multi_vector_in_g4 \
	test_next_bit_permutation \
	test_nth_bit_permutation_inverse \
	test_num_of_components \
	test_pop_count \
	test_sign_table \
	test_trailing_zeroes

LDADD = -lboost_unit_test_framework

LOG_COMPILER = BOOST_TEST_BUILD_INFO=yes BOOST_TEST_DETECT_FP_EXCEPTIONS=yes

TESTS = $(check_PROGRAMS)
