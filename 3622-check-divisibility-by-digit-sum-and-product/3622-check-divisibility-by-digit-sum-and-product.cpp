class Solution {
public:
    bool checkDivisibility(int n) {
        if(n<1)
        return false;
        int og= n;
        int sum1 =0;
        int sum2 =1;

        while(n>0){
            int rem = n%10;
            sum1 = sum1+rem;
            sum2 = sum2*rem;
            n=n/10;
        }
        int sum = sum1+sum2;
        if(og%sum == 0)
        return true;
        else
        return false;
    }
};