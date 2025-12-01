#define ll long long
class Solution {
public:
    bool isValid(ll mid,int totalTrips,vector<int>& time)
    {
        ll cnt=0;
        for(auto u:time)
        {
            cnt += (mid/u*1LL);
        }
        return cnt>=totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low =0,high=1e14,mid,ans=0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(isValid(mid,totalTrips,time))
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};