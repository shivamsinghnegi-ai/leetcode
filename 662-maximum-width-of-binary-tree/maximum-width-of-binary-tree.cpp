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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        long long maxi = 0;

        q.push({root, 0});

        while (!q.empty()) {
            long long size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            maxi = max(maxi, end - start + 1);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second - start;
                q.pop();
                if (node->left)
                    q.push({node->left, 2 * index + 1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }
        }

        return maxi;
    }
};