#include "node.h"

Node::Node(int inf)
{
    info = inf;

}

Node::Node(QPointF cood, int inf)
{
    coord = cood;
    info = inf;
}

double Node::get_distance_between_2_points(Node node2)
{
    return sqrt((node2.coord.x() - coord.x())*(node2.coord.x() - coord.x())+
                (node2.coord.y() - coord.y())*(node2.coord.y() - coord.y()));
}

void Node::setCoordinate(QPointF newCoordinate)
{
    coord.setX(newCoordinate.x());
    coord.setY(newCoordinate.y());

}




