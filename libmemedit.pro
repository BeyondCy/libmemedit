TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    libmemedit.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    libmemedit.h \
    platform/windows/memedit_scan.h \
    platform/linux/memedit_scan.h

