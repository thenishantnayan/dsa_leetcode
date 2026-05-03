class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();
        if (m != n)
            return false;
        string temp = s+s;
        if(temp.find(goal) != string::npos)
            return true;

        return false;
    }
};