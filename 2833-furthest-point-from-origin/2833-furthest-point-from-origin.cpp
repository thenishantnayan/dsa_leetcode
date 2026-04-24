class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int L=0,R=0,B=0;
        for(char c : moves)
        {
            if(c =='L')L++;
            else if(c == 'R')R++;
            else B++;
        }
        return abs(R-L)+B;
    }
};