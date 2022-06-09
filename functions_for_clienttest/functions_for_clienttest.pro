QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_solve_tasks.cpp \
    ../client/solver.cpp

HEADERS += \
    ../client/solver.h
