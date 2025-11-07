#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Graph.h"

using namespace std;


int main() {
    cout<<"Marisa puppy fart!"<<endl;
    cout<<"TEST" << endl;
    cout<<"this is from marisa"<<endl;

//     ifstream file("uscities.csv");
//     if (!file.is_open()) {
//         cout<<"File could not be opened"<<endl;
//         return 1;
//     }
//
//     Graph temp;
//     string line;
//     getline(file,line);
// ;   while (getline(file, line)) {
//         stringstream ss(line);
//         string city;
//         if (getline(ss,city,',')) {
//             temp.addCity(city);
//         }
//     }
//     vector<string> cities = temp.getCities();
//     for (auto city: cities) {
//         cout<<city<<endl;
//     }

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