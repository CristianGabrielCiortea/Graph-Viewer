#include "edge.h"

Edge::Edge()
{

}

void Edge::setFirstNode(QPointF newPosition)
{
    firstNode.setCoordinate(newPosition);
}

void Edge::setSecondNode(QPointF newPosition)
{
    secondNode.setCoordinate(newPosition);
}

bool Edge::operator == (const Edge& edge)
{
    return firstNode.getCoordinate() == edge.getFirstNode().getCoordinate() && secondNode.getCoordinate() == edge.getSecondNode().getCoordinate();
}
