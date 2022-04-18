#pragma once
#include "std_lib_facilities.h"

class Network {
private:
// Set of nodes, each node is identified by a string
set<string> nodes;
// Map of edges for each node, i.e. edges[n] is a set of node n's neighbors
map<string, set<string>> edges;
// Whether the network is symmetric or asymmetric
bool symmetric;
public:
Network(bool symmetric = true) : nodes(nodes), edges(edges), symmetric(symmetric) {}
void addNode(string n) { nodes.insert(n); }
void addEdge(string u, string v);
void addPath(vector<string> ns);
Network operator+(Network &rhs);
map<string, int> traverse(string start);
int distance(string from, string to);
float avgPathLength();
void loadNetwork(string filename, bool symmetric);

};