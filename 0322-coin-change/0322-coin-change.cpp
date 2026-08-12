class Solution {
public:
    int solve(vector<int>& coins, int amount, int n){
        // t[i][j] = min coins needed to make amount j using first i coin types
        int t[n+1][amount+1];

        // Initialize base cases
        for(int i=0;i<n+1;i++){                 // for every row (coin count 0..n)
            for(int j=0;j<amount+1;j++){        // for every column (amount 0..amount)
                if(i==0)
                    t[i][j] = amount+1;         // 0 coin types available -> impossible for j>0 (use amount+1 as "infinity")
                if(j==0)
                    t[i][j] = 0;                // amount 0 needs 0 coins, regardless of coins available (overwrites t[0][0] to 0)
            }
        }

        // Fill the DP table
        for(int i=1;i<n+1;i++){                             // consider coin types one by one (1-indexed row)
            for(int j=1;j<amount+1;j++){                     // for every target amount from 1 to amount
                if(coins[i-1]<=j)                            // if current coin value can fit into amount j
                    t[i][j] = min(t[i][j-coins[i-1]]+1,      // option 1: use this coin (stay on row i since unbounded), add 1 coin
                                  t[i-1][j]);                // option 2: don't use this coin, take best from previous row
                else
                    t[i][j] = t[i-1][j];                     // coin too big to use, so just carry forward previous row's answer
            }
        }

        // t[n][amount] holds min coins using all coin types; if it's still "infinity" (amount+1), it's unreachable
        return t[n][amount] > amount ? -1 : t[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount, coins.size());  // call helper with total number of coin types
    }
};