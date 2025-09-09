// #include<unordered_map>
// #include<vector>
// #include<list>

// bool iscycleDFS(int node ,int parent , unordered_map<int, list<int>>&adj , unordered_map<int , bool > &vis){
//     vis[node] = true;
//     for(auto neighbour : adj[node]){
//         if(!vis[neighbour]){
//             bool iscyclepresent = iscycleDFS(neighbour , node , adj , vis);
//             if(iscyclepresent)return true;
//         }else if(vis[neighbour] && neighbour != parent)return true;
        
//     }
//     return false;
// }

// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     // Write your code here.
//     //create adj list
//     unordered_map<int,list<int>> adj;
//     for(int i = 0 ; i < m ; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     unordered_map<int,bool> vis;
//     for(int i = 0 ; i < n ; i++){
//         if(!vis[i]){
//             bool iscyclepresent = iscycleDFS(i , -1 , adj , vis);
//             if(iscyclepresent)return "Yes";
//         }
//     }
//     return "No";
// }


//...........method 2 :- using bfs

#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
bool iscycleBFS(int node , unordered_map<int,list<int>>&adj , unordered_map<int,bool>&vis){
    unordered_map<int,int> parent;
    parent[node] = -1;
    vis[node] = true;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int neighbour : adj[front]){
            if(vis[neighbour] && neighbour != parent[front])return true;
            else if(!vis[neighbour]){
                vis[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
            
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    // create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            bool iscyclepresent = iscycleBFS(i  , adj , vis);
            if(iscyclepresent)return "Yes";
        }
    }
    return "No";

}


















