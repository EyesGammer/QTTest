/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QSlider *blueSlider;
    QSlider *redSlider;
    QSlider *greenSlider;
    QSpinBox *redSpin;
    QSpinBox *greenSpin;
    QSpinBox *redSpin_2;
    QWidget *displayWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(759, 545);
        MainWindow->setMinimumSize(QSize(759, 545));
        MainWindow->setMaximumSize(QSize(759, 545));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 517, 517));
        blueSlider = new QSlider(centralwidget);
        blueSlider->setObjectName(QString::fromUtf8("blueSlider"));
        blueSlider->setGeometry(QRect(530, 20, 160, 20));
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Horizontal);
        redSlider = new QSlider(centralwidget);
        redSlider->setObjectName(QString::fromUtf8("redSlider"));
        redSlider->setGeometry(QRect(530, 90, 160, 20));
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Horizontal);
        greenSlider = new QSlider(centralwidget);
        greenSlider->setObjectName(QString::fromUtf8("greenSlider"));
        greenSlider->setGeometry(QRect(530, 160, 160, 20));
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Horizontal);
        redSpin = new QSpinBox(centralwidget);
        redSpin->setObjectName(QString::fromUtf8("redSpin"));
        redSpin->setGeometry(QRect(700, 20, 52, 32));
        redSpin->setMaximum(255);
        greenSpin = new QSpinBox(centralwidget);
        greenSpin->setObjectName(QString::fromUtf8("greenSpin"));
        greenSpin->setGeometry(QRect(700, 160, 52, 32));
        greenSpin->setMaximum(255);
        redSpin_2 = new QSpinBox(centralwidget);
        redSpin_2->setObjectName(QString::fromUtf8("redSpin_2"));
        redSpin_2->setGeometry(QRect(700, 90, 52, 32));
        redSpin_2->setMaximum(255);
        displayWidget = new QWidget(centralwidget);
        displayWidget->setObjectName(QString::fromUtf8("displayWidget"));
        displayWidget->setGeometry(QRect(530, 210, 221, 111));
        displayWidget->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(blueSlider, SIGNAL(valueChanged(int)), redSpin, SLOT(setValue(int)));
        QObject::connect(redSpin, SIGNAL(valueChanged(int)), blueSlider, SLOT(setValue(int)));
        QObject::connect(redSlider, SIGNAL(valueChanged(int)), redSpin_2, SLOT(setValue(int)));
        QObject::connect(redSpin_2, SIGNAL(valueChanged(int)), redSlider, SLOT(setValue(int)));
        QObject::connect(greenSlider, SIGNAL(valueChanged(int)), greenSpin, SLOT(setValue(int)));
        QObject::connect(greenSpin, SIGNAL(valueChanged(int)), greenSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
