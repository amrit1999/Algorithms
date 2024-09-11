class RangeModule {
public:

    list<pair<int,int>> ranges;

    RangeModule() {
        
    }

    /*
        ADD 3-7
        1. -> 1-2, 9-12
        2. -> 1-2, 4-8
    */
    
    void addRange(int left, int right) {
        auto it = ranges.begin();
        while(it!=ranges.end()){
            int currLeft = it->first;
            int currRight = it->second;
            if(right<currLeft){
                ranges.insert(it, {left, right});
                break;
            }
            if(left<=currRight){
                left = min(left, currLeft);
                right = max(right, currRight);
                it  = ranges.erase(it);
            }else{
                it++;
            }

        }
        ranges.insert(it,{left, right});
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.begin();
        while(it!=ranges.end()){
            int currLeft = it->first;
            int currRight = it->second;
            if(left>=currLeft && right<=currRight){
                return true;
            }
            it++;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = ranges.begin();
        while(it!=ranges.end()){
            int currLeft = it->first;
            int currRight = it->second;
            if(right<=currLeft || left>=currRight){
                it++;
                continue;
            }
            it = ranges.erase(it);
            if(left > currLeft){
                ranges.insert(it,{currLeft, left});
            }
            if(currRight > right){
                ranges.insert(it, {right, currRight});
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
