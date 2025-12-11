class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
        dp[1]=costs[0]+1;
        if(n==1) return dp[1];
        

        for(int i=2;i<=n;i++)
        {
            int mn = INT_MAX;
            for(int j=i-1;j>=0 && i-j<=3;j--)
            {
                
                mn = min(mn,costs[i-1]+((i-j)*(i-j))+dp[j] );
            }
            dp[i] = mn;
        }
        return dp[n];


        // for(int i=4;i<=n;i++)
        // {
        //     int mn = INT_MAX;
        //     for(int j=1;j<=3;j++)
        //     {
        //         mn = min(mn,costs[i-1]+(i-j+1)*(i-j+1));
        //     }
        //     dp[i] = mn;
        // }
        // return dp[n];
    }
};