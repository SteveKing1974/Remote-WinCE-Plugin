QT += network

include(../../qtcreatorplugin.pri)

HEADERS += \
    winceplugin.h \
    wincedevice.h \
    wincedeviceconfigurationfactory.h \
    wincedeviceconfigurationwizard.h \
    wincedeviceconfigurationwizardpages.h \
 #   wincedeployconfiguration.h \
    wincedeployconfigurationfactory.h

SOURCES += \
    winceplugin.cpp \
    wincedevice.cpp \
    wincedeviceconfigurationfactory.cpp \
    wincedeviceconfigurationwizard.cpp \
    wincedeviceconfigurationwizardpages.cpp \
#    wincedeployconfiguration.cpp \
    wincedeployconfigurationfactory.cpp

FORMS += \
    winceconfigurationwizardsetuppage.ui

RESOURCES += remotewince.qrc

DEFINES += REMOTEWINCE_LIBRARY
