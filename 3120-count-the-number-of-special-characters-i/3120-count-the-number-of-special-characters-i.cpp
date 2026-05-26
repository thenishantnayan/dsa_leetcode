class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int count =0;
        unordered_set<char>lower;
        unordered_set<char>upper;

        for(char ch: word){
            if(islower(ch))
                lower.insert(ch);
            
            else
                upper.insert(tolower(ch));
        }
        
        for(char ch: lower)
        {
            if(upper.find(ch) != upper.end())
                count++;
        }
        return count;
    }
};