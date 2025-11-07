#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Graph.h"
#include <set>
using namespace std;

int main() {

    ifstream file("uscities.csv");
    if (!file.is_open()) {
        cout<<"File could not be opened"<<endl;
        return 1;
    }

    Graph temp;
    string line;
    getline(file,line);
    set<string> cities_set;
    while (getline(file, line)) {
        stringstream ss(line);
        string city;
        if (getline(ss,city,',')) {
            cities_set.insert(city);
        }
    }
    for (auto city: cities_set) {
        temp.addCity(city);
    }
    temp.generateRandEdges();
    map<string, vector<Edge>> edges = temp.getEdges();
    for (auto city: edges) {
        cout<<city.first<<" = ";
        for (auto edge: city.second) {
            edge.printEdge();
        }
        cout<<endl;
    }

    cout<<cities_set.size()<<endl;


    return 0;
}