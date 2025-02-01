// Leetcode Qn Link            : https://leetcode.com/problems/permutations/

//method 1:
class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int id,vector<int>& nums){
        if(id==n){
            result.push_back(nums);
            return ;
        }
        for(int i=id;i<n;i++){
            swap(nums[i],nums[id]);
            solve(id+1,nums);
            swap(nums[i],nums[id]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        solve(0,nums);
        return result;
        
    }
};


//method 2:

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        do{
            res.push_back(nums);

        }while(next_permutation(nums.begin(),nums.end()));
        return res;
        
    }
};

