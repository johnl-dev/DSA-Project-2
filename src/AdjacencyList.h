#pragma once
#include <vector>
#include <map>
#include <string>

using namespace std;

class AdjacencyList {
private:
    //Think about what member variables you need to initialize
    map<string, vector<pair<string, float>>> graph;
    map<string, vector<string>> indegrees;
    map<string, float> ranks;
    int powerIterations;
    int vertexCount;

public:
    AdjacencyList(int powerIterations) {
        this->powerIterations = powerIterations;
        vertexCount = 0;

    }

    void calculateRanks();
    void addVertex(string from, string to);
    string pageRank();
};
