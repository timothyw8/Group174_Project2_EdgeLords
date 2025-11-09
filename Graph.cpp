//
// Created by Timothy Wang on 11/4/25.
//

#include <vector>
#include <sstream>
#include <random>
#include "Graph.h"

#include <iostream>
using namespace std;

City::City() {
    name = "";
    x_coord = 0;
    y_coord = 0;
};

City::City(string nam, double x_coor, double y_coor) {
    name = nam;
    x_coord = x_coor;
    y_coord = y_coor;
}

Edge::Edge() {
    to = City();
    type = "";
    cost = 0.0;
    time = 0.0;
};

Edge::Edge(string t, double x, double y, string ty, double co, double ti) {
    to = City(t,x,y);
    type = ty;
    cost = co;
    time = ti;
};

void Graph::addEdge(City src, string dst, string type, double cost, double time) {
    edges[src].push_back(Edge(dst,coordinates[src.name].first, coordinates[src.name].second, type, cost, time));
}
void Graph::addCity(string city, double x_coor, double y_coor) {
    cities.push_back(city);
    coordinates[city] = {x_coor,y_coor};
}
vector<string> Graph::getCities() const{
    return cities;
}
void Graph::generateRandEdges() {
    for (auto city : cities) {
        int randNum = rand() % 5+3;
        string type = "ground";
        for (int i = 0; i < randNum; i++) {
            int randCity = rand() % cities.size();
            double randCost = (double)rand()*1900.0/RAND_MAX+100.0;
            int randDist = rand() % 10000+2400;
            double numHrs = (double)randDist/60.0;
            if (type == "ground") {
                type = "aerial";
            }
            else {
                type = "ground";
            }
            addEdge(City(city,coordinates[city].first,coordinates[city].second), cities[randCity],type,randCost, numHrs);
        }
    }
}
map<City, vector<Edge>>& Graph::getEdges() {
    return edges;
}
bool City::operator==(const City& other) const {
    return name == other.name;
}
bool City::operator<(const City& other) const {
    return name < other.name;
}

void Edge::printEdge() {
    cout<<"To: "<<to.name<<", Type: "<<type<<", Cost: "<<cost<<", Time: "<<time<<" | ";
}
void City::printCity() const{
    cout<<"Name: "<<name<<"X: "<<x_coord<<"Y: "<<y_coord<<" ";
}



const map<City, vector<Edge>>& Graph::getAdjList() {
    return edges;
}
