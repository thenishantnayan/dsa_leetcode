class Solution {
public:
    char findKthBit(int n, int k) {
        // main structure
        //Previous string + "1" + mirror (reverse + flip)
        // mid element always 1
        if(n==1)
        return '0';

        int mid = 1 << (n-1);

        if(k == mid)
        return '1';

        if(k<mid)
        {
            return findKthBit(n-1,k);
        }
        else
        {
            char ch = findKthBit(n-1,(1<<n)-k);
            return ch == '0'?'1':'0';
        }
    }
};