TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

SOURCES += \
    lab2.cc \
    monetary.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    monetary.h

