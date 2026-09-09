#define ll long long
class Solution {
public:
    ll countCommas(ll n) {
        // if(n<1000)
        // {
        //     return 0;
        // }
        // ll ans=0;
        // if(n>=1000 && n<1e6)
        // {
        //     ans += (1e6-1000)*1;
        // }
        ll ans=0,p=1000;
        while(p<=n)
        {
            ans += (n-p+1);
            p*=1000;
        }
        return ans;

    }
};