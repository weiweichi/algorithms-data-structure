// #include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <queue>
// #include <vector>
using namespace std;


// Definition:
// n := numbers of nodes
// edges[i] := [from node_u, to node_v, cost]
// src := source(start node)
// dst := distance(end node)

// single-source shortest paths 
int Bellman_Ford(int n, vector<vector<int>>& edges, int src, int dst) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> temp(dist);
        for (auto& flight : edges) {
            if (dist[flight[0]] != INT_MAX) {
                temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
            }
        }
        swap(temp, dist);
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

// single-source shortest paths 
int Dijkstra(int n, vector<vector<int>>& edges, int src, int dst) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
    }
    vector<int> stops(n, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int dist = temp[0];
        int node = temp[1];
        int steps = temp[2];
        if (steps > stops[node] || steps >= n) 
            continue;
        stops[node] = steps;
        if (node == dst)
            return dist;
        int neighbor, price;
        for (auto& [neighbor, price] : adj[node]) {
            pq.push({dist + price, neighbor, steps + 1});
        }
    }
    return -1;
}

// all-pairs shortest paths 
int Floyd_Warshall(int n, vector<vector<int>>& edges, int src, int dst) {
    vector<vector<int>> graph(n, vector<int> (n, INT_MAX));
    for (int i = 0; i < n; ++i)
        graph[i][i] = 0;
    for (auto e: edges) {
        graph[e[0]][e[1]] = e[2];
    }

    for (int k = 0; k < n; ++k) {
        vector<vector<int>> new_graph=graph;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[k][j] == INT_MAX || graph[i][k] == INT_MAX)
                    continue;
                new_graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
        swap(new_graph, graph);
    }
    return graph[src][dst] == INT_MAX ? -1 : graph[src][dst];
}

int main() {
    vector<vector<int>> edges = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4, src = 0, dst = 3;
    cout<<"Answer: 4"<<endl;
    cout<< Bellman_Ford(n, edges, src, dst)<< endl;
    cout<< Dijkstra(n, edges, src, dst)<< endl;
    cout<< Floyd_Warshall(n, edges, src, dst)<< endl;
    return 0;
}