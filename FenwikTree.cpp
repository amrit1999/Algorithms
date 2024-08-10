#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &vec){
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
}

// T=O(logn) upper bound can be O(log2*n)
int getSum(int ind,  vector<int> &bit){
    ind++;
    int sum = 0;
    while(ind>0){
        sum += bit[ind];
        ind = ind - (ind&(-ind));
    }
    return sum;
}

// T=O(logn) upper bound can be O(log2*n)
void updateIndexVal(int ind, int val, vector<int> &bit, vector<int> &nums){
    int diff = val-nums[ind];
    nums[ind]+=diff; // skip this if you are doing initial setup
    
    ind = ind+1;
    while(ind<=nums.size()){
        bit[ind] += diff;
        ind = ind + (ind & (-ind));
    }
 
}

void update(int ind, int diff, vector<int> &bit, vector<int> &nums){
    ind = ind+1;
    while(ind<=nums.size()){
        bit[ind] += diff;
        ind = ind + (ind & (-ind));
    }
}

// T = O(n*logn) upper bound can be O(log2*n)
void constructBit(vector<int> &nums){
    int n = nums.size();
    vector<int> bit(n+1,0);
    
    for(int i=0;i<n;i++){
        update(i,nums[i],bit, nums);
    }
    print(bit);
    cout<<getSum(3, bit)<<endl;
    cout<<getSum(2, bit)<<endl;
    updateIndexVal(0, 100, bit, nums);
    cout<<getSum(4, bit)<<endl;
    cout<<getSum(1, bit)<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>nums[i];
    }
    constructBit(nums);
    
    
}
