class Solution {
public:
    int sumofsubset(vector<int>& nums,int sum,int n){
        const int MOD = 1e9 +7;
        // int t[n+1][sum+1];
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                t[i][j] = 0;
                if(j==0)
                t[i][j] = 1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(nums[i-1]<=j)
                    t[i][j] = (t[i-1][j-nums[i-1]]+t[i-1][j]) % MOD;
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>total) return 0;
        if((total+target) % 2 != 0) return 0;
        int sum = (total + target)/2;
        return sumofsubset(nums,sum,nums.size());
    }
};