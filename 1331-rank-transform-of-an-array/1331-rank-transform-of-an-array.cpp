class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // vector<int>a(arr.size()); this is wrong it will create a vector of arr size filled with 0 
        // instead use simple vector<int>a or niche wala 
        vector<int>a = arr;
        sort(a.begin(),a.end());

        unordered_map<int,int>mp;
        int rank = 1;

        //assign ranks 
        for(int x : a){
            if(mp.find(x) == mp.end()){
            mp[x] = rank;
            rank++;
            }
        }
        //replace original values with ranks
        for(int i=0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};