int timer = 1;
  
    void dfs(int ind, int parent, vector<int> &visited, vector<int> &timeIn,
    vector<int> &low, vector<int> adj[], vector<int> &ans){
        visited[ind] = 1;
        low[ind] = timeIn[ind] = timer++;
        int childCount = 0;
        for(auto child:adj[ind]){
            if(parent==child)continue;
            if(visited[child]==0){
                dfs(child, ind, visited, timeIn, low, adj, ans);
                low[ind] = min(low[ind], low[child]);
                // chcek articulatio point
                if(low[child]>=timeIn[ind] && parent!=-1){
                    ans[ind]=1;
                }
                childCount++;
            }else{
                low[ind] = min(low[ind], timeIn[child]);
            }
        }
        if(childCount>1 && parent==-1){
            ans[ind]=1;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       vector<int> visited(V,0), low(V), timeIn(V), res(V,0);
       for(int i=0;i<V;i++){
           if(visited[i]==0){
               dfs(i, -1, visited, timeIn, low, adj, res);
           }
       }
       
       vector<int> ans;
       for(int i=0;i<res.size();i++){
           if(res[i]==1){
               ans.push_back(i);
           }
           
       }
       if(ans.size()==0)return {-1};
       return ans;
       
    }
