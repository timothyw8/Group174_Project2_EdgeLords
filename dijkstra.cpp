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





map<City, double> Dijkstra::dijkstraShortestPath(Graph& graph, const City& src){
    map<City, double> dist;                                            //stores minimum cost of each city
    const double INF = numeric_limits<double>::max();                    //INF for unkown distances -> all cities initialized
    for(const auto& city: graph.getEdges()){
        dist[city.first] = INF;
    }
    dist[src] = 0;                                                       //dist of source initialized

    priority_queue<nodeDist, vector<nodeDist>, greater<nodeDist>> q;

    q.push({src, 0});
    while(!q.empty()){
        auto curr_node = q.top();
        q.pop();
        double curr_dist = curr_node.dist;
        City curr_nodeName = curr_node.node;

        if(curr_dist > dist[curr_nodeName]){
            continue;
        }
        auto& adjList = graph.getAdjList();
        if (adjList.find(curr_nodeName)!=adjList.end()) {
            for(const auto& adj: adjList.at(curr_nodeName)){
                City dest = adj.to;
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

