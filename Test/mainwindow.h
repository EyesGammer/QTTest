#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QColor color() const
    {
        return m_color;
    }
    bool checkPosInGraphicsView(QPoint *point);
    QPoint checkInnerRect(QPoint *point);

signals:
    void colorChanged(QColor arg);

private slots:
    void onColorChanged();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QColor m_color;
};
#endif // MAINWINDOW_H
