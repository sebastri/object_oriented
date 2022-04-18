#include "Network.h"

void Network::addEdge(string u, string v){
    edges[u].insert(v);
    if (symmetric)
    {
        edges[v].insert(u);
    }
}

void Network::loadNetwork(string filename, bool symmetric){
    ifstream ist{filename};
    Network network(symmetric);
    if (!ist) throw(99);
    string line;
    
    while (getline(ist,line))
    {
        string node;
        string edge;
        stringstream ss{line};
        ss >> node;
        network.addNode(node);
        while (ss >> edge)
        {
            network.addEdge(node, edge);
        }
    }
}

void Network::addPath(vector<string> nodes) {
string prev; // Will be set in first iteration below
vector<string>::iterator it;
for (it = nodes.begin(); it != nodes.end(); it++) {
    string n = *it;
    addNode(n);
    if (it != nodes.begin()) {
    addEdge(prev, n);
    }
    prev = n;
}
}

Network Network::operator+(Network &rhs){
    Network x; //set kan bare holde en av hver verdi viktig!!
    x.nodes = nodes; // "this" sine noder
    x.nodes.insert(rhs.nodes.begin(), rhs.nodes.end());
    x.edges = edges; // "this" sine edges
    for(auto p : rhs.edges){
        for (auto i : p.second) //iterer gjennom settet med strings i edges
        {
            x.addEdge(p.first, i);
        }
    }
    return x;
}

int Network::distance(string from, string to){
    map<string, int> map = traverse(from);
    for(auto p:map){
        if (p.first == to)
        {
            return p.second;
        }   
    }
    return -1;
}

float Network::avgPathLength(){
    
}