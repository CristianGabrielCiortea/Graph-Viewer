#include "graph.h"

Graph::Graph()
{

}


void Graph::printMatrix()
{
        ofstream fout;
        fout.open("matricea_de_adiacenta.txt");
        if(!fout)
        {
            throw("Fisierul nu s-a deschis!!");
        }
        vector<vector<int>> adiacentMatrix(nodes.size(), vector<int>(nodes.size()));
        for(int i = 0; i < edges.size(); i++)
        {
            adiacentMatrix[edges[i].getFirstNode().getInfo()-1][edges[i].getSecondNode().getInfo()- 1] = 1;
            adiacentMatrix[edges[i].getSecondNode().getInfo()-1][edges[i].getFirstNode().getInfo()- 1] = 1;
        }
        fout << nodes.size() << "\n";
        for(int i = 0; i < nodes.size(); i++)
        {
            for(int j = 0; j < nodes.size(); j++)
            {
                fout << adiacentMatrix[i][j] << " ";
            }
            fout << "\n";
        }

        fout.close();
}

void Graph::moveNode(int selectedNodePosition, QPointF newPosition)
{
    nodes[selectedNodePosition].setCoordinate(newPosition);
    for(size_t i = 0; i < edges.size(); i++)
    {
        if(edges[i].getFirstNode().getInfo() == nodes[selectedNodePosition].getInfo())
        {
            edges[i].setFirstNode(newPosition);
        }
        if(edges[i].getSecondNode().getInfo() == nodes[selectedNodePosition].getInfo())
        {
             edges[i].setSecondNode(newPosition);
        }
    }
}
