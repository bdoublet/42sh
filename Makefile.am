EXTRA_DIST = autogen.sh
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_MAKEFLAGS = --no-print-directory

AM_CPPFLAGS = \
	      -include $(top_builddir)/config.h \
	      -I${top_srcdir}/src

AM_CFLAGS = $(my_CFLAGS) $(PTHREAD_FLAGS)

bin_PROGRAMS = 42sh

42sh_SOURCES = \
		  src/parser.c \
                  src/lexeur.c

42sh_LDADD = $(PTHREAD_LIBS)

TESTS = \
	tests/test-args \
	test-example

EXTRA_DIST += tests/test-args

check_PROGRAMS = test-example

test_example_SOURCES = tests/test-example.c
