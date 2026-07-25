class Solution {
public:
    int maxProduct(int n) {
        int first =0;
        int last =0;
        while(n>0){
            int digit = n%10;
            if(digit>=first){
                last = first;
                first = digit;
            }
            else if (digit > last){
                last = digit;
            }
            n=n/10;
        }
        return first*last;
    }
};