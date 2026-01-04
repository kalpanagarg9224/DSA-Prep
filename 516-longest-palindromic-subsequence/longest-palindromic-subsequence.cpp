class Solution {
public:
    int solve(string& str, vector<vector<int>>&dp, int s, int e){
        if (s==e) return 1;
        if (s>e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        if (str[s]==str[e]) return (2+solve(str,dp,s+1,e-1));
        
        int l = solve(str,dp,s+1,e);
        int r = solve(str, dp,s,e-1);
        return dp[s][e] = max(l,r); 
    }

    int longestPalindromeSubseq(string s){
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = solve(s, dp, 0, n-1);
        return ans;
    }
};