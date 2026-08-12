class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0,right=0,n = nums.size();
        int ans=0,cnt=0;
        while(right<n)
        {
            if(mp[nums[right]] ==k)
            {
                while(mp[nums[right]]==k)
                {
                   /// cnt = right-left;
                    mp[nums[left]]--;
                    left++;
                    ///ans= max(ans,cnt);
                    
                }
            }
            cnt = right-left+1;
            ans= max(ans,cnt);

            mp[nums[right]]++;
            right++;
        }
        return ans;
    }
};