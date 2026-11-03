class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int need = *max_element(nums.begin(),nums.end()),ans=0;
        for(int i=0;i<n;i++)
        {
            ans += abs(nums[i] - need);
        }
        return ans;
    }
};