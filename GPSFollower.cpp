#include "GPSFollower.h"

GPSFollower::GPSFollower(const QString& name,
                         const QString& topic,
                         QWidget* parent)
    : QWidget(parent), Subscriber(name, topic) {

    label = new QLabel("Esperando posición...", this);
    label->setAlignment(Qt::AlignCenter);

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(label);

    setWindowTitle("GPSFollower: " + topic);
    resize(300, 100);
    show();
}

void GPSFollower::receive(const QString& msg) {
    label->setText("Posición recibida: " + msg);
}
