class Solution {
public:
    void backTrack(vector<int>& nums, vector<int>& stateAnswer,vector<vector<int>>& ans, int start) {
        ans.push_back(stateAnswer);
        for (int i = start; i < nums.size(); i++) {
            stateAnswer.push_back(nums[i]);
            backTrack(nums, stateAnswer, ans, i + 1);
            stateAnswer.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> stateAnswer;
        backTrack(nums, stateAnswer, ans, 0);
        return ans;
    }
};