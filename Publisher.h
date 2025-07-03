#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Component.h"
class Topic;
#include "Broker.h"

class Publisher : public Component {
public:
    Publisher(const QString& name, const QString& topic)
        : name(name), topic(Broker::instance().getOrCreateTopic(topic)) {}

    void publish(const QString& msg) {
        topic->publish(msg);
    }

    QString getName() const override { return name; }

protected:
    QString name;
    Topic* topic;
};

#endif
