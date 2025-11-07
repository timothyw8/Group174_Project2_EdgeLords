//
// Created by aryan on 11/6/2025.
//
#pragma once
#include "Graph.h"
#include <map>
#include <string>
using namespace std;


#ifndef BELLMANFORD_H
#define BELLMANFORD_H


class BellmanFord {
public:
    static map<string, double> bellmanShortestPath(const Graph& graph, const string& src);
};


#endif //BELLMANFORD_H
