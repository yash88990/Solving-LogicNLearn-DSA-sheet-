#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    // /create  adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0 ; i< edges ; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v , w});
        adj[v].push_back({u , w});

    }

    vector<int> distance(vertices , INT_MAX);
    set<pair<int, int>> s;
    distance[source] = 0;
    s.insert({0 , source});
    while(!s.empty()){
        auto top = *(s.begin());
        s.erase(s.begin());
        int node = top.second;
        int nodedist = top.first;
        for(auto u : adj[node]){
            int v = u.first; 
            int w = u.second;
            if(nodedist + w < distance[v]){
                if(distance[v]  != INT_MAX)
                     s.erase({distance[v] , v});
                
                distance[v] = nodedist + w;
                s.insert({distance[v] , v});
            }
        }
    }
    return distance;
}
