#include<unordered_map>
#include<queue>
#include<vector>
#include<list>

// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//   // Write your code here.
//   //create adj list 
//   unordered_map<int , list<int>> adj;
//   for(int i = 0 ; i < edges.size() ; i++){
//     int u =  edges[i].first -1 ;
//     int v =  edges[i].second -1;
//     adj[u].push_back(v);
//   }
//   //find indegree
//   vector<int>indegree(n);
//   for(auto i : adj){
//     for(auto j : i.second){
//       indegree[j]++;
//     }
//   }
//   //push into q with o indegree
//   queue<int>q;
//   for(int i= 0 ; i < n ; i++){
//     if(indegree[i] == 0)q.push(i);
//   }
//   //do bfs
//   int cnt = 0;
//   while(!q.empty()){
//     int front = q.front();
//     q.pop();
//     cnt++;
//     //update indegree
//     for(auto neighbour : adj[front]){
//       indegree[neighbour]--;
//       if(indegree[neighbour] == 0)q.push(neighbour);

//     }

//   }
//   if(cnt == n)return false;
//   else return true;
// }



bool solve(int node , unordered_map<int,bool> &visited , unordered_map<int,bool>&dfsvisited , unordered_map<int,list<int>>&adj){
  visited[node] = true;
  dfsvisited[node] = true;
  for(auto neighbour : adj[node]){
    if(!visited[neighbour]){
      bool cycle = solve(neighbour , visited , dfsvisited , adj);
      if(cycle)return true;
    }else if(visited[neighbour] && dfsvisited[neighbour])return true;
  }
  dfsvisited[node] = false;
  return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  //create adj list 
  unordered_map<int , list<int>> adj;
  for(int i = 0 ; i < edges.size() ; i++){
    int u =  edges[i].first -1 ;
    int v =  edges[i].second -1;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i = 0 ; i <= n ; i++){
    if(!visited[i]){
      bool cycle = solve(i , visited , dfsvisited , adj);
      if(cycle)return true;
    }
  }
  return false;
}













