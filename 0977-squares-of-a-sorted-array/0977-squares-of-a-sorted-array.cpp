class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // optimised solution 
        int n=nums.size();
        vector<int>result(n);
        int i=0,j=n-1;
        int index = n-1;
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                result[index] = nums[j]*nums[j];
                j--;
            }
            else
            {
                result[index] = nums[i]*nums[i];
                i++;
            }
            index--;
        }
        return result;
    }
};