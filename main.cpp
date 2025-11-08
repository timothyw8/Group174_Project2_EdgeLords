#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Dijkstra.h"
#include "Astar.h"
#include "Graph.h"
#include <set>
#include "gui.h"

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
        vector<string> entireLine;
        while (getline(ss,city,',')) {
            if (city.front()=='"' && city.back()=='"') {
                city = city.substr(1, city.length()-2);
            }
            entireLine.push_back(city);
        }
        if (entireLine.size()<8) {
            cout<<"error, less than 8"<<endl;
            continue;
        }
        string cityName = entireLine[0];
        string lat = entireLine[6];
        string lng = entireLine[7];
        if (cityName.empty() || lat.empty() || lng.empty()) {
            cout<<"Invalid input"<<line<<endl;
            continue;
        }
        if (cities_set.find(cityName)!=cities_set.end()) {
            continue;
        }
        try {
            temp.addCity(entireLine[0], stod(entireLine[6]),stod(entireLine[7]));
        }
        catch (const invalid_argument&) {
            continue;
            cout<<"Invalid number of parts"<<endl;
        }
    }

    temp.generateRandEdges();
    map<City, vector<Edge>> edges = temp.getEdges();
    // for (auto city: edges) {
    //     city.first.printCity();
    //     for (auto edge: city.second) {
    //         edge.printEdge();
    //     }
    //     cout<<endl;
    // }
    // cout<<temp.getEdges().size();
    vector<string> cities = temp.getCities();
    // // startGUI(cities);
    Dijkstra dij;
    map<City, double> dijResult;
    string src, dest;

    cout<<"Please enter the source: ";
    cin>>src;
    cout<<src<<": "<<endl;
    City srcObj;
    for (auto to: edges) {
        if (to.first.name==src) {
            to.first.printCity();
            srcObj = to.first;
        }
    }

    cout<<endl;
    cout<<"Please enter the destination: ";
    cin>>dest;
    cout<<endl;
    City destObj;
    for (auto to: edges) {
        if (to.first.name==dest) {
            to.first.printCity();
            destObj = to.first;
        }
    }
    dijResult = dij.dijkstraShortestPath(temp,srcObj);
    cout<<dijResult[destObj]<<endl;

    //=====================^^Dijkstra^^===============================

    //=====================BellmanFord================================

    // Astar bel;
    // map<string, double> belResult;
    // string src1, dest1;
    //
    // cout<<"Please enter the source: ";
    // cin>>src1;
    // cout<<src1<<": "<<endl;
    // for (auto to: edges[src1]) {
    //     to.printEdge();
    // }
    // cout<<endl;
    // cout<<"Please enter the destination: ";
    // cin>>dest1;
    // cout<<endl;
    // belResult = bel.bellmanShortestPath(temp,src1);
    // cout<<belResult[dest1]<<endl;

    // Graph g;
    // g.addCity("A");
    // g.addCity("B");
    // g.addCity("C");
    //
    // g.addEdge("A", "B", "ground", 10, 2);
    // g.addEdge("A", "C", "air", 15, 1);
    // g.addEdge("B", "C", "ground", 2, 0.5);
    //
    // auto dist = Dijkstra::dijkstraShortestPath(g, "A");
    //
    // auto dist2 = BellmanFord::bellmanShortestPath(g, "A");
    //
    // for (const auto& [city, cost] : dist) {
    //     cout << city << " : ";
    //     if (cost == numeric_limits<double>::max()) cout << "INF\n";
    //     else cout << cost << endl;
    // }
    //
    // for (const auto& [city, cost] : dist2) {
    //     cout << city << " : ";
    //     if (cost == numeric_limits<double>::max()) cout << "INF\n";
    //     else cout << cost << endl;
    // }
    return 0;
}