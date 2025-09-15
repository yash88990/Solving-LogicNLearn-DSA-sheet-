#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){	
	// Write your code here

	//step 1 :- create adj list
	unordered_map<int,list<int>>adj;
	for(int i = 0 ;i < m ; i++){
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//create ds - vis , parent , queue
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int>q;
	//push src node into q and mark vis and set parent
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	//do bfs
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto neighbour : adj[front]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}
	//prepare sortest path
	vector<int>ans;
	int currentnode = t;
	ans.push_back(t);
	while(currentnode != s){
		currentnode = parent[currentnode];
		ans.push_back(currentnode);
	}
	//reverse the ans
	reverse(ans.begin(), ans.end());
	return ans;




	
}





