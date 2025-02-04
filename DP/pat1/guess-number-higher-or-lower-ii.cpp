// Leetcode Qn Link : https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

class Solution {
public:
    int dp[202][202];
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
    int solve(int low,int high){
        if(low>=high)return 0;
        if(dp[low][high]!=-1)return dp[low][high];
        int mn=INT_MAX;
        for(int i=low;i<=high;i++){
            int ans=i+max(solve(low,i-1),solve(i+1,high));
            mn=min(mn,ans);
        }
        return dp[low][high]=mn;
    }
};
