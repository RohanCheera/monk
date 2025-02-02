// gfg Qn Link :https://www.geeksforgeeks.org/problems/level-order-traversal/1



class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp;
            while(sz--){
                Node* cur=q.front();
                q.pop();
                temp.push_back(cur->data);
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
                
            }
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};
