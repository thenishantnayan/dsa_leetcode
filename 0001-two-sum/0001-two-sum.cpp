class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size();i++){
            int need = target - nums[i];

            if(mp.find(need) != mp.end())
                return {i,mp[need]};

            mp[nums[i]] = i; //most mistske yaha index usko save kr rhe jisme mp ke nums ke i ko ith me store krenge 
        }
        return {};
    }
};