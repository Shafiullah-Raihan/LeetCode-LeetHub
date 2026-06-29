class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto u: patterns)
        {
            if(word.find(u) != string::npos)
            {
                ans++;
            }
        }
        return ans;
    }
};