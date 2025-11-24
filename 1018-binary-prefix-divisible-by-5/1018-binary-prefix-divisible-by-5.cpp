class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int ans=0,pre=0;
        int n= nums.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            pre = ((pre<<1) + nums[i])%5;
            vis[i]= (pre== 0);
        }
        return vis;
    }
};