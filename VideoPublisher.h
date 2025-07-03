#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include "Publisher.h"

class VideoPublisher : public QWidget, public Publisher {
    Q_OBJECT

public:
    VideoPublisher(const QString& name, const QString& topic, QWidget* parent = nullptr)
        : QWidget(parent), Publisher(name, topic) {
        input = new QLineEdit(static_cast<QWidget*>(this));
        layout = new QVBoxLayout(static_cast<QWidget*>(this));
        layout->addWidget(input);

        connect(input, &QLineEdit::returnPressed, this, &VideoPublisher::onEnter);
    }

private slots:
    void onEnter() {
        QString url = input->text();
        if (!url.isEmpty()) {
            publish(url);
            input->clear();
        }
    }

private:
    QLineEdit* input;
    QVBoxLayout* layout;
};

#endif
