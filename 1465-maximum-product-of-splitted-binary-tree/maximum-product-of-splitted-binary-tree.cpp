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
    long long total = 0;
    long long ans = 0;
    int MOD = 1e9 + 7;
    long long solve(TreeNode* root) {
        if (!root) return 0;
        long long left = solve(root->left);
        long long right = solve(root->right);
        long long cur = root->val + left + right;
        ans = max(ans, cur * (total - cur));
        return cur;
    }
    int maxProduct(TreeNode* root) {
        total = solve(root);  
        solve(root);           
        return ans % MOD;
    }
};
