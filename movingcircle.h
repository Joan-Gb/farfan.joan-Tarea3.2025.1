#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QLabel>
#include "Subscriber.h"

namespace Ui {
class MovingCircle;
}

class MovingCircle : public QDialog, public Subscriber
{
    Q_OBJECT

public:
    explicit MovingCircle(const QString& name, const QString& topic, QWidget* parent = nullptr);
    void receive(const QString& msg) override;
    ~MovingCircle();

private slots:
    void newPosition();

private:
    Ui::MovingCircle* ui;
    QGraphicsScene* scene;
    QGraphicsEllipseItem* car;
    QLabel* info;
};

#endif
