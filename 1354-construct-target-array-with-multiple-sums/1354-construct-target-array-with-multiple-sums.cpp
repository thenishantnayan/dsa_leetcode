class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>p;
        long sum=0;
        for(int i=0;i<target.size();i++){
            p.push(target[i]);
            sum+=target[i];
        }
        long long maxele,remsum,element;
        while(p.top()!=1){
            maxele = p.top();
            p.pop();
            remsum = sum - maxele;
            //maxelem = remsum + element
            // edge case
            if(remsum<=0 || remsum>=maxele)
            return 0;
            //changes will occur 
            element = maxele % remsum;
            if(element == 0)
            {
                if(remsum != 1)
                    return 0;
                else
                    return 1;
            }
            sum = remsum + element;
            p.push(element);
        }
        return 1;
    }
};