class Solution {
public:
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if (i >= s1.length() && j >= s2.length()) return 0;
        if(i==s1.length()){
            int sum=0;
            for(int k=j;k<s2.length();k++) sum+=s2[k];
            return sum;
        }
        if(j==s2.length()){
            int sum=0;
            for(int k=i;k<s1.length();k++) sum+=s1[k];
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=helper(i+1,j+1,s1,s2,dp);
        return dp[i][j]= min({helper(i+1,j,s1,s2,dp)+s1[i],helper(i,j+1,s1,s2,dp)+s2[j]});
    }

    int minimumDeleteSum(string s1, string s2) {
        int l1=s1.length() , l2=s2.length();
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return helper(0,0,s1,s2,dp);
    }
};