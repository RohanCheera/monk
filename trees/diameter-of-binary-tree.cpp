

// gfg problem link : https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
  public:
    int mx=0;
    int diameter(Node* root) {
        if(!root)return 0;
        solve(root);
        return mx;
    }
    int solve(Node* root){
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        mx=max(l+r,mx);
        return 1+max(l,r);
    }
    
};
