AC_INIT(tpcqa,[1.00])
AC_CONFIG_SRCDIR([configure.ac])

AM_INIT_AUTOMAKE
AC_PROG_CXX(CC g++)

LT_INIT([disable-static])

dnl   no point in suppressing warnings people should 
dnl   at least see them, so here we go for g++: -Wall
if test $ac_cv_prog_gxx = yes; then
   CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wshadow -Werror"
fi

case $CXX in
 clang++)
   CXXFLAGS="$CXXFLAGS -Wno-dangling -fopenmp"
 ;;
esac

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
