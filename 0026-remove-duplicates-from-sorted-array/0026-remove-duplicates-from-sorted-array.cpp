class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();      // size of the array
        // If array is empty, no unique elements
        if (n == 0)
            return 0;
            
        int i = 0;  
        // 'i' points to the index of the last unique element
        // nums[0..i] will always contain unique elements

        // 'j' is the scanning pointer
        for (int j = 1; j < n; j++) {

            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move 'i' to next position for new unique element
                i++;
                // Place the new unique element at index 'i'
                nums[i] = nums[j];
            }
            // If nums[j] == nums[i], it's a duplicate → skip it
        }

        // Number of unique elements = i + 1
        return i + 1;
    }
};
