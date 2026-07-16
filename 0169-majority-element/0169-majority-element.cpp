class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;   // Stores the current majority candidate
        int count = 0;       // Tracks the candidate's vote count

        // Traverse all elements
        for (int num : nums) {

            // If no candidate is left, choose the current number
            if (count == 0)
                candidate = num;

            // Same as candidate -> increase votes
            if (num == candidate)
                count++;

            // Different from candidate -> decrease votes
            else
                count--;
        }

        // Remaining candidate is the majority element
        return candidate;
    }
};