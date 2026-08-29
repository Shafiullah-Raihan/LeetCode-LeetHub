class Solution {
    int solve(vector<int>& nums, int k, vector<vector<vector<int>>>& dp,int idx, int op1, int op2) {
        if (idx == nums.size()) return 0;

        int& ans = dp[idx][op1][op2];
        if (ans != -1) return ans;

        int x = nums[idx];
        ans = x + solve(nums, k, dp, idx + 1, op1, op2);

        if (op1) {
            ans = min(ans, (x + 1) / 2 +solve(nums, k, dp, idx + 1, op1 - 1, op2));
        }

        if (op2 && x >= k) {
            ans = min(ans, x - k + solve(nums, k, dp, idx + 1, op1, op2 - 1));
        }

        if (op1 && op2) {
            int half = (x + 1) / 2;

            if (half >= k) {
                ans = min(ans, half - k +solve(nums, k, dp, idx + 1, op1 - 1, op2 - 1));
            }

            if (x >= k) {
                ans = min(ans, (x - k + 1) / 2 +solve(nums, k, dp, idx + 1, op1 - 1, op2 - 1));
            }
        }

        return ans;
    }

public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));

        return solve(nums, k, dp, 0, op1, op2);
    }
};





// class Solution {
// public:
//     int minArraySum(vector<int>& nums, int k, int op1, int op2) {
//         multiset<pair<int,int>>mlst;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             mlst.insert({nums[i],i});
//         }

//         unordered_set<int>st;

//         int choice1=op1,choice2=op2;
//         int ans =0;
//         while((choice1 || choice2) && !mlst.empty())
//         {
//             auto it = *mlst.rbegin();
//             mlst.erase(prev(mlst.end()));
//             int number = it.first;int idx = it.second;
//             int temp1,temp2;
//             if(choice1)
//             {
//                 temp1 = (number+1)/2;
//             }
//             else{
//                 temp1 = INT_MAX;
//             }
//             if(choice2)
//             {
//                 if(number-k>=0)
//                 {
//                     temp2= number-k;
//                 }
//                 else{
//                     temp2 = INT_MAX;
//                 }
//             }
//             else{
//                 temp2=INT_MAX;
//             }
//             // int temp1 = (number+1)/2,temp2 = (number-k>=0?number-k:INT_MAX);
//             if(temp1<temp2 )
//             {
//                 choice1--;
//                 ans+=temp1;
//             }
//             else{
//                 choice2--;
//                 ans+=temp2;
//             }
            

//         }
//         for(auto u:mlst)
//         {
//             auto number = u.first;auto idx = u.second;
//             ans+= number;
//         }
//         return ans;
//     }
// };