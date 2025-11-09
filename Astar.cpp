//
// Created by Timothy Wang on 11/8/25.
//
#include "Astar.h"
#include <queue>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

double shortCut(City& from, City& to) {
    double x_diff = from.x_coord - to.x_coord;
    double y_diff = from.y_coord - to.y_coord;
    double minCost = 100.0;
    double maxCost = 10000.0;
    return sqrt((x_diff)*(x_diff)+(y_diff)*(y_diff))*minCost/maxCost;
}

bool nodeDist1::operator>(const nodeDist1 &other) const {
    return dist>other.dist;

}
// bool nodeDist1::operator<(const nodeDist1 &other) const {
//     return dist<other.dist;
//
// }


map<City, double> Astar::astarShortestPath(Graph& graph, City& src, City& dst, vector<City>& result) {
    map<City, double> bestCosts;
    map<City, City> path;
    set<string> visited;

    map<City, vector<Edge>> cit = graph.getEdges();

    for (auto& city : cit) {
        bestCosts[city.first] = numeric_limits<double>::max();
    }
    bestCosts[src] = 0.0;

    priority_queue<nodeDist1, vector<nodeDist1>, greater<nodeDist1>> potential;
    potential.push({src,shortCut(src, dst)});

    while (potential.empty()!=true) {
        nodeDist1 curr = potential.top();
        potential.pop();
        if (curr.node.name == dst.name) {
            result.clear();
            City temp = dst;
            while (temp.name!=src.name) {
                result.push_back(temp);
                temp = path[temp];
            }
            result.push_back(src);
            reverse(result.begin(), result.end());
            return bestCosts;
        }
        if (visited.count(curr.node.name)>0) {
            continue;
        }
        visited.insert(curr.node.name);
        map<City, vector<Edge>>& edges = graph.getEdges();
        for (auto& edge: edges[curr.node]) {
            double cost = bestCosts[curr.node] + edge.cost;
            if (cost<bestCosts[edge.to]) {
                bestCosts[edge.to] = cost;
                path[edge.to] = curr.node;
                double cost2 = cost + shortCut(edge.to,dst);
                potential.push({edge.to, cost});
            }
        }

    }
    for (auto& city : bestCosts) {
        bestCosts[city.first] = numeric_limits<double>::max();
    }
    return bestCosts;

}
