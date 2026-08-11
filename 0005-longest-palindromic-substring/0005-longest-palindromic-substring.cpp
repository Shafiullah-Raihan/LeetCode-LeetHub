class Solution {
public:
    string longestPalindrome(string s) {
        int start =0,end=0,maxLen =1,init=0 ;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            start = i,end = i;
            while(start>=0 && end<n && s[start] == s[end])
            {
                if(maxLen <end-start+1){
                    maxLen = end-start+1;
                    init = start;
                    
                }
                
                
                start--,end++;
            }
            
            start =i ,end = i+1;
            while(start>=0 && end<n && s[start] == s[end]){
                if(maxLen < end-start+1){
                    maxLen = end-start +1;
                    init =start;
                }
                start--,end++;
            }
        }
        return s.substr(init,maxLen);
    }
};