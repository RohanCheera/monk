

//gfg problem link :https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
       return solve(node)-1;
    }
    int solve(Node* root){
        if(!root)return 0;
        return 1+max(solve(root->left),solve(root->right));
    }
};
