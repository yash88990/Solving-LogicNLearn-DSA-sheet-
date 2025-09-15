#include<vector>
#include<stack>



void toposort(int node , vector<vector<pair<int,int>>>&adj , vector<bool>&visited , stack<int>&s){
    visited[node] = true;
    for(auto & neighbour : adj[node]){
        if(!visited[neighbour.first]){
            toposort(neighbour.first , adj , visited , s);
        }
    }
    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    //create adj list
    vector<vector<pair<int,int>>> adj(n);
    for(const auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].emplace_back(v , w);
    }
    vector<bool> visited(n , false);
    stack<int>s;
    //topological sort
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            toposort(i, adj , visited , s);
        }
    }
    //dis array
    vector<int>distance(n , INT_MAX);
    distance[0] = 0;
    //update sortest dist
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(distance[node] != INT_MAX){
            for(auto & i : adj[node]){
                int v = i.first;
                int w = i.second;
                if(distance[node] + w < distance[v]){
                    distance[v] = distance[node] + w;
                }
            }
        }
    }
    //mark -1 for unreachable node
    for(auto &d : distance){
        if(d == INT_MAX)d = -1;
    }
    return distance;

}










