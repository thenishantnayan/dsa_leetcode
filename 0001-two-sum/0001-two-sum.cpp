class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int rem = target - nums[i]; // remaining nikalo
            if(mp.find(rem) != mp.end()) // find kro rem hai ya nhi , hai to 
                return {mp[rem],i}; //return index dena hai  
            
            mp[nums[i]] = i; //store current value baad me check krne k liy
        }
        return {};
    }
};