#############################################################################
# Makefile for building: Version1_0
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue May 31 20:35:46 2016
# Project:  Version1_0.pro
# Template: app
# Command: /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake -o Makefile Version1_0.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -D_TTY_POSIX_ -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/default -I. -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtNetwork -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -lQtGui -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		posix_qextserialport.cpp \
		qextserialbase.cpp \
		qextserialport.cpp \
		serialclass.cpp \
		socketclass.cpp \
		moudle.cpp \
		ledandmotor.cpp \
		temperature.cpp \
		clock.cpp \
		replays.cpp \
		camerainit.cpp \
		airirda.cpp \
		smoke.cpp \
		moudleset.cpp \
		coorimpl.cpp \
		ultrasonicandpwm.cpp \
		login.cpp \
		WidgetKeyboard.cpp \
		curtain.cpp \
		detectusb.cpp \
		httpreply.cpp \
		download.cpp \
		security.cpp moc_mainwindow.cpp \
		moc_qextserialbase.cpp \
		moc_qextserialport.cpp \
		moc_serialclass.cpp \
		moc_socketclass.cpp \
		moc_moudle.cpp \
		moc_temperature.cpp \
		moc_clock.cpp \
		moc_replays.cpp \
		moc_moudleset.cpp \
		moc_coorimpl.cpp \
		moc_ultrasonicandpwm.cpp \
		moc_login.cpp \
		moc_WidgetKeyboard.cpp \
		moc_detectusb.cpp \
		moc_httpreply.cpp \
		moc_download.cpp
OBJECTS       = main.o \
		mainwindow.o \
		posix_qextserialport.o \
		qextserialbase.o \
		qextserialport.o \
		serialclass.o \
		socketclass.o \
		moudle.o \
		ledandmotor.o \
		temperature.o \
		clock.o \
		replays.o \
		camerainit.o \
		airirda.o \
		smoke.o \
		moudleset.o \
		coorimpl.o \
		ultrasonicandpwm.o \
		login.o \
		WidgetKeyboard.o \
		curtain.o \
		detectusb.o \
		httpreply.o \
		download.o \
		security.o \
		moc_mainwindow.o \
		moc_qextserialbase.o \
		moc_qextserialport.o \
		moc_serialclass.o \
		moc_socketclass.o \
		moc_moudle.o \
		moc_temperature.o \
		moc_clock.o \
		moc_replays.o \
		moc_moudleset.o \
		moc_coorimpl.o \
		moc_ultrasonicandpwm.o \
		moc_login.o \
		moc_WidgetKeyboard.o \
		moc_detectusb.o \
		moc_httpreply.o \
		moc_download.o
DIST          = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		Version1_0.pro
QMAKE_TARGET  = Version1_0
DESTDIR       = 
TARGET        = Version1_0

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_WidgetKeyboard.h ui_login.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Version1_0.pro  /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/default/qmake.conf /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtNetwork.prl
	$(QMAKE) -o Makefile Version1_0.pro
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Version1_0.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Version1_01.0.0 || $(MKDIR) .tmp/Version1_01.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Version1_01.0.0/ && $(COPY_FILE) --parents mainwindow.h posix_qextserialport.h qextserialbase.h qextserialport.h serialclass.h socketclass.h serialservice.h abstracemoudle.h moudle.h ledandmotor.h temperature.h clock.h replays.h camerainit.h airirda.h smoke.h moudleset.h coorimpl.h ultrasonicandpwm.h login.h WidgetKeyboard.hpp curtain.h detectusb.h httpreply.h download.h security.h .tmp/Version1_01.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp posix_qextserialport.cpp qextserialbase.cpp qextserialport.cpp serialclass.cpp socketclass.cpp moudle.cpp ledandmotor.cpp temperature.cpp clock.cpp replays.cpp camerainit.cpp airirda.cpp smoke.cpp moudleset.cpp coorimpl.cpp ultrasonicandpwm.cpp login.cpp WidgetKeyboard.cpp curtain.cpp detectusb.cpp httpreply.cpp download.cpp security.cpp .tmp/Version1_01.0.0/ && $(COPY_FILE) --parents mainwindow.ui WidgetKeyboard.ui login.ui .tmp/Version1_01.0.0/ && (cd `dirname .tmp/Version1_01.0.0` && $(TAR) Version1_01.0.0.tar Version1_01.0.0 && $(COMPRESS) Version1_01.0.0.tar) && $(MOVE) `dirname .tmp/Version1_01.0.0`/Version1_01.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Version1_01.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_qextserialbase.cpp moc_qextserialport.cpp moc_serialclass.cpp moc_socketclass.cpp moc_moudle.cpp moc_temperature.cpp moc_clock.cpp moc_replays.cpp moc_moudleset.cpp moc_coorimpl.cpp moc_ultrasonicandpwm.cpp moc_login.cpp moc_WidgetKeyboard.cpp moc_detectusb.cpp moc_httpreply.cpp moc_download.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_qextserialbase.cpp moc_qextserialport.cpp moc_serialclass.cpp moc_socketclass.cpp moc_moudle.cpp moc_temperature.cpp moc_clock.cpp moc_replays.cpp moc_moudleset.cpp moc_coorimpl.cpp moc_ultrasonicandpwm.cpp moc_login.cpp moc_WidgetKeyboard.cpp moc_detectusb.cpp moc_httpreply.cpp moc_download.cpp
moc_mainwindow.cpp: posix_qextserialport.h \
		qextserialbase.h \
		camerainit.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		serialclass.h \
		clock.h \
		moudleset.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h \
		mainwindow.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_qextserialbase.cpp: qextserialbase.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) qextserialbase.h -o moc_qextserialbase.cpp

moc_qextserialport.cpp: posix_qextserialport.h \
		qextserialbase.h \
		qextserialport.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) qextserialport.h -o moc_qextserialport.cpp

moc_serialclass.cpp: posix_qextserialport.h \
		qextserialbase.h \
		serialservice.h \
		serialclass.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) serialclass.h -o moc_serialclass.cpp

moc_socketclass.cpp: socketclass.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) socketclass.h -o moc_socketclass.cpp

moc_moudle.cpp: abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		moudle.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) moudle.h -o moc_moudle.cpp

moc_temperature.cpp: moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		temperature.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) temperature.h -o moc_temperature.cpp

moc_clock.cpp: clock.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) clock.h -o moc_clock.cpp

moc_replays.cpp: moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		replays.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) replays.h -o moc_replays.cpp

moc_moudleset.cpp: abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h \
		moudleset.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) moudleset.h -o moc_moudleset.cpp

moc_coorimpl.cpp: abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		coorimpl.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) coorimpl.h -o moc_coorimpl.cpp

moc_ultrasonicandpwm.cpp: moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		ultrasonicandpwm.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) ultrasonicandpwm.h -o moc_ultrasonicandpwm.cpp

moc_login.cpp: WidgetKeyboard.hpp \
		ui_WidgetKeyboard.h \
		login.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) login.h -o moc_login.cpp

moc_WidgetKeyboard.cpp: ui_WidgetKeyboard.h \
		WidgetKeyboard.hpp
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) WidgetKeyboard.hpp -o moc_WidgetKeyboard.cpp

moc_detectusb.cpp: detectusb.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) detectusb.h -o moc_detectusb.cpp

moc_httpreply.cpp: httpreply.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) httpreply.h -o moc_httpreply.cpp

moc_download.cpp: httpreply.h \
		socketclass.h \
		download.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) download.h -o moc_download.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_WidgetKeyboard.h ui_login.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_WidgetKeyboard.h ui_login.h
ui_mainwindow.h: mainwindow.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_WidgetKeyboard.h: WidgetKeyboard.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic WidgetKeyboard.ui -o ui_WidgetKeyboard.h

ui_login.h: login.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic login.ui -o ui_login.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		camerainit.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		serialclass.h \
		clock.h \
		moudleset.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h \
		login.h \
		WidgetKeyboard.hpp \
		ui_WidgetKeyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		camerainit.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		serialclass.h \
		clock.h \
		moudleset.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

posix_qextserialport.o: posix_qextserialport.cpp posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o posix_qextserialport.o posix_qextserialport.cpp

qextserialbase.o: qextserialbase.cpp qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialbase.o qextserialbase.cpp

qextserialport.o: qextserialport.cpp qextserialport.h \
		posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialport.o qextserialport.cpp

serialclass.o: serialclass.cpp serialclass.h \
		posix_qextserialport.h \
		qextserialbase.h \
		serialservice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serialclass.o serialclass.cpp

socketclass.o: socketclass.cpp socketclass.h \
		mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		camerainit.h \
		abstracemoudle.h \
		serialservice.h \
		serialclass.h \
		clock.h \
		moudleset.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o socketclass.o socketclass.cpp

moudle.o: moudle.cpp moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moudle.o moudle.cpp

ledandmotor.o: ledandmotor.cpp ledandmotor.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ledandmotor.o ledandmotor.cpp

temperature.o: temperature.cpp temperature.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temperature.o temperature.cpp

clock.o: clock.cpp clock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o clock.o clock.cpp

replays.o: replays.cpp replays.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o replays.o replays.cpp

camerainit.o: camerainit.cpp camerainit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camerainit.o camerainit.cpp

airirda.o: airirda.cpp airirda.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o airirda.o airirda.cpp

smoke.o: smoke.cpp smoke.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o smoke.o smoke.cpp

moudleset.o: moudleset.cpp moudleset.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h \
		temperature.h \
		moudle.h \
		ledandmotor.h \
		replays.h \
		airirda.h \
		smoke.h \
		serialclass.h \
		posix_qextserialport.h \
		qextserialbase.h \
		ultrasonicandpwm.h \
		curtain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moudleset.o moudleset.cpp

coorimpl.o: coorimpl.cpp coorimpl.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o coorimpl.o coorimpl.cpp

ultrasonicandpwm.o: ultrasonicandpwm.cpp ultrasonicandpwm.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ultrasonicandpwm.o ultrasonicandpwm.cpp

login.o: login.cpp login.h \
		WidgetKeyboard.hpp \
		ui_WidgetKeyboard.h \
		ui_login.h \
		mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		camerainit.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		serialclass.h \
		clock.h \
		moudleset.h \
		coorimpl.h \
		detectusb.h \
		download.h \
		httpreply.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o login.o login.cpp

WidgetKeyboard.o: WidgetKeyboard.cpp WidgetKeyboard.hpp \
		ui_WidgetKeyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o WidgetKeyboard.o WidgetKeyboard.cpp

curtain.o: curtain.cpp curtain.h \
		moudle.h \
		abstracemoudle.h \
		serialservice.h \
		socketclass.h \
		serialclass.h \
		posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o curtain.o curtain.cpp

detectusb.o: detectusb.cpp detectusb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o detectusb.o detectusb.cpp

httpreply.o: httpreply.cpp httpreply.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o httpreply.o httpreply.cpp

download.o: download.cpp download.h \
		httpreply.h \
		socketclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o download.o download.cpp

security.o: security.cpp security.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o security.o security.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_qextserialbase.o: moc_qextserialbase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qextserialbase.o moc_qextserialbase.cpp

moc_qextserialport.o: moc_qextserialport.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qextserialport.o moc_qextserialport.cpp

moc_serialclass.o: moc_serialclass.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serialclass.o moc_serialclass.cpp

moc_socketclass.o: moc_socketclass.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_socketclass.o moc_socketclass.cpp

moc_moudle.o: moc_moudle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_moudle.o moc_moudle.cpp

moc_temperature.o: moc_temperature.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_temperature.o moc_temperature.cpp

moc_clock.o: moc_clock.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_clock.o moc_clock.cpp

moc_replays.o: moc_replays.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_replays.o moc_replays.cpp

moc_moudleset.o: moc_moudleset.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_moudleset.o moc_moudleset.cpp

moc_coorimpl.o: moc_coorimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_coorimpl.o moc_coorimpl.cpp

moc_ultrasonicandpwm.o: moc_ultrasonicandpwm.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ultrasonicandpwm.o moc_ultrasonicandpwm.cpp

moc_login.o: moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_login.o moc_login.cpp

moc_WidgetKeyboard.o: moc_WidgetKeyboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_WidgetKeyboard.o moc_WidgetKeyboard.cpp

moc_detectusb.o: moc_detectusb.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_detectusb.o moc_detectusb.cpp

moc_httpreply.o: moc_httpreply.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_httpreply.o moc_httpreply.cpp

moc_download.o: moc_download.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_download.o moc_download.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

