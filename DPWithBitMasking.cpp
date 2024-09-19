#include<bits/stdc++.h>
using namespace std;


int solve(int ind, vector<vector<int>> &val, int &bit, vector<vector<int>> &dp){
    int n = val.size();
    int m = val[0].size();
    if(ind == val.size()){
        //cout<<"bit = "<<bit<<endl;
        return 0;
    }
    
    if(dp[ind][bit]!=-1) return dp[ind][bit];
    
    int ans = INT_MAX;
    for(int i=1;i<=m;i++){
        if(bit & (1<<i)){
            bit = bit ^ (1<<i);
            ans = min(ans, solve(ind+1, val, bit, dp)+val[ind][i-1]);
            bit = bit ^ (1<<i);
        }
    }
    
    return dp[ind][bit] = ans;
    
}


int main(){
    
    vector<vector<int>> val = {
        {9,2,7,8},
        {6,4,3,7},
        {5,8,1,8},
        {7,6,9,4}
    };
    
    int n = val.size();
    int m = val[0].size();
    
    vector<vector<int>> dp(n, vector<int>(1<<m+1, -1));
    
    int bit = ((1<<m+1)-1);
    
    cout<<solve(0, val, bit, dp)<<endl;
    
}
/*
16 8 4 2 1
1  1 1 1 1


*/

