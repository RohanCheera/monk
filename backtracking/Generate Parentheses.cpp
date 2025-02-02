// Leetcode Qn Link : https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string op="";
        int open=n,close=n;
        solve(open,close,ans,op);
        return ans;
    }
    void solve(int open,int close,vector<string>& ans, string op){
        if(open<0 || close <0)return ;
        if(open==0 && close==0){
            ans.push_back(op);
            return ;
        }
        if(open>0){
            string op1=op;
            op1+='(';
            solve(open-1,close,ans,op1);
        }
        if(close>open){
            string op1=op;
            op1+=')';
            solve(open,close-1,ans,op1);
        }

    }
};
