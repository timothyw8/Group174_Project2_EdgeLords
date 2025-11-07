//
// Created by Timothy Wang on 11/4/25.
//

#include <vector>
#include <sstream>
#include <random>
#include "Graph.h"

#include <iostream>
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
vector<string> Graph::getCities() const{
    return cities;
}
void Graph::generateRandEdges() {
    for (auto city : cities) {
        int randNum = rand() % 5+3;
        string type = "ground";
        for (int i = 0; i < randNum; i++) {
            int randCity = rand() % 31253;
            double randCost = (double)rand()*1900.0/RAND_MAX+100.0;
            int randDist = rand() % 10000+2400;
            double numHrs = (double)randDist/60.0;
            if (type == "ground") {
                type = "aerial";
            }
            else {
                type = "ground";
            }
            addEdge(city, cities[randCity],type,randCost, numHrs);
        }
    }
}
map<string, vector<Edge>> Graph::getEdges() {
    return edges;
}
void Edge::printEdge() {
    cout<<"To: "<<to<<", Type: "<<type<<", Cost: "<<cost<<", Time: "<<time<<" | ";
}


const map<string, vector<Edge>>& Graph::getAdjList() const {
    return edges;
}
