#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Component.h"
#include "Broker.h"
class Topic;

class Subscriber : public Component {
public:
    Subscriber(const QString& name, const QString& topic)
        : name(name), topic(Broker::instance().getOrCreateTopic(topic)) {
        this->topic->subscribe(this);
    }

    virtual void receive(const QString& msg) = 0;

    QString getName() const override { return name; }

protected:
    QString name;
    Topic* topic;
};

#endif
