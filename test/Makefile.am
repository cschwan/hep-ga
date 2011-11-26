AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -std=c++0x

check_PROGRAMS = test_ga

test_ga_SOURCES = test_ga.cpp
test_ga_LDADD = -lboost_unit_test_framework

TESTS_ENVIRONMENT = BOOST_TEST_LOG_LEVEL=all
TESTS = $(check_PROGRAMS)
