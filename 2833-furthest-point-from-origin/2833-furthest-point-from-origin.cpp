class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int count = 0, B=0;
        for(int i=0;i<n;i++)
        {
            if(moves[i] == 'L')
                count--;
            else if(moves[i] == 'R')
                count++;
            else
                B++;
        }
        return abs(count) + B;
    }
};