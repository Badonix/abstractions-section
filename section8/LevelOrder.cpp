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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> answ;
      rec(root, 0, answ);
      return answ;
    }

    void rec(TreeNode* root, int level, vector<vector<int>>& answ){
      if(!root) return nullptr;

      if(level == answ.size()){
        vector<int> v;
        answ.push_back(v);
      }

      answ[level].push_back(root->val);

      rec(root->left, level + 1, answ);
      rec(root->right, level + 1, answ);
    }
};

