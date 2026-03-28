class Solution {
public:
    int reverse(int x) {
        int rem,ans=0,n=x;
        while(n)
        {
            rem = n%10;
            n=n/10;
            // Overflow check
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            ans = ans*10 +rem;
        }
        return ans;
    }
};