AC_PREREQ([2.69])
AC_INIT([C_JSB], [1.0])
AM_INIT_AUTOMAKE([foreign])
LT_INIT
AC_CONFIG_SRCDIR([use_hyb_reda.cpp])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
AC_PROG_CC
AC_LANG([C++])
AM_LDFLAGS="-L./libtorch/lib -ltorch -ltorch_cpu -lc10 -ldl -pthread -D_GLIBCXX_USE_CXX11_ABI=0"
AC_SUBST([AM_LDFLAGS])
AC_CONFIG_MACRO_DIRS([m4])
AC_CHECK_LIB([torch], [main])
AC_CHECK_LIB([c10], [main])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
