class DSU{

    public: 
    vector<int> parent;
    vector<int> count;

    DSU(int n){
        parent.resize(n);
        count.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
            count[i] = 1;
        }
    }

    int getCount(int x){
        int x_rep = getParent(x);
        return count[x_rep];
    }

    int getParent(int x){
        int x_par = parent[x];
        if(x==x_par){
            return x;
        }

        parent[x] = getParent(x_par);
        return parent[x];
    }

    void unionByRank(int x, int y){
        int x_rep = getParent(x);
        int y_rep = getParent(y);

        if(x_rep == y_rep){
            return;
        }

        if(count[x_rep]>count[y_rep]){
            parent[y_rep] = x_rep;
            count[x_rep] += count[y_rep];
        }
        else if(count[y_rep]>count[x_rep]){
            parent[x_rep] = y_rep;
            count[y_rep] += count[x_rep];
        }else{
            parent[y_rep] = x_rep;
            count[x_rep] += count[y_rep];
        }

    }


};
