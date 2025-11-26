class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n= nums.size();
        if(n<3)
        {
            return nums[0];
        }
        return nums[2];
    }
};