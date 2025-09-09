#include<unordered_map>
#include<vector>
#include<list>

void dfs(int node , unordered_map<int,list<int>>&adj , unordered_map<int,bool>&vis , vector<int>&component){
    component.push_back(node);
    vis[node] = true;
    for(int neighbour : adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour , adj, vis , component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i = 0 ; i < E ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    unordered_map<int,bool> vis;
    for(int i = 0 ; i < V ; i++){
        if(!vis[i]){
            vector<int> component;
            dfs(i , adj , vis , component);
            ans.push_back(component);
        }
    }
    return ans;
}
