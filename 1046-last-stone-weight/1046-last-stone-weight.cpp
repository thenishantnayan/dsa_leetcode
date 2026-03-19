class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int>p;
        for(int i=0;i<n;i++)
            p.push(stones[i]);

        while(p.size()>1)
        {
            int weight = p.top();
            p.pop();
            weight -= p.top();
            p.pop();

            if(weight)
                p.push(weight); 
        }
        return p.empty() ? 0 : p.top(); 
    }
};