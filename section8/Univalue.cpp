class Solution {
public:

    // Correct version
    // int dfs(TreeNode* root, int& answ){
    //   if(!root) return 0;
    //
    //   int l = dfs(root->left, answ);
    //   int r = dfs(root->right, answ);
    //
    //   int l_val = 0;
    //   int r_val = 0;
    //   if(root->left && root->left->val == root->val){
    //     l_val = l + 1;
    //   }
    //
    //   if(root->right && root->right->val == root->val){
    //     r_val = r + 1;
    //   }
    //
    //   answ = max(answ, l_val + r_val);
    //
    //   return max(l_val, r_val);
    // }
    //


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

