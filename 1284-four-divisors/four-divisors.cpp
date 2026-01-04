class Solution {
public:
int helper(int n){
    int count=0, sum=0;
    for (int i=1; i<=sqrt(n);i++) {
        if (n%i==0) {
            if (n/i == i) {
                count++;
                sum += i;
            } 
            else {
                count += 2;
                sum = sum + i + (n/i);
            }
        }
    }
    if(count==4) return sum;
    return -1;
}

    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int k = helper(nums[i]);
            if(k>0) ans+=k;
            cout<<ans<<endl;
        }
        return ans;
    }
};