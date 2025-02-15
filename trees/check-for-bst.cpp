// gfg problem link : https://www.geeksforgeeks.org/problems/check-for-bst/1

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        vector<int> ans;
        solve(root,ans);
        bool flag=true;
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]>ans[i])return false;
        }
        return flag;
    }
    void solve(Node* root,vector<int>& ans){
        if(!root)return ;
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
        
    }
};
