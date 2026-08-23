class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>pr;
        int lower = l;
        bool flag = false;
        for(int i=0;i<nums.size() ;i++)
            {
                if(nums[i]<lower) continue;
                if(nums[i]>upper) break;

                if(nums[i]>lower)
                {
                    pr.push_back({lower,nums[i]-1});
                    flag = true;

                    lower = nums[i]+1;
                }
                else if(nums[i] == lower )
                {
                    lower = nums[i]+1;
                }
                
                // auto lit = lower_bound(nums.begin(),nums.end(),lower);
                // auto uit = upper_bound(nums.begin(),nums.end(),lower);
                // if(lit == uit)
                // {
                //     pr.push_back({lower,*lit-1});
                //     lower = *lit+1;
                // }
                // else if(lit != uit)
                // {
                //     lower = nums[i]+1;
                // }
                
            }
        if(lower<=upper )
        {
           pr.push_back({lower,upper});
        }
        




        
        // for(int i=0;i<nums.size() && nums[i]<=upper;i++)
        //     {
        //         auto lit = *lower_bound(nums.begin(),nums.end(),lower)
        //         auto uit = *upper_bound(nums.begin(),nums.end(),lower);
        //         if(lit == uit)
        //         {
        //             pr.push_back({lower,uit-1});lower = uit+1;
                    
        //         }
                
        //     }
        return pr;
    }
};