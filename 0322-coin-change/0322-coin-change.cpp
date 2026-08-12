class Solution {
public:
    int solve(vector<int>& coins,int amount,int n){
        int t[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0)
                    t[i][j] = amount+1;
                if(j==0)
                    t[i][j] = 0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j)
                    t[i][j] = min(t[i][j-coins[i-1]]+1,t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][amount] > amount ? -1 : t[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        //coin-wt,sum-W
        return solve(coins,amount,coins.size());
    }
};