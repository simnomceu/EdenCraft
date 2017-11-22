TEMPLATE = app

QT += core gui widgets

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ../include/editor

SOURCES += ../src/editor/main.cpp \
    ../src/editor/main_window.cpp \
    ../src/editor/attribute_tab.cpp

DESTDIR = bin/qt/

FORMS += ../src/editor/main_window.ui

HEADERS += \
    ../include/editor/main_window.hpp \
    ../include/editor/attribute_tab.hpp
