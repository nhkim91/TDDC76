TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

SOURCES += \
    ../Variable_Table.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../Variable_Table.h

