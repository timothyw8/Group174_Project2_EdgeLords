//
// Created by Timothy Wang on 11/4/25.
//

#pragma once
#include <map>
using namespace std;

struct Edge {
    string to;
    string type;
    double cost;
    double time;

    Edge();
    Edge(string t, string ty, double co, double ti);
};

class Graph {
    map<string, vector<Edge>> edges;
    vector<string> cities;
public:
    void addEdge(string src, string dst, string type, double cost, double time);
    void addCity(string city);
    vector<string> getCities() const;
    const map<string, vector<Edge>>& getAdjList() const;

};