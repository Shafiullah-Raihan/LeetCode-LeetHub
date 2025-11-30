class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>pre(101,0);
        vector<int>freq(101,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=1;i<101;i++)
        {
            pre[i] = pre[i-1]+ freq[i-1];
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) ans.push_back(0);
            else ans.push_back(pre[nums[i]]);
        }
        return ans;
        
    }
};

