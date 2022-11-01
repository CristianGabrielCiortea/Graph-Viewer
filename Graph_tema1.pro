QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp

HEADERS += \
    C:/Users/ciort/Downloads/New folder/edge.h \
    C:/Users/ciort/Downloads/New folder/edge.h \
    C:/Users/ciort/Downloads/New folder/graph.h \
    C:/Users/ciort/Downloads/New folder/graph.h \
    C:/Users/ciort/Downloads/New folder/mainwindow.h \
    C:/Users/ciort/Downloads/New folder/mainwindow.h \
    C:/Users/ciort/Downloads/New folder/node.h \
    C:/Users/ciort/Downloads/New folder/node.h \
    edge.h \
    graph.h \
    mainwindow.h \
    node.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-Graph_tema1-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/matricea_de_adiacenta.txt
