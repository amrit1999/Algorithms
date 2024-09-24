vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
unordered_map<int,string> dirMapper = {{0,"Right"},{1,"Left"},{2,"Up"},{3,"Down"},{-1,"-"}};
vector<vector<bool>> vis;
vector<int> colors;
int n,m;
bool isPos (int x,int y,vector<vector<int>> &grid) {
    if(x<0 || x>=n || y<0 || y>=m || vis[x][y] == true) return false;
    if(grid[x][y]==-1)
        return true;
    int col = grid[x][y];
    int assignedDir = colors[col];
    vis[x][y]=true;
    
    if(assignedDir != -1) {
        vector<int> nMove = dir[assignedDir];
        int nx = x+nMove[0]; 
        int ny = y+nMove[1];
        if(isPos(nx,ny,grid)) return true;
    } else {
        for(int i=0;i<dir.size();i++) {
            colors[col]=i;
            int nx = x+dir[i][0]; 
            int ny = y+dir[i][1];
            if(isPos(nx,ny,grid)) return true;
        }
        colors[col] = -1;
    }
    
    vis[x][y]=false;    
    return false;
}

vector<int> solve(vector<vector<int>> grid) {
    n = grid.size();
    m = grid[0].size();
    colors.resize(8,-1);
    vis.resize(n, vector<bool> (m,false));
    
    if(isPos(0,0,grid))
        return colors;
    return {};
}

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));    
    for(auto &y:a) for(auto &x:y) cin>>x;
    
    vector<int> res = solve(a);
    if(res.size()==0) cout<<"Not Possible !!!";
    else for(int i=0;i<res.size();i++) if(res[i]!=-1) cout<<i<<": "<<dirMapper[res[i]]<<", ";
    
}
