class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int n=nums.size();
        int ans=0;
        long long prod=1;
        for(int right=0,left=0;right<n && left<=right;right++)
        {

            prod *=nums[right];
            while(prod>=(long long)k)
            {
                prod/=(1LL*nums[left]);left++;
            }
            ans += (right-left+1);
        }
        return ans;
    }
};