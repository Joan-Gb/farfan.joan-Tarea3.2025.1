#include "Topic.h"
#include "Subscriber.h"

Topic::Topic(const QString& name) : name(name) {}

void Topic::subscribe(Subscriber* sub) {
    subs.append(sub);
}

void Topic::publish(const QString& msg) {
    for (Subscriber* s : subs)
        s->receive(msg);
}

QString Topic::getName() const { return name; }
