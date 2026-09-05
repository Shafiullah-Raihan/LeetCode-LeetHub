class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mx(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                mx[i] = nums[i];continue;
            }
            mx[i] = max(mx[i-1],nums[i]);
        }
        vector<int>mn(n);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                mn[i] = nums[i];continue;
            }
            mn[i] = min(mn[i+1],nums[i]);
        }
        // k = (k%n);
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int temp = mx[i] - mn[i];
            if(temp<=k)
            {
                ans =i;
                break;
            }
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};