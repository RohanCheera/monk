// Leetcode Qn Link : https://leetcode.com/problems/combination-sum

//Method 1: Without using for loop
class Solution {
public:
    void solve(int idx,vector<int>& candidates,int target,vector<int> temp,vector<vector<int>>& ans){
        if(idx>=candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return ;
            
        }

        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            solve(idx,candidates,target-candidates[idx],temp,ans);
            temp.pop_back();
        }
        solve(idx+1,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};


// Method 2: using for loop  and sorting 

class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int> temp,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};

// Method 3: for loop without sorting 
class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int> temp,
               vector<vector<int>>& ans) {
        if (target < 0)
            return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};
