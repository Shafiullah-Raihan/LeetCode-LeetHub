class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n= nums.size();
        vector<bool> have(n+1,false);
        for(int i=0;i<n;i++)
        {
            have[nums[i]] = true;
        }
        for(int i=1;i<=n;i++)
        {
            if(!have[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};