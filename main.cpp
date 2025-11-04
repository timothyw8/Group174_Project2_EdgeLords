#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Graph.h"
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