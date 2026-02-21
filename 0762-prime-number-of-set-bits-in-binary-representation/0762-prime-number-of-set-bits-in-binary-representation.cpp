class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>prime = {2,3,5,7,11,13,17,19}; //range 20
        int ans =0;
        for(int i=left;i<=right;i++)
        {
            int bits = __builtin_popcount(i); // count 1
            
            if(prime.count(bits))
                ans++;
        }
        return ans;
    }    
};