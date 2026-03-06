class Solution {
public:
    bool checkOnesSegment(string s) {
        // at most 1 continous segment maang rha yaani 01 aaya to false return kyuki dubara continous segment start ho jayega

        int n = s.size();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0' && s[i+1]=='1')
                return false;
        }
        return true;
    }
};