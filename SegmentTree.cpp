#include<bits/stdc++.h>
using namespace std;

// T = O(n) can go upper bound to O(4*n)
int constructSegmentTree(vector<int> &tree, vector<int> &nums, int start, int end, int currInd){
    if(start==end){
        tree[currInd] = nums[start];
        return tree[currInd];
    }
    int mid = (start+end)/2;
    int leftSum = constructSegmentTree(tree, nums, start, mid, (2*currInd)+1);
    int rightSum = constructSegmentTree(tree, nums, mid+1, end, (2*currInd)+2);
    tree[currInd] = leftSum+rightSum;
    return tree[currInd];
}


// T = O(logn) can go upper bound to O(4*logn)
int getSumRec(int queryStart, int queryEnd, int startInd,  int endInd, int treeInd, vector<int> &tree){
    if(queryStart>endInd || queryEnd<startInd){
        return 0;
    }
    if(queryEnd>=endInd && queryStart<=startInd){
        return tree[treeInd];
    }
    
    int mid = (startInd+endInd)/2;
    
    int leftSum = getSumRec(queryStart, queryEnd, startInd, mid, (2*treeInd)+1, tree);
    int rightSum = getSumRec(queryStart, queryEnd, mid+1, endInd, (2*treeInd)+2, tree);
    
    return leftSum+rightSum;
    
}


// T = O(logn)
void updateSumRec(int startInd, int endInd, int treeInd, vector<int> &tree, int diff, int diffInd){
    if(diffInd<startInd || diffInd>endInd){
        return;
    }
    tree[treeInd] += diff;
    
    if(endInd>startInd){
        int mid = (startInd+endInd)/2;
        updateSumRec(startInd, mid, (2*treeInd)+1, tree, diff, diffInd);
        updateSumRec(mid+1, endInd, (2*treeInd)+2, tree, diff, diffInd);
    }
    
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>nums[i];
    }
    
    vector<int> tree(4*n,0);
    int ans = constructSegmentTree(tree, nums, 0, n-1, 0);
    cout<<getSumRec(0, 3, 0, 3, 0, tree)<<endl;
    cout<<getSumRec(1, 3, 0, 3, 0, tree)<<endl;
    cout<<getSumRec(2, 2, 0, 3, 0, tree)<<endl;
    updateSumRec(0, 3, 0, tree, 10, 1);
    cout<<getSumRec(0, 3, 0, 3, 0, tree)<<endl;
    cout<<getSumRec(1, 3, 0, 3, 0, tree)<<endl;
    cout<<getSumRec(2, 2, 0, 3, 0, tree)<<endl;
}


