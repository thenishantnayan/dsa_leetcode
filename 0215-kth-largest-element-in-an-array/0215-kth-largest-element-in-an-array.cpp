class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=n-1;
        
        priority_queue<int,vector<int>,greater<int>>p;

        for(int i=0;i<k;i++)
            p.push(nums[i]);
        
        for(int i=k;i<n;i++)
        {
            if(nums[i]>p.top())
            {
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};