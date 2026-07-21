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
class Solution {
public:
    int res = INT_MIN;

    int solve(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int self = root->val;

        int left = solve(root->left);
        int right = solve(root->right);

       
        int temp=max(max(left,right) +root->val,root->val);    //jo upar bhejna h
        int ans = max(temp, self + left + right);  //neeche me max path sum mil jaaye
         res= max(res,ans);
        return temp;
    }

    int maxPathSum(TreeNode* root) {

        solve(root);

        return res;
    }
};