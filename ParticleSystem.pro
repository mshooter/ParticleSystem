QT += core
QT -= gui
# qt 5 wants this may cause errors with 4
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += core
QT +=opengl
CONFIG += c++11

TARGET = ParticleSystem
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += include
LIBS+=$$system(sdl2-config --libs)
QMAKE_CXXFLAGS += -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64

macx: {
  DEFINES+=MAC_OS_X_VERSION_MIN_REQUIRED=1060
  QMAKE_LFLAGS += -F/Library/Frameworks
  LIBS+= -framework OpenGL
  LIBS += -framework SDL2
  INCLUDEPATH += /usr/local/include
  INCLUDEPATH += /usr/local/Cellar
  INCLUDEPATH += /usr/local/lib
}
linux-g++:linux-g++-64{
    LIBS+= -lGLEW
}
linux-clang{
    LIBS+= -lGLEW
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Camera.cpp \
    Displaywindow.cpp \
    Emitter.cpp \
    Fire.cpp \
    Main.cpp \
    Particle.cpp \
    Timer.cpp \
    Snow.cpp \
    WaterFall.cpp


HEADERS += \
    Camera.h \
    Displaywindow.h \
    Emitter.h \
    Fire.h \
    Particle.h \
    Timer.h \
    Snow.h \
    WaterFall.h



