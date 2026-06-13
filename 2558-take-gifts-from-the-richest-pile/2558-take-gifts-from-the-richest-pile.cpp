class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;

        for(int i=0;i<gifts.size();i++)
            p.push(gifts[i]);
        long long ans =0;
        while(k--){
            int x = p.top();
            p.pop();
            p.push(int(sqrt(x)));
        }
        while(!p.empty()){
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};