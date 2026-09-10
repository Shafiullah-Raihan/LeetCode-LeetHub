/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #define pii pair<int,int>
class Solution {
public:
    int ans =0;
    pii dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {0,0};
        }
        // int ans=0;
        pii left = dfs(root->left);
        pii right = dfs(root->right);
        int lnc = left.first;int lsum = left.second;
        int rnc = right.first;int rsum = right.second;
        int cnt = 1 + lnc + rnc;
        int sum = (root->val + lsum+rsum);
        if(sum/cnt == root->val) ans++;
        return {cnt,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;

    }
};