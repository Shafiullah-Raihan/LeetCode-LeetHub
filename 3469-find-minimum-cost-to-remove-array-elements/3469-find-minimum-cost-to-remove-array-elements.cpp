class Solution {
public:
    int dp[1001][1001] , n;

    int raihan(vector<int>& arr,int pre, int cur)
    {
        if(cur==n-1) return max(arr[pre],arr[cur]);
        if(cur>=n) return arr[pre];
        if(dp[pre][cur] != -1) return dp[pre][cur];
        int ans=INT_MAX;
        ans = min(ans,max(arr[cur],arr[cur+1]) + raihan(arr,pre,cur+2));
        ans = min(ans,max(arr[pre],arr[cur+1])+raihan(arr,cur,cur+2));
        ans = min(ans,max(arr[pre],arr[cur])+raihan(arr,cur+1,cur+2));
        return dp[pre][cur] = ans;
    }

    int minCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return raihan(nums,0,1);
    }
};