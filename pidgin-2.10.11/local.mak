SHELL := /bin/bash
CC := /usr/bin/i586-mingw32msvc-cc
GMSGFMT := msgfmt
MAKENSIS := /usr/bin/makensis
WINDRES := /usr/bin/i586-mingw32msvc-windres
STRIP := /usr/bin/i586-mingw32msvc-strip
INTLTOOL_MERGE := /usr/bin/intltool-merge
GCC_SSP_TOP := $(PIDGIN_TREE_TOP)/../win32-dev/libssp/bin


#MONO_SIGNCODE=/usr/bin/signcode
#SIGNCODE_SPC=c:\\Path\\to\\authenticode.spc
#       SIGNCODE_PVK=c:\\Path\\to\\authenticode.pvk
#       #Set up gpg to use a separate keyring
#       GPG_SIGN=gpg --no-default-keyring --secret-keyring /path/to/secring.gpg

#Disable Signing
MONO_SIGNCODE=echo ***Bypassing signcode***
GPG_SIGN=echo ***Bypassing gpg***


INCLUDE_PATHS := -I$(PIDGIN_TREE_TOP)/../win32-dev/w32api/include
LIB_PATHS := -L$(PIDGIN_TREE_TOP)/../win32-dev/w32api/lib
