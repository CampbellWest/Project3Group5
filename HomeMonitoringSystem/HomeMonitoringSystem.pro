QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    TylerSource/doorlocks.cpp \
    TylerSource/garagedoor.cpp \
    TylerSource/locks.cpp \
    TylerSource/windows.cpp \
=======
    CampbellSource/AuditLogs.cpp \
>>>>>>> origin/main
    main.cpp \
    mainwindow.cpp \
    CampbellSource/Thermostat.cpp \
    CampbellSource/COMonitor.cpp \
    CampbellSource/SmokeAlarm.cpp \
        #File.cpp
#   CampbellSource/*.cpp \
#    TylerSource/*.cpp \
 \#    AliSource/emptyEx.cpp
    smokealarmalertform.cpp

# When you add new files within your file it will look like
# CampbellSource/filename/*.cpp
# *.cpp just means it includes all .cpp files in that file
# and for every file you add in a file you have to add that layer here again

HEADERS += \
<<<<<<< HEAD
#    TylerHeader/doorlocks.h \
#    TylerHeader/garagedoor.h \
#    TylerHeader/locks.h \
#    TylerHeader/windows.h \
#    TylerSource/locks.h \
=======
    CampbellHeader/AuditLogs.h \
>>>>>>> origin/main
    mainwindow.h \
    CampbellHeader/COMonitor.h \
    CampbellHeader/Thermostat.h \
    CampbellHeader/SmokeAlarm.h \
#    TylerHeader/*.h \
#    AliHeader/*.h \
    smokealarmalertform.h


# CampbellHeader\newFile\*.h \
# CampbellHeader\newFile\newerFile\*.h

#for extra files added in files

FORMS += \
    mainwindow.ui \
    smokealarmalertform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
