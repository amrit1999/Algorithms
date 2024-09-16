class Solution
{
    public:
        void getLPS(string pat, vector<int> &lps,int n){
            
            lps[0]=0;
            int len=0;
            int i=1;
            
            while(i<n){
                if(pat[i]==pat[len]){
                    lps[i] = len+1;
                    len++;
                    i++;
                }
                else{
                    if(len==0){
                        lps[i]=0;
                        i++;
                    }else{
                        len = lps[len-1];
                    }
                }
            }
        }
    
        vector <int> search(string pat, string txt)
        {
            int m = pat.size();
            int n = txt.size();
            vector<int> ans;
            vector<int> lps(m,0);
            getLPS(pat,lps,m);
            int i=0,j=0;            
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                    if(j==m){
                        ans.push_back(i-m+1);
                        j = lps[j-1];
                    }
                }
                else if(i<n && pat[j]!=txt[i]){
                    if(j==0){
                        i++;
                    }else{
                        j = lps[j-1];
                    }
                    
                }
                
            }
            return ans;
            
        }
        
     
};
