class Solution {
public:
int n,m;
int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
    if(i==n || j==m) return INT_MIN;
    if(dp[i][j]!=INT_MIN) return dp[i][j];
    dp[i][j] = max((nums1[i]*nums2[j] + max(helper(i+1,j+1,nums1,nums2,dp),0)), 
    max(helper(i+1,j,nums1,nums2,dp), helper(i,j+1,nums1,nums2,dp)));
    return dp[i][j]; 
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(),m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return helper(0,0,nums1,nums2,dp);
    }
};