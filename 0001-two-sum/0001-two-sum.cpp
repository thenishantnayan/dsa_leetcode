class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int start=0,end=n-1;
        while(start<end)
        {
            int sum = arr[start].first + arr[end].first;
            
            if(sum == target)
                return {arr[start].second,arr[end].second};
            
            else if(sum<target)
                start++;
            
            else
                end--;
        }
        return {};
    }
};