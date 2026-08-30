class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,bool>vis;
        for(int i=0;i<n;i++)
        {
           mp[nums[i]].push_back(i);
            vis[nums[i]] = true;
        }
        for(auto u:mp)
        {
            if(u.second.size()>1){
                for(int i=1;i<u.second.size();i++)
                {
                    if(i>0 && u.second[i-1]+1 != u.second[i])
                    {
                        vis[u.first] = false;
                        break;
                    }
                }
            }
        }
        int ans=0;
        for(auto u: vis)
        {
            if(u.second == true) ans++;
        }
        return ans;

    }
};