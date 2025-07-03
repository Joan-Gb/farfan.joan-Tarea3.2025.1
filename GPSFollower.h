#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H

#include "Subscriber.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class GPSFollower : public QWidget, public Subscriber {
    Q_OBJECT
public:
    GPSFollower(const QString& name,
                const QString& topic,
                QWidget* parent = nullptr);

    void receive(const QString& msg) override;
    QString getName() const override { return name; }

private:
    QLabel* label;
};

#endif
