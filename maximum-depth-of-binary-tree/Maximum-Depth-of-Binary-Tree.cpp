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
    int maxDepth(TreeNode* root) {
        using namespace std;

        if (root == nullptr) { return 0; }

        queue<TreeNode*> q{};

        q.push(root);

        auto max_depth = 0;

        while (not q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto current = q.front();
                q.pop();
                
                if (current->left)  { q.push(current->left);  }
                if (current->right) { q.push(current->right); }
            }
            ++max_depth;
        }
        return max_depth;
    }
};