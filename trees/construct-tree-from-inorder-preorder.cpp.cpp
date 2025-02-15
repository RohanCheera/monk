
// gfg problem link : https://www.geeksforgeeks.org/problems/construct-tree-1/

class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> inmp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            inmp[inorder[i]]=i;
        }
        return buildTree(preorder,inorder,0,n-1,0,n-1,inmp);
    }
    
    Node* buildTree(vector<int>& preorder, vector<int>& inorder,
    int ins,int ine,int ps,int pe,unordered_map<int,int>& inmap) {

        if(ins>ine || ps>pe)return NULL;

        Node* root=new Node(preorder[ps]);

        int numsleft=inmap[preorder[ps]]-ins;

        root->left=buildTree(preorder,inorder,ins,inmap[preorder[ps]]-1,ps+1,ps+numsleft,inmap);

        root->right=buildTree(preorder,inorder,inmap[preorder[ps]]+1,ine,ps+numsleft+1,pe,inmap);
        return root;

    }
    
};
