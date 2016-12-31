# AC_CONFIG_MACRO_DIR needs >=2.58
AC_PREREQ([2.58])

# initialize configure
AC_INIT([hep-ga], [0.0.1.9999], [https://github.com/cschwan/hep-ga/issues],
	[hep-ga], [https://github.com/cschwan/hep-ga])

# put autotools files into a separate directory
AC_CONFIG_AUX_DIR([build-aux])

# initialize automake
AM_INIT_AUTOMAKE([foreign -Wall dist-bzip2 no-dist-gzip nostdinc 1.11])

# put aclocal macros into m4
AC_CONFIG_MACRO_DIR([m4])

# C++ is our language
AC_LANG([C++])

# check for C++11 conforming compiler (autoconf-archive macro)
AX_CXX_COMPILE_STDCXX([14], [noext], [mandatory])

# point to a source file in order to let ./configure find itself
AC_CONFIG_SRCDIR([include/hep/ga.hpp])

# do not pollute command line with compiler definitions but instead write them
# into the specified header
AC_CONFIG_HEADERS([config.hpp])

# needed for linking
AC_PROG_RANLIB
AM_PROG_AR

AC_ARG_ENABLE([examples], AS_HELP_STRING([--enable-examples],
	[Enable building of example programs]))

AM_CONDITIONAL([HAVE_EXAMPLES], [test "x$enable_examples" = "xyes"])

# add possibility to generate API documentation with Doxygen
AC_ARG_ENABLE([doxygen], AS_HELP_STRING([--enable-doxygen],
	[Enable generation of Doxygen documentation]))

# variable pointing to the doxygen binary
AC_ARG_VAR([DOXYGEN], [Doxygen documentation generator])

# check for the doxygen binary
AS_IF([test "x$enable_doxygen" = "xyes"], [
	AC_CHECK_PROGS([DOXYGEN], [doxygen])
	AS_IF([test -z "$DOXYGEN"],
		AC_MSG_ERROR([Doxygen not found but requested]))
])

# if doxygen is requested, define HAVE_DOXYGEN and configure Doxyfile.in
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])

# configure Makefiles and Doxyfile
AC_CONFIG_FILES([
	Makefile
	doc/Doxyfile
	doc/Makefile
	examples/Makefile
	include/Makefile
	tests/Makefile
])

# write configure script
AC_OUTPUT
