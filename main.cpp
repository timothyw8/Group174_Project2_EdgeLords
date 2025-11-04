#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Edge {
    string to;
    string type;
    double cost;
    double time;

    Edge() {
        to = "";
        type = "";
        cost = 0.0;
        time = 0.0;
    }
    Edge(string t, string ty, double co, double ti) {
        to = t;
        type = ty;
        cost = co;
        time = ti;
    }
};

class Graph {
    map<string, vector<Edge>> edges;
    vector<string> cities;
public:
    void addEdge(string src, string dst, string type, double cost, double time) {
        edges[src].push_back(Edge(dst, type, cost, time));
    }
    void addCity(string city) {
        cities.push_back(city);
    }
    vector<string> getCities() {
        return cities;
    }



};

int main() {
    cout<<"Marisa puppy fart!"<<endl;
    cout<<"TEST" << endl;
    cout<<"this is from marisa"<<endl;

    ifstream file("uscities.csv");
    if (!file.is_open()) {
        cout<<"File could not be opened"<<endl;
        return 1;
    }

    Graph temp;
    string line;
    getline(file,line);
;   while (getline(file, line)) {
        stringstream ss(line);
        string city;
        if (getline(ss,city,',')) {
            temp.addCity(city);
        }
    }
    vector<string> cities = temp.getCities();
    for (auto city: cities) {
        cout<<city<<endl;
    }

    return 0;
}