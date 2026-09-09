class Solution {
public:
    long long countCommas(long long n) {
        long long count =0;
        if(n<1000)
            return 0;
        // for(long long i=n;i>=1000;i--){
        //     count++;
        // }

        if(n>=1000)
            count+=(n-1000+1);
        if(n>=1000000)
            count+=(n-1000000+1);
        if(n>=1000000000)
            count+=(n-1000000000+1);
        if(n>=1000000000000)
            count+=(n-1000000000000+1);
        if(n>=1000000000000000)
            count+=(n-1000000000000000+1);
        
        return count;
    }
};