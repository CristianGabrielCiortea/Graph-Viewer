#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <vector>
#include <fstream>

using namespace std;
class Graph
{
    vector<Node> nodes;
    vector<Edge> edges;
public:
    Graph();
    void addNode(Node n) {nodes.push_back(n);}
    void addEdge(Edge a) {edges.push_back(a);}
    int getNumberOfNodes(){return (int)nodes.size();}
    vector<Node> getNodes(){return nodes;}
    vector<Edge> getEdges(){return edges;}
    void printMatrix();
    void moveNode(int selectedNodePosition, QPointF newPosition);

};

#endif // GRAPH_H
