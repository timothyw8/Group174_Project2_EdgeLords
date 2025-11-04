#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

struct Edge {
    string to;
    string type;
    double cost;
    double time;

    Edge(string t, string ty, double co, double ti) {
        to = t;
        type = ty;
        cost = co;
        time = ti;
    }
};

class Graph {
    map<string, vector<Edge>> edges;
public:
    void addEdge(string src, string dst, string type, double cost, double time) {
        edges[src].push_back(Edge(dst, type, cost, time));
    }



};

int main() {
    cout<<"Marisa puppy fart!"<<endl;
    cout<<"TEST" << endl;
    cout<<"this is from marisa"<<endl;

    ifstream file("us_cities.json");
    if (!file.is_open()) {
        cout<<"File could not be opened"<<endl;
        return 1;
    }


    return 0;
}