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
        }
    }

    temp.generateRandEdges();
    vector<string> cities = temp.getCities();
    //GUI
    startGUI(temp, cities);

    return 0;
}
