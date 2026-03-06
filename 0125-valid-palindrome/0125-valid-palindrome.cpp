class Solution {
public:
    bool isPalindrome(string s) {
        //use two pointer 
        //ignore the case that is not in alnum
        // isalnum(c) check digit or char
        // tolower(c) convert to lower

        int n = s.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            if(!isalnum(s[start]))
                start++;
            
            else if(!isalnum(s[end]))
                end--;

            else
            {
                if(tolower(s[start]) != tolower(s[end]))
                    return false;

                start++;
                end--;
            }  
        }
        return true;
    }
};