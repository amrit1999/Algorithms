int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;
    vector<int> visited(V, 0);
    edges.push({0, 0, -1});
    int ans = 0;
    while(!edges.empty()) {
        int currNode = edges.top()[1];
        int currParent = edges.top()[2];
        int wt = edges.top()[0];
        edges.pop();
        if(visited[currNode] == 0) {
            visited[currNode] = 1;
            ans += wt;
            for(auto& child:adj[currNode]){
                int nextNode = child[0];
                int newWt = child[1];
                if(visited[nextNode] == 0) {
                    edges.push({newWt, nextNode, currNode});
                }
            }
        }
    }
    return ans;
}
