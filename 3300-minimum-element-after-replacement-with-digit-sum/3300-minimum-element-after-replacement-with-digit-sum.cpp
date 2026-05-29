class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mx=1e8;
        for(int i=0;i<n;i++)
        {
            int digit = 0;
            while(nums[i]>0)
            {
                digit += (nums[i]%10);
                nums[i] /=10;
            }
            mx = min(mx,digit);
        }
        return mx;
    }
};