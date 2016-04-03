#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T09:56:13
#
#-------------------------------------------------

QT       += core gui network

TARGET = Version1_0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    serialclass.cpp \
    socketclass.cpp \
    moudle.cpp \
    ledandmotor.cpp \
    lib_json/json_internalarray.inl \
    lib_json/json_internalmap.inl \
    lib_json/json_reader.cpp \
    lib_json/json_value.cpp \
    lib_json/json_valueiterator.inl \
    lib_json/json_writer.cpp \
    temperature.cpp \
    clock.cpp \
    replays.cpp \
    camerainit.cpp

HEADERS  += mainwindow.h \
    posix_qextserialport.h \
    qextserialbase.h \
    qextserialport.h \
    serialclass.h \
    socketclass.h \
    serialservice.h \
    abstracemoudle.h \
    moudle.h \
    ledandmotor.h \
    lib_json/json_batchallocator.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/reader.h \
    json/value.h \
    json/writer.h \
    temperature.h \
    clock.h \
    replays.h \
    camerainit.h

FORMS    += mainwindow.ui

unix:DEFINES           += _TTY_POSIX_

OTHER_FILES +=
