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
    bool isSymmetric(TreeNode* root) {
        return rec(root->left, root->right);
    }

    bool rec(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;

        if(!l || !r || l->val != r->val) return false;

        return rec(l->left, r->right) && rec(l->right, r->left);
    }
};


