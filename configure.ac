# Check for Autoconf
AC_PREREQ([2.67])

# Initialize package information
define([MY_NAME], [edo])
define([MY_MAJOR_VERSION], [0])
define([MY_MINOR_VERSION], [2])
define([MY_VERSION], MY_MAJOR_VERSION.MY_MINOR_VERSION)
define([MY_EMAIL], [adb1413@rit.edu])
define([MY_URL], [http://github.com/adbrown85/edo])
AC_INIT(MY_NAME, MY_VERSION, MY_EMAIL, , MY_URL)
AC_SUBST([PACKAGE_MAJOR_VERSION], MY_MAJOR_VERSION)
AC_SUBST([PACKAGE_MINOR_VERSION], MY_MINOR_VERSION)
AC_CONFIG_SRCDIR([src/edo/common.h])
AC_CONFIG_HEADERS([config.h])

# Check for system
AC_CANONICAL_HOST

# Check for compilers and languages
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])

# Check for common headers
AC_HEADER_STDBOOL

# Check for tools
AC_PROG_INSTALL
AC_PROG_SED

# Finish
AC_CONFIG_FILES([edo.pc Makefile])
AC_OUTPUT

# Report
echo \
"--------------------------------------------------------------
 ${PACKAGE_NAME} ${PACKAGE_VERSION}

 prefix      ${prefix}
 CXX         ${CXX}
 CPPFLAGS    ${CPPFLAGS}
 CXXFLAGS    ${CXXFLAGS}
 LDFLAGS     ${LDFLAGS}
 LIBS        ${LIBS}
 DEFS        ${DEFS}
 
 Now type 'make' then 'sudo make install'
--------------------------------------------------------------"
