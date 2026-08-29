class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        unordered_map<int,queue<int>>mp;
        vector<int> copy = nums;
        int n=nums.size();
        sort(copy.begin(),copy.end());
        int id=1;
        unordered_map<int,int>grp;
        for(int i=0;i<n;i++)
        {
            if(i>0 && copy[i]-copy[i-1]>limit)
            {
                id++;
            }
            mp[id].push(copy[i]);
            grp[copy[i]] = id;
        }
        for(int i=0;i<n;i++)
        {
            int group = grp[nums[i]];
            int number = mp[group].front();
            mp[group].pop();
            nums[i] = number;
        }
        return nums;

    }
};