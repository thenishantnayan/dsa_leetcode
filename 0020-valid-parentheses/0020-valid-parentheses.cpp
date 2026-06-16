class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c == '(')
                st.push(')');
            else if(c == '{')
                st.push('}');
            else if(c == '[')
                st.push(']');
            else{
                if(st.empty() || st.top() != c) //stack empty ho ya top se match nhi kr rha to false
                    return false;
                st.pop(); // match hai to pop kr do
            }
        }
        return st.empty(); // iska matlb true 
    }
};