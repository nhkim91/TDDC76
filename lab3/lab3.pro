TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

SOURCES += \
    Calculator.cc \
    Expression.cc \
    Expression_Tree.cc \
    expression_tree_test.cc \
    expression-test.cc \
    kalkylator.cc \
    test.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Calculator.h \
    Expression.h \
    Expression_Tree.h

