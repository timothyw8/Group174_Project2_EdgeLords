//
// Created by aryan on 11/6/2025.
//

#include <vector>
#include <limits>
#include <iostream>
using namespace std;
#include "BellmanFord.h"
#include "Graph.h"

map<string, double> BellmanFord::bellmanShortestPath(const Graph& graph, const string& src){
    map<string, double> dist;
    const double INF = numeric_limits<double>::max();                    //INF for unkown distances -> all cities initialized
    for(const auto& city: graph.getCities()){
        dist[city] = INF;                                                //dist of source initialized
    }
    dist[src] = 0;

    vector<tuple<string, string, double>> graphEdges;
    for(const auto& pair: graph.getAdjList()){
      const string& from = pair.first;
      const vector<Edge>& edges = pair.second;

      for(const auto& edge: edges){
          graphEdges.push_back({from, edge.to, edge.cost});
      }

    }

    int numCities = graph.getCities().size();
    for(int i = 0; i < numCities - 1; i++){
      bool updated = false;
      for(const auto& edge :graphEdges){
        const string& source = get<0>(edge);
        const string& dest = get<1>(edge);
        double w = get<2>(edge);

        if(dist[source] != INF && dist[source] + w < dist[dest]){
          dist[dest] = dist[source] + w;
          updated = true;
        }
      }


    }

    return dist;

}


