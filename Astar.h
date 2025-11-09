//
// Created by Timothy Wang on 11/8/25.
//
#pragma once
#include "Graph.h"
#include <map>
using namespace std;
#ifndef ASTAR_H
#define ASTAR_H

struct nodeDist1 {
    City node;
    double dist;

    bool operator>(const nodeDist1 &other) const;
    // bool operator<(const nodeDist1 &other) const;

};

class Astar {
public:
    map<City, double> astarShortestPath(Graph& graph, City& src, City& dst, vector<City>& result);
};
#endif //ASTAR_H
