const int mx = 1e5+10;
class Solution {
public:
    vector<int>div;
    void precompute()
    {
        for(int i=1;i<mx;i++)
        {
            for(int j=i;j<mx;j+=i)
            {
                div[j]++;
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        div.assign(mx,0);
        precompute();
        vector<int>exactFour;
        for(auto u:nums)
        {
            if(div[u] == 4)
            {
                exactFour.push_back(u);
            }
        }
        int ans=0;
        for(auto u:exactFour)
        {
            for(int i=1;i*i<=u;i++)
            {
                if(u%i==0) {
                    ans += i;
                    ans += (u/i);
                }
            }
        }
        return ans;
    }
};