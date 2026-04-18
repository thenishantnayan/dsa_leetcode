class Solution {
public:
    int mirrorDistance(int n) {
    int ans=0,rem=0;
    int num = n;
    while(num>0)
    {
        rem = num%10;
        ans = ans*10+rem;
        num = num/10;
    }
        return abs(n-ans);
    }
};