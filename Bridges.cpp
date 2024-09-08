int timer = 1;

    void dfs(int ind , int parent, vector<int> &low, vector<int> &time, vector<int> &visited, vector<vector<int>> &graph, vector<vector<int>> &bridge){
        low[ind] = timer;
        time[ind] = timer++;
        visited[ind] = 1;

        for(auto child:graph[ind]){
            if(child==parent)continue;
            if(visited[child]==0){
                dfs(child, ind, low, time, visited, graph, bridge);
                low[ind] = min(low[ind], low[child]);
                // check for bridge
                if(low[child]>time[ind]){
                    bridge.push_back({ind, child});
                }
            }else{
                low[ind] = min(low[ind], time[child]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> bridges;
        vector<int> low(n,0), time(n,0), visited(n,0);
        for(auto connec:connections){
            int u = connec[0];
            int v = connec[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, low, time, visited, graph, bridges);
        return bridges;

    }
