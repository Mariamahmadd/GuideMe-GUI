#include"files.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <SFML/Graphics.hpp>

using namespace std;

// Class to represent the transportation map
class GuideMe {
public:

    string addEdge(unordered_map<string, vector<Edge>>& graph, string& source, string& destination, string& transportationType, int& price);
    bool addEdgeHelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportationType, const int& price);

    string updateEdge(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, string transportation, int newCost);
    bool updateEdgehelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, string transportation, int newCost);

    string deleteEdge(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportationType);
    bool deleteEdgehelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportation);

    string isCompleteMap(unordered_map<string, vector<Edge>>& graph);

    string isConnectedMap(unordered_map<string, vector<Edge>>& graph);

    string BFS(const std::unordered_map<std::string, std::vector<Edge>>& graph, const std::string& startCity);

    string DFS(unordered_map<string, vector<Edge>>& graph, string startCity);

    string findAllPaths(const string& source, const string& destination, int currentBudget, const unordered_map<string, vector<Edge>>& graph);

    void dfsAllPaths(string current, const string& destination, int currentBudget,
        unordered_map<string, vector<Edge>> graph,
        unordered_set<string>& visited,
        vector<pair<string, string>>& path,
        double totalCost);

};



