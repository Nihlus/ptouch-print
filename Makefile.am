AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS= -DLOCALEDIR='"$(localedir)"'
AM_CFLAGS=-g -std=c11 -Wall -O3 -I$(top_srcdir)/include `pkg-config --cflags gtk+-3.0`
SUBDIRS = po
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = config.rpath m4/ChangeLog Makefile.old data/ptouch.ui
bin_PROGRAMS=ptouch-print ptouch-gtk
noinst_HEADERS=include/ptouch.h include/gettext.h
ptouch_print_SOURCES=src/ptouch-print.c src/libptouch.c include/ptouch.h include/gettext.h
ptouch_print_LDFLAGS=-lusb-1.0 -lgd
ptouch_gtk_SOURCES=src/ptouch-gtk.c src/libptouch.c include/ptouch.h include/gettext.h
ptouch_gtk_LDFLAGS=-lusb-1.0 -lgd `pkg-config --libs gtk+-3.0` -rdynamic
