#ifndef BROKER_H
#define BROKER_H

#include <QMap>
#include "Topic.h"

class Broker {
public:
    static Broker& instance() {
        static Broker broker;
        return broker;
    }

    Topic* getOrCreateTopic(const QString& name) {
        if (!topics.contains(name))
            topics[name] = new Topic(name);
        return topics[name];
    }

private:
    QMap<QString, Topic*> topics;
    Broker() {}
};

#endif
