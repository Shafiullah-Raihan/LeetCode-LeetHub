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
                if(temp.size()==3)
                {
                    if(temp[1] - temp[0] == temp[2] - temp[1] )
                    ans++;
                }
            }
        return ans;
    }
};