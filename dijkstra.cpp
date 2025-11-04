//
// Created by aryan on 11/4/2025.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;


//current cheapest cost of city track
struct nodeDist{
  string nodeName;
  double dist;

};

class dijkstra{

  public:
    static map<string, double> dijkstraShortestPath(const Graph& graph, const string& src){
      map<string, double> dist;                                            //stores minimum cost of each city
      const double INF = numeric_limits<double>::max();                    //INF for unkown distances -> all cities initialized
      for(const auto& [city, _]:graph.getAdjList()){
        dist[city] = INF;
      }
      dist[src] = 0;                                                       //dist of source initialized

      priority_queue<nodeDist> q;
    }

}


