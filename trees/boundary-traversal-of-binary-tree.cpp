//gfg problem link :https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
  public:
  bool isLeaf(Node* root){
      return root->right==NULL && root->left==NULL;
  }
  void addleft(Node* root,vector<int>& res){
      Node* curr=root->left;
      
      while(curr!=NULL){
          if(isLeaf(curr)==false){
              
            res.push_back(curr->data);
          }
          if(curr->left!=NULL){
              curr=curr->left;
          }
          else {
              curr=curr->right;
          }
      }
      
  }
  void addLeaves(Node* root,vector<int>& res){
      if(isLeaf(root)){
          res.push_back(root->data);
          return ;
      }
      if(root->left!=NULL)addLeaves(root->left,res);
      if(root->right!=NULL)addLeaves(root->right,res);
      
  }
  void addright(Node* root,vector<int>& res){
      Node* curr=root->right;
      stack<int> st;
      while(curr!=NULL){
          if(isLeaf(curr)==false){
              
            st.push(curr->data);
          }
          if(curr->right!=NULL){
              curr=curr->right;
          }
          else {
              curr=curr->left;
          }
      }
      while(!st.empty()){
          res.push_back(st.top());
          st.pop();
      }
      
      
  }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root)return {};
        if(isLeaf(root))return {root->data};
        res.push_back(root->data);
        addleft(root,res);
        addLeaves(root,res);
        addright(root,res);
        return res;
    }
};
