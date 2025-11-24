class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i+=2*k)
        {
            int start=i;
            int finish= min(start+k-1,n-1);
            while(start<finish)
            {
                swap(s[start],s[finish]);
                start++,finish--;
            }
        }
        return s;
    } 
};