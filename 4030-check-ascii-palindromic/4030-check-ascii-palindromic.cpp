class Solution {
public:
    bool isPalindromic(string s) {
        string str;
        // bitset<8>bt;
        int n=s.size();
        for(auto u:s)
            {
               str +=  bitset<8>(u).to_string();
            }
        for(int i=0;i<str.size()/2;i++)
            {
                if(str[i] != str[str.size()-i-1])
                {
                    return false;
                }
            }
        return true;
    }
};