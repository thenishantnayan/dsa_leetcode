class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        // we keep shrinking the search space
        // until start and end meet at peak index
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            // compare current element with next element
            // this tells us whether we are going UP or DOWN
            if(nums[mid] < nums[mid + 1])
            {
                // slope is increasing (↗️)
                // peak must be on RIGHT side
                start = mid + 1;
            }
            else
            {
                // slope is decreasing (↘️)
                // peak is on LEFT side or at mid
                end = mid;
            }
        }
        // when start == end, we found a peak index
        return start;
    }
};
