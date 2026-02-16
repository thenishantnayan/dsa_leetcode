class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<ans)
                ans=nums[i];
        }
        return ans;
    }
};