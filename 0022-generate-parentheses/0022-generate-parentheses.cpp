class Solution {
public:

    void genPar(int open,int close,string par, vector<string>& final, int n)
        {
            if(open == n && close == n){
                final.push_back(par);
                return;
            }
            
            
            if(open<n){
                genPar(open+1, close, par+"(", final,n);
            }
            
            if(close<open){
                genPar(open, close+1, par+ ")", final,n);
            }
            
            
            
        }
    vector<string> generateParenthesis(int n) {
        vector<string>final;
        
        if(n>0){
            genPar(0,0,"", final, n);
        }
        return final;
    }
};


