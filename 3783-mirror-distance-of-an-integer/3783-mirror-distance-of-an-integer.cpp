class Solution {
public:
    int mirrorDistance(int n) {
        int num =n;
        int rem =0;
        int rev =0;
        while(num>0){
            rem = num % 10;
            num/=10;
            rev = rev*10+ rem;
        }
        return abs(rev-n);
    }
};