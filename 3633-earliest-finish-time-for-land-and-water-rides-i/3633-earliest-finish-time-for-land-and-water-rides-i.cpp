class Solution {
public:
    int calc(vector<int>& aStart, vector<int>& aDur,
             vector<int>& bStart, vector<int>& bDur) {

        int firstFinish = INT_MAX;

        for (int i = 0; i < aStart.size(); i++) {
            firstFinish = min(firstFinish, aStart[i] + aDur[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < bStart.size(); i++) {
            ans = min(ans,
                      max(firstFinish, bStart[i]) + bDur[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst =
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration);

        int waterFirst =
            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};