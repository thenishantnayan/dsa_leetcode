class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first=-1,last=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target && first ==-1 && last == -1)
            {
                first = i;
                last = i;
            }
            else if(nums[i] == target && first !=-1 && last != -1)
            {
                last =i;
            }
        }
        return {first,last};
    }
};