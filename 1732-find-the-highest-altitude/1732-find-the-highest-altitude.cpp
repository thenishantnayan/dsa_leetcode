class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int maxi = 0;
        for(int g: gain){
            curr += g;
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};