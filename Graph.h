//
// Created by Timothy Wang on 11/4/25.
//

#pragma once
#include <map>
using namespace std;

struct City {
    string name;
    double x_coord;
    double y_coord;

    City();
    City(string name, double x_coord, double y_coord);
    void printCity() const;
    bool operator<(const City& other) const;
    bool operator==(const City& other) const;
};

struct Edge {
    City to;
    string type;
    double cost;
    double time;

    Edge();
    Edge(string t, double x, double y, string ty, double co, double ti);
    void printEdge();
};

class Graph {
    map<City, vector<Edge>> edges;
    vector<string> cities;
    map<string, pair<double,double>> coordinates;
public:
    void addEdge(City src, string dst, string type, double cost, double time);
    void addCity(string city, double x_coor, double y_coor);
    vector<string> getCities() const;
    void generateRandEdges();
    map<City, vector<Edge>>& getEdges();
    const map<City, vector<Edge>>& getAdjList();

};