class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>answer;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            vector<int>temp;
            while(num>0)
            {
                temp.push_back(num % 10);
                num/=10;
            }

            for(int k=temp.size()-1;k>=0;k--)
            {
                answer.push_back(temp[k]);
            }
        }
        return answer;
    }
};