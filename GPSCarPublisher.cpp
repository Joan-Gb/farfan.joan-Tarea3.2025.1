#include "GPSCarPublisher.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>

GPSCarPublisher::GPSCarPublisher(const QString& name, const QString& topic, QWidget* parent)
    : QWidget(parent), Publisher(name, topic)
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "Selecciona archivo GPS",
        "",
        "Archivos de texto (*.txt)"
        );

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() != 3) continue;
        int t = parts[0].toInt();
        float x = parts[1].toFloat();
        float y = parts[2].toFloat();
        positions.append({t, QPointF(x, y)});
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GPSCarPublisher::tick);
    timer->start(1000);
}

void GPSCarPublisher::tick()
{
    if (currentIndex >= positions.size()) {
        timer->stop();
        return;
    }

    int time = positions[currentIndex].first;
    QPointF pos = positions[currentIndex].second;
    QString msg = QString("%1 %2 %3").arg(time).arg(pos.x()).arg(pos.y());
    publish(msg);
    currentIndex++;
}
