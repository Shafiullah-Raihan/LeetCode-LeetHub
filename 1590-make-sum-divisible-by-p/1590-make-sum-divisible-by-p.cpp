class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size(),ans=nums.size();
        long long pre=0;
        unordered_map<int,int>mp;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum = (nums[i]+sum);
            sum %=p;
        }
        if(sum ==0) return 0;
        mp[0]=-1;
        int curSum=0;
        for(int i=0;i<n;i++)
        {
            curSum = (curSum+nums[i])%p;
            int need = (curSum - sum+p)%p;
            if(mp.find(need)!= mp.end())
            {
                ans = min(ans,i-mp[need]);
            }
            mp[curSum]=i;

        }
        if(ans==n)
        {
            return -1;
        }
        return ans;

    }
};