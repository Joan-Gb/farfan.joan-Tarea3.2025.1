#include "Stage1.h"
#include "VideoPublisher.h"
#include "VideoFollower.h"
#include "GPSCarPublisher.h"
#include "GPSFollower.h"
#include <QHBoxLayout>

Stage1::Stage1(QWidget *parent) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);

    auto* pubVideo = new VideoPublisher("Pub1", "Video", this);
    auto* subVideo = new VideoFollower("Sub1", "Video", this);

    auto* pubGPS = new GPSCarPublisher("PubGPS", "GPS", this);
    layout->addWidget(pubGPS);
    auto* subGPS = new GPSFollower("SubGPS", "GPS");
    layout->addWidget(subGPS);

    layout->addWidget(pubVideo);
    layout->addWidget(subVideo);
}
