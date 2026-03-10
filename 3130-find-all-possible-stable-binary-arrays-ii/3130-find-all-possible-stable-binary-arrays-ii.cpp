#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1e9 + 7;
        // dp[i][j][0] -> ending with 0, dp[i][j][1] -> ending with 1
        // Using vector of vectors for clarity; can be flattened for speed.
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        // Base cases: Arrays consisting of only 0s or only 1s
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                // To get dp0[i][j], we append a '0' to existing arrays.
                // We can append '0' to any stable array of (i-1, j) 
                // EXCEPT those that already have 'limit' consecutive 0s.
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % MOD;
                if (i > limit) {
                    // Subtract configurations that would exceed the limit of 0s
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + MOD) % MOD;
                }

                // To get dp1[i][j], we append a '1' to existing arrays.
                dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % MOD;
                if (j > limit) {
                    // Subtract configurations that would exceed the limit of 1s
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + MOD) % MOD;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};