//
// Created by aryan on 11/6/2025.
//
#include "Graph.h"
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
using namespace std;

struct nodeDist {
    City node;
    double dist;

    bool operator>(const nodeDist &other) const;
};

class Dijkstra {
public:
    static map<City, double> dijkstraShortestPath(Graph& graph, const City& src);
};



#endif //DIJKSTRA_H