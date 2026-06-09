class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest =0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int num : st){
            if(st.find(num-1) == st.end()){ //check num-1 99 nhi hai to 
                int currentnum = num; //current num 100
                int count =1; // count 1 se hi 
            
            while(st.find(currentnum+1) != st.end()){ //uske aage ka present hai 
                currentnum++; //new num ko aage badhao
                count++; //count bhi 
            }
            longest = max(longest,count); // longest ko update kro 
            }
        }
        return longest;
    }
};