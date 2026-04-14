class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        return level(root, x, 0) == level(root, y, 0) && !isSiblings(root, x, y);
    }
    int level(TreeNode* node, int val, int l) {
        if (!node) return 0;
        if (node->val == val) return l;
        int left = level(node->left, val, l + 1);
        if (left != 0) return left;
        return level(node->right, val, l + 1);
    }
    bool isSiblings(TreeNode* node, int x, int y) {
        if (!node) return false;
        if (node->left && node->right) {
            if ((node->left->val == x && node->right->val == y) ||
                (node->left->val == y && node->right->val == x)) return true;
        }
        return isSiblings(node->left, x, y) || isSiblings(node->right, x, y);
    }
};