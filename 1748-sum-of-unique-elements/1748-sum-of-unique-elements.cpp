class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int sum=0;
        for(auto &[num,fre]:mp)
        {
            if(fre == 1)
            {
                sum += num;
            }
        }
        return sum;
    }
};