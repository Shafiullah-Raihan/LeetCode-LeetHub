#define ll long long
class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,ll>mp;
        ll pre=0;int ans=0;
        for(int i=0;i<n;i++)
        {
            pre = (((pre+arr[i])%k)+k)%k;
            if(pre==0)
            {
                ans++;
            }
            
            ans += mp[pre];
            mp[pre]++;
        }
        return ans;
    }
};