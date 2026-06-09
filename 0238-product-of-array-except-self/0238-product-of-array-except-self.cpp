class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        //store final answer 
        vector<int>ans(n,1);

        //build prefix
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1]*nums[i-1];
        }

        //stores suffix product
        int suffix = 1;
        //traverse from right to left
        for(int i=n-1;i>=0;i--){
            //multiply prefix and suffix
            ans[i] = ans[i]*suffix;
            //update suffix
            suffix = suffix*nums[i];
        }
        return ans;
    }
};