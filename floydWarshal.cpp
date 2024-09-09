// multi-source shortest distance

vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
            dist[u][u] = 0;
            dist[v][v] = 0;
        }


        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
