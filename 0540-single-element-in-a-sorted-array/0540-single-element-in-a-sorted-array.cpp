class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();          
        int low = 0, high = n - 1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;

            // pairs always start from EVEN index before the single element
            // so if mid becomes odd, shift it one step back
            // this makes mid always point to the FIRST element of a pair
            if(mid % 2 == 1)
                mid--;

            // check if current pair is valid
            if(nums[mid] == nums[mid + 1])
            {
                // pair is correct → single element lies on RIGHT side
                // skip this confirmed pair
                low = mid + 2;
            }
            else
            {
                // pair is broken → single element lies on LEFT side
                // include mid in search space
                high = mid;
            }
        }
        // when low == high, we found the single element index
        return nums[low];
    }
};
