#include "AdjacencyList.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AdjacencyList::addVertex(string from, string to) {
    if (graph.find(from) == graph.end()) {
        vertexCount++;
    }
    graph[from].push_back(make_pair(to, 0));
    indegrees[to].push_back(from);
    if (graph.find(to) == graph.end()) {
        graph[to] = {};
        vertexCount++;
    }
}

string AdjacencyList::pageRank() {
    string finalString;
    float total = 0.00;
    map<string, float> tempRanks = ranks;

    for (int i = 0; i < powerIterations - 1; i++) {
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            for (auto j: indegrees[it->first]) {
                total += ranks[j] / graph[j].size();
            }
            tempRanks[it->first] = total;
            total = 0;
        }
        ranks = tempRanks;
    }

    for (auto it = ranks.begin(); it != ranks.end(); ++it) {
        // inspired by "How to use setprecision in C++" stackoverflow post from Simplified PageRank FAQ
        string simplified;
        stringstream ss;
        ss << fixed << setprecision(2) << it->second;
        simplified += ss.str();
        finalString += it->first + " " + simplified + "\n";
    }
    return finalString;
}

void AdjacencyList::calculateRanks() {
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        ranks[it->first] = 1.00/vertexCount;

        for (size_t i = 0; i < it->second.size(); i++) {
            it->second[i].second = 1.00/(it->second.size());
        }
    }
}
