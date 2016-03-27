AM_CPPFLAGS = -I$(top_srcdir)/include -DGTEST_HAS_PTHREAD=0

AM_DEFAULT_SOURCE_EXT = .cpp

# convenience libraries
check_LIBRARIES = libgtest.a libgtest_main.a

libgtest_a_SOURCES = gtest/gtest.h gtest-all.cpp
libgtest_main_a_SOURCES = gtest/gtest.h gtest_main.cpp

check_PROGRAMS = \
	test_difference_in_g2 \
	test_grade_in_g2 \
	test_inner_product_in_g2 \
	test_multi_vector_in_g2 \
	test_multi_vector_in_g3 \
	test_multi_vector_in_g4 \
	test_negation_in_g2 \
	test_next_bit_permutation \
	test_outer_product_in_g2 \
	test_pop_count \
	test_product_in_g2 \
	test_product_in_g3 \
	test_product_in_g4 \
	test_product_with_scalar_in_g2 \
	test_reversion_in_g3 \
	test_selection_in_g2 \
	test_sign_table \
	test_sum_in_g2 \
	test_sum_with_scalar_in_g2

LDADD = libgtest.a libgtest_main.a

TESTS = $(check_PROGRAMS)
