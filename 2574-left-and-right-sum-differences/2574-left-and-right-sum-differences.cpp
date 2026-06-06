class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightsum=0,leftsum=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            rightsum -=nums[i];
            ans.push_back(abs(leftsum-rightsum));
            leftsum+= nums[i];
        }
        return ans;
    }
};