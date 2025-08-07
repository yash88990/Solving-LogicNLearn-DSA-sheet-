vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    queue<int> q;
    vector<int>ans;
    vector<int>visited(n , false);
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return ans;
}
