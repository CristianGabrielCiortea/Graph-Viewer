#ifndef NODE_H
#define NODE_H

#include <QPoint>
class Node
{
    int info;
    QPointF coord;
public:
    Node(int inf = -1);
    Node(QPointF cood, int inf = -1);
    void setInfo(int inf){info = inf;}
    QPointF getCoordinate(){return coord;}
    int getInfo(){return info;}
    //functie pentru distanta dintre 2 noduri
    double get_distance_between_2_points(Node node2);
    void setCoordinate(QPointF newCoordinate);

};

#endif // NODE_H
