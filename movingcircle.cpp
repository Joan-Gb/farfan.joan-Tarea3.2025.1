#include "movingcircle.h"
#include "ui_movingcircle.h"
#include <QInputDialog>
#include <QBrush>

MovingCircle::MovingCircle(const QString& name, const QString& topic, QWidget* parent) :
    QDialog(parent), Subscriber(name, topic),
    ui(new Ui::MovingCircle)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 400, 300);

    ui->graphicsView->setScene(scene);

    car = new QGraphicsEllipseItem(0, 0, 30, 30);
    car->setBrush(QBrush(Qt::red));
    scene->addItem(car);

    connect(ui->newPositionButton, &QPushButton::clicked, this, &MovingCircle::newPosition);

    info = new QLabel(this);
    ui->verticalLayout->addWidget(info);
    info->setText("Tiempo: -  X: -  Y: -");
}

MovingCircle::~MovingCircle()
{
    delete ui;
    delete car;
    delete scene;
}

void MovingCircle::receive(const QString& msg) {
    QStringList p = msg.split(' ');
    if (p.size() != 3) return;

    int t = p[0].toInt();
    float x = p[1].toFloat();
    float y = p[2].toFloat();

    QPointF pos(x, y);
    car->setPos(pos);

    QRectF carBounds = car->boundingRect().translated(pos);
    if (!scene->sceneRect().contains(carBounds)) {
        QRectF expanded = scene->sceneRect().united(carBounds.adjusted(-20, -20, 20, 20));
        scene->setSceneRect(expanded);
    }

    info->setText(QString("t=%1  x=%2  y=%3").arg(t).arg(x).arg(y));
}

void MovingCircle::newPosition()
{
    bool ok;
    int deltax = 20, deltay = 30;

    QString text = QInputDialog::getText(this, "Enter car's new position", "Delta x movement:", QLineEdit::Normal, "20", &ok);
    if (ok && !text.isEmpty()) deltax = text.toInt();

    text = QInputDialog::getText(this, "Enter car's new position", "Delta y movement:", QLineEdit::Normal, "30", &ok);
    if (ok && !text.isEmpty()) deltay = text.toInt();

    car->moveBy(deltax, deltay);
}
