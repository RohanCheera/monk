
//LeetCode Qn Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/



class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;

        Node* temp = root;

        queue<Node*> q;
        q.push(temp);
        while(!q.empty()){
            int size = q.size();

            vector<Node*> curr;
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                curr.push_back(node);

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            for(int i = 0; i < curr.size(); i++){
                Node* currNode = curr[i];
                Node* nextNode = (i + 1 < curr.size()) ? curr[i+1] : NULL;

                currNode->next = nextNode;
            }
        }

        return root;

    }
};
