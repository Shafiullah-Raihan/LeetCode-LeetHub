class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto u:mp)
            {
                int val = u.first;
                vector<int>temp = u.second;
                if(temp.size()<3) continue;
                int cng  = temp[1] - temp[0];
                bool flag = true;
                for(int i=2;i<temp.size();i++)
                {
                    if(temp[i] - temp[i-1] != cng) flag = false;
                    
                }
                if(flag) ans++;
            }
        return ans;
    }
};