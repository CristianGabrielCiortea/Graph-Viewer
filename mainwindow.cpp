#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <fstream>

const qreal Pi = 3.14;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFirstNode = false;
    isSelected = false;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::MiddleButton)
    {
        isSelected = false;
    }
    if (ev->button() == Qt::RightButton)
    {
        Node n(ev->position());
        vector<Node> nodes = graph.getNodes();

        if(nodes.empty())
        {
            n.setInfo(graph.getNumberOfNodes() + 1);
            graph.addNode(n);
            update();
            graph.printMatrix();
        }
         // verificare suprapunere noduri
        else
        {
            bool CloseNode = false;
            for(Node& node: nodes)
            {
                if(node.get_distance_between_2_points(ev->position())< 25)
                    {
                        CloseNode = true;
                        break;
                    }
            }
            if (CloseNode == false)
            {
                n.setInfo(graph.getNumberOfNodes() + 1);
                graph.addNode(n);
                update();
                graph.printMatrix();
            }

        }

    }
    else if (ev->button() == Qt::LeftButton && !isSelected)
     {
        vector<Node> nodes = graph.getNodes();
        Node selected;
        bool ok = false;
        for(Node& n: nodes)
        {
            QPointF coord = n.getCoordinate();
            float dist = sqrt((ev->position().x() - coord.x())*(ev->position().x() - coord.x())+
                              (ev->position().y() - coord.y())*(ev->position().y() - coord.y()));

            if (dist <= nodeRadius)
            {
                selected = n;
                ok = true;
                break;
            }
        }

        if (ok)
        {
            if (!isFirstNode)
            {
                firstNode = selected;
                isFirstNode = true;
            }
            else
            {
                //verificare multigraf
                if(firstNode.getCoordinate() != selected.getCoordinate())
                {
                    bool edgeAlreadyExists = false;
                    Edge newEdge(firstNode, selected);
                    vector<Edge> edges = graph.getEdges();
                    for(Edge& edge: edges)
                    {
                        if(newEdge == edge)
                        {
                            edgeAlreadyExists = true;
                            break;
                        }
                    }
                    if(!edgeAlreadyExists)
                    {
                        graph.addEdge(newEdge);
                        isFirstNode= false;
                        update();
                        graph.printMatrix();
                    }
                }
            }
        }
        else
        {
            isFirstNode = false;
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    vector<Node> nodes = graph.getNodes();
    for(Node& n:nodes)
    {
        QPointF coord = n.getCoordinate();
        QRect r(coord.x() - nodeRadius, coord.y()- nodeRadius,
                2*nodeRadius, 2*nodeRadius);
        QPen pen;
        pen.setColor(Qt::black);
        p.setPen(pen);
        p.drawEllipse(r);
        QString num = QString::number(n.getInfo());
        p.drawText(r, Qt::AlignCenter, num);
    }
    vector<Edge> edges = graph.getEdges();
    QPen pen;
    pen.setColor(Qt::red);
    p.setPen(pen);
    for(Edge& e:edges)
    {
        QLineF line = QLineF(e.getFirstNode().getCoordinate(), e.getSecondNode().getCoordinate());
        if(ui->radioButton->isChecked())
       {
            double x3 = e.getSecondNode().getCoordinate().x() + 10 / line.length() * ((e.getFirstNode().getCoordinate().x() - e.getSecondNode().getCoordinate().x())* cos(Pi/4)
                                + (e.getFirstNode().getCoordinate().y() - e.getSecondNode().getCoordinate().y())* sin(Pi/4));
            double y3 = e.getSecondNode().getCoordinate().y() + 10 / line.length() * ((e.getFirstNode().getCoordinate().y() - e.getSecondNode().getCoordinate().y())* cos(Pi/4)
                                - (e.getFirstNode().getCoordinate().x() - e.getSecondNode().getCoordinate().x())* sin(Pi/4));
            double x4 = e.getSecondNode().getCoordinate().x() + 10 / line.length() * ((e.getFirstNode().getCoordinate().x() - e.getSecondNode().getCoordinate().x())* cos(Pi/4)
                                - (e.getFirstNode().getCoordinate().y() - e.getSecondNode().getCoordinate().y())* sin(Pi/4));
            double y4 = e.getSecondNode().getCoordinate().y() + 10 / line.length() * ((e.getFirstNode().getCoordinate().y() - e.getSecondNode().getCoordinate().y())* cos(Pi/4)
                                + (e.getFirstNode().getCoordinate().x() - e.getSecondNode().getCoordinate().x())* sin(Pi/4));
            p.drawLine(QPointF(x3,y3), e.getSecondNode().getCoordinate());
            p.drawLine(QPointF(x4,y4), e.getSecondNode().getCoordinate());
        }
        p.drawLine(line);
        update();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(isSelected)
    {
        graph.moveNode(selectedNodePosition, ev->position());
        update();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::MiddleButton)
    {
        isSelected = true;
    }
    if(isSelected)
    {
        if (ev->button() == Qt::MiddleButton)
        {
            vector<Node> nodes = graph.getNodes();
            for(size_t i = 0; i <= nodes.size(); i++)
            {

               {
                   if(nodes[i].get_distance_between_2_points(ev->position()) < 10)
                    {
                        selectedNodePosition = i;
                        break;
                }
            }
        }
    }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_released()
{

}

