class Solution {
public:
    int findfirst(vector<int>&nums,int target)
    {
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                end = mid -1; //move left
            }
            else if (nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }      
        }
        return ans;
    }
    int findlast(vector<int>&nums,int target)
    {
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                start = mid+1; //move right
            }
            else if (nums[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }

        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findfirst(nums,target);
        int last = findlast(nums,target);
        return {first,last};
        
    }
};