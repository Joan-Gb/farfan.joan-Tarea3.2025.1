#include "VideoFollower.h"
#include <QUrl>

VideoFollower::VideoFollower(const QString& name,
                             const QString& topic,
                             QWidget* parent)
    : QWidget(parent), Subscriber(name, topic) {

    button = new QPushButton(QStringLiteral("Esperando URL…"), this);
    layout = new QVBoxLayout(this);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &VideoFollower::playVideo);
}

void VideoFollower::receive(const QString& msg) {
    lastUrl = msg.trimmed();
    button->setText(lastUrl);
}

void VideoFollower::playVideo() {
    if (lastUrl.isEmpty()) return;

    auto* playerWnd   = new QWidget;
    auto* videoWidget = new QVideoWidget(playerWnd);
    auto* player      = new QMediaPlayer(playerWnd);
    auto* audio       = new QAudioOutput(playerWnd);

    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audio);

    player->setSource(QUrl::fromUserInput(lastUrl));
    audio->setVolume(0.8);

    auto* vlayout = new QVBoxLayout(playerWnd);
    vlayout->addWidget(videoWidget);

    playerWnd->resize(800, 600);
    playerWnd->setWindowTitle(lastUrl);
    playerWnd->show();

    player->play();
}
