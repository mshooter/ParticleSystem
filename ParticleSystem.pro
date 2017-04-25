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

SOURCES += main.cpp \
    displaywindow.cpp \
    particle.cpp \
    emitter.cpp

macx: {
  DEFINES+=MAC_OS_X_VERSION_MIN_REQUIRED=1060
  QMAKE_LFLAGS += -F/Library/Frameworks
  LIBS+= -framework OpenGL
  LIBS += -framework SDL2
  INCLUDEPATH += /Library/Frameworks/SLD2_image.framework
  INCLUDEPATH += /usr/local/include
  INCLUDEPATH += /usr/local/Cellar
  INCLUDEPATH += /usr/local/lib
}
CONFIG += console
CONFIG -= app_bundle
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    displaywindow.h \
    particle.h \
    emitter.h
