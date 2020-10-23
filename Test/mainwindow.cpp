#include <QPalette>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->installEventFilter(ui->graphicsView);
    ui->graphicsView->setMouseTracking(true);
    connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
    QBrush whiteBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    for(int y = 0; y < ui->graphicsView->width() - 5; y += 32){
        for(int x = 0; x < ui->graphicsView->width() - 5; x += 32){
            rectangle = scene->addRect(x, y, 32, 32, outlinePen, whiteBrush);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
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
            if(!(clicked.isNull())){
                rectangle = scene->addRect(clicked.x() * 32, clicked.y() * 32, 32, 32, outlinePen, personalBrush);
            }
        }
    }else if(event->button() == Qt::RightButton){
        if(checkPosInGraphicsView(&pt)){
            clicked = checkInnerRect(&pt);
            rectangle = scene->addRect(clicked.x() * 32, clicked.y() * 32, 32, 32, outlinePen, whiteBrush);
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
    QPoint clicked;
    int countX, countY = 0;
    for(int y = 0; y < ui->graphicsView->height() - 5 + 32; y += 32){
        countX = 0;
        for(int x = 0; x < ui->graphicsView->width() - 5; x += 32){
            if(point->x() > x && point->x() < x + 32 && point->y() > y && point->y() < y + 32){
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
