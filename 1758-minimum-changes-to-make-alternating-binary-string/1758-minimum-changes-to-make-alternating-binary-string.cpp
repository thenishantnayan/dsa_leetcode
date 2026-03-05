class Solution {
public:
    int solve(string s, char start)
    {
        int count =0;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]!=start)
                count++;
            
            //flip character
            start = (start =='0') ? '1' : '0';
        }
        return count;
    }

    int minOperations(string s) {
        int opt1 = solve(s,'0'); //010101
        int opt2 = solve(s,'1'); //101010

        return min(opt1,opt2);
    }
};