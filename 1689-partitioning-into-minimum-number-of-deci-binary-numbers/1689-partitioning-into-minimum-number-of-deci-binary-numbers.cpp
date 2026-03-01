class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end())-'0';

        //for this return the maximum integer which needed deci binary numbers
        // to convert single digit string into integer '7'-'0'
    }
};