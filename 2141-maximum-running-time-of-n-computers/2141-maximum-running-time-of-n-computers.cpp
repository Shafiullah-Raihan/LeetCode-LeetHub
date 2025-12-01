#define ll long long
class Solution {
public:
    ll maxRunTime(int n, vector<int>& bat) {
        if(n == (int)bat.size())
        {
            return  *min_element(bat.begin(),bat.end());
        }
        ll total =0;
        for(auto u:bat)
        {
            total += (ll)u;
        }
        ll target = total/n;
        ll left=0,right=target;
        while(left<=right)
        {
            ll mid = (right+left)>>1;
            ll need =0;
            for(auto u:bat)
            {
                need += min(mid,(ll)u);
            }
            if(need>=(ll)n*mid)
            {
                left = mid+1;
            }
            else{
                right = mid-1;
            }


        }
        return right;

    }
};