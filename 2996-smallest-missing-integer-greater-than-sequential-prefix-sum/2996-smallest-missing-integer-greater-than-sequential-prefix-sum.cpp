class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int ans=INT_MAX,sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1]+1)
            {
                sum+=nums[i];
            }
            else{
                break;

            }

        }
        ans= min(ans,sum);

        while(true)
        {
            if(!st.count(ans)) break;
            ans+=1;
        }
        return ans;
    }
};