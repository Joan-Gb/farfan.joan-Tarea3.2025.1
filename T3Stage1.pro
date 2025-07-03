QT += core gui widgets multimedia multimediawidgets
CONFIG += c++17

FORMS += movingcircle.ui


SOURCES += main.cpp \
    GPSCarPublisher.cpp \
    GPSFollower.cpp \
    Stage1.cpp \
    Topic.cpp \
    VideoFollower.cpp \
    movingcircle.cpp


HEADERS += Component.h \
    GPSCarPublisher.h \
    GPSFollower.h \
    Topic.h Broker.h \
    Publisher.h Subscriber.h \
    Stage1.h \
    VideoPublisher.h VideoFollower.h \
    movingcircle.h
