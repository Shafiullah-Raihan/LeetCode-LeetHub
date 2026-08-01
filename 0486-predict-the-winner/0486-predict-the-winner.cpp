class Solution {
public:
    int dp[21][21];  

    int solve(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        
        int pickLeft = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int pickRight = nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j-2));

        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int score = solve(nums, 0, nums.size() - 1);
        return score >= total - score;
    }
};
