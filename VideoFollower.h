#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include "Subscriber.h"

class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT

public:
    VideoFollower(const QString& name,
                  const QString& topic,
                  QWidget* parent = nullptr);

    /* —– Subscriber —– */
    void receive(const QString& msg) override;
    QString getName() const override { return name; }

private slots:
    void playVideo();

private:
    QString     lastUrl;
    QPushButton *button;
    QVBoxLayout *layout;
};

#endif
