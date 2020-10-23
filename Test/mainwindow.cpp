#include <QDebug>

#include <QPalette>
#include <QGraphicsSceneMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    sizeX = 100;
    sizeY = 100;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setMouseTracking(false);
    connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
    QBrush whiteBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    for(int y = 0; y < ui->graphicsView->height() - (int)(ui->graphicsView->height() % sizeY); y += (int)(ui->graphicsView->height() / sizeY)){
        for(int x = 0; x < ui->graphicsView->width() - (int)(ui->graphicsView->height() % sizeY); x += (int)(ui->graphicsView->width() / sizeX)){
            rectangle = scene->addRect(x, y, (int)(ui->graphicsView->width() / sizeX), (int)(ui->graphicsView->height() / sizeY), outlinePen, whiteBrush);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == scene){
        QGraphicsSceneMouseEvent *mouseSceneEvent;
        if(event->type() == QEvent::GraphicsSceneMouseMove){
            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
            QPoint clicked;
            QPoint pt = {(int)mouseSceneEvent->scenePos().x(), (int)mouseSceneEvent->scenePos().y()};
            QBrush whiteBrush(Qt::white);
            QBrush personalBrush(m_color);
            QPen outlinePen(Qt::black);
            outlinePen.setWidth(1);
            if(mouseSceneEvent->buttons() == Qt::LeftButton){
                if(checkPosInGraphicsView(&pt)){
                    clicked = checkInnerRect(&pt);
                    if(!(clicked == (QPoint){-1, -1})){
                        rectangle = scene->addRect(clicked.x() * (int)(ui->graphicsView->width() / sizeX), clicked.y() * (int)(ui->graphicsView->height() / sizeY), (int)(ui->graphicsView->width() / sizeX), (int)(ui->graphicsView->height() / sizeY), outlinePen, personalBrush);
                    }
                }
            }else if(mouseSceneEvent->buttons() == Qt::RightButton){
                if(checkPosInGraphicsView(&pt)){
                    clicked = checkInnerRect(&pt);
                    rectangle = scene->addRect(clicked.x() * (int)(ui->graphicsView->width() / sizeX), clicked.y() * (int)(ui->graphicsView->height() / sizeY), (int)(ui->graphicsView->width() / sizeX), (int)(ui->graphicsView->height() / sizeY), outlinePen, whiteBrush);
                }
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint clicked;
    QPoint pt = event->pos();
    QBrush whiteBrush(Qt::white);
    QBrush personalBrush(m_color);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    if(event->button() == Qt::LeftButton){
        if(checkPosInGraphicsView(&pt)){
            clicked = checkInnerRect(&pt);
            if(!(clicked == (QPoint){-1, -1})){
                rectangle = scene->addRect(clicked.x() * (int)(ui->graphicsView->width() / sizeX), clicked.y() * (int)(ui->graphicsView->height() / sizeY), (int)(ui->graphicsView->width() / sizeX), (int)(ui->graphicsView->height() / sizeY), outlinePen, personalBrush);
            }
        }
    }else if(event->button() == Qt::RightButton){
        if(checkPosInGraphicsView(&pt)){
            clicked = checkInnerRect(&pt);
            rectangle = scene->addRect(clicked.x() * (int)(ui->graphicsView->width() / sizeX), clicked.y() * (int)(ui->graphicsView->height() / sizeY), (int)(ui->graphicsView->width() / sizeX), (int)(ui->graphicsView->height() / sizeY), outlinePen, whiteBrush);
        }
    }
}

bool MainWindow::checkPosInGraphicsView(QPoint *point)
{
    QPoint graphicPos = ui->graphicsView->pos();
    if(point->x() > graphicPos.x() && point->x() < graphicPos.x() + ui->graphicsView->width() && point->y() > graphicPos.y() && point->y() < graphicPos.y() + ui->graphicsView->height()){
        return 1;
    }
    return 0;
}

QPoint MainWindow::checkInnerRect(QPoint *point)
{
    QPoint clicked = {-1, -1};
    int countX, countY = 0;
    for(int y = 0; y < ui->graphicsView->height() - (int)(ui->graphicsView->height() % sizeY); y += (int)(ui->graphicsView->height() / sizeY)){
        countX = 0;
        for(int x = 0; x < ui->graphicsView->width() - (int)(ui->graphicsView->height() % sizeY); x += (int)(ui->graphicsView->width() / sizeX)){
            if(point->x() > x && point->x() < x + (int)(ui->graphicsView->width() / sizeX) && point->y() > y && point->y() < y + (int)(ui->graphicsView->height() / sizeY)){
                clicked = {countX, countY};
            }
            countX++;
        }
        countY++;
    }
    return clicked;
}

void MainWindow::onColorChanged()
{
    m_color.setRgb(ui->redSlider->value(), ui->blueSlider->value(), ui->greenSlider->value());
    QPalette pal = ui->displayWidget->palette();
    pal.setColor(QPalette::Window, m_color);
    ui->displayWidget->setPalette(pal);
    emit colorChanged(m_color);
}
