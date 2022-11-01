#ifndef EDGE_H
#define EDGE_H
#include "node.h"
#include "qpolygon.h"

class Edge
{
    Node firstNode, secondNode;
    QPolygonF arrowHead;
public:
    Edge();
    Edge(Node fN, Node sN){
        firstNode = fN;
        secondNode = sN;
    }
    Node getFirstNode() const{return firstNode;}
    Node getSecondNode() const{return secondNode;}
    void setFirstNode(QPointF newPosition);
    void setSecondNode(QPointF newPosition);

    bool operator == (const Edge& edge);

};

#endif // EDGE_H
