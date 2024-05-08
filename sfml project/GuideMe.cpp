#include "GuideMe.h"
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <locale>

using namespace std;
string GuideMe::addEdge(unordered_map<string, vector<Edge>>& graph, string& source, string& destination, string& transportationType, int& price) {
    stringstream output;
    bool first=addEdgeHelper(graph, source, destination, transportationType, price);
    bool second=addEdgeHelper(graph, destination, source, transportationType, price);
    if (first && second) {
        output << "The Edge From " << source << " to " << destination << "\n is added successfully.\n" << endl;
    }
    else {
        output << "ERROR: Couldn't add edge from\n " << source << " to " <<destination<< endl;
    }
    
     return output.str();
}

bool GuideMe::addEdgeHelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportationType, const int& price) {
    // Check if there is an existing edge between source and destination
    std::stringstream output;
    if (graph.find(source) == graph.end()) {
        return false;
    }
    if (graph.find(destination) == graph.end()) {
        return false;
    }
    if (graph.find(source) != graph.end()) {
        vector<Edge>& edges = graph[source];
        for (Edge& edge : edges) {
            if (edge.destination == destination) {
                // Edge already exists, update transportation prices
                edge.transportationPrices[transportationType] = price;
                return true;
            }
        }
    }

    // If no existing edge found, create a new one and add it to the graph
    Edge newEdge(destination, { {transportationType, price} });
    graph[source].push_back(newEdge);
    return true;
}

string GuideMe::updateEdge(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, string transportation, int newCost) {

    stringstream output;
    bool first= updateEdgehelper(graph, source, destination, transportation, newCost);
    bool second = updateEdgehelper(graph, destination, source, transportation, newCost);
    if (first && second) {
        output << "Edge from " << source << " to " << destination << "\nupdated successfully";
        return output.str();
    }
    else {
        output << "ERROR: couldn't find edge from\n " << source << " to " << destination;
        return output.str();
    }
}

bool GuideMe::updateEdgehelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, string transportation, int newCost) {
    auto sourceIt = graph.find(source);
    std::stringstream output;
    if (sourceIt == graph.end()) {
        return false;
    }

    // Find the edge corresponding to the destination and source
    vector<Edge>& edges = sourceIt->second;
    auto edgeIt = edges.end();  // Initialize edgeIt to the end iterator as a default value

    // Iterate over the edges vector
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        // Check if the destination of the current Edge matches the provided destination
        if (it->destination == destination) {
            // If found, update edgeIt and break out of the loop
            edgeIt = it;
            break;
        }
    }


    if (edgeIt == edges.end()) {
        return false;
    }

    // Update the corresponding transportation price for the specified destination
    auto& transportationPrices = edgeIt->transportationPrices;
    if (transportationPrices.find(transportation) != transportationPrices.end()) {
        transportationPrices[transportation] = newCost;
        return true;
    }
    else {
        return false;
    }
}

string GuideMe::deleteEdge(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportationType) {
    stringstream output;
    bool first = deleteEdgehelper(graph, source, destination, transportationType);
    bool second = deleteEdgehelper(graph, destination, source, transportationType);
    if (first && second)
    {
        output << "Transportation type '" << transportationType << "' deleted\n successfully from edge \n" << source << " to " << destination << endl;
    }
    else {
        output << "Error: Edge not found or \n specified transportation type\n not present!\n\n" << endl;
    }
   
    return output.str();
}

bool GuideMe::deleteEdgehelper(unordered_map<string, vector<Edge>>& graph, const string& source, const string& destination, const string& transportation) {
    stringstream output;
    auto it = graph.find(source);
    vector<Edge>& edges = it->second; 
    for (auto& edge : edges) {
        if (edge.destination == destination) {
            auto priceIt = edge.transportationPrices.find(transportation);
            if (priceIt != edge.transportationPrices.end()) {
                edge.transportationPrices.erase(priceIt);
                if (edge.transportationPrices.empty()) {
                    auto it2 = graph.find(source);
                    auto& edgeVector = it2->second;
                    for (auto it2 = edgeVector.begin(); it2 != edgeVector.end(); ++it2) {
                        if (it2->destination == destination) {
                            edgeVector.erase(it2);
                            break; //3shan fe 1 edge between the vertex and the destination
                        }
                    }

                }
                return true;
            }
            else {
                return false;
            }
        }
    }

}

string GuideMe::isCompleteMap(unordered_map<string, vector<Edge>>& graph) {
    for (const auto& pair : graph) {
        const vector<Edge>& edges = pair.second;
        // Check if every other node is connected to this node
        for (const auto& other_pair : graph) {
            if (pair.first != other_pair.first) {
                bool found = false;
                for (const auto& edge : edges) {
                    if (edge.destination == other_pair.first) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    // If any other node is not connected to this node, graph is not complete
                    return "WE'RE SORRY BUT, \nTHIS GRAPH IS NOT COMPLETE!";
                }
            }
        }
    }
    return "YAAAAAAY! \nTHIS GRAPH IS COMPLETE";
}
string GuideMe::isConnectedMap(unordered_map<string, vector<Edge>>& graph) {
    if (graph.empty()) return "WE'RE SORRY BUT, \nTHIS GRAPH IS NOT CONNECTED!"; // If the graph has no nodes, it's not connected

    unordered_set<string> visited; // Set to store visited nodes
    queue<string> queue; // Queue for BFS traversal

    // Start BFS traversal from the first node in the adjacency list
    queue.push(graph.begin()->first);
    visited.insert(graph.begin()->first);

    // BFS traversal
    while (!queue.empty()) {
        string current = queue.front();
        queue.pop();

        // Visit all neighbors of the current node
        for (const Edge& edge : graph[current]) {
            if (visited.find(edge.destination) == visited.end()) {
                queue.push(edge.destination);
                visited.insert(edge.destination);
            }
        }
    }

    // Check if all nodes are visited
    bool isConnected = visited.size() == graph.size();

    // Return "connected graph" if true, "graph not connected" otherwise
    return isConnected ? "YAAAAAAY!\nTHIS GRAPH IS CONNECTED" : "WE'RE SORRY BUT, \nTHIS GRAPH IS NOT CONNECTED!";
}

string GuideMe::BFS(const std::unordered_map<std::string, std::vector<Edge>>& graph, const std::string& startCity) {
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    std::stringstream output;

    // Check if the starting city exists in the graph
    if (graph.find(startCity) == graph.end()) {
        output << "Error: City not found in the graph." << endl;
        return output.str(); // Return the error message
    }

    q.push(startCity);
    visited.insert(startCity);

    while (!q.empty()) {
        std::string currentSource = q.front();
        q.pop();
        output << "•" << currentSource << " \n";

        for (const auto& edge : graph.at(currentSource)) {
            std::string destination = edge.destination;
            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                q.push(destination);
            }
        }
    }

    return output.str();

}

string GuideMe::DFS(unordered_map<string, vector<Edge>>& graph, string startCity) {
    stack<string> stack;
    unordered_set<string> visited;
    std::stringstream output;
    stack.push(startCity);
    visited.insert(startCity);
    // Check if the starting city exists in the graph
    if (graph.find(startCity) == graph.end()) {
        output << "Error: City not found in the graph." << endl;
        return output.str(); // Return the error message
    }

    while (!stack.empty()) {
        string currentSource = stack.top();
        stack.pop();
        output << "•" << currentSource << " \n";

        for (const auto& edge : graph[currentSource]) {
            string destination = edge.destination;
            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                stack.push(destination);
            }
        }
    }

    return output.str();
}
vector <pair<int, vector<pair<string, string>> >> Routes;
//Enumerate paths with backtracking
void GuideMe::dfsAllPaths(string current, const string& destination, int currentBudget,
    unordered_map<string, vector<Edge>> graph,
    unordered_set<string>& visited,
    vector<pair<string, string>>& path,
    double totalCost) {
    
    visited.insert(current);

    for (const auto& edge : graph[current]) {
        for (const auto& pair : edge.transportationPrices) {
            const string& currentTransportation = pair.first;
            const double cost = pair.second;

            if (currentBudget - cost >= 0 && visited.find(edge.destination) == visited.end()) { //ytzbat
                path.push_back(make_pair(current, currentTransportation));

                double newBudget = currentBudget - cost;
                double newTotalCost = totalCost + cost;

                if (edge.destination == destination) {
                    Routes.push_back(make_pair(newTotalCost, path));
                }
                else {
                    dfsAllPaths(edge.destination, destination, newBudget, graph, visited, path, newTotalCost);
                }

                path.pop_back(); //Backtrack
            }
        }
    }

    visited.erase(current); //Backtrack feha moshkla ig

}

string GuideMe::findAllPaths(const string& source, const string& destination, int currentBudget, const unordered_map<string, vector<Edge>>& graph) {
    unordered_set<string> visited;
    vector<pair<string, string>> path;
    stringstream output;
    double totalCost = 0.0;
    dfsAllPaths(source, destination, currentBudget, graph, visited, path, totalCost);
    sort(Routes.begin(), Routes.end());

    for (int i = 0; i < Routes.size(); i++) {
        for (int j = 0; j < Routes[i].second.size(); j++) {
            output << Routes[i].second[j].first << " (" << Routes[i].second[j].second << ") -> ";
        }
        output << destination << " " << Routes[i].first << endl;
        output << endl;
    }

    return output.str();
}
