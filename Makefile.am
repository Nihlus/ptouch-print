AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS= -DLOCALEDIR='"$(localedir)"'
AM_CFLAGS=-g -std=c11 -Wall -Wextra -Wunused -O3 -I$(top_srcdir)/include -fPIC
SUBDIRS = po
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = config.rpath m4/ChangeLog Makefile.old
bin_PROGRAMS=ptouch-print
noinst_HEADERS=include/ptouch.h include/gettext.h
ptouch_print_SOURCES=src/ptouch-print.c src/libptouch.c include/ptouch.h include/gettext.h
ptouch_print_LDFLAGS=-lusb-1.0 -lgd
