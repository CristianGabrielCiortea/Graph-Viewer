#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include <QFlags>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* ev);
    void paintEvent(QPaintEvent* p);
    void mouseMoveEvent(QMouseEvent*ev);
    void mousePressEvent(QMouseEvent *ev);

    ~MainWindow();

private slots:
    void on_radioButton_released();

private:

    Graph graph;
    Ui::MainWindow *ui;
    int selectedNodePosition;
    const int nodeRadius = 10;
    bool isFirstNode;
    Node firstNode;
    bool isSelected;
};
#endif // MAINWINDOW_H
