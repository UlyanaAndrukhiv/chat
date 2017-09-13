TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ClientSocket.cpp \
    ServerSocket.cpp \
    Windows/ClientSocketImpl.cpp \
    Windows/ServerSocketImpl.cpp

HEADERS += \
    ClientSocket.hpp \
    ServerSocket.hpp \
    Windows/ClientSocketImpl.hpp \
    Windows/ServerSocketImpl.hpp
