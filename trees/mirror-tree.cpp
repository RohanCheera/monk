
//gfg problem link : https://www.geeksforgeeks.org/problems/mirror-tree/1


class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        solve(root);
    }
    Node* solve(Node* root){
        if(!root)return root;
        Node* l=solve(root->left);
        Node* r=solve(root->right);
        root->right=l;
        root->left=r;
        return root;
    }
};
