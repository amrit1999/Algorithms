class Solution {
public:

    bool isSolvable(int ind, vector<vector<int>>& grid, vector<int> &visited, vector<int> &alloted){
        int girls = grid[0].size();
        for(int i=0;i<girls;i++){
            if(grid[ind][i] && !visited[i]){
                visited[i] = 1;
                if(alloted[i]==-1 || isSolvable(alloted[i], grid, visited, alloted)){
                    alloted[i] = ind;
                    return true;
                }
            }
        }

        return false;

    }

    int maximumInvitations(vector<vector<int>>& grid) {
        int boys = grid.size();
        int girls = grid[0].size();

        vector<int> alloted(girls,-1);
        int ans = 0;
        for(int i=0;i<boys;i++){
            vector<int> visited(girls,0);
            if(isSolvable(i, grid, visited, alloted)){
                ans++;
            }
        }

        return ans;

    }
};
