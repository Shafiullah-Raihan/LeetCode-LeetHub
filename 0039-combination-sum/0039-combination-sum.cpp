class Solution {
public:


    void solve(vector<int>& candidates, int target,int index,int curSum,vector<vector<int>>& ans,vector<int>& individual)
    {
        if(curSum>target){
            return ;
        }
        if(curSum == target){
            ans.push_back(individual);
            return;

        }
        for(int i=index;i<candidates.size();i++)
        {
            individual.push_back(candidates[i]);
            solve(candidates,target,i,candidates[i]+curSum,ans,individual);
            individual.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int curSum=0;
        vector<vector<int>>ans;
        vector<int>individual;
        solve(candidates,target,0,curSum,ans,individual);
        return ans;
    }
};