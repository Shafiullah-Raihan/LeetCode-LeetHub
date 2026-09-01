class Solution {
public:
    int bitwiseComplement(int n) {
        string s = "";
        if(n==0) return 1;
        while(n>0)
        {
            if(n&1)
            {
                s+='0';
            }
            else{
                s+='1';
            }
            n>>=1;
        }
        reverse(s.begin(),s.end());
        int ans=0;
        int id=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            int num = s[i]-'0';
            ans += (num*pow(2,id));id++;
        }
        return ans;
    }
};