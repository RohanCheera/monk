

// gfg problem Link :https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1



class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root==NULL || root==n1 || root==n2)return root;
        Node* left_tree=LCA(root->left,n1,n2);
        Node* right_tree=LCA(root->right,n1,n2);
        if(left_tree==NULL){
            return right_tree;
        }else if (right_tree==NULL){
            return left_tree;
        }
        return root;
    }
};
