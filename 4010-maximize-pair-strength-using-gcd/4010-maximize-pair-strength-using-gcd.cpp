using ll = long long;
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        ll ans =0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll mul = 1LL*nums[i]*nums[j];
                ll g = __gcd(nums[i],nums[j]);
                g = g*g;
                ans = max(ans,mul/g);
            }
        }
        return ans;
    }
};