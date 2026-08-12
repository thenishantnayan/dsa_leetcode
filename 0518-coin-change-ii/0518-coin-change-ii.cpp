class Solution {
public:
    int solve(int amount,vector<int>&coins,int n){
        long long t[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }
        for(int i=1;i<n+1;i++){
    for(int j=1;j<amount+1;j++){

        if(coins[i-1] <= j) {

            if(t[i][j-coins[i-1]] > INT_MAX - t[i-1][j])
                t[i][j] = INT_MAX;
            else
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];

        }
        else
            t[i][j] = t[i-1][j];
    }
}
        return t[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        return solve(amount,coins,coins.size());
    }
};