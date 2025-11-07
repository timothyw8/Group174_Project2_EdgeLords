#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Graph.h"
#include <set>

using namespace std;


int main() {
    // ifstream file("uscities.csv");
    // if (!file.is_open()) {
    //     cout<<"File could not be opened"<<endl;
    //     return 1;
    // }
    //
    // Graph temp;
    // string line;
    // getline(file,line);
    // set<string> cities_set;
    // while (getline(file, line)) {
    //     stringstream ss(line);
    //     string city;
    //     if (getline(ss,city,',')) {
    //         cities_set.insert(city);
    //     }
    // }
    // for (auto city: cities_set) {
    //     temp.addCity(city);
    // }
    // temp.generateRandEdges();
    // map<string, vector<Edge>> edges = temp.getEdges();
    // for (auto city: edges) {
    //     cout<<city.first<<" = ";
    //     for (auto edge: city.second) {
    //         edge.printEdge();
    //     }
    //     cout<<endl;
    // }
    //
    // cout<<cities_set.size()<<endl;
    //

    Graph g;
    g.addCity("A");
    g.addCity("B");
    g.addCity("C");
    
    g.addEdge("A", "B", "ground", 10, 2);
    g.addEdge("A", "C", "air", 15, 1);
    g.addEdge("B", "C", "ground", 2, 0.5);
    
    auto dist = Dijkstra::dijkstraShortestPath(g, "A");
    
    auto dist2 = BellmanFord::bellmanShortestPath(g, "A");
    
    for (const auto& [city, cost] : dist) {
        cout << city << " : ";
        if (cost == numeric_limits<double>::max()) cout << "INF\n";
        else cout << cost << endl;
    }
    
    for (const auto& [city, cost] : dist2) {
        cout << city << " : ";
        if (cost == numeric_limits<double>::max()) cout << "INF\n";
        else cout << cost << endl;
    }
    return 0;
}