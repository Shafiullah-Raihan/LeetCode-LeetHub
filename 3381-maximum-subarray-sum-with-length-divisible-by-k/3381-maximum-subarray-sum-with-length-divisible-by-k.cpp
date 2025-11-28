#define ll long long
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll ans=LONG_MIN/2;
        ll pre=0;
        vector<ll>arrk(k,LONG_MAX/2);
        arrk[k-1]=0;

        for(int i=0;i<n;i++)
        {
            pre += nums[i];
            ans= max(pre-arrk[i%k],ans);
            arrk[i%k] = min(arrk[i%k],pre);
        }
        return ans;
    }
};