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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    using ll = long long;
    template<typename T>
    using v = vector<T>;

    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_map<TreeNode*, array<ll,2>> dp;

    void build(TreeNode* root)
    {
        if(root==NULL)
            return;

        if(root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);

            build(root->left);
        }

        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);

            build(root->right);
        }
    }

    void dfs(TreeNode* node, TreeNode* parent)
    {
        dp[node][0]=0;
        dp[node][1]=node->val;

        for(auto child:adj[node])
        {
            if(child==parent)
                continue;

            dfs(child,node);

            dp[node][0]+=max(dp[child][0],dp[child][1]);

            dp[node][1]+=dp[child][0];
        }
    }

    int rob(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        build(root);

        dfs(root,NULL);

        return max(dp[root][0],dp[root][1]);
    }
};