AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-DBOOST_TEST_NO_LIB \
	-DBOOST_TEST_DYN_LINK \
	-DBOOST_TEST_MAIN

AM_CXXFLAGS = -std=c++0x

check_PROGRAMS = \
	test_ga \
	test_binomial_coefficient \
	test_next_bit_permutation \
	test_num_of_components \
	test_pop_count \
	test_sign_table \
	test_nth_bit_permutation_inverse

test_binomial_coefficient_SOURCES = test_binomial_coefficient.cpp
test_binomial_coefficient_LDADD = -lboost_unit_test_framework

test_ga_SOURCES = test_ga.cpp
test_ga_LDADD = -lboost_unit_test_framework

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
