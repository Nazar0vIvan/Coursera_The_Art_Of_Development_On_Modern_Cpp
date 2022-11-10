QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        condition_parser.cpp \
        condition_parser_test.cpp \
        database.cpp \
        database_test.cpp \
        date.cpp \
        date_test.cpp \
        event_set.cpp \
        main.cpp \
        node.cpp \
        node_test.cpp \
        token.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    condition_parser.h \
    database.h \
    date.h \
    event_set.h \
    node.h \
    test_runner.h \
    token.h
