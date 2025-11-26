class Solution {
public:
    unordered_map<string, int> memo; 
    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }

        string key = to_string(i) + "," + to_string(total);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        return memo[key] = backtrack(i + 1, total + nums[i], nums, target) +backtrack(i + 1, total - nums[i], nums, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memo.clear(); 
        return backtrack(0, 0, nums, target);
    }
};



