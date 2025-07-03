#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QPair>
#include <QPointF>
#include "Publisher.h"

class GPSCarPublisher : public QWidget, public Publisher {
    Q_OBJECT

public:
    GPSCarPublisher(const QString& name,
                    const QString& topic,
                    QWidget* parent = nullptr);

private slots:
    void tick();

private:
    QTimer* timer;
    QList<std::pair<int, QPointF>> positions;
    int currentSecond = 0;
    int currentIndex = 0;
    int maxSecond = 0;
};

#endif
