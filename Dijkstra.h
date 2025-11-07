//
// Created by aryan on 11/6/2025.
//
#include "Graph.h"
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
using namespace std;

struct nodeDist {
    string nodeName;
    double dist;

    bool operator>(const nodeDist &other) const;
};

class Dijkstra {
public:
    static map<string, double> dijkstraShortestPath(const Graph& graph, const string& src);
};



#endif //DIJKSTRA_H