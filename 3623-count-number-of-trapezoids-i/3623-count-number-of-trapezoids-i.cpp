#define ll long long
const ll mod = 1e9 + 7;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll,ll> mp;
        for(auto it: points)
        {
            ll u = (ll)it[0],v = (ll)it[1];
            mp[v]++;
        }
        ll ans=0,sum=0;
        for(auto& [u,v]: mp)
        {
            if(v<2) continue;
            ll edge = (v*(v-1))/2;
            ans = (ans +(edge*sum))%mod;
            sum = (sum+edge)%mod;


        }
        return (int)ans;


        
    }
};