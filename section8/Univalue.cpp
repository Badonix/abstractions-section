/**
 *  NOT COMPLETE
 */
class Solution {
public:

    int dfs(TreeNode* root, int& answ){
      if(!root) return 0;

      int l = dfs(root->left);
      int r = dfs(root->right);

      if(root->left && root->left->val == root->val){
        l++;
      }

      if(root->right && root->right->val == root->val){
        r++;
      }

      answ = max(answ, l + r);

      return max(l, r);
    }


    int longestUnivaluePath(TreeNode* root) {
       int answ = 0;
       dfs(root, answ);
       return answ;
    }
};

