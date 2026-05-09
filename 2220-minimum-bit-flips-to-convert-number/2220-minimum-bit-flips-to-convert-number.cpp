class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count =0;
        int x = start^goal; //xor gives only 1 same value comes to 0  
        while(x){
            x= x & (x-1); // remove right most bit 
            count++;
        }
        return count;
    }
};