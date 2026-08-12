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
            if(i > index && candidates[i] == candidates[i - 1]) continue;

            individual.push_back(candidates[i]);

            solve(candidates,target,i+1,candidates[i]+curSum,ans,individual);

            individual.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         int curSum=0;
        vector<vector<int>>ans;
        vector<int>individual;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,curSum,ans,individual);
        return ans;
    }
};
