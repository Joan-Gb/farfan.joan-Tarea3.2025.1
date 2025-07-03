#ifndef TOPIC_H
#define TOPIC_H

#include <QString>
#include <QList>

class Subscriber;

class Topic {
public:
    explicit Topic(const QString& name);

    void subscribe(Subscriber* sub);
    void publish(const QString& msg);

    QString getName() const;

private:
    QString name;
    QList<Subscriber*> subs;
};

#endif
