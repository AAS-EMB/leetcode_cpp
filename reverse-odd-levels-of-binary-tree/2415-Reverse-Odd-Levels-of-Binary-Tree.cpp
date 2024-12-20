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
    TreeNode* reverseOddLevels(TreeNode* root) {
        treverse(root->left, root->right, 0);
        return root;
    }

    void treverse(TreeNode* left, TreeNode* right, int level) {
        if (not left or not right) { return; }

        if (level % 2 == 0) {
            swap(left->val, right->val);
        }

        // left
        treverse(left->left, right->right, level + 1);

        // right
        treverse(left->right, right->left, level + 1);

    }
};