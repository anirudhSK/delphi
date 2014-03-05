#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([mahimahi], [0.1], [anirudh@mit.edu])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([child_process.cc])
AC_CONFIG_HEADERS([config.h])

# Add picky CXXFLAGS
CPPFLAGS="-std=c++11 -pthread"
PICKY_CXXFLAGS="-pedantic -Wall -Wextra -Weffc++ -Werror -fno-default-inline"
AC_SUBST([PICKY_CXXFLAGS])

# Checks for programs.
AC_PROG_CXX
AC_PROG_RANLIB

AC_ARG_VAR([PING], [path to ping])
AC_PATH_PROG([PING], [ping], [no], [$PATH$PATH_SEPARATOR/sbin$PATH_SEPARATOR/usr/sbin$PATH_SEPARATOR/bin$PATH_SEPARATOR/usr/bin])
if test "$PING" = "no"; then
  AC_MSG_ERROR([ping is required])
fi
AC_DEFINE_UNQUOTED([PING], ["$PING"], [path to PING])

# Set path to directory with installed executable programs
AC_DEFINE_UNQUOTED([EXEC_DIR], ["${prefix}/bin/"], [path to directory with installed executable programs])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
