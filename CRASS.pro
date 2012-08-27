#-------------------------------------------------
#
# Project created by QtCreator 2012-08-09T20:54:18
#
#-------------------------------------------------

QT       += core gui

TARGET = CRASS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objects/cocinvestigator.cpp \
    objects/investigator.cpp \
    objects/cocgaslightinvestigator.cpp \
    objects/diceroller.cpp \
    objects/coc6e1920investigator.cpp

HEADERS  += mainwindow.h \
    objects/cocinvestigator.h \
    objects/investigator.h \
    objects/cocgaslightinvestigator.h \
    objects/diceroller.h \
    objects/coc6e1920investigator.h

FORMS    += mainwindow.ui

mac {
    # Only Intel binaries are accepted so force this
    #CONFIG += x86

    # Minimum OS X version for submission is 10.6.6
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

    # Copy the custom Info.plist to the app bundle
    plist.path = "$$DESTDIR/$$join(TARGET,,,.app)/Contents"
    plist.files = Info.plist
    INSTALLS += plist

    # Icon is mandatory for submission
    #ICON = appicon.icns
}

OTHER_FILES += \
    resources/6e1920skills.dat

