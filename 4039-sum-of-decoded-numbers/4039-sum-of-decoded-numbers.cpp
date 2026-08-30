class Solution {
public:
    #define ll long long
    #define mod 1000000007LL
    ll expo(ll base,ll pow)
    {
        ll ans=1;
        while(pow)
        {
            if(pow&1)
            {
                ans = (base*ans)%mod;
            }
            base = (base*base)%mod;
            pow>>=1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        ll res =0;
        for(auto u:nums)
        {
            ll width = u%10;
            ll d= u/10;
            string s = to_string(d);
            ll x = stoi(s.substr(0,width));
            ll y = stoi(s.substr(width));
            res = (res + expo(x,y))%mod;
        }
        return (int)res;
    }
};