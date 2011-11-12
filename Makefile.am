ACLOCAL_AMFLAGS = -I m4 --install

EXTRA_DIST = VERSION

# if doxygen is enabled include doc subdir
if HAVE_DOXYGEN
    DOCDIR = doc
endif

SUBDIRS = include test $(DOCDIR)
