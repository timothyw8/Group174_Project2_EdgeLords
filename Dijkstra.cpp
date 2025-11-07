//
// Created by aryan on 11/4/2025.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include "Graph.h"
#include "Dijkstra.h"
#include<unordered_map>
using namespace std;


//current cheapest cost of city track

bool nodeDist::operator>(const nodeDist &other) const{return dist>other.dist;}





    map<string, double> Dijkstra::dijkstraShortestPath(const Graph& graph, const string& src){
      map<string, double> dist;                                            //stores minimum cost of each city
      const double INF = numeric_limits<double>::max();                    //INF for unkown distances -> all cities initialized
      for(const auto& city: graph.getCities()){
        dist[city] = INF;
      }
      dist[src] = 0;                                                       //dist of source initialized

      priority_queue<nodeDist, vector<nodeDist>, greater<nodeDist>> q;

      q.push({src, 0});
      while(!q.empty()){
        auto curr_node = q.top();
        q.pop();
        double curr_dist = curr_node.dist;
        string curr_nodeName = curr_node.nodeName;

        if(curr_dist > dist[curr_nodeName]){
          continue;
        }
        auto& adjList = graph.getAdjList();
        if (adjList.count(curr_nodeName)) {
          for(const auto& adj: adjList.at(curr_nodeName)){
            string dest = adj.to;
            double w = adj.cost;                                              //weight is the cost of travel

            //Relaxing both nodes by comparing
            if(dist[dest] > dist[curr_nodeName] + w){
              dist[dest] = dist[curr_nodeName] + w;
              q.push({dest, dist[dest]});
            }
          }
        }

      }
      return dist;
    }


