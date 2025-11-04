//
// Created by Timothy Wang on 11/4/25.
//

#include <vector>
#include <sstream>
#include "Graph.h"
using namespace std;

Edge::Edge() {
    to = "";
    type = "";
    cost = 0.0;
    time = 0.0;
};

Edge::Edge(string t, string ty, double co, double ti) {
    to = t;
    type = ty;
    cost = co;
    time = ti;
};

void Graph::addEdge(string src, string dst, string type, double cost, double time) {
    edges[src].push_back(Edge(dst, type, cost, time));
}
void Graph::addCity(string city) {
    cities.push_back(city);
}
vector<string> Graph::getCities() {
    return cities;
}