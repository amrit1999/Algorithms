#include<bits/stdc++.h>
using namespace std;


void setBit(int &bit, int ind){
    bit = (bit ^ (1<<(ind-1)));
}


void unsetBit(int &bit, int ind){
    bit = (bit ^ (1<<(ind-1)));
}

void display(int bit){
    for(int i=0;i<=9;i++){
        if(bit & (1<<i)){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int bit = 17; // 10001
    display(bit);
    setBit(bit, 3);
    display(bit);
    setBit(bit, 4);
    display(bit);
    unsetBit(bit, 1);
    display(bit);
    
}


