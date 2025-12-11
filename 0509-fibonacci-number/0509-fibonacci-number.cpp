class Solution {
public:
    int fibSolve(int i,vector<int>&dp){
        if(i == 1 || i == 0)   return i; // Base cases: F(0) = 0, F(1) = 1 
        if(dp[i] != -1) return dp[i];
        dp[i] = fibSolve(i - 1, dp) + fibSolve(i - 2, dp); 
        return dp[i];
    }

    int fib(int n) {
        vector<int>dp(31, -1); 
        int ans =  fibSolve(n, dp);
        return ans; 
    }
};