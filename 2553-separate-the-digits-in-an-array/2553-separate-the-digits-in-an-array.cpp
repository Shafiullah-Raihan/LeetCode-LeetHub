class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto u:nums)
        {
            string s=to_string(u);
            for(int i=0;i<s.size();i++ )
            {
                int p=s[i]-'0';
                ans.push_back(p);
            }
        }
        return ans;
    }
};