# _AC_CXX_STD_TRY(STANDARD, TEST-PROLOGUE, TEST-BODY, OPTION-LIST,
#                 ACTION-IF-AVAILABLE, ACTION-IF-UNAVAILABLE)
# --------------------------------------------------------------
# Check whether the C++ compiler accepts features of STANDARD (e.g `cxx11',
# `cxx98') by trying to compile a program of TEST-PROLOGUE and TEST-BODY.  If
# this fails, try again with each compiler option in the space-separated
# OPTION-LIST; if one helps, append it to CXX.  If eventually successful, run
# ACTION-IF-AVAILABLE, else ACTION-IF-UNAVAILABLE.
AC_DEFUN([_AC_CXX_STD_TRY],
[AC_MSG_CHECKING([for $CXX option to accept ISO ]m4_translit($1, [cxx], [C++]))
AC_CACHE_VAL(ac_cv_prog_cxx_$1,
[ac_cv_prog_cxx_$1=no
ac_save_CXX=$CXX
AC_LANG_PUSH([C++])
AC_LANG_CONFTEST([AC_LANG_PROGRAM([$2], [$3])])
for ac_arg in '' $4
do
  CXX="$ac_save_CXX $ac_arg"
  _AC_COMPILE_IFELSE([], [ac_cv_prog_cxx_$1=$ac_arg])
  test "x$ac_cv_prog_cxx_$1" != "xno" && break
done
rm -f conftest.$ac_ext
CXX=$ac_save_CXX
])# AC_CACHE_VAL
case "x$ac_cv_prog_cxx_$1" in
  x)
    AC_MSG_RESULT([none needed]) ;;
  xno)
    AC_MSG_RESULT([unsupported]) ;;
  *)
    CXX="$CXX $ac_cv_prog_cxx_$1"
    AC_MSG_RESULT([$ac_cv_prog_cxx_$1]) ;;
esac
AS_IF([test "x$ac_cv_prog_cxx_$1" != xno], [$5], [$6])
AC_LANG_POP([C++])
])# _AC_CXX_STD_TRY


# _AC_PROG_CXX_CXX11 ([ACTION-IF-AVAILABLE], [ACTION-IF-UNAVAILABLE])
# ----------------------------------------------------------------
# If the C++ compiler is not in ISO C++11 mode by default, try to add an
# option to output variable CXX to make it so.  This macro tries
# various options that select ISO C++11 on some system or another.  It
# considers the compiler to be in ISO C++11 mode if it handles ...
AC_DEFUN([_AC_PROG_CXX_CXX11],
[_AC_CXX_STD_TRY([cxx11],
[[
#include <string>
#include <tuple>
]],
[[
auto t = std::make_tuple(1, 2.0f, 3.0, std::string("foo"));

if (std::get<0>(t) != 1)
{
    return 1;
}

if (std::get<1>(t) != 2.0f)
{
    return 2;
}

if (std::get<2>(t) != 3.0)
{
    return 3;
}

return 0;
]],
[[-std=gnu++11 -std=gnu++0x -std=c++11 -std=c++0x -qlanglvl=extended0x]], [$1],
[$2])[]dnl
])# _AC_PROG_CXX_CXX11


# AC_PROG_CXX_CXX11
# --------------
AC_DEFUN([AC_PROG_CXX_CXX11],
[ AC_REQUIRE([AC_PROG_CXX])dnl
  _AC_PROG_CXX_CXX11
])
